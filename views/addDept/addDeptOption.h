//
// Created by Donato Wolfisberg on 19.12.2017.
//

#ifndef OWENATORV2_ADDDEPTOPTION_H
#define OWENATORV2_ADDDEPTOPTION_H

#include "../routeOption.h"
#include "../../person/personStruct.h"
#include "../../user/userStruct.h"

struct AddDeptOption: RouteOption {
	AddDeptOption() {
		route = "addDept";
	}
	Person* person;
	User* user;
};


#endif //OWENATORV2_ADDDEPTOPTION_H
