#include "SinglyList.h"
#include <cstddef>

SinglyList::SinglyList(): size(0), head(NULL){

}

SinglyList::~SinglyList(){

   while (!isEmpty())
      remove(1);

} // end destructor

bool SinglyList::isEmpty() const{

   return size == 0;

}  // end isEmpty

int SinglyList::getLength() const{

   return size;

}  // end getLength

SinglyList::ListNode *SinglyList::find(int index) const{
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

bool SinglyList::retrieve(int index,
           SinglyListItemType& dataItem) {

   if ((index < 1) || (index > getLength()))
      return false;
   
   // get pointer to node, then data in node
   ListNode *cur = find(index);
   dataItem = cur->item;

   return true;

} // end retrieve

bool SinglyList::insert(SinglyListItemType newItem) {

   int newLength = getLength() + 1;
   
   for( ListNode *cur = head; cur != NULL; cur = cur->next )
        if( cur->item.getID() == newItem.getID() ) return false;
   
   ListNode *newPtr = new ListNode;
   size = newLength;
   newPtr->item = newItem;

   newPtr->next = head;
   head = newPtr;
   
   return true;

} // end insert

bool SinglyList::remove(int index) {

   ListNode *cur;

   if ((index < 1) || (index > getLength()))
      return false;

   --size;
   if (index == 1){
      cur = head;  
      head = head->next;
   }
   else{
      ListNode *prev = find(index-1);
      cur = prev->next;
      prev->next = cur->next;
   }
   cur->next = NULL;
   delete cur;
   cur = NULL;
   
   return true;

}  // end remove

bool SinglyList::remove(SinglyListItemType newItem) {
     int ind = 1;
     for( ListNode *cur = head; cur != NULL; cur = cur->next ){
        if( cur->item.getID() == newItem.getID() ){
            return remove(ind);
        }
        ind++;
     }
     return false;
}
