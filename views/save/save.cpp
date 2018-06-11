//
// Created by Donato Wolfisberg on 20.12.2017.
//

#include "save.h"
#include "../../filemanager/filemanager.h"

RouteOption *handleSave(SaveOption *saveOption) {
	saveToFile();
	RouteOption* routeOption = new RouteOption;
	routeOption->route = "exit";
	return routeOption;
}
