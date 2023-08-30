#pragma once
#include <iostream>
using std::cout;
using std::endl;

template<typename T>

class OneNode{
public:
    T info;
    OneNode<int>* next;
    
    OneNode(T value){
        info = value;
        next = nullptr;
    }
    
    void show(){
        cout << "Info : " << info << endl;
        cout << "Next : " << next << endl;
    }
};

template <typename U>

class OneLinkedList{
private:
    OneNode<U>* head;
    OneNode<U>* current;
    
public:
    OneLinkedList(){
        head = nullptr;
        current = nullptr;
    }
    ~OneLinkedList(){
        OneNode<U>* tmp = head;
        while(tmp != nullptr){
            OneNode<U>* prev = tmp;
            tmp = tmp->next;
            cout << "Delete: ";
            cout << prev->info << " (" << prev->next << ")\n";
            delete prev;
        }
        
        
    }
    void add(U value){
        OneNode<U>* element = new OneNode<U>(value);
        
        if(head == nullptr){
            head = element;
            current = element;
        }else{
            current->next = element;
            current = element;
        }
    }
    void show()const{
        OneNode<U>* tmp = head;
        cout << "OneLinkedList : ";
        while(tmp != nullptr){
            cout << tmp->info << " ";
            tmp = tmp->next;
        }
    }
    void showList()const{
        OneNode<U>* tmp = head;
        cout << "OneLinkedList : \n";
        while(tmp != nullptr){
            tmp->show();
            tmp = tmp->next;
        }
    }
};

