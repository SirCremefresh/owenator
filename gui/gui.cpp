#include <windows.h>
#include <stdio.h>
#include <string>
#include <iostream>

#include "gui.h"
#include "button.h"

using namespace std;

Button* buttons;

void moveCursor(short x, short y) {
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

void addButton(Button newButtons[]) {
	int sizeofbuttons = sizeof(newButtons);
	int sizeofbutton = sizeof(newButtons[0]);

	for (unsigned int i = 0; i <  sizeofbuttons / sizeofbutton; i++) {
		setText(newButtons[i].x, newButtons[i].y, newButtons[i].text);
	}
	buttons = newButtons;
}

void setText(short x, short y, string text) {
	moveCursor(x, y);
	cout << text;
}

/*
HANDLE hStdin;
DWORD fdwSaveOldMode;

VOID MouseEventProc(MOUSE_EVENT_RECORD);
VOID ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD);

DWORD fdwMode;

void clearConsole() {
	SetConsoleMode(hStdin, fdwSaveOldMode);
	system("cls");
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	if (hStdin == INVALID_HANDLE_VALUE)
		std::cout << "GetStdHandle";

	// Save the current input mode, to be restored on exit.

	if (!GetConsoleMode(hStdin, &fdwSaveOldMode))
		std::cout << "GetConsoleMode";


	// Enable the window and mouse input events.

	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(hStdin, fdwMode))
		std::cout << "SetConsoleMode";
}

int main()
{

	DWORD cNumRead, i;
	INPUT_RECORD irInBuf[128];

	// Get the standard input handle.
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	if (hStdin == INVALID_HANDLE_VALUE)
		std::cout << "GetStdHandle";

	// Save the current input mode, to be restored on exit.
	if (!GetConsoleMode(hStdin, &fdwSaveOldMode))
		std::cout << "GetConsoleMode";


	// Enable the window and mouse input events.
	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(hStdin, fdwMode))
		std::cout << "SetConsoleMode";


	// Loop to read and handle the next 100 input events.
	while (1)
	{
		// Wait for the events.

		if (!ReadConsoleInput(
			hStdin,      // input buffer handle
			irInBuf,     // buffer to read into
			128,         // size of read buffer
			&cNumRead)) // number of records read
			std::cout << "ReadConsoleInput";


		// Dispatch the events to the appropriate handler.

		for (i = 0; i < cNumRead; i++)
		{
			switch (irInBuf[i].EventType)
			{

			case MOUSE_EVENT: // mouse input

				MouseEventProc(irInBuf[i].Event.MouseEvent);
				break;

			case WINDOW_BUFFER_SIZE_EVENT: // scrn buf. resizing
				ResizeEventProc(irInBuf[i].Event.WindowBufferSizeEvent);
				break;
			}
		}
	}

	// Restore input mode on exit.

	SetConsoleMode(hStdin, fdwSaveOldMode);

	return 0;
}



VOID MouseEventProc(MOUSE_EVENT_RECORD mer)
{


	switch (mer.dwEventFlags)
	{
	case 0:
		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{

			clearConsole();

			printf("left button press \n");
			std::cout << "X: " << mer.dwMousePosition.X << " \n";
			std::cout << "Y: " << mer.dwMousePosition.Y << " \n";

		}
		else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
		{
			clearConsole();
			printf("right button press \n");

			std::cout << "X: " << mer.dwMousePosition.X << " \n";
			std::cout << "Y: " << mer.dwMousePosition.Y << " \n";
		}
		break;
	case DOUBLE_CLICK:
		clearConsole();

		printf("double click\n");

		std::cout << "X: " << mer.dwMousePosition.X << " \n";
		std::cout << "Y: " << mer.dwMousePosition.Y << " \n";
		break;
	default:
		break;
	}
}

VOID ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD wbsr)
{
	printf("Resize event\n");
	printf("Console screen buffer is %d columns by %d rows.\n", wbsr.dwSize.X, wbsr.dwSize.Y);
}
*/