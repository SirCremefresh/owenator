//
// Created by Donato Wolfisberg on 12.12.2017.
//

#include <iostream>
#include "render.h"
#include "../cursor/cursor.h"
#include "../../list/getNextFromList.h"

template<typename T, typename = std::enable_if<std::is_base_of<GuiElement, T>::value>>
void renderGuiElement(T *guiElement) {
	setGuiColor(guiElement->foregroundColor, guiElement->backgroundColor);
	for (short i = 0; i < guiElement->paddingTop + guiElement->paddingBottom + 1; i++) {
		moveCursor(guiElement->X - guiElement->paddingLeft, guiElement->Y - guiElement->paddingTop + i);
		string text;
		text.append(static_cast<unsigned long long int>(guiElement->paddingLeft + guiElement->length +
		                                                guiElement->paddingRight), ' ');
		cout << text;
	}

	moveCursor(guiElement->X, guiElement->Y);
	if (guiElement->inputType == INPUT_TYPE_TEXT) {
		cout << guiElement->text;
	} else if (guiElement->inputType == INPUT_TYPE_PASSWORD) {
		string pwdText;
		pwdText.append(guiElement->text.length(), '*');
		cout << pwdText;
	}
}

void renderButtons() {
	NodeWrapper<Button> *buttonWrapper = nullptr;
	List<Button> *buttonList = getButtonList();
	while (getNextNode(&buttonWrapper, buttonList)) {
		renderButton(buttonWrapper->value);
	}
}

void renderButton(Button *btn) {
	renderGuiElement(btn);
}

void renderInputs() {
	NodeWrapper<Input> *inputWrapper = nullptr;
	List<Input> *inputList = getInputList();
	while (getNextNode(&inputWrapper, inputList)) {
		renderInput(inputWrapper->value);
	}
}

void renderInput(Input *input) {
	renderGuiElement(input);
}

void renderLabels() {
	NodeWrapper<Label> *labelWrapper = nullptr;
	List<Label> *labelList = getLabelList();
	while (getNextNode(&labelWrapper, labelList)) {
		renderLabel(labelWrapper->value);
	}
}

void renderLabel(Label *label) {
	renderGuiElement(label);
}



