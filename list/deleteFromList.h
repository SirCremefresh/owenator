//
// Created by Donato Wolfisberg on 14.12.2017.
//

#ifndef LIST_DELETEFROMLIST_H
#define LIST_DELETEFROMLIST_H

template<typename T, typename = std::enable_if<std::is_base_of<Node, T>::value>>
T *deleteNodeWrapper(NodeWrapper<T> *nodeWrapper, List<T> *list) {
	if (nodeWrapper == nullptr) {
		return nullptr;
	}


	if (nodeWrapper == list->head && nodeWrapper == list->tail) {
		list->head = nullptr;
		list->tail = nullptr;
	} else if (nodeWrapper == list->head) {
		list->head = nodeWrapper->next;
		nodeWrapper->next->previous = nullptr;
	} else if (nodeWrapper == list->tail) {
		list->tail = nodeWrapper->previous;
		nodeWrapper->previous->next = nullptr;
	} else {
		nodeWrapper->previous->next = nodeWrapper->next;
		nodeWrapper->next->previous = nodeWrapper->previous;
	}


	T *node = nodeWrapper->value;
	delete nodeWrapper;
	list->length--;
	return node;
};


template<typename T, typename = std::enable_if<std::is_base_of<Node, T>::value>>
T *deleteNodeByIndex(unsigned long index, List<T> *list) {
	if (index >= list->length || index < 0) {
		return nullptr;
	}

	unsigned long counter = 0;
	NodeWrapper<T> *nodeWrapper = list->head;

	while (nodeWrapper != nullptr) {
		if (index == counter) {
			return deleteNodeWrapper(nodeWrapper, list);
		}
		counter++;
		nodeWrapper = nodeWrapper->next;
	}

	return nullptr;
};

template<typename T, typename = std::enable_if<std::is_base_of<Node, T>::value>>
T *deleteNodeById(unsigned long id, List<T> *list) {

	NodeWrapper<T> *nodeWrapper = list->head;

	while (nodeWrapper != nullptr) {
		if (nodeWrapper->value->id == id) {
			return deleteNodeWrapper(nodeWrapper, list);
		}
		nodeWrapper = nodeWrapper->next;
	}

	return nullptr;
};

template<typename T, typename = std::enable_if<std::is_base_of<Node, T>::value>>
T *deleteNode(T *node, List<T> *list) {
	NodeWrapper<T> *nodeWrapper = list->head;

	while (nodeWrapper != nullptr) {
		if (nodeWrapper->value == node) {
			return deleteNodeWrapper(nodeWrapper, list);
		};

		nodeWrapper = nodeWrapper->next;
	}

	return nullptr;
};

#endif //LIST_DELETEFROMLIST_H
