//
// Created by Donato Wolfisberg on 12.12.2017.
//

#ifndef GUIV2_BUTTON_H
#define GUIV2_BUTTON_H

#include <string>
#include <functional>
#include "../guiElementStruct.h"

using namespace std;


struct Button : GuiElement {
	Button() = default;

	Button(short padding) : GuiElement(padding) {}

	function<bool(Button *button)> onClick = nullptr;
};

void addButton(Button *btn);

List<Button> *getButtonList();

void destroyButtons();

void initialiseButtons();

#endif //GUIV2_BUTTON_H
