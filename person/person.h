//
// Created by Donato Wolfisberg on 20.11.2017.
//

#ifndef OWENATOR_PERSON_H
#define OWENATOR_PERSON_H

#include <string>
#include "personNode.h"
#include "../user/userNode.h"

using namespace std;



Person* addPerson(User* user, string name, string lastName);

void deletePerson(User* user, long int id);
Person* getPerson(User* user, long int id);
bool getNextPerson(User* user, Person** person, bool backwards = false);
#endif //OWENATOR_PERSON_H
