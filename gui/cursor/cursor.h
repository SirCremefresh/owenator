//
// Created by Donato Wolfisberg on 12.12.2017.
//

#ifndef GUIV2_CURSOR_H
#define GUIV2_CURSOR_H

using namespace std;

#include "windows.h"
#include "../guiElement/guiElement.h"

void ShowConsoleCursor(bool show);

void moveCursor(short x, short y);

void focusActiveInput();

void focusInput(Input *input);

#endif //GUIV2_CURSOR_H
