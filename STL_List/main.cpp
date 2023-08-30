#include "OneLinkedList.h"
#include "TwoLinkedList.h"
#include <vector>

int main() {
    /*
    std::vector<int> array = {5, 4, 3, 2};
    OneNode<int> first(5);
    OneNode<int> second(8);
    first.next = &second;
    
    OneNode<int> third(9);
    second.next = &third;
    
    OneNode<int> fourth(10);
    third.next = &fourth;
    
    //show
    cout << "Array: ";
    for(int i = 0; i < array.size(); i++){
        cout << array[i] << " ";
    }
    
    //show2
    cout << "\n\n<INT>List: ";
    
    OneNode<int>* tmp = &first;
    while(tmp != nullptr){
        cout << tmp->info << " ";
        tmp = tmp->next;
    }
     */
    /*
    OneLinkedList<int> list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.show();
    cout << endl << endl;
    list.showList();
     */
    /*
    TwoNode<int> first(4);
    TwoNode<int> second(5);
    first.next = &second;
    second.prev = &first;
    TwoNode<int> third(6);
    second.next = &third;
    third.prev = &second;
    TwoNode<int> fourth(7);
    third.next = &fourth;
    fourth.prev = &third;
    //show1
    cout << "1 side: ";
    TwoNode<int>* tmp = &first;
    while (tmp != nullptr){
        cout << tmp->info << " ";
        tmp = tmp->next;
    }
    cout << endl;
    cout << "2 side: ";
    TwoNode<int>* tmp2 = &fourth;
    while (tmp2 != nullptr){
        cout << tmp2->info << " ";
        tmp2 = tmp2->prev;
    }
    return 0;
    */
    
    DoubleLinkedList<int> doubleList;
    doubleList.add(100);
    doubleList.add(200);
    doubleList.add(300);
    doubleList.add(400);
    //task1
    doubleList.add_on_head(500);
    //task2
    /*error fix*/doubleList.add_before_value(500, 600);
    doubleList.add_before_value(300, 250);
    //task3
    doubleList.add_after_value(300, 350);
    /*error fix*/doubleList.add_after_value(400, 450);
    doubleList.show();
    cout << endl << endl;
    //task4
    doubleList.erase(250);
    /*error fix*/doubleList.erase(600);
    /*error fix*/doubleList.erase(450);
    
    
    doubleList.showList();
    cout << endl;
    
    doubleList.show();
    cout << endl << endl;
    doubleList.showR();
    cout << endl << endl;
    
    if(doubleList.find(200) != nullptr){
        doubleList.find(200)->show();
        cout << endl;
    }else{
        cout << "There is no Node\n";
    }
}

