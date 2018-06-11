//
// Created by Donato Wolfisberg on 13.12.2017.
//

#ifndef OWENATORV2_LOGINOPTIONS_H
#define OWENATORV2_LOGINOPTIONS_H

using namespace std;

#include <string>
#include "../routeOption.h"

struct LoginOption: RouteOption {
	LoginOption() {
		route = "login";
	}
};

#endif //OWENATORV2_LOGINOPTIONS_H
