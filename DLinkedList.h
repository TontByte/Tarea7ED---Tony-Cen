#pragma once
#include <iostream>
#include "List.h"
#include <stdexcept>
#include "DNode.h"

using std::cout;
using std::endl;
using std::runtime_error;

template <typename E>
class DLinkedList : public List<E> {
private:
    DNode<E>* head;
    DNode<E>* tail;
    DNode<E>* current;
    int size;

public:
    DLinkedList() {
        current = head = new DNode<E>(nullptr, nullptr);
        head->next = tail = new DNode<E>(nullptr, head);
        size = 0;
    }

    ~DLinkedList() {
        clear();
        delete head;
        delete tail;
    }

    void insert(E element) {
        current->next = current->next->previous = new DNode<E>(element, current->next, current);
        size++;
    }

    void append(E element) {
        tail->previous = tail->previous->next = new DNode<E>(element, tail, tail->previous);
        size++;
    }

    E remove() {
        if (size == 0) {
            throw runtime_error("List is empty.");
        }
        if (current->next == tail) {
            throw runtime_error("No current element");
        }
        E res = current->next->element;
        current->next = current->next->next;
        delete current->next->previous;
        current->next->previous = current;
        size--;
        return res;
    }

    void setElement(E element) {
        if (size == 0) {
            throw runtime_error("List is empty.");
        }
        if (current->next == tail) {
            throw runtime_error("No current element");
        }
        current->next->element = element;
    }

    E getElement() {
        if (size == 0) {
            throw runtime_error("List is empty.");
        }
        if (current->next == tail) {
            throw runtime_error("No current element");
        }
        return current->next->element;
    }

    void clear() {
        current = head->next;
        while (head->next != tail) {
            head->next = current->next;
            delete current;
            current = head->next;
        }
        size = 0;
        current = head;
    }

    void goToStart() {
        current = head;
    }

    void goToEnd() {
        current = tail->previous;
    }

    void goToPos(int pos) {
        if (pos > size || pos < 0) {
            throw runtime_error("Invalid index.");
        }
        current = head;
        for (int i = 0; i < pos; i++) {
            current = current->next;
        }
    }

    void next() {
        if (current->next != tail) {
            current = current->next;
        }
    }
    void previous() {
        if (current->previous != head) {
            current = current->previous;
        }
    }

    bool atStart() {
        return (current == head);
    }

    bool atEnd() {
        return (current->next == tail);
    }

    int getPos() {
        DNode<E>* temp = head;
        int res = 0;
        while (temp != current) {
            temp = temp->next;
            res++;
        }
        return res;
    }

    int getSize() {
        return size;
    }

    void print() {
        cout << "[";
        DNode<E>* temp = head->next;
        for (int i = 0; i < size; i++) {
            cout << temp->element;
            if (temp->next != tail) {
                cout << ", ";
            }
            temp = temp->next;
        }
        cout << "]" << endl;
    }
};