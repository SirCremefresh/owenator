//
// Created by Donato Wolfisberg on 13.12.2017.
//

#include "login.h"
#include "../../gui/gui.h"
#include "../../user/user.h"
#include "../overview/overviewOption.h"
#include "../register/registerOption.h"

RouteOption *handleLogin(LoginOption *loginOption) {


	Label *titleLabel = new Label;
	titleLabel->X = 2;
	titleLabel->Y = 2;
	titleLabel->text = "Please Login";
	addLabel(titleLabel);


	Input *usernameInput = new Input;
	usernameInput->X = 12;
	usernameInput->Y = 5;
	usernameInput->length = 20;
	addInput(usernameInput);

	Label *usernameLabel = new Label;
	usernameLabel->X = 2;
	usernameLabel->Y = 5;
	usernameLabel->text = "Username: ";
	usernameLabel->length = 10;
	usernameLabel->forInput = usernameInput;
	addLabel(usernameLabel);


	Input *passwordInput = new Input;
	passwordInput->X = 12;
	passwordInput->Y = 7;
	passwordInput->length = 20;
	passwordInput->inputType = INPUT_TYPE_PASSWORD;
	addInput(passwordInput);

	Label *passwordLabel = new Label;
	passwordLabel->X = 2;
	passwordLabel->Y = 7;
	passwordLabel->text = "Password: ";
	passwordLabel->length = 10;
	passwordLabel->forInput = passwordInput;
	addLabel(passwordLabel);


	Label *errorLabel = new Label;
	errorLabel->X = 2;
	errorLabel->Y = 8;
	errorLabel->length = 20;
	errorLabel->foregroundColor = GUI_COLOR_FOREGROUND_RED;
	addLabel(errorLabel);


	function<bool(Button *)> onLoginButton = [&](Button *button) -> bool {
		User *user = getUserWith(usernameInput->text, passwordInput->text);
		if (user != nullptr) {
			return true;
		}
		errorLabel->text = "Username Or Password are Wrong";
		passwordInput->text = "";
		renderInput(passwordInput);
		renderLabel(errorLabel);
		setActiveInput(usernameInput);
		return false;
	};


	Button *loginButton = new Button;
	loginButton->X = 4;
	loginButton->Y = 10;
	loginButton->text = "Login";
	loginButton->paddingLeft = 2;
	loginButton->paddingRight = 2;
	loginButton->backgroundColor = GUI_COLOR_BACKGROUND_WHITE;
	loginButton->foregroundColor = GUI_COLOR_FOREGROUND_BLACK;
	loginButton->onClick = onLoginButton;
	addButton(loginButton);


	function<bool(Button *)> onGoToRegisterButton = [&](Button *button) -> bool {
		return true;
	};

	Button *goToRegisterButton = new Button;
	goToRegisterButton->X = 16;
	goToRegisterButton->Y = 10;
	goToRegisterButton->text = "go to Register";
	goToRegisterButton->paddingLeft = 2;
	goToRegisterButton->paddingRight = 2;
	goToRegisterButton->backgroundColor = GUI_COLOR_BACKGROUND_WHITE;
	goToRegisterButton->foregroundColor = GUI_COLOR_FOREGROUND_BLACK;
	goToRegisterButton->onClick = onGoToRegisterButton;
	addButton(goToRegisterButton);

	Button *clickedButton = showGui();

	RouteOption* returnRouteOption = nullptr;

	if (clickedButton == loginButton) {
		OverviewOption *overviewOption = new OverviewOption();
		overviewOption->user = getUserWith(usernameInput->text, passwordInput->text);
		returnRouteOption = overviewOption;
	} else {
		RegisterOption *registerOption = new RegisterOption();
		returnRouteOption = registerOption;
	}

	destroyGui();
	delete loginOption;
	return returnRouteOption;
}
