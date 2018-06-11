//
// Created by Donato Wolfisberg on 14.12.2017.
//

#ifndef LIST_ADDTOLIST_H
#define LIST_ADDTOLIST_H


template<typename T, typename = std::enable_if<std::is_base_of<Node, T>::value>>
NodeWrapper<T> *addNode(T *newNode, List<T> *list) {
	list->length++;
	auto *nodeWrapper = new NodeWrapper<T>;
	nodeWrapper->value = newNode;
	if (newNode != nullptr) {
		nodeWrapper->value->id = list->idCounter++;
	}
	if (list->head == nullptr) {
		list->head = nodeWrapper;
		list->tail = nodeWrapper;
	} else {
		nodeWrapper->previous = list->tail;
		list->tail->next = nodeWrapper;
		list->tail = nodeWrapper;
	}
	return nodeWrapper;
};

template<typename T, typename = std::enable_if<std::is_base_of<Node, T>::value>>
NodeWrapper<T> *addNodeInternal(T *newNode, List<T> *list) {
	auto *nodeWrapper = new NodeWrapper<T>;
	nodeWrapper->value = newNode;
	if (list->head == nullptr) {
		list->head = nodeWrapper;
		list->tail = nodeWrapper;
	} else {
		nodeWrapper->previous = list->tail;
		list->tail->next = nodeWrapper;
		list->tail = nodeWrapper;
	}
	return nodeWrapper;
};

#endif //LIST_ADDTOLIST_H
