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
    
    T deleteLast(){
        prev() ;
        node<T>* temp = cur->next ;
        T item = temp->item ;
        cur->next = tail->next ;
        tail = cur ;
        size-- ;
            
        delete temp ;
        return item ;
    }
    

public:
    /**
     * constructor for initialization or an empty linked list
     */
    LList() {
        size = 0 ;
        head = tail = cur = NULL;
    }

    LList(T* _arr , int _size = 0 , int _memorysize = 0){
        size = 0 ;
        head = tail = cur = NULL ;
        int i = 0 ;
        while(i++ < _size){
            append(_arr[i-1]) ;
        }
    }

    // Destructor 
    ~LList(){
        if(head) clear() ; // if the list is not clear ;
        std::cout <<"Memory freed" <<'\n' ;
        
    }

    void clear(){
        while(head){
            cur = head ;
            head = head->next ;
            delete cur ;
        }
        
        head = tail = cur = NULL ;

        size = 0 ;
    }

    /**
     * @param item -> Inserts an element at the current location.
     * No return type
     * O(1)
     */
    void insert(const T& item){
        node<T>* temp = new node<T>(item) ;
        if(cur == NULL){
            head = tail = cur = temp ;
            ++size ;
            return ;
        }
        temp->next = cur->next ;
        cur->next = temp ;
        std::swap(cur->next->item, cur->item) ;
        if(cur == tail) tail = cur->next ; 
        ++size ; 
    }

    /**
     * @param item -> insert an element at the end of the list
     * No return type
     * O(1)
     */

    void append(const T& item){
        node<T>* temp = new node<T>(item) ;
        if(cur == NULL){
            head = cur = tail = temp ;
            ++size ;
            return ;
        }
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
        assert(cur != NULL) ;
        if(cur == tail && cur != head){
            deleteLast() ;
        }
        if(cur == head && cur == tail){
            node<T>* temp = head ;
            T item = temp->item ;
            head = head->next ;
            cur = tail = head ;
            size-- ;
            
            delete temp ;
            return item ;
        }
        cur->item = cur->next->item ;
        if(cur->next == tail) tail = cur ;
        
        node<T>* temp = cur->next ;
        T item = temp->item ;
        cur->next = cur->next->next ;
        size-- ;
        
        delete temp ;
        return item ;
    }

    void moveToStart() {
        cur = head ; // current set to dummy node of the list
    }

    void moveToEnd(){
        //moveToPos(size-1) ;
        cur = tail ;
    }

    /**
     * set the current node to previous one
     * O(n)
     */
    void prev(){
        assert(cur != NULL) ;
        
        node<T>* temp = head ;
        while(temp->next != cur){
            temp = temp->next ;
        }
        cur = temp ;
    }

    void next(){
        assert(cur != NULL) ;
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
        assert(cur != NULL) ;
        if(idx < 0 || idx >= size){
            cur = NULL ;
            assert(cur != NULL) ;
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
        assert(cur != NULL) ;
        
        return cur->item ;
    }
    
    /**
     * @param item -> may be in the list or not 
     * @return the position of the given item
     * 
     */

    int searchItem(const T& item){
        node<T>* temp = head ;
        int i = 0 ;
        while(temp) {
            if(temp->item == item) return i ;
            temp = temp->next ; i++ ;
        }
        return -1 ;  
        
    }

    void print(){
        node<T>* temp = head ;
        while(temp){
            if(temp == cur) std::cout <<"|" <<" " ;
            std::cout << temp->item << " " ; 
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
    li.prev() ;
    li.print() ;
    std:: cout << li.getValue() <<'\n' ;
    li.print() ;
    //li.moveToStart() ;
    li.moveToEnd() ;
    li.print() ;
    li.moveToPos(4) ;
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
    li.moveToStart() ;
    li.print() ;
    li.remove() ;
    li.print() ;
    li.clear() ;
    li.clear() ;
    li.print() ;
    li.append(765) ;
    li.remove() ;
    li.print() ;
}