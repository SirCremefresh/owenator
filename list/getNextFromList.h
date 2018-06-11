//
// Created by Donato Wolfisberg on 14.12.2017.
//

#ifndef LIST_GETNEXTFROMLIST_H
#define LIST_GETNEXTFROMLIST_H


template<typename T, typename = std::enable_if<std::is_base_of<Node, T>::value>>
T *getNextNode(T *node, List<T> *list) {
	unsigned long index = getIndexOfNode(node, list);
	if (index > list->length - 1) {
		return nullptr;
	}
	return getNodeByIndex(index + 1, list);
};



template<typename T, typename = std::enable_if<std::is_base_of<Node, T>::value>>
bool getNextNode(NodeWrapper<T> **nodeWrapper, List<T> *list) {
	if (list->head == nullptr) {
		return false;
	}

	if (*nodeWrapper == nullptr) {
		*nodeWrapper = list->head;
		return true;
	}

	if ((**nodeWrapper).next != nullptr) {
		*nodeWrapper = (**nodeWrapper).next;
		return true;
	}

	return false;
};

template<typename T, typename = std::enable_if<std::is_base_of<Node, T>::value>>
NodeWrapper<T> *getNextNodeFromNodeWrapper(NodeWrapper<T> *nodeWrapper, List<T> *list) {
	if (list->head == nullptr) {
		return nullptr;
	}


	if (nodeWrapper->next != nullptr) {
		return nodeWrapper->next;
	}

	return false;
};



#endif //LIST_GETNEXTFROMLIST_H
