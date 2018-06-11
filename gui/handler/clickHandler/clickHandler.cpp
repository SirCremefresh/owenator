//
// Created by Donato Wolfisberg on 12.12.2017.
//

#include "clickHandler.h"
#include "../../cursor/cursor.h"
#include "../../../list/getNextFromList.h"


template<typename T, typename = std::enable_if<std::is_base_of<GuiElement, T>::value>>
bool isInArea(T guiElement, short X, short Y) {
	if (Y > guiElement->Y - guiElement->paddingTop - 1 && Y < guiElement->Y + guiElement->paddingBottom + 1) {
		if (X > guiElement->X - guiElement->paddingLeft - 1 &&
		    X < guiElement->X + guiElement->length + guiElement->paddingRight) {
			return true;
		}
	}
	return false;
}


Button *buttonClickHandler(MOUSE_EVENT_RECORD mouseEvent) {
	short mouseEventX = mouseEvent.dwMousePosition.X;
	short mouseEventY = mouseEvent.dwMousePosition.Y;

	NodeWrapper<Button> *buttonWrapper = nullptr;
	List<Button> *buttonList = getButtonList();
	Button *button;
	while (getNextNode(&buttonWrapper, buttonList)) {
		button = buttonWrapper->value;
		if (isInArea(button, mouseEventX, mouseEventY)) {
			ShowConsoleCursor(false);
			if (button->onClick != nullptr && button->onClick(button)) {
				return button;
			}
		}
	}
	return nullptr;
}

Input *inputClickHandler(MOUSE_EVENT_RECORD mouseEvent) {
	short mouseEventX = mouseEvent.dwMousePosition.X;
	short mouseEventY = mouseEvent.dwMousePosition.Y;

	NodeWrapper<Input> *inputWrapper = nullptr;
	List<Input> *inputList = getInputList();
	Input *input;
	while (getNextNode(&inputWrapper, inputList)) {
		input = inputWrapper->value;
		if (isInArea(input, mouseEventX, mouseEventY)) {
			setActiveInput(input);
			return input;
		}
	}
	return nullptr;
}

Label *labelClickHandler(MOUSE_EVENT_RECORD mouseEvent) {
	short mouseEventX = mouseEvent.dwMousePosition.X;
	short mouseEventY = mouseEvent.dwMousePosition.Y;

	NodeWrapper<Label> *labelWrapper = nullptr;
	List<Label> *labelList = getLabelList();
	Label *label;
	while (getNextNode(&labelWrapper, labelList)) {
		label = labelWrapper->value;
		if (label->forInput != nullptr) {
			if (isInArea(label, mouseEventX, mouseEventY)) {
				setActiveInput(label->forInput);
				return label;
			}
		}
	}
	return nullptr;
}
