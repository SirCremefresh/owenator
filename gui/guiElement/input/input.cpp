//
// Created by Donato Wolfisberg on 12.12.2017.
//

#include "input.h"
#include "../../cursor/cursor.h"
#include "../../../list/list.h"
#include "../guiElement.h"

List<Input> inputList;
Input *activeInput = nullptr;

void addInput(Input *input) {
	addNode(input, &inputList);
}

List<Input> *getInputList() {
	return &inputList;
}

void setActiveInput(Input *input) {
	ShowConsoleCursor(true);
	activeInput = input;
	focusActiveInput();
}

Input *getActiveInput() {
	return activeInput;
}

void resetActiveInput() {
	activeInput = nullptr;
}


void addToInput(Input *input, string text) {
	if (!input->text.empty() && input->text.size() + text.size() > input->length) { return; }
	setGuiColor(input->foregroundColor, input->backgroundColor);
	focusInput(input);
	input->text += text;
	if (input->inputType == INPUT_TYPE_TEXT) {
		cout << input->text.back();
	} else if (input->inputType == INPUT_TYPE_PASSWORD) {
		cout << "*";
	}
}


void addToActiveInput(string text) {
	if (getActiveInput() == nullptr) { return; }
	addToInput(getActiveInput(), text);
}

void clearLastFromInput(Input *input) {
	if (input == nullptr) { return; }
	if (!input->text.empty() && input->text.length() > 0) {
		setGuiColor(input->foregroundColor, input->backgroundColor);
		focusInput(input);
		cout << '\b' << ' ' << '\b';
		input->text.pop_back();
	}

}

void clearLastFromActiveInput() {
	clearLastFromInput(getActiveInput());
}

Input *getNextInput(Input *input) {
	return getNextNode(input, &inputList);
}

void destroyInputs() {
	NodeWrapper<Input>* inputWrapper = nullptr;
	while(getNextNode(&inputWrapper, getInputList())) {
		delete inputWrapper->value;
	}

	destroyList(&inputList);
	activeInput = nullptr;
}

void initialiseInputs() {
	NodeWrapper<Input> *inputWrapper = nullptr;
	List<Input> *inputList = getInputList();
	while (getNextNode(&inputWrapper, inputList)) {
		setDefaultLengthOfGuiElement(inputWrapper->value);
	}
	if (inputList->head != nullptr) {
		setActiveInput(inputList->head->value);
	}
}




