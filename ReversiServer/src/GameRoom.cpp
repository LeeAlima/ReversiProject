//
// Created by omer on 25/12/17.
//

#include <unistd.h>
#include "../include/GameRoom.h"
#include "../include/RunServer.h"

GameRoom::GameRoom(Game *game, ServerContainer *serverContainer) : game(game), serverContainer(serverContainer) {}

bool GameRoom::handleMove(int sender, int receiver) {
    char buffer_local[9];
    cout << "wait for receiving move " << sender << endl;
    int n = read(sender, buffer_local, 9);
    if (n == -1) {
        cout << "Error reading buffer_local" << endl;
        return false;
    }
    if (n == 0) {
        cout << "Client disconnected" << endl;
        return false;
    }
    cout << "Got move: " << buffer_local << endl;
    if (strcmp(buffer_local, "END") == 0) {
        cout<<"end of game "<< game->getName() << endl;
        game->setStatus(ENDGAME);
        serverContainer->removeGame(game->getName());
        return false;
    }
    // write data
    n = write(receiver, buffer_local, 9);
    if (n == -1) {
        cout << "Error writing buffer_local" << endl;
        return false;
    }
    if (n == 0) {
        cout << "Client disconnected" << endl;
        return false;
    }
    cout << "Sent Move:" << buffer_local << endl;
    return true;
}

void* GameRoom::runGame(void* obj) {
    GameRoom *ptr = (GameRoom *) obj;
    int num_of_client=1;
    write(ptr->game->getFirst_socket(), &num_of_client, sizeof(num_of_client));
    num_of_client = 2;
    write(ptr->game->getSecond_socket(), &num_of_client, sizeof(num_of_client));
    bool ok = true;
    int i=0;
    while (ok) {
        if (i % 2 == 0) {
            ok = ptr->handleMove(ptr->game->getFirst_socket(), ptr->game->getSecond_socket());
        } else {
            ok = ptr->handleMove(ptr->game->getSecond_socket(), ptr->game->getFirst_socket());
        }
        i++;
    }

}

void GameRoom::addThread() {
    pthread_t *newThread = new pthread_t();
    int rc = pthread_create(newThread, NULL, runGame, (void*)this);
    if (rc) {
        cout << "Error: unable to create thread, " << rc << endl;
        pthread_exit(&newThread);
    }
    pthread_exit(&newThread);

}

