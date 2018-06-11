//
// Created by dw on 21.11.2017.
//

#ifndef OWENATOR_LIST_H
#define OWENATOR_LIST_H

#include <type_traits>



template<typename T>
struct node_struct {
    node_struct() {}
    explicit node_struct(long id) : id(id) {}

    long int id;
    T* next = nullptr;
    T* previous = nullptr;
};


template<typename T, typename = std::enable_if<std::is_base_of<struct node_struct<T>, T>::value>>
void addNode(T **newNode, T **head, T **tail) {
    if(*head == nullptr) {
        *head = *newNode;
        *tail = *newNode;
    } else {
        (**newNode).previous = *tail;
        (**tail).next = *newNode;
        *tail = *newNode;
    }
}


template<typename T, typename = std::enable_if<std::is_base_of<struct node_struct<T>, T>::value>>
T* deleteNode(long int id, T **head, T **tail) {
    T* node = *head;

    while (node != nullptr) {
        if (node->id == id) {
            if (node == *head && node == *tail) {
                *head = nullptr;
                *tail = nullptr;
            } else if(node == *head) {
                *head = node->next;
                node->next->previous = nullptr;
            } else if(node == *tail) {
                *tail = node->previous;
                node->previous->next = nullptr;
            } else {
                node->previous->next = node->next;
                node->next->previous = node->previous;
            }
            node->previous = nullptr;
            node->next = nullptr;

            return node;
        }
        node = node->next;
    }
}


template<typename T, typename = std::enable_if<std::is_base_of<struct node_struct<T>, T>::value>>
T* getNode(long int id, T *head, T *tail) {
    T* node = head;

    while (node != nullptr) {
        if (node->id == id) {
            return node;
        }
        node = node->next;
    }
    return nullptr;
}

template<typename T, typename = std::enable_if<std::is_base_of<struct node_struct<T>, T>::value>>
bool getNextNode(T **node, T *head, T *tail, bool backwards = false) {
    if(head == nullptr) {
        return false;
    }
    if(*node == nullptr) {
        if (!backwards) {
            *node = head;
        } else {
            *node = tail;
        }
        return true;
    }

    if (!backwards) {
        if((**node).next != nullptr) {
            *node = (**node).next;
            return true;
        }
    } else {
        if((**node).previous != nullptr) {
            *node = (**node).previous;
            return true;
        }
    }

    return false;
}


#endif //OWENATOR_LIST_H
