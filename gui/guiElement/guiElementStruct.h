//
// Created by Donato Wolfisberg on 14.12.2017.
//

#ifndef GUIV2_GUIELEMENTSTRUCT_H
#define GUIV2_GUIELEMENTSTRUCT_H

#include <string>
#include "../../list/listStructs.h"
#include "../color/color.h"

enum INPUT_TYPE {
	INPUT_TYPE_TEXT, INPUT_TYPE_PASSWORD
};

struct GuiElement : Node {
	GuiElement() = default;

	GuiElement(short padding) {
		paddingTop = padding;
		paddingBottom = padding;
		paddingRight = padding;
		paddingLeft = padding;
	};
	short paddingTop = 0;
	short paddingBottom = 0;
	short paddingRight = 0;
	short paddingLeft = 0;

	short X;
	short Y;
	string text;
	short length = -1;
	INPUT_TYPE inputType = INPUT_TYPE_TEXT;
	GUI_COLOR backgroundColor = getDefaultBackgroundColor();
	GUI_COLOR foregroundColor = getDefaultForegroundColor();
};


#endif //GUIV2_GUIELEMENTSTRUCT_H
