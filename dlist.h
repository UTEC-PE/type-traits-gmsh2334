#ifndef DLIST_H
#define DLIST_H

#include "iterator.h"

template <typename T>
class DListIterator : public Iterator<T> {     
    public: 
        DListIterator() : Iterator<T>() {};
        DListIterator(Node<T> *current) : Iterator<T>(current) {};
        DListIterator<T> operator++(){
            if (current)
            {
                this->current = this->current -> next;
                return *this;
            }
        };
        DListIterator<T> operator--(){
            if (current)
            {
                this->current = this->current -> prev;
                return *this;
            }
        };
};

template <typename Tr>
class DList {     
    public:
        typedef typename Tr::T T;
        typedef DListIterator<T> iterator;
      
    private:
        Node<T>* head;
        Node<T>* tail;
        int nodes;
              
    public:
        DList() {
            head = tail = nullptr;
            nodes = 0;
        };

        void push_front(T value) {
            Node<T>* temp = new Node<T>(value);
            if(nodes==0){
                head=tail=temp;
            }else{
                temp -> next = head;
                head -> prev = temp;
                head = temp;
            }
            nodes++;
        }

        void push_back(T value) {
            Node<T>* temp = new Node<T>(value);
            temp->data=value;
            if(tail->next == nullptr){
                tail->next=temp;
            }
            nodes++;
        }
             
        void pop_front() {
            Node<T>* temp= head;
            temp->next=head->next;
            head = temp->next;
            delete temp;
            nodes--;
        }
             
        void pop_back() {
            Node<T>* temp = tail;
            temp -> prev = tail -> prev;
            tail = temp -> prev;
            delete temp;
            nodes--;
        }
             
        iterator begin() {
            return iterator(head);
        }
             
        iterator end() {
            return iterator(tail);
        }
             
        ~DList() {
            if (head) {
                head->killSelf();
            } 
        }         
};

#endif