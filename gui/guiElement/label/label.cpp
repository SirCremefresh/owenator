//
// Created by Donato Wolfisberg on 13.12.2017.
//

#include "label.h"
#include "../../../list/list.h"
#include "../guiElement.h"

List<Label> labelList;


void addLabel(Label *label) {
	addNode(label, &labelList);
}

List<Label> *getLabelList() {
	return &labelList;
}

void destroyLabels() {
	NodeWrapper<Label>* labelWrapper = nullptr;
	while(getNextNode(&labelWrapper, getLabelList())) {
		delete labelWrapper->value;
	}

	destroyList(&labelList);
}

void InitialiseLabels() {
	NodeWrapper<Label> *labelWrapper = nullptr;
	List<Label> *labelList = getLabelList();
	while (getNextNode(&labelWrapper, labelList)) {
		setDefaultLengthOfGuiElement(labelWrapper->value);
	}
}
