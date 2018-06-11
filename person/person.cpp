//
// Created by Donato Wolfisberg on 13.12.2017.
//

#include "person.h"



Person *addPerson(string surname, string lastName, User* user) {
	auto* person = new Person();
	person->surname = surname;
	person->forename = lastName;
	return addNode(person, user->personList)->value;
}
