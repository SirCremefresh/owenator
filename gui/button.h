//
// Created by Donato Wolfisberg on 22.11.2017.
//

#ifndef button_H
#define button_H

#include <string>


typedef struct button_struct Button;
struct button_struct {
	short x;
	short y;
	std::string text;
};

#endif //button_H
