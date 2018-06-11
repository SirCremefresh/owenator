//
// Created by Donato Wolfisberg on 13.12.2017.
//

#ifndef GUIV2_LABEL_H
#define GUIV2_LABEL_H

#include "../guiElementStruct.h"
#include "../input/input.h"

struct Label : GuiElement {
	Label() = default;

	Label(short padding) : GuiElement(padding) {}

	Input *forInput = nullptr;
};

void addLabel(Label *label);

List<Label> *getLabelList();

void destroyLabels();

void InitialiseLabels();

#endif //GUIV2_LABEL_H
