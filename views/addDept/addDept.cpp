//
// Created by Donato Wolfisberg on 19.12.2017.
//

#include "addDept.h"
#include "../../gui/gui.h"
#include "../../dept/dept.h"
#include "../personDetail/personDetailOption.h"

RouteOption *handleAddDept(AddDeptOption *addDeptOption) {
	Person *person = addDeptOption->person;
	User *user = addDeptOption->user;

	Label *titleLabel = new Label;
	titleLabel->X = 2;
	titleLabel->Y = 2;
	titleLabel->text = "Create new Person";
	addLabel(titleLabel);


	Input *reasonInput = new Input;
	reasonInput->X = 12;
	reasonInput->Y = 5;
	reasonInput->length = 20;
	addInput(reasonInput);

	Label *reasonLabel = new Label;
	reasonLabel->X = 2;
	reasonLabel->Y = 5;
	reasonLabel->text = "reason: ";
	reasonLabel->length = 10;
	reasonLabel->forInput = reasonInput;
	addLabel(reasonLabel);


	Input *amountInput = new Input;
	amountInput->X = 12;
	amountInput->Y = 7;
	amountInput->length = 20;
	addInput(amountInput);

	Label *amountLabel = new Label;
	amountLabel->X = 2;
	amountLabel->Y = 7;
	amountLabel->text = "amount: ";
	amountLabel->length = 10;
	amountLabel->forInput = amountInput;
	addLabel(amountLabel);


	Label *errorLabel = new Label;
	errorLabel->X = 2;
	errorLabel->Y = 8;
	errorLabel->length = 20;
	errorLabel->foregroundColor = GUI_COLOR_FOREGROUND_RED;
	addLabel(errorLabel);


	function<bool(Button *)> onCreateButton = [&](Button *button) -> bool {
		if (reasonInput->text.empty()) {
			errorLabel->text = "Reason field can't be empty";
			renderLabel(errorLabel);
			setActiveInput(reasonInput);
			return false;
		}
		if (amountInput->text.empty()) {
			errorLabel->text = "Amount field can't be empty";
			renderLabel(errorLabel);
			setActiveInput(amountInput);
			return false;
		}
		double amount = atof(amountInput->text.c_str());
		if (amount == 0) {
			errorLabel->text = "Amount are not all numbers or is zero";
			renderLabel(errorLabel);
			setActiveInput(amountInput);
			return false;
		}
		addDept(reasonInput->text, amount, person);
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


	function<bool(Button *)> onCancelButton = [&](Button *button) -> bool {
		return true;
	};

	Button *CancelButton = new Button;
	CancelButton->X = 16;
	CancelButton->Y = 10;
	CancelButton->text = "Cancel";
	CancelButton->paddingLeft = 2;
	CancelButton->paddingRight = 2;
	CancelButton->backgroundColor = GUI_COLOR_BACKGROUND_WHITE;
	CancelButton->foregroundColor = GUI_COLOR_FOREGROUND_BLACK;
	CancelButton->onClick = onCancelButton;
	addButton(CancelButton);

	Button *clickedButton = showGui();
	destroyGui();

	PersonDetailOption *personDetailOption = new PersonDetailOption();
	personDetailOption->person = person;
	personDetailOption->user = user;
	return personDetailOption;
}
