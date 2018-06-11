//
// Created by Donato Wolfisberg on 15.12.2017.
//

#ifndef OWENATORV2_USERSTRUCT_H
#define OWENATORV2_USERSTRUCT_H

#include <string>
#include "../person/personStruct.h"
#include "../list/listStructs.h"

using namespace std;


struct User : Node {
	~User() {
		delete personList;
	}
	string username = "";
	string password = "";

	List<Person>* personList = new List<Person>();
};

#endif //OWENATORV2_USERSTRUCT_H
