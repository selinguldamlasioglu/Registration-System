#include "SortedDoublyList.h"
#include <cstddef>

SortedDoublyList::SortedDoublyList(): size(0), head(NULL){

}

SortedDoublyList::~SortedDoublyList(){

   while (!isEmpty())
      remove(1);

} // end destructor

bool SortedDoublyList::isEmpty() const{

   return size == 0;

}  // end isEmpty

int SortedDoublyList::getLength() const{

   return size;

}  // end getLength

SortedDoublyList::ListNode *SortedDoublyList::find(int index) const{
// Locates a specified node in a linked list.
// Precondition: index is the number of the
// desired node.
// Postcondition: Returns a pointer to the 
// desired node. If index < 1 or index > the 
// number of nodes in the list, returns NULL.

   if ( (index < 1) || (index > getLength()) )
      return NULL;
      
   else{ // count from the beginning of the list
   
      ListNode *cur = head;
      for (int skip = 1; skip < index; ++skip)
         cur = cur->next;
      return cur;
   }
}  // end find

int SortedDoublyList::find(SortedDoublyListItemType item_tobeFound) {
   
   // count from the beginning of the list
   if( head == NULL ){
       return false;
   }
   else{
        ListNode *cur = head;
        int index = 1;
        
        while( cur->item.getID() < item_tobeFound.getID() ){
            if( cur->next == NULL ){
                // End of the list
                return -1;
            }
            else{ 
                  cur = cur->next;
                  ++index;
            }
        }
        if( cur->item.getID() == item_tobeFound.getID() )
            return index;
        else return -1;
   }
   
}  // end find


bool SortedDoublyList::retrieve(int index,
           SortedDoublyListItemType **dataItem)  {

   if ((index < 1) || (index > getLength()))
      return false;

   // get pointer to node, then data in node
   ListNode *cur = find(index);
   *dataItem = &(cur->item);

   return true;

} // end retrieve

bool SortedDoublyList::add(SortedDoublyListItemType newItem) {

   int newLength = getLength() + 1;

   ListNode *newPtr = new ListNode;
   size = newLength;
   newPtr->item = newItem;
   
   if (head == NULL){
      newPtr->next = NULL;
      newPtr->prev = NULL;
      head = newPtr;
   }
   else if( head->item.getID() > newItem.getID() ){
        newPtr->next = head;
        head->prev = newPtr;
        head = newPtr;
   }
   else{

      ListNode *cur = head;
      for( ; cur != NULL ; cur = cur->next ){
           if( cur->item.getID() == newItem.getID() ){
               size--;
               return false;
           }
           if( cur->item.getID() > newItem.getID() ){
               
               // Insert between nodes cur and prev
               ListNode *temp = cur->prev;
               cur->prev      = newPtr;
               if( temp != NULL ) temp->next = newPtr;
               newPtr->next   = cur;
               newPtr->prev   = temp;
               break;
           }
           else if( cur->next == NULL ){   
               cur->next = newPtr;
               newPtr->prev = cur;
               newPtr->next = NULL;
               break;
           }
      }
   }
   return true;
} // end add

bool SortedDoublyList::remove(int index) {

   ListNode *cur;

   if ((index < 1) || (index > getLength()))
      return false;

   if (index == 1){
      cur = head;
      head->prev = NULL;  
      head = head->next;
   }
   else{
      ListNode *prevNode = find(index-1);
      cur = prevNode->next;
      prevNode->next = cur->next;
      if( cur->next != NULL ) cur->next->prev = prevNode;
   }
   
   --size;
   cur->next = NULL;
   cur->prev = NULL;
   delete cur;
   cur = NULL;
   
   return true;
}  // end remove

bool SortedDoublyList::remove(SortedDoublyListItemType item_tobeRemoved) {

   int itemIndex = find( item_tobeRemoved );
   if( itemIndex == -1 ){
       return false;
   }else{
       return remove(itemIndex);
   }
}  // end remove
