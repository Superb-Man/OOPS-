#include<iostream>
#include<stdlib.h>
#include<assert.h>

template<class T>
struct node{
    node<T>* next ;
    T  item ;

    node(){
        this->next = NULL ;
    }

    node(T item){
       this->next = NULL ;
       this->item  = item ;
    }
};

template< class T >
class LList{

private: 
    int size ; 
    node<T> *head,*tail,*cur;

public:
    /**
     * constructor for initialization or an empty linked list
     * Only a dummy node
     */
    LList() {
        size = 0 ;
        head = tail = cur = new node<T> ;
    }

    LList(T* _arr , int _size = 0 , int _memorysize = 0){
        size = 0 ;
        head = tail = cur = new node<T> ;
        int i = 0 ;
        while(i++ < _size){
            append(_arr[i-1]) ;
        }
    }

    // Destructor 
    ~LList(){
        if(head->next) clear() ; // if the list is not clear
        delete head ;
        std::cout <<"Memory freed" <<'\n' ;
        
    }

    void clear(){
        while(head){
            cur = head ;
            head = head->next ;
            delete cur ;
        }
        
        head = tail = cur = new node<T> ;

        size = 0 ;
    }

    /**
     * @param item -> Inserts an element at the current location.
     * No return type
     * O(1)
     */
    void insert(const T& item){
        node<T>* temp = new node<T>(item) ;
        temp->next = cur->next ;
        cur->next = temp ;
        if(cur == tail) {
            tail = cur->next ;
        }
        ++size ; 
    }

    /**
     * @param item -> insert an element at the end of the list
     * No return type
     * O(1)
     */

    void append(const T& item){
        node<T>* temp = new node<T>(item) ;
        tail->next = temp ;
        tail = tail->next ;
        ++size ;
    }

    /**
     * Remove current node
     * @return  the element of that current node
     * O(1)
     */

    T remove(){
        assert(cur->next != NULL) ;
        node<T>* temp = cur->next ;
        T item = cur->next->item ;
        if (tail == cur->next) tail = cur ;
        cur->next = cur->next->next ;
        delete temp ;
        size-- ;
        
        if(cur == tail) prev() ;
        return item ;
    }

    void moveToStart() {
        cur = head ; // current set to dummy node of the list
    }

    void moveToEnd(){
        moveToPos(size-1) ;
    }

    /**
     * set the current node to previous one
     * O(n)
     */
    void prev(){
        if(cur == head) return ;
        
        node<T>* temp = head ;
        while(temp->next != cur){
            temp = temp->next ;
        }
        cur = temp ;
    }

    void next(){
        if(cur != tail) cur = cur->next ;
    }

    int length() const{
        return size ;
    }

    int curPos(){
        int i = 0 ;
        node<T>* temp = head ;
        while(temp != cur) {
            temp = temp->next ;
            i++ ;
        }

        return i ;
    }

    /**
     * @param idx the index that the current node needs to be set 
     * No return type 
     * 
     */

    void moveToPos(int idx){
        if(idx < 0 || idx >= size){
            cur->next = NULL ;
            assert(cur->next != NULL) ;
        }
        /**
         * if idx is less than the current position
         */ 
        if(idx < curPos()) {
            node<T>* temp = head ;
            while(idx--){
                temp = temp->next ;
                if(idx == 0) break ; 
            }
    
            cur = temp ;
        }
        /**
         * if idx is greater than the current position
         * current node needs to go in right
         */ 
        else {
            int pos = curPos() ;
            while(pos++ <= idx){
                if(pos > idx) break ;
                cur = cur->next ;
            }
                
        }
        
    }

    /**
     *
     * @return current node element
     */ 
    T getValue() const{
        assert(cur->next != NULL) ;
        return cur->next->item ;
    }
    
    /**
     * @param item -> may be in the list or not 
     * @return the position of the given item
     * 
     */

    int searchItem(const T& item){
        node<T>* temp = head->next ;
        int i = 0 ;
        while(temp) {
            if(temp->item == item) return i ;
            temp = temp->next ; i++ ;
        }
        return -1 ;  
        
    }

    void print(){
        node<T>* temp = head->next ;
        while(temp){
            if(temp == cur->next) std::cout <<"|" <<" " ;
            std::cout << temp->item <<" " ;
            temp = temp->next ;
        }

        std::cout << '\n' ;
    }


};
int main(){
    int ara[6] ;
    for(int i = 0 ; i< 6; i++){
        ara[i] = i*i+1 ;
    }
    LList<int>lii,li(ara,6,3) ;
    //std::cout << lii.getValue() ;
    lii.insert(765) ;
    lii.insert(76) ;
    lii.print() ;
    li.insert(77) ;
    li.print() ;
    li.moveToEnd() ;
    li.print() ;
    li.insert(9) ;
    li.print() ;
    li.print() ;
    //li.moveToStart() ;
    li.moveToEnd() ;
    li.print() ;
    li.moveToPos(4) ;
    std:: cout << li.getValue() <<'\n' ;
    //li.prev() ;
    /*while(li.length()!=0){
        std :: cout <<li.length() <<" " ;
        std:: cout <<li.getValue() <<"\n" ;
        li.print() ;
        li.prev() ;//li.next() ;
    }*/
    
    li.print() ;
    li.remove() ;
    li.print() ;
    std::cout << li.searchItem(288) <<'\n' ;
    li.clear() ;
    li.clear() ;
    li.print() ;
    li.append(765) ;
    li.print() ;
}