//
// Created by Donato Wolfisberg on 12.12.2017.
//

#include "button.h"
#include "../../../list/list.h"
#include "../guiElement.h"

List<Button> buttonList;

void addButton(Button *btn) {
	addNode(btn, &buttonList);
}

List<Button> *getButtonList() {
	return &buttonList;
}

void destroyButtons() {
	NodeWrapper<Button>* buttonWrapper = nullptr;
	while(getNextNode(&buttonWrapper, getButtonList())) {
		delete buttonWrapper->value;
	}

	destroyList(&buttonList);
}

void initialiseButtons() {
	NodeWrapper<Button> *buttonWrapper = nullptr;
	List<Button> *buttonList = getButtonList();
	while (getNextNode(&buttonWrapper, buttonList)) {
		setDefaultLengthOfGuiElement(buttonWrapper->value);
	}
}

