#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
  // writer note:  //use prev smaller to become the next of the value being added and then change smaller to the value being added
  // head recursion
  // base case aka like end of the list then set everything to null from video?
  if (head == NULL)
  {
    smaller = NULL;
    larger = NULL;
    return;
  }
  
  // recursive call
  llpivot(head->next, smaller, larger, pivot);
  
  // compare to pivot to see which list to place in
  if (head->val > pivot)
  {
    head->next = larger;
    larger = head;
    head = NULL;
  }
  else // assume the value is less than or equal to the pivot value
  {
    head->next = smaller;
    smaller = head;
    head = NULL;
  }
}


