#ifndef SINGLY_LIST_H
   #define SINGLY_LIST_H
    
    #include "Course.h"
    
    using namespace std;
    
    typedef Course SinglyListItemType;
    
    class SinglyList{
    
        // constructors and destructor:
        public:
           SinglyList();                  // default constructor
           ~SinglyList();                 // destructor
        
        // list operations:
           bool isEmpty() const;
        
           int getLength() const;
        
           bool insert(SinglyListItemType newItem) ;
        
           bool remove(int index);
           
           bool remove(SinglyListItemType newItem) ;
        
           bool retrieve(int index, 
        		            SinglyListItemType& dataItem) ;
        private:
        
           struct ListNode{      // a node on the list
              SinglyListItemType item; // a data item on the list
              ListNode *next;    // pointer to next node
           };
        
        
           int       size;  // number of items in list
           ListNode *head;  // pointer to linked list 
        				    // of items
        
        
           ListNode *find(int index) const;
           // Returns a pointer to the index-th node
           // in the linked list.
    };

#endif
