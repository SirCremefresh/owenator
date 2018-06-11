//
// Created by Donato Wolfisberg on 15.12.2017.
//

#ifndef GUIV2_GUIELEMENTINITIALISER_H
#define GUIV2_GUIELEMENTINITIALISER_H

template<typename T, typename = std::enable_if<std::is_base_of<GuiElement, T>::value>>
void setDefaultLengthOfGuiElement(T *guiElement) {
	if (guiElement->length == -1) {
		if (guiElement->text.empty() || guiElement->text.length() <= 0) {
			guiElement->length = 0;
		} else {
			guiElement->length = guiElement->text.size();
		}
	}
}

#endif //GUIV2_GUIELEMENTINITIALISER_H
