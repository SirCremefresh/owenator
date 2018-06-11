//
// Created by Donato Wolfisberg on 20.11.2017.
//

#ifndef OWENATOR_USER_H
#define OWENATOR_USER_H

#include <string>
#include "userNode.h"

using namespace std;



User* addUser(string username, string password);

void deleteUser(long int id);
User* getUser(long int id);
bool getNextUser(User** user, bool backwards = false);
#endif //OWENATOR_USER_H
