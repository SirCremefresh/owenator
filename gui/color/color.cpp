//
// Created by Donato Wolfisberg on 12.12.2017.
//

#include "color.h"

void setGuiColor(GUI_COLOR foreground, GUI_COLOR background) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, foreground | background);
}

void resetGuiColor() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, getDefaultForegroundColor() | getDefaultBackgroundColor());
}

GUI_COLOR getDefaultForegroundColor() {
	return GUI_COLOR_FOREGROUND_WHITE;
}

GUI_COLOR getDefaultBackgroundColor() {
	return GUI_COLOR_BACKGROUND_BLACK;
}
