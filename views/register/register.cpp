//
// Created by Donato Wolfisberg on 15.12.2017.
//

#include <iostream>
#include "../../list/list.h"
#include "../../gui/gui.h"
#include "register.h"
#include "../overview/overviewOption.h"
#include "../login/loginOption.h"

RouteOption *handleRegister(RegisterOption *registerOption) {

	Label* titleLabel = new Label;
	titleLabel->X = 2;
	titleLabel->Y = 2;
	titleLabel->text = "Please Register";
	addLabel(titleLabel);


	Input* usernameInput = new Input;
	usernameInput->X = 19;
	usernameInput->Y = 5;
	usernameInput->length = 20;
	addInput(usernameInput);

	Label *usernameLabel = new Label;
	usernameLabel->X = 2;
	usernameLabel->Y = 5;
	usernameLabel->text = "Username       : ";
	usernameLabel->length = 10;
	usernameLabel->forInput = usernameInput;
	addLabel(usernameLabel);


	Input *passwordInput = new Input;
	passwordInput->X = 19;
	passwordInput->Y = 7;
	passwordInput->length = 20;
	passwordInput->inputType = INPUT_TYPE_PASSWORD;
	addInput(passwordInput);

	Label *passwordLabel = new Label;
	passwordLabel->X = 2;
	passwordLabel->Y = 7;
	passwordLabel->text = "Password       : ";
	passwordLabel->length = 10;
	passwordLabel->forInput = passwordInput;
	addLabel(passwordLabel);


	Input *passwordRepeatInput = new Input;
	passwordRepeatInput->X = 19;
	passwordRepeatInput->Y = 9;
	passwordRepeatInput->length = 20;
	passwordRepeatInput->inputType = INPUT_TYPE_PASSWORD;
	addInput(passwordRepeatInput);

	Label *passwordRepeatLabel = new Label;
	passwordRepeatLabel->X = 2;
	passwordRepeatLabel->Y = 9;
	passwordRepeatLabel->text = "Repeat Password: ";
	passwordRepeatLabel->length = 10;
	passwordRepeatLabel->forInput = passwordRepeatInput;
	addLabel(passwordRepeatLabel);






	Label *errorLabel = new Label;
	errorLabel->X = 2;
	errorLabel->Y = 10;
	errorLabel->length = 20;
	errorLabel->foregroundColor = GUI_COLOR_FOREGROUND_RED;
	addLabel(errorLabel);


	function<bool(Button *)> onRegisterButton = [&](Button *button) -> bool {
		if (usernameInput->text.empty()) {
			errorLabel->text = "Username can't be empty";
			renderLabel(errorLabel);
			setActiveInput(usernameInput);
			return false;
		}
		if (doesUsernameExist(usernameInput->text)) {
			errorLabel->text = "Username does already exist";
			renderLabel(errorLabel);
			setActiveInput(usernameInput);
			return false;
		}
		if(passwordInput->text != passwordRepeatInput->text) {
			errorLabel->text = "passwords do not match";
			renderLabel(errorLabel);
			setActiveInput(usernameInput);
			return false;
		}
		if(passwordInput->text.empty() || passwordRepeatInput->text.empty()) {
			errorLabel->text = "password can't be empty";
			renderLabel(errorLabel);
			setActiveInput(usernameInput);
			return false;
		}

		return true;
	};


	Button *registerButton = new Button;
	registerButton->X = 4;
	registerButton->Y = 11;
	registerButton->text = "Register";
	registerButton->paddingLeft = 2;
	registerButton->paddingRight = 2;
	registerButton->backgroundColor = GUI_COLOR_BACKGROUND_WHITE;
	registerButton->foregroundColor = GUI_COLOR_FOREGROUND_BLACK;
	registerButton->onClick = onRegisterButton;
	addButton(registerButton);


	function<bool(Button *)> onGoToLoginButton = [&](Button *button) -> bool {
		return true;
	};

	Button *goToLoginButton = new Button;
	goToLoginButton->X = 17;
	goToLoginButton->Y = 11;
	goToLoginButton->text = "go to Login";
	goToLoginButton->paddingLeft = 2;
	goToLoginButton->paddingRight = 2;
	goToLoginButton->backgroundColor = GUI_COLOR_BACKGROUND_WHITE;
	goToLoginButton->foregroundColor = GUI_COLOR_FOREGROUND_BLACK;
	goToLoginButton->onClick = onGoToLoginButton;
	addButton(goToLoginButton);

	Button *clickedButton = showGui();

	RouteOption *returnRouteOption = nullptr;

	if (clickedButton == registerButton) {
		auto* overviewOption = new OverviewOption();
		overviewOption->user = addUser(usernameInput->text, passwordRepeatInput->text);
		returnRouteOption = overviewOption;
	} else {
		returnRouteOption = new LoginOption();
	}


	destroyGui();
	delete registerOption;
	return returnRouteOption;
}
