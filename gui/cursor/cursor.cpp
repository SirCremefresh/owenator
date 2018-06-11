//
// Created by Donato Wolfisberg on 12.12.2017.
//

#include <iostream>
#include "cursor.h"

void ShowConsoleCursor(bool show) {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cursorInfo{};

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = show; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

void moveCursor(short x, short y) {
	COORD pos = {x, y};
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

void focusInput(Input *input) {
	if (input != nullptr) {
		short textLength = 0;
		if (!input->text.empty() && input->text.length() > 0) {
			textLength = static_cast<short>(input->text.length());
			moveCursor(static_cast<short>(input->X + textLength - 1), input->Y);
			setGuiColor(input->foregroundColor, input->backgroundColor);
			if (input->inputType == INPUT_TYPE_TEXT) {
				cout << input->text.back();
			} else if (input->inputType == INPUT_TYPE_PASSWORD) {
				cout << "*";
			}
		} else {
			moveCursor(static_cast<short>(input->X), input->Y);
		}
	}
}

void focusActiveInput() {
	Input *activeInput = getActiveInput();
	focusInput(activeInput);
}

