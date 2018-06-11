//
// Created by Donato Wolfisberg on 20.11.2017.
//

#include <iostream>
#include "user.h"
#include "userNode.h"
#include "../list/list.h"


using namespace std;

User* head = nullptr;
User* tail = nullptr;
float userIdCounter = 0;


User* addUser(string username, string password) {
    auto* user = new User();
	user->username = username;
	user->password = password;
	user->id = userIdCounter++;

    addNode(&user, &head, &tail);
    return user;
}



void deleteUser(long int id) {
    delete deleteNode(id, &head, &tail);
}


bool getNextUser(User** user, bool backwards /*false*/) {
    return getNextNode(user, head, tail, backwards);
}

User *getUser(long int id) {
    return getNode(id, head, tail);
}




