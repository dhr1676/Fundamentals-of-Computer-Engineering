//
// Created by DING on 2018/2/19.
//

//#include <mmcobj.h>
#include "DoublyLinkedList.h"

DoublyLinkedList::Node::Node(Object* data) {
    this->m_data = data;
    this->m_next = NULL;
    this->m_prev = NULL;
}

DoublyLinkedList::DoublyLinkedList() {
    m_head = NULL;
    current = NULL;
    m_tail = NULL;
    m_size = 0;
}

DoublyLinkedList::~DoublyLinkedList() {
    if (!isEmpty()) {
        Node * i = m_head;
        while (true) {
            i = i->m_next;
            if (i != NULL) {
                delete i->m_prev;
                i->m_prev = NULL;
            } else {
                delete m_tail;
                m_tail = m_head = NULL;
                break;
            }
        }
        m_size = 0;
    }
}

bool DoublyLinkedList::isEmpty() {
    return !m_size;
}

void DoublyLinkedList::ClearList() {
    this->~DoublyLinkedList();
}

void DoublyLinkedList::Head() {
    current = m_head;
}

void DoublyLinkedList::Tail() {
    current = m_tail;
}

void DoublyLinkedList::Next() {
    if (!current)
        return;
    current = current->m_next;
}

void DoublyLinkedList::Prev() {
    if (current == m_head)
        return;
    current = current->m_prev;
}

Object* DoublyLinkedList::GetCurrent() {
    if (!current)
        return NULL;
    return current->m_data;
}

void DoublyLinkedList::push_front(Object *x) {
    if (m_head == NULL) {
        m_head = new Node(x);
        m_tail = m_head;
        current = m_head;
        std::cout << "Push front when NULL!" << std::endl;
    } else {
        Node * temp = new Node(x);
        temp->m_next = m_head;
        m_head->m_prev = temp;
        m_head = temp;
        current = m_head;
    }
    m_size++;
}

void DoublyLinkedList::push_back(Object *x) {
    if (m_head == NULL) {
        m_head = new Node(x);
        m_tail = m_head;
        current = m_tail;
    } else {
        Node* temp = new Node(x);
        m_tail->m_next = temp;
        temp->m_prev = m_tail;
        m_tail = temp;
        current = m_tail;
    }
    m_size++;
}

void DoublyLinkedList::pop_front() {
    if (!this->isEmpty()) {
        m_head = m_head->m_next;
        m_head->m_prev = NULL;
        current = current->m_next;
        m_size--;
    } else{
        std::cout << "The list is empty!" << std::endl;
    }
}
void DoublyLinkedList::pop_back() {
    if (!this->isEmpty()) {
        m_tail = m_tail->m_prev;
        m_tail->m_next = NULL;
        current = current->m_prev;
        m_size--;
    } else{
        std::cout << "The list is empty!" << std::endl;
    }
}

void DoublyLinkedList::Insert(Object *x) {
    if (current == NULL) {
        Node *temp = new Node(x);
        m_head = temp;
        m_tail = temp;
        current = temp;
    } else {
        if (current->m_next == NULL) {
            Node *temp = new Node(x);
            current->m_next = temp;
            temp->m_prev = current;
            current = temp;
            m_tail = temp;
        } else {
            Node *temp = new Node(x);
            temp->m_next = current->m_next;
            temp->m_prev = current;
            current->m_next->m_prev = temp;
            current->m_next = temp;
            current = temp;
        }
    }
    m_size++;
}

void DoublyLinkedList::Remove() {
    if (current != NULL) {
        if (m_head == current) {
            pop_front();
            return;
        }
        if (m_tail == current) {
            pop_back();
            return;
        }
        current->m_next->m_prev = current->m_prev;
        current->m_prev->m_next = current->m_next;
        current = current->m_next;
    }
}

void DoublyLinkedList::Print() {
    Node * temp;
//    std::cout << "Output from the head: " << std::endl;
    for(temp = m_head; temp; temp = temp->m_next)
        temp->m_data->Print();
//    std::cout << "\nOutput from the tail: " << std:: endl;
//    for(temp = m_tail; temp; temp = temp->m_prev)
//        temp->m_data->Print();
}