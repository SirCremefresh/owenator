//
// Created by Donato Wolfisberg on 13.12.2017.
//

#include "keyHandler.h"
#include "../../cursor/cursor.h"


void keyHandler(KEY_EVENT_RECORD keyEvent) {
	Input *activeInput = getActiveInput();
	if (activeInput == nullptr) return;
	switch (keyEvent.uChar.UnicodeChar) {
		case 8: //Backspace
			clearLastFromActiveInput();
			break;
		case 0: // Up
			break;
		case 9: //Tab
		case 13: //Enter
		{
			Input *nextInput = getNextInput(activeInput);
			if (nextInput != nullptr) {
				setActiveInput(nextInput);
				focusActiveInput();
			}
		}
			break;
		default:
			addToActiveInput(string(1, keyEvent.uChar.AsciiChar)
			);
			break;
	}
}