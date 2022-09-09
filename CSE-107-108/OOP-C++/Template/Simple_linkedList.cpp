#include<iostream>

class node{

public :
    node* next ;
    int   data ;
    node(int data){
        next        = NULL ;
        this->data  = data ;
    }
};

class list{

private: 
    node* head,*tail ;

public:
    list(){
        head = NULL ;
        tail = NULL ;
    }

    void add(int data){
        /*
        *Alloacating the space required for a node
        *assigining a value to data variable
        *assiging next pointer to NULL
        */

        node* temp = new node(data) ;
        
        /*
        *This part is to join the nodes.
        *Then create the linked list .
        *Chking if the head is set to NULL or not.
        *If head is set to NULL , we assign the temp node to head.
        *It will also be the tailing node.
        *If head is not NULL , then our linked list is created..
        *Now we just have to add the nodes at the end of the list.
        */
        if(head == NULL){
            head = temp ;
            tail = head ;

            return ;
        }

        tail->next = temp ;
        tail       = tail->next ;
    }

    void print(){
        node* temp = head ;
        while(temp != NULL){
            std::cout << temp->data << " " ;
            temp = temp->next ;
        }
        std::cout <<'\n' ;
    }

};

int main(){
    list ilist;
    ilist.add(1) ;
    ilist.add(2) ;
    ilist.add(4) ;
    ilist.add(8) ;
    ilist.print() ;
    ilist.add(16) ;
    ilist.print() ;
}