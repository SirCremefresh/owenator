//
// Created by daPros on 21.11.420.
//

#ifndef GUI_H
#define GUI_H

#include <string>

#include "button.h"

using namespace std;

void moveCursor(short x, short y);
void addButton(Button* button);
void setText(short x, short y, string text);


#endif //GUI_H