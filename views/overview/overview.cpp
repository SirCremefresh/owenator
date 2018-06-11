//
// Created by Donato Wolfisberg on 13.12.2017.
//

#include <iostream>
#include <sstream>
#include "overview.h"
#include "../../gui/gui.h"
#include "../login/loginOption.h"
#include "../createPerson/createPersonOption.h"
#include "../../dept/dept.h"
#include "../personDetail/personDetailOption.h"
#include "../save/saveOption.h"


RouteOption *handleOverview(OverviewOption *overviewOption) {
	User *user = overviewOption->user;

	if (overviewOption->sortProp == "surname") {
		function<bool(Person *, Person *)> sorter;
		if (overviewOption->sortAsc) {
			sorter = [](Person *person1, Person *person2) {
				return person1->surname > person2->surname;
			};
		} else {
			sorter = [](Person *person1, Person *person2) {
				return person1->surname < person2->surname;
			};
		}
		sortList(sorter, user->personList);
	} else if (overviewOption->sortProp == "dept") {
		function<bool(Person *, Person *)> sorter;
		if (overviewOption->sortAsc) {
			sorter = [](Person *person1, Person *person2) {
				return getSumOfDept(person1) > getSumOfDept(person2);
			};
		} else {
			sorter = [](Person *person1, Person *person2) {
				return getSumOfDept(person1) < getSumOfDept(person2);
			};
		}

		sortList(sorter, user->personList);
	} else if (overviewOption->sortProp == "forename") {
		function<bool(Person *, Person *)> sorter;
		if (overviewOption->sortAsc) {
			sorter = [](Person *person1, Person *person2) {
				return person1->forename > person2->forename;
			};
		} else {
			sorter = [](Person *person1, Person *person2) {
				return person1->forename < person2->forename;
			};
		}

		sortList(sorter, user->personList);
	}else {
		if (overviewOption->sortAsc) {
			sortListbyId(user->personList);
		} else {
			sortListbyId(user->personList, false);
		}
	}

	Button *saveButton = new Button;
	saveButton->X = 35;
	saveButton->Y = 0;
	saveButton->text = "Save Exit";
	saveButton->paddingLeft = 1;
	saveButton->paddingRight = 1;
	saveButton->backgroundColor = GUI_COLOR_BACKGROUND_WHITE;
	saveButton->foregroundColor = GUI_COLOR_FOREGROUND_BLACK;
	saveButton->onClick = [&](Button *button) -> bool { return true; };
	addButton(saveButton);

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
	titleLabel->text = "Overview";
	addLabel(titleLabel);

	Button *createNewPersonButton = new Button;
	createNewPersonButton->X = 4;
	createNewPersonButton->Y = 4;
	createNewPersonButton->text = "Create new Person";
	createNewPersonButton->paddingLeft = 2;
	createNewPersonButton->paddingRight = 2;
	createNewPersonButton->backgroundColor = GUI_COLOR_BACKGROUND_WHITE;
	createNewPersonButton->foregroundColor = GUI_COLOR_FOREGROUND_BLACK;
	createNewPersonButton->onClick = [&](Button *button) -> bool { return true; };
	addButton(createNewPersonButton);

	Button *tableIdButton = new Button;
	tableIdButton->X = 3;
	tableIdButton->Y = 6;
	tableIdButton->paddingLeft = 1;
	tableIdButton->length = 9;
	tableIdButton->backgroundColor = GUI_COLOR_BACKGROUND_WHITE;
	tableIdButton->foregroundColor = GUI_COLOR_FOREGROUND_RED;
	tableIdButton->text = "id";
	tableIdButton->onClick = [&](Button *button) -> bool { return true; };
	addButton(tableIdButton);

	Button *tableForenameButton = new Button;
	tableForenameButton->X = 13;
	tableForenameButton->Y = 6;
	tableForenameButton->paddingLeft = 1;
	tableForenameButton->length = 20;
	tableForenameButton->backgroundColor = GUI_COLOR_BACKGROUND_WHITE;
	tableForenameButton->foregroundColor = GUI_COLOR_FOREGROUND_RED;
	tableForenameButton->text = "Forename";
	tableForenameButton->onClick = [&](Button *button) -> bool { return false; };
	addButton(tableForenameButton);

	Button *tableSurnameButton = new Button;
	tableSurnameButton->X = 33;
	tableSurnameButton->Y = 6;
	tableSurnameButton->length = 20;
	tableSurnameButton->backgroundColor = GUI_COLOR_BACKGROUND_WHITE;
	tableSurnameButton->foregroundColor = GUI_COLOR_FOREGROUND_RED;
	tableSurnameButton->text = "Surname";
	tableSurnameButton->onClick = [&](Button *button) -> bool { return false; };
	addButton(tableSurnameButton);

	Button *tableDeptButton = new Button;
	tableDeptButton->X = 53;
	tableDeptButton->Y = 6;
	tableDeptButton->length = 20;
	tableDeptButton->backgroundColor = GUI_COLOR_BACKGROUND_WHITE;
	tableDeptButton->foregroundColor = GUI_COLOR_FOREGROUND_RED;
	tableDeptButton->text = "Dept";
	tableDeptButton->onClick = [&](Button *button) -> bool { return true; };
	addButton(tableDeptButton);

	Person *clickedPerson = nullptr;
	NodeWrapper<Person> *personWrapper = nullptr;
	for (short i = 7; getNextNode(&personWrapper, user->personList); i++) {
		Person *person = personWrapper->value;

		auto *tableDataIdLabel = new Label;
		tableDataIdLabel->X = 3;
		tableDataIdLabel->Y = i;
		tableDataIdLabel->paddingLeft = 1;
		tableDataIdLabel->length = 20;
		tableDataIdLabel->text = std::to_string(personWrapper->value->id);
		addLabel(tableDataIdLabel);

		auto *tableDataForenameLabel = new Label;
		tableDataForenameLabel->X = 13;
		tableDataForenameLabel->Y = i;
		tableDataForenameLabel->paddingLeft = 1;
		tableDataForenameLabel->length = 20;
		tableDataForenameLabel->text = personWrapper->value->surname;
		addLabel(tableDataForenameLabel);

		Label *tableDataSurnameLabel = new Label;
		tableDataSurnameLabel->X = 33;
		tableDataSurnameLabel->Y = i;
		tableDataSurnameLabel->length = 20;
		tableDataSurnameLabel->text = personWrapper->value->forename;
		addLabel(tableDataSurnameLabel);

		Label *tableDataDeptLabel = new Label;
		tableDataDeptLabel->X = 53;
		tableDataDeptLabel->Y = i;
		tableDataDeptLabel->length = 20;
		tableDataDeptLabel->text = to_string(getSumOfDept(person));
		addLabel(tableDataDeptLabel);

		auto onTableDataEditButtonClick = [&, person](Button *button) -> bool {
			clickedPerson = person;
			return true;
		};

		Button *tableDataEditButton = new Button;
		tableDataEditButton->X = 73;
		tableDataEditButton->Y = i;
		tableDataEditButton->length = 20;
		tableDataEditButton->text = "Show Details";
		tableDataEditButton->onClick = onTableDataEditButtonClick;
		addButton(tableDataEditButton);
	}


	Button *clickedButton = showGui();

	RouteOption *returnRouteOption = nullptr;

	if (clickedPerson != nullptr) {
		PersonDetailOption* personDetailOption = new PersonDetailOption;
		personDetailOption->person = clickedPerson;
		personDetailOption->user = user;
		returnRouteOption = personDetailOption;
	}

	if (clickedButton == createNewPersonButton) {
		CreatePersonOption *createPersonOption = new CreatePersonOption;
		createPersonOption->user = user;
		returnRouteOption = createPersonOption;
	}

	if (clickedButton == logoutButton) {
		returnRouteOption = new LoginOption;
	}

	if (clickedButton == tableForenameButton) {
		OverviewOption *returnOverviewOption = new OverviewOption;
		returnOverviewOption->user = overviewOption->user;
		returnOverviewOption->sortProp = "forename";
		if (overviewOption->sortProp == "forename") {
			returnOverviewOption->sortAsc = !overviewOption->sortAsc;
		}
		returnRouteOption = returnOverviewOption;
	}

	if (clickedButton == tableSurnameButton) {
		OverviewOption *returnOverviewOption = new OverviewOption;
		returnOverviewOption->user = overviewOption->user;
		returnOverviewOption->sortProp = "surname";
		if (overviewOption->sortProp == "surname") {
			returnOverviewOption->sortAsc = !overviewOption->sortAsc;
		}
		returnRouteOption = returnOverviewOption;
	}

	if (clickedButton == tableIdButton) {
		OverviewOption *returnOverviewOption = new OverviewOption;
		returnOverviewOption->user = overviewOption->user;
		returnOverviewOption->sortProp = "id";
		if (overviewOption->sortProp == "id") {
			returnOverviewOption->sortAsc = !overviewOption->sortAsc;
		}
		returnRouteOption = returnOverviewOption;
	}

	if (clickedButton == tableDeptButton) {
		OverviewOption *returnOverviewOption = new OverviewOption;
		returnOverviewOption->user = overviewOption->user;
		returnOverviewOption->sortProp = "dept";
		if (overviewOption->sortProp == "dept") {
			returnOverviewOption->sortAsc = !overviewOption->sortAsc;
		}
		returnRouteOption = returnOverviewOption;
	}

	if (clickedButton == saveButton) {
		returnRouteOption = new SaveOption;
	}

	destroyGui();
	delete overviewOption;
	return returnRouteOption;
}
