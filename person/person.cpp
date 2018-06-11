//
// Created by Donato Wolfisberg on 20.11.2017.
//

#include <iostream>
#include "person.h"
#include "../list/list.h"

using namespace std;



Person* addPerson(User* user, string name, string lastName) {
    auto* person = new Person(user->personIdCounter++, name, lastName);
    addNode(&person, &user->personHead, &user->personTail);
    return person;
}



void deletePerson(User* user, long int id) {
    delete deleteNode(id, &user->personHead, &user->personTail);
}


bool getNextPerson(User* user, Person** person, bool backwards /*false*/) {
    return getNextNode(person, user->personHead, user->personTail, backwards);
}

Person *getPerson(User* user, long int id) {
    return getNode(id, user->personHead, user->personTail);
}




