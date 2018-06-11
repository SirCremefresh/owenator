//
// Created by Donato Wolfisberg on 15.12.2017.
//

#ifndef OWENATORV2_PERSONSTRUCT_H
#define OWENATORV2_PERSONSTRUCT_H

#include "../list/list.h"
#include "../dept/deptStruct.h"

using namespace std;

struct Person : Node {
	string surname = "";
	string forename = "";

	List<Dept>* deptList = new List<Dept>();

};

#endif //OWENATORV2_PERSONSTRUCT_H
