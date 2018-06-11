//
// Created by Donato Wolfisberg on 22.11.2017.
//

#ifndef OWENATOR_PERSONNODE_H
#define OWENATOR_PERSONNODE_H

#include "../list/list.h"
#include "../debt/debtNode.h"


typedef struct personNode Person;
struct personNode : node_struct<Person> {
    personNode() = default;
    personNode(long int id, const string &name, const string &lastName)
            : node_struct(id), name(name), lastName(lastName) {}

    string name = "";
    string lastName = "";

    long int debtIdCounter = 0;
    Debt* debtHead = nullptr;
    Debt* debtTail = nullptr;
};

#endif //OWENATOR_PERSONNODE_H
