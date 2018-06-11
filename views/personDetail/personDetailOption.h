//
// Created by Donato Wolfisberg on 18.12.2017.
//

#ifndef OWENATORV2_PERSONDETAILOPTION_H
#define OWENATORV2_PERSONDETAILOPTION_H

#include "../routeOption.h"
#include "../../person/personStruct.h"
#include "../../user/userStruct.h"

struct PersonDetailOption: RouteOption {
	PersonDetailOption() {
		route = "personDetail";
	}
	User* user;
	Person* person;
};



#endif //OWENATORV2_PERSONDETAILOPTION_H
