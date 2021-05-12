//
// Created by Donato Wolfisberg on 18.12.2017.
//

#ifndef OWENATORV2_DEPTSTRUCT_H
#define OWENATORV2_DEPTSTRUCT_H

#include <string>
#include "../list/list.h"

using namespace std;

struct Dept : Node {
	string reason = "";
	double amount = 0;
};

#endif //OWENATORV2_DEPTSTRUCT_H
