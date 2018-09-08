#ifndef SLIST_H
#define SLIST_H

#include "iterator.h"
#include <iostream>
using namespace std;
template <class T>
class SListIterator : public Iterator<T> {
public:
    SListIterator() : Iterator<T>() {};

    explicit SListIterator(Node<T> *current) : Iterator<T>(current) {};

    SListIterator<T> operator++() {
        if (current) {
            this->current = this->current->next;
            return *this;
        };
    }
};

template <typename Tr>
class SList {     
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
        typedef SListIterator<T> iterator;
      
    private:
        Node<T>* head;
        Operation cmp;
              
    public:
        SList() {
            head = nullptr;
        };

        bool find(T search, Node<T> **&pointer) {
            pointer=&head;
            while(*pointer){
                if(cmp(search,(*pointer)->data)){
                    break;
                }
                pointer=&((*pointer)->next);
            }
            if(!(*pointer)){
                return false;
            }
            else return (*pointer)->data == search;
        }

        bool insert(T data) {
            Node<T> **pointer = &head;
            Node <T>* n = new Node<T>(data);
            if(head == nullptr){
                head = n;
                head->next= nullptr;

                return true;
            }else if(find(data, pointer)) {
                return false;
            } else {
                Node<T> *pointer_2 = new Node<T>(data);
                pointer_2->next = (*pointer);
                *pointer = pointer_2;
                return true;
            }
        }

        bool remove(T item) {
            Node<T> **pointer = &head;
            Node <T>* n = new Node<T>(item);
            if(head == nullptr){
                return true;
            }else if (find(item, pointer)) {
                Node<T> *tmp = (*pointer);
                (*pointer) = (*pointer)->next;
                delete tmp;
                return true;
            }
            return false;
        }

        iterator begin() {
            return iterator(head);
        }

        iterator end() {
            Node<T>* temp =head;
            while (temp){
                temp = temp->next;
            }
            return iterator(temp);
        }
             
        ~SList() {
            if (head) {
                head->killSelf();
            } 
        }         
};

#endif