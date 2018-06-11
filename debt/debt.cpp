//
// Created by Donato Wolfisberg on 20.11.2017.
//
#include <string>
#include "../person/person.h"
#include "../list/list.h"

using namespace std;



Debt *addDebt(Person *person, string reason, double amount) {
    auto* debt = new Debt(person->debtIdCounter++, reason, amount);
    addNode(&debt, &person->debtHead, &person->debtTail);
    return debt;
}



void deleteDebt(Person *person, long int id) {
    delete deleteNode(id, &person->debtHead, &person->debtTail);
}



Debt *getDebt(Person *person, long int id) {
    return getNode(id, person->debtHead, person->debtTail);
}



bool getNextDebt(Person *person, Debt **debt, bool backwards) {
    return getNextNode(debt, person->debtHead, person->debtTail, backwards);
}
