//
// Created by Donato Wolfisberg on 18.12.2017.
//

#ifndef OWENATORV2_CREATEPERSONOPTION_H
#define OWENATORV2_CREATEPERSONOPTION_H

using namespace std;

#include <string>
#include "../routeOption.h"
#include "../../user/userStruct.h"

struct CreatePersonOption: RouteOption {
	CreatePersonOption() {
		route = "createPerson";
	}
	User* user;
};


#endif //OWENATORV2_CREATEPERSONOPTION_H
