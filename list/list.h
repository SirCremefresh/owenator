//
// Created by Donato Wolfisberg on 08.12.2017.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

using namespace std;

#include <type_traits>
#include <functional>

#include "listStructs.h"
#include "addToList.h"
#include "deleteFromList.h"
#include "getFromList.h"
#include "replaceInList.h"
#include "sortList.h"
#include "getNextFromList.h"


template<typename T, typename = std::enable_if<std::is_base_of<Node, T>::value>>
void destroyList(List<T> *list) {
	if (list->head == nullptr) {
		return;
	}

	NodeWrapper<T> *nodeWrapper = list->head;
	while (nodeWrapper->next != nullptr) {
		nodeWrapper = nodeWrapper->next;
		delete nodeWrapper->previous;
	}
	delete nodeWrapper;

	list->head = nullptr;
	list->tail = nullptr;
	list->length = 0;
}

#endif //LIST_LIST_H
