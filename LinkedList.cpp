#include "LinkedList.h"
#include <iostream>
using std::cout;
using std::endl;
LinkedList::LinkedList() {
   head = nullptr;
   count = 0;
}

LinkedList::~LinkedList() {
    delete head;
}

bool LinkedList::Append(Node node){
    Node* currNode = head;



}
// bool LinkedList::Insert(Node node, unsigned index){
//     return false;
// }
bool LinkedList::Remove(Node node, unsigned index){
    bool ret = false;
    if(index > this->count){
        cout<<"You tried to remove an index which was greater than the length of the linkedlist"<<endl;
    }
    else if (index < 0){
        cout<<"You tried to remove an index less than 0"<<endl;
    }else{
        try{
            unsigned counter = index-1;
            //a variable head so that we don't make changes to the actual head of the linkedlist
            Node* head = this->head;
            //get to the corret place
            while (counter>0 && head->next != nullptr ){
                head = head->next;
                counter -=1;
            }
            /*head is currently 1 before the node we want to remove
            so we have something like this:
                HEAD->node->head->node_to_remove->node->node->TAIL
                and so we want to the link between head and node_to_remove by:
                setting head's next value to be the node after the one we want to remove. 
            */
            head->next->~Node();
            head->next = head->next->next;
            ret = true;
        }
        catch(std::exception& e){
            cout<<e.what()<<endl;
        }
    }
    return ret;
}

