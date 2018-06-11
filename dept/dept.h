//
// Created by Donato Wolfisberg on 18.12.2017.
//

#ifndef OWENATORV2_DEPT_H
#define OWENATORV2_DEPT_H

#include "../list/list.h"
#include "../person/personStruct.h"
#include "deptStruct.h"

using namespace std;

Dept *addDept(string reason, double amount, Person *person);

double getSumOfDept(Person *person);

#endif //OWENATORV2_DEPT_H
