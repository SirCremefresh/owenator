//
// Created by Donato Wolfisberg on 14.12.2017.
//

#ifndef LIST_LISTSTRUCTS_H
#define LIST_LISTSTRUCTS_H


struct Node {
	unsigned long id;
};

template<typename T, typename = std::enable_if<std::is_base_of<Node, T>::value>>
struct NodeWrapper {
	NodeWrapper<T> *next = nullptr;
	NodeWrapper<T> *previous = nullptr;
	T *value = nullptr;
};

template<typename T, typename = std::enable_if<std::is_base_of<Node, T>::value>>
struct List {
	NodeWrapper<T> *head = nullptr;
	NodeWrapper<T> *tail = nullptr;
	unsigned long idCounter = 0;
	unsigned long length = 0;
};

#endif //LIST_LISTSTRUCTS_H
