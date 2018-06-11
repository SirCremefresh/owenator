//
// Created by Donato Wolfisberg on 22.11.2017.
//

#ifndef OWENATOR_DEBTNODE_H
#define OWENATOR_DEBTNODE_H

#include "../list/list.h"

using namespace std;

typedef struct debtNode Debt;
struct debtNode : node_struct<Debt>{
    debtNode() = default;
    debtNode(long int id, const string &reason, double amount) : node_struct(id), reason(reason), amount(amount) {}

    string reason;
    double amount;
};

#endif //OWENATOR_DEBTNODE_H
