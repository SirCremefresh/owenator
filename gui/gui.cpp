//
// Created by Donato Wolfisberg on 12.12.2017.
//

#include <windows.h>
#include <iostream>
#include "gui.h"
#include "cursor/cursor.h"
#include "render/render.h"
#include "handler/clickHandler/clickHandler.h"
#include "handler/keyHandler/keyHandler.h"


Button *showGui() {
	system("cls");

	InitialiseLabels();
	initialiseInputs();
	initialiseButtons();

	renderLabels();
	renderButtons();
	renderInputs();

	focusActiveInput();


	bool stopLoop = false;
	Button *returnButton = nullptr;
	DWORD oldConsoleMode, newConsoleMode, numberOfReadInputEvents;

	HANDLE stdInputHandle;
	INPUT_RECORD InputEventsBuffer[128];



	// Get the standard input handle.
	stdInputHandle = GetStdHandle(STD_INPUT_HANDLE);
	if (stdInputHandle == INVALID_HANDLE_VALUE)
		std::cout << "Failed to get the standart Input handle";

	// Save the current input mode, to be restored on exit.
	if (!GetConsoleMode(stdInputHandle, &oldConsoleMode))
		std::cout << "Failed to save Console Mode";


	// Enable the window and mouse input events. and disable einfügemodus und quickedit modus
	newConsoleMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(stdInputHandle, newConsoleMode))
		std::cout << "Failed to enable keyboard and Mouse Event";


	// Loop to read and handle the next 100 input events.
	while (true) {
		// Wait for the events.

		if (!ReadConsoleInput(
				stdInputHandle,      // input buffer handle
				InputEventsBuffer,     // buffer to read into
				128,         // size of read buffer
				&numberOfReadInputEvents)) // number of records read
			std::cout << "ReadConsoleInput";


		// Dispatch the events to the appropriate handler.
		for (short i = 0; i < numberOfReadInputEvents; i++) {
			switch (InputEventsBuffer[i].EventType) {
				case KEY_EVENT: // keyboard input
					// beim runter drücken das nicht zweimal geschrieben wird

					if (InputEventsBuffer[i].Event.KeyEvent.bKeyDown) {
						keyHandler(InputEventsBuffer[i].Event.KeyEvent);
//						cout << InputEventsBuffer[i].Event.KeyEvent.uChar.AsciiChar;
					}
					break;

				case MOUSE_EVENT: // mouse input
					if (InputEventsBuffer[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
						// beim runter drücken das nicht zweimal geschrieben wird
						if (InputEventsBuffer[i].Event.MouseEvent.dwEventFlags == 0) {
							Button *button = buttonClickHandler(InputEventsBuffer[i].Event.MouseEvent);
							if (button != nullptr) {
								returnButton = button;
								stopLoop = true;
							}
							Input *input = inputClickHandler(InputEventsBuffer[i].Event.MouseEvent);
							Label *label = labelClickHandler(InputEventsBuffer[i].Event.MouseEvent);
						}
					}
					// bei rechts klick
					if (InputEventsBuffer[i].Event.MouseEvent.dwButtonState == DOUBLE_CLICK) {
						stopLoop = true;
					}
					break;
				default:
					break;
			}
			if (stopLoop) {
				break;
			}
		}
		if (stopLoop) {
			break;
		}
	}

	// Restore input mode on exit.
	SetConsoleMode(stdInputHandle, oldConsoleMode);

	return returnButton;
}

void destroyGui() {
	destroyButtons();
	destroyInputs();
	destroyLabels();
	resetGuiColor();
	system("cls");
}