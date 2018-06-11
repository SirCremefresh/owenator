//
// Created by Donato Wolfisberg on 12.12.2017.
//

#ifndef GUIV2_CLICKHANDLER_H
#define GUIV2_CLICKHANDLER_H

using namespace std;

#include "../../guiElement/guiElement.h"

Button *buttonClickHandler(MOUSE_EVENT_RECORD mouseEvent);

Input *inputClickHandler(MOUSE_EVENT_RECORD mouseEvent);

Label *labelClickHandler(MOUSE_EVENT_RECORD mouseEvent);

#endif //GUIV2_CLICKHANDLER_H
