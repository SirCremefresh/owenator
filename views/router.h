//
// Created by Donato Wolfisberg on 13.12.2017.
//

#ifndef OWENATORV2_ROUTER_H
#define OWENATORV2_ROUTER_H

#include "routeOption.h"
#include "login/login.h"
#include "register/register.h"
#include "overview/overview.h"
#include "createPerson/createPerson.h"
#include "personDetail/personDetailOption.h"
#include "personDetail/personDetail.h"
#include "addDept/addDept.h"
#include "save/save.h"

void runRouter(RouteOption *routeOptionStart) {
	RouteOption *routeOption = routeOptionStart;
	while (true) {
		if (routeOption->route == "login") {
			routeOption = handleLogin((LoginOption *) routeOption);
		}
		if (routeOption->route == "register") {
			routeOption = handleRegister((RegisterOption *) routeOption);
		}
		if (routeOption->route == "overview") {
			routeOption = handleOverview((OverviewOption *) routeOption);
		}
		if (routeOption->route == "createPerson") {
			routeOption = handleCreatePerson((CreatePersonOption *) routeOption);
		}
		if (routeOption->route == "personDetail") {
			routeOption = handlePersonDetail((PersonDetailOption *) routeOption);
		}
		if (routeOption->route == "addDept") {
			routeOption = handleAddDept((AddDeptOption *) routeOption);
		}

		if (routeOption->route == "save") {
			routeOption = handleSave((SaveOption *) routeOption);
		}

		if (routeOption->route == "exit") {
			break;
		}
	}
}

#endif //OWENATORV2_ROUTER_H
