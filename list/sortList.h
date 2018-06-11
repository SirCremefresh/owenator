//
// Created by Donato Wolfisberg on 14.12.2017.
//

#ifndef LIST_SORTLIST_H
#define LIST_SORTLIST_H


template<typename T, typename = std::enable_if<std::is_base_of<Node, T>::value>>
void sortList(function<bool(T *node1, T *node2)> sorter, List<T> *list) {

	unsigned long n = list->length;

	for (unsigned long i = 0; i < n; i++) {
		for (unsigned long j = 1; j < (n - i); j++) {

			if (sorter(getNodeByIndex(j - 1, list), getNodeByIndex(j, list))) {
				switchNodes(j - 1, j, list);
			}

		}
	}
}

template<typename T, typename = std::enable_if<std::is_base_of<Node, T>::value>>
void sortListbyId(List<T> *list, bool asc = true) {
	function<bool(T *node1, T *node2)> sorterId;
	if (asc) {
		sorterId = [](T *node1, T *node2) -> bool {
			return node1->id > node2->id;
		};
	} else {
		sorterId = [](T *node1, T *node2) -> bool {
			return node1->id < node2->id;
		};
	}
	sortList(sorterId, list);
}


#endif //LIST_SORTLIST_H
