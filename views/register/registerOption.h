//
// Created by Donato Wolfisberg on 15.12.2017.
//

#ifndef OWENATORV2_REGISTEROPTION_H
#define OWENATORV2_REGISTEROPTION_H

using namespace std;

#include <string>
#include "../routeOption.h"

struct RegisterOption: RouteOption {
	RegisterOption() {
		route = "register";
	}
};

#endif //OWENATORV2_REGISTEROPTION_H
