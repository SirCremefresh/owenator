//
// Created by Donato Wolfisberg on 12.12.2017.
//

#ifndef GUIV2_INPUT_H
#define GUIV2_INPUT_H


#include "../guiElementStruct.h"
#include "../../../list/list.h"

using namespace std;

struct Input : GuiElement {
	Input() = default;

	Input(short padding) : GuiElement(padding) {}
};

void addInput(Input *input);

List<Input> *getInputList();

void setActiveInput(Input *input);

void resetActiveInput();

Input *getActiveInput();

void addToInput(Input *input, string text);

void addToActiveInput(string text);

void clearLastFromInput(Input *input);

void clearLastFromActiveInput();

Input *getNextInput(Input *input);

void destroyInputs();

void initialiseInputs();

#endif //GUIV2_INPUT_H
