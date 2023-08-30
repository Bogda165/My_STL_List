#pragma once
#include <iostream>
using std::cout;
using std::endl;

template<typename T>
class TwoNode{
public:
    T info;
    TwoNode* prev;
    TwoNode* next;
    
    TwoNode(T value){
        info = value;
        prev = nullptr;
        next = nullptr;
    }
    
    void showE()const{
        cout << "   Name : " << info << endl;
        cout << "   Prev : " << prev << endl;
        cout << "   Next : " << next << endl;
    }
    void show()const{
        cout << "(" << prev << ") " << info << " (" << next << ")\n";
    }
};

template <typename U>

class DoubleLinkedList{
private:
    TwoNode<U>* head;
    TwoNode<U>* current;
    
public:
    DoubleLinkedList(){
        head = nullptr;
        current = nullptr;
    }
    ~DoubleLinkedList(){
        TwoNode<U>* tmp = head;
        while(tmp != nullptr){
            TwoNode<U>* prev = tmp;
            tmp = tmp->next;
            cout << "Delete: ";
            cout << prev->info << " p(" << prev->prev << ")" << " n(" << prev->next << ")\n";
            delete prev;
    }
        
        
    }
    void add(U value){
        TwoNode<U>* element = new TwoNode<U>(value);
        
        if(head == nullptr){
            head = element;
            current = element;
        }else{
            current->next = element;
            element->prev = current;
            current = element;
        }
    }
    void add_on_head(U value){
        TwoNode<U>* tmp = new TwoNode<U>(value);
        tmp->next = head;
        head->prev = tmp;
        head = tmp;
    }
    void add_before_value(U value, U value2){
        TwoNode<U>* tmp = head;
        
        while(tmp != nullptr){
            if(value == tmp->info){
                
                if(tmp == head){
                    add_on_head(value2);
                }else{
                    TwoNode<U>* val = new TwoNode<U>(value2);
                    val->prev = tmp->prev;
                    val->next = tmp;
                    (tmp->prev)->next = val;
                    tmp->prev = val;
                }
                break;
            }
            tmp = tmp->next;
        }
    }
    
    void add_after_value(U value, U value2){
        TwoNode<U>* tmp = head;
        
        while(tmp != nullptr){
            if(value == tmp->info){
                if(tmp == current){
                    add(value2);
                }else{
                    TwoNode<U>* val = new TwoNode<U>(value2);
                    val->prev = tmp;
                    val->next = tmp->next;
                    (tmp->next)->prev = val;
                    tmp->next = val;
                }
                break;
            }
            tmp = tmp->next;
        }
    }
    
    void erase(U value){
        TwoNode<U>* tmp = head;
        while(tmp != nullptr){
            if(tmp->info == value){
                if(tmp == head){
                    head = tmp->next;
                    head->prev = nullptr;
                }else if(tmp == current){
                    current = tmp->prev;
                    current->next = nullptr;
                }else{
                    (tmp->prev)->next = tmp->next;
                    (tmp->next)->prev = tmp->prev;
                }
                delete tmp;
                break;
            }
            tmp = tmp->next;
        }
    }
    void showR()const{
        TwoNode<U>* tmp = current;
        cout << "TwoLinkedList : ";
        while(tmp != nullptr){
            cout << tmp->info << " ";
            tmp = tmp->prev;
        }
    }
    void show()const{
        TwoNode<U>* tmp = head;
        cout << "TwoLinkedList : ";
        while(tmp != nullptr){
            cout << tmp->info << " ";
            tmp = tmp->next;
        }
    }
    void showList()const{
        TwoNode<U>* tmp = head;
        cout << "TwoLinkedList : \n";
        int i = 1;
        while(tmp != nullptr){
            cout << "Index " << i << ":\n";
            tmp->showE();
            tmp = tmp->next;
            i++;
        }
    }
    void showListR()const{
        TwoNode<U>* tmp = current;
        cout << "TwoLinkedList : \n";
        int i = 1;
        while(tmp != nullptr){
            cout << "Index " << i << ":\n";
            tmp->showE();
            tmp = tmp->prev;
            i++;
        }
    }
    
    
    TwoNode<U>* find(U value){
        TwoNode<U>* tmp = head;
        while( tmp!= nullptr){
            if(tmp->info == value){
                return tmp;
            }
            tmp = tmp->next;
        }
        return nullptr;
    }
};



