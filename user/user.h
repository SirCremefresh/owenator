//
// Created by Donato Wolfisberg on 13.12.2017.
//

#ifndef OWENATORV2_USER_H
#define OWENATORV2_USER_H

#include "../list/list.h"
#include "../person/personStruct.h"
#include "userStruct.h"

using namespace std;


List<User> *getUserList();

void setUserList(List<User> *userList);

User *addUser(string username, string password);

User *getUserWith(string username, string password);

bool doesUsernameExist(string username);

#endif //OWENATORV2_USER_H
