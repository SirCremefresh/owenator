//
// Created by Donato Wolfisberg on 14.12.2017.
//

#ifndef LIST_GETFROMLIST_H
#define LIST_GETFROMLIST_H


template<typename T, typename = std::enable_if<std::is_base_of<Node, T>::value>>
T *getNodeByIndex(unsigned long index, List<T> *list) {
	if (index >= list->length || index < 0) {
		return nullptr;
	}

	unsigned long counter = 0;
	NodeWrapper<T> *nodeWrapper = list->head;

	while (nodeWrapper != nullptr) {
		if (index == counter) {
			return nodeWrapper->value;
		}
		counter++;
		nodeWrapper = nodeWrapper->next;
	}

	return nullptr;
};

template<typename T, typename = std::enable_if<std::is_base_of<Node, T>::value>>
T *getNodeById(unsigned long id, List<T> *list) {
	NodeWrapper<T> *nodeWrapper = list->head;

	while (nodeWrapper != nullptr) {
		if (id == nodeWrapper->value->id) {
			return nodeWrapper->value;
		}
		nodeWrapper = nodeWrapper->next;
	}

	return nullptr;
};

template<typename T, typename = std::enable_if<std::is_base_of<Node, T>::value>>
unsigned long getIndexOfNode(T *node, List<T> *list) {

	unsigned long counter = 0;
	NodeWrapper<T> *nodeWrapper = list->head;

	while (nodeWrapper != nullptr) {
		if (nodeWrapper->value == node) {
			return counter;
		}
		counter++;
		nodeWrapper = nodeWrapper->next;
	}

	return list->length;
};

#endif //LIST_GETFROMLIST_H
