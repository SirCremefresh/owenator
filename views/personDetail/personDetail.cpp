//
// Created by Donato Wolfisberg on 18.12.2017.
//

#include "personDetail.h"
#include "../../user/userStruct.h"
#include "../../gui/gui.h"
#include "../login/loginOption.h"
#include "../overview/overviewOption.h"
#include "../../dept/dept.h"
#include "../addDept/addDeptOption.h"

RouteOption *handlePersonDetail(PersonDetailOption *personDetailOption) {
	User *user = personDetailOption->user;
	Person *person = personDetailOption->person;

	Label *loggedInAsLabel = new Label;
	loggedInAsLabel->X = 53;
	loggedInAsLabel->Y = 0;
	loggedInAsLabel->text = "Logged in as: " + user->username;
	addLabel(loggedInAsLabel);

	Button *logoutButton = new Button;
	logoutButton->X = static_cast<short>(69 + user->username.length());
	logoutButton->Y = 0;
	logoutButton->text = "Logout";
	logoutButton->paddingLeft = 1;
	logoutButton->paddingRight = 1;
	logoutButton->backgroundColor = GUI_COLOR_BACKGROUND_WHITE;
	logoutButton->foregroundColor = GUI_COLOR_FOREGROUND_BLACK;
	logoutButton->onClick = [&](Button *button) -> bool { return true; };
	addButton(logoutButton);

	Label *titleLabel = new Label;
	titleLabel->X = 2;
	titleLabel->Y = 1;
	titleLabel->text = "PersonDetail";
	addLabel(titleLabel);

	Button *createNewDeptButton = new Button;
	createNewDeptButton->X = 4;
	createNewDeptButton->Y = 4;
	createNewDeptButton->text = "add Dept";
	createNewDeptButton->paddingLeft = 2;
	createNewDeptButton->paddingRight = 2;
	createNewDeptButton->backgroundColor = GUI_COLOR_BACKGROUND_WHITE;
	createNewDeptButton->foregroundColor = GUI_COLOR_FOREGROUND_BLACK;
	createNewDeptButton->onClick = [&](Button *button) -> bool { return true; };
	addButton(createNewDeptButton);

	Button *backToOverviewButton = new Button;
	backToOverviewButton->X = 19;
	backToOverviewButton->Y = 4;
	backToOverviewButton->text = "go Back";
	backToOverviewButton->paddingLeft = 2;
	backToOverviewButton->paddingRight = 2;
	backToOverviewButton->backgroundColor = GUI_COLOR_BACKGROUND_WHITE;
	backToOverviewButton->foregroundColor = GUI_COLOR_FOREGROUND_BLACK;
	backToOverviewButton->onClick = [&](Button *button) -> bool { return true; };
	addButton(backToOverviewButton);

	Label *deptStatusLabel = new Label;
	deptStatusLabel->X = 4;
	deptStatusLabel->Y = 6;
	if (getSumOfDept(person) >= 0) {
		deptStatusLabel->text = "you own him: ";
	} else {
		deptStatusLabel->text = "he owns you: ";
	}
	deptStatusLabel->text += to_string(abs(getSumOfDept(person)));
	addLabel(deptStatusLabel);

	Button *tableIdButton = new Button;
	tableIdButton->X = 3;
	tableIdButton->Y = 8;
	tableIdButton->paddingLeft = 1;
	tableIdButton->length = 9;
	tableIdButton->backgroundColor = GUI_COLOR_BACKGROUND_WHITE;
	tableIdButton->foregroundColor = GUI_COLOR_FOREGROUND_RED;
	tableIdButton->text = "id";
	addButton(tableIdButton);

	Button *tableForenameButton = new Button;
	tableForenameButton->X = 13;
	tableForenameButton->Y = 8;
	tableForenameButton->paddingLeft = 1;
	tableForenameButton->length = 20;
	tableForenameButton->backgroundColor = GUI_COLOR_BACKGROUND_WHITE;
	tableForenameButton->foregroundColor = GUI_COLOR_FOREGROUND_RED;
	tableForenameButton->text = "reason";
	addButton(tableForenameButton);

	Button *tableSurnameButton = new Button;
	tableSurnameButton->X = 33;
	tableSurnameButton->Y = 8;
	tableSurnameButton->length = 20;
	tableSurnameButton->backgroundColor = GUI_COLOR_BACKGROUND_WHITE;
	tableSurnameButton->foregroundColor = GUI_COLOR_FOREGROUND_RED;
	tableSurnameButton->text = "amount";
	addButton(tableSurnameButton);

	NodeWrapper<Dept> *deptWrapper = nullptr;
	for (short i = 9; getNextNode(&deptWrapper, person->deptList); i++) {
		Dept *dept = deptWrapper->value;

		auto *tableDataIdLabel = new Label;
		tableDataIdLabel->X = 3;
		tableDataIdLabel->Y = i;
		tableDataIdLabel->paddingLeft = 1;
		tableDataIdLabel->length = 20;
		tableDataIdLabel->text = std::to_string(dept->id);
		addLabel(tableDataIdLabel);

		auto *tableDataForenameLabel = new Label;
		tableDataForenameLabel->X = 13;
		tableDataForenameLabel->Y = i;
		tableDataForenameLabel->paddingLeft = 1;
		tableDataForenameLabel->length = 20;
		tableDataForenameLabel->text = dept->reason;
		addLabel(tableDataForenameLabel);


		Label *tableDataDeptLabel = new Label;
		tableDataDeptLabel->X = 33;
		tableDataDeptLabel->Y = i;
		tableDataDeptLabel->length = 20;
		tableDataDeptLabel->text = to_string(dept->amount);
		addLabel(tableDataDeptLabel);

	}


	Button *clickedButton = showGui();

	RouteOption *returnRouteOption = nullptr;


	if (clickedButton == createNewDeptButton) {
		AddDeptOption* addDeptOption = new AddDeptOption;
		addDeptOption->user = user;
		addDeptOption->person = person;
		returnRouteOption = addDeptOption;
	}

	if (clickedButton == logoutButton) {
		returnRouteOption = new LoginOption;
	}

	if (clickedButton == backToOverviewButton) {
		OverviewOption* overviewOption = new OverviewOption;
		overviewOption->user = user;
		returnRouteOption = overviewOption;
	}


	destroyGui();
	delete personDetailOption;
	return returnRouteOption;}
