//
// Created by Donato Wolfisberg on 20.11.2017.
//

#ifndef OWENATOR_OWE_H
#define OWENATOR_OWE_H

#include <string>
#include "debtNode.h"
#include "../person/personNode.h"

using namespace std;




Debt* addDebt(Person* person, string reason, double amount);


void deleteDebt(Person* person, long int id);


Debt* getDebt(Person* person, long int id);


bool getNextDebt(Person* person, Debt** debt, bool backwards = false);

#endif //OWENATOR_OWE_H
