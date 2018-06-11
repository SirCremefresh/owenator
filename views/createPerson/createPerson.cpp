//
// Created by Donato Wolfisberg on 18.12.2017.
//

#include "createPerson.h"
#include "../../gui/gui.h"
#include "../../person/person.h"
#include "../overview/overviewOption.h"

RouteOption *handleCreatePerson(CreatePersonOption *createPersonOption) {
	Label *titleLabel = new Label;
	titleLabel->X = 2;
	titleLabel->Y = 2;
	titleLabel->text = "Create new Person";
	addLabel(titleLabel);


	Input *surnameInput = new Input;
	surnameInput->X = 12;
	surnameInput->Y = 5;
	surnameInput->length = 20;
	addInput(surnameInput);

	Label *surnameLabel = new Label;
	surnameLabel->X = 2;
	surnameLabel->Y = 5;
	surnameLabel->text = "surname: ";
	surnameLabel->length = 10;
	surnameLabel->forInput = surnameInput;
	addLabel(surnameLabel);


	Input *lastNameInput = new Input;
	lastNameInput->X = 12;
	lastNameInput->Y = 7;
	lastNameInput->length = 20;
	addInput(lastNameInput);

	Label *lastNameLabel = new Label;
	lastNameLabel->X = 2;
	lastNameLabel->Y = 7;
	lastNameLabel->text = "lastName: ";
	lastNameLabel->length = 10;
	lastNameLabel->forInput = lastNameInput;
	addLabel(lastNameLabel);


	Label *errorLabel = new Label;
	errorLabel->X = 2;
	errorLabel->Y = 8;
	errorLabel->length = 20;
	errorLabel->foregroundColor = GUI_COLOR_FOREGROUND_RED;
	addLabel(errorLabel);


	function<bool(Button *)> onCreateButton = [&](Button *button) -> bool {
		if (surnameInput->text.empty()) {
			errorLabel->text = "Surname field can't be empty";
			renderLabel(errorLabel);
			setActiveInput(surnameInput);
			return false;
		}
		if (lastNameInput->text.empty()) {
			errorLabel->text = "LastName field can't be empty";
			renderLabel(errorLabel);
			setActiveInput(lastNameInput);
			return false;
		}
		addPerson(surnameInput->text, lastNameInput->text, createPersonOption->user);
		return true;
	};


	Button *CreateButton = new Button;
	CreateButton->X = 4;
	CreateButton->Y = 10;
	CreateButton->text = "create";
	CreateButton->paddingLeft = 2;
	CreateButton->paddingRight = 2;
	CreateButton->backgroundColor = GUI_COLOR_BACKGROUND_WHITE;
	CreateButton->foregroundColor = GUI_COLOR_FOREGROUND_BLACK;
	CreateButton->onClick = onCreateButton;
	addButton(CreateButton);


	Button *CancelButton = new Button;
	CancelButton->X = 16;
	CancelButton->Y = 10;
	CancelButton->text = "Cancel";
	CancelButton->paddingLeft = 2;
	CancelButton->paddingRight = 2;
	CancelButton->backgroundColor = GUI_COLOR_BACKGROUND_WHITE;
	CancelButton->foregroundColor = GUI_COLOR_FOREGROUND_BLACK;
	CancelButton->onClick = [&](Button *button) -> bool { return true; };
	addButton(CancelButton);

	Button *clickedButton = showGui();
	destroyGui();

	OverviewOption *overviewOption = new OverviewOption();
	overviewOption->user = createPersonOption->user;
	return overviewOption;
}
