//
// Created by Donato Wolfisberg on 13.12.2017.
//

#ifndef OWENATORV2_OVERVIEWOPTION_H
#define OWENATORV2_OVERVIEWOPTION_H


using namespace std;

#include <string>
#include "../routeOption.h"
#include "../../user/user.h"

struct OverviewOption: RouteOption {
	OverviewOption() {
		route = "overview";
	}
	User* user;
	string sortProp = "id";
	bool sortAsc = true;
};


#endif //OWENATORV2_OVERVIEWOPTION_H
