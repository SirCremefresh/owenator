//
// Created by Donato Wolfisberg on 20.12.2017.
//

#ifndef OWENATORV2_SAVEOPTION_H
#define OWENATORV2_SAVEOPTION_H

#include "../routeOption.h"

struct SaveOption: RouteOption {
	SaveOption() {
		route = "save";
	}
};

#endif //OWENATORV2_SAVEOPTION_H
