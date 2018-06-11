#include "views/router.h"
#include "filemanager/filemanager.h"

int main() {
	loadFromFile();


	auto* routeOption = new LoginOption();
	runRouter(routeOption);

	return 0;
}