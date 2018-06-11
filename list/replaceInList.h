//
// Created by Donato Wolfisberg on 14.12.2017.
//

#ifndef LIST_REPLACEINLIST_H
#define LIST_REPLACEINLIST_H


template<typename T, typename = std::enable_if<std::is_base_of<Node, T>::value>>
T *replaceNode(T *newNode, unsigned long index, List<T> *list) {
	if (index >= list->length) {
		return nullptr;
	}

	NodeWrapper<T> *nodeWrapper = list->head;
	unsigned long counter = 0;

	while (nodeWrapper != nullptr) {
		if (index == counter) {
			T *oldNode = nodeWrapper->value;
			nodeWrapper->value = newNode;
			return oldNode;
		}
		counter++;
		nodeWrapper = nodeWrapper->next;
	}

	return nullptr;
}

template<typename T, typename = std::enable_if<std::is_base_of<Node, T>::value>>
void switchNodes(unsigned long index1, unsigned long index2, List<T> *list) {
	replaceNode(replaceNode(getNodeByIndex(index1, list), index2, list), index1, list);
}

#endif //LIST_REPLACEINLIST_H
