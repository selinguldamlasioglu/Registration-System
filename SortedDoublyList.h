#ifndef DOUBLY_LIST_H
   #define DOUBLY_LIST_H
    
    #include "Student.h"
    
    using namespace std;
    
    typedef Student SortedDoublyListItemType;
    
    class SortedDoublyList{
    
        // constructors and destructor:
        public:
           SortedDoublyList();                  // default constructor
           ~SortedDoublyList();                 // destructor
        
        // list operations:
           bool isEmpty() const;
        
           int getLength() const;
        
           bool add(SortedDoublyListItemType newItem) ;
        
           bool remove(int index) ;
           
           bool remove(SortedDoublyListItemType item_tobeRemoved) ;
        
           bool retrieve(int index, 
        		            SortedDoublyListItemType ** dataItem) ;
           
           int find(SortedDoublyListItemType item_tobeFound) ;
           
           void showAll();
           
        private:
        
           struct ListNode{      // a node on the list
              SortedDoublyListItemType item; // a data item on the list
              ListNode *next;    // pointer to next node
              ListNode *prev;
           };
        
        
           int       size;  // number of items in list
           ListNode *head;  // pointer to linked list 
        				    // of items
        
           ListNode *find(int index) const;
           // Returns a pointer to the index-th node
           // in the linked list.
           
    };

#endif
