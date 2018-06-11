//
// Created by Donato Wolfisberg on 22.11.2017.
//

#ifndef OWENATOR_USERNODE_H
#define OWENATOR_USERNODE_H

#include "../list/list.h"
#include "../person/personNode.h"


typedef struct userNode User;
struct userNode : node_struct<User> {
	userNode() = default;

    string username = "";
    string password = "";

    long int personIdCounter = 0;
    Person* personHead = nullptr;
    Person* personTail = nullptr;
};

#endif //OWENATOR_USERNODE_H
