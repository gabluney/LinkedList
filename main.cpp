//----------------------------------------------
// Purpose: Implement simple List class.
// Author:  John Gauch(Professor) and Gabrielle Luney
//----------------------------------------------

#include "list2.h"
#include <stdlib.h>

//----------------------------------------------
// Constructor function.
//----------------------------------------------
List::List()
{
   Head = NULL;
}

//----------------------------------------------
// Constructor function.
//----------------------------------------------
List::List(const List & list)
{
   // Create first node
   LNode *copy = new LNode();
   Head = copy;

   // Walk list to copy nodes
   LNode *ptr = list.Head;
   while (ptr != NULL)
   {
      copy->Next = new LNode();
      copy = copy->Next;
      copy->Value = ptr->Value;
      copy->Next = NULL;
      ptr = ptr->Next;
   }

   // Tidy first node
   copy = Head;
   Head = copy->Next;
   delete copy;
}

//----------------------------------------------
// Destructor function.
//----------------------------------------------
List::~List()
{
  //call recursively
  DestroyHelper(Head);
}
//----------------------------------------------
// Destructor function helper
//----------------------------------------------
void List::DestroyHelper(LNode* head)
{
    //cout to make sure it destroyed
    cout << "Destroyed" << endl;
    //replace while loop
    if (head != NULL)
   {
      LNode *ptr = Head;
      head = head->Next;
      delete ptr;
      //recursive handle
      return DestroyHelper(head);

   }
   else
    return;

}

//----------------------------------------------
// Insert data into linked list.
//----------------------------------------------
bool List::InsertHead(float value)
{
   // Create new node
   LNode *ptr = new LNode();
   ptr->Value = value;
   ptr->Next = Head;

   // Insert new node
   Head = ptr;
   return true;
}

//----------------------------------------------
// Insert data into linked list.
//----------------------------------------------
bool List::InsertTail(float value)
{
   LNode *ptr = Head;
   InsertTailHelper(ptr, value);
    // Create new node
   LNode *tmp = new LNode();
   tmp->Value = value;

   // Insert new node
   if (ptr != NULL)
   {
      tmp->Next = NULL;
      ptr->Next = tmp;
   }
   else
   {
      tmp->Next = Head;
      Head = tmp;
   }
   return true;
}
//----------------------------------------------
// Insert data into linked list helper
//----------------------------------------------
bool List::InsertTailHelper(LNode * &head, float value)

{
    //replace while loop
    if ((head != NULL) && (head->Next != NULL))
    {
       head = head->Next;
       //recursive handle
       return InsertTailHelper(head, value);
    }
      if (head == NULL)
        return false;
      else
        return true;
}
//----------------------------------------------
// Search for data in linked list.
//----------------------------------------------
bool List::Search(float value)
{
  // Walk list to find node
   LNode *ptr = Head;
   return (SearchHelper(ptr, value));
}
//----------------------------------------------
// Search helper
//----------------------------------------------

bool List::SearchHelper(LNode* head, float value)
{
    //replace while loops
     if (head == NULL)
        return false;
    //recursive call
    else if (head->Value != value)
    SearchHelper(head->Next, value);
    else{
        return true;
    }
}
//----------------------------------------------
// Delete data from linked list.
//----------------------------------------------
bool List::Delete(float value)
{
    LNode *curr = Head;
    LNode *prev = Head;
    DeleteHelper(curr,prev,value);

   //Check if value was found
   if (curr == NULL)
      return false;

   // Delete node from list
   if (curr == Head)
      Head = curr->Next;
   else
   prev->Next = curr->Next;
   delete curr;
   return true;
}

//----------------------------------------------
// Delete helper
//----------------------------------------------
bool List::DeleteHelper(LNode* &curr, LNode* &prev, float value)

  {
    //replace while loops
     if (curr == NULL)
            return false;

    if  ((curr != NULL) && (curr->Value != value))
   {
      prev = curr;
      curr = curr->Next;
      //recursive call
      DeleteHelper(curr,prev,value);
   }

else
    return true;

}

//----------------------------------------------
// Print all records in linked list.
//----------------------------------------------
void List::Print()
{
   LNode *ptr = Head;
   PrintHelper(ptr);
}
//----------------------------------------------
// Printer helper
//----------------------------------------------
void List::PrintHelper(LNode* head)
{
     if (head == NULL)
        return;
    //recursive call
    cout << head -> Value << endl;
    PrintHelper(head->Next);

}
//----------------------------------------------
// Check to see if list is empty.
//----------------------------------------------
bool List::IsEmpty()
{
   return (Head == NULL);
}


//-----------------------------------------------------------
// Testing function
//-----------------------------------------------------------
int main()
{
   const int size = 10;
   float num[size] = { 0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.5, 7.6, 8.7, 9.8 };
   List list;

   // Test insert head
   for (int count = 0; count < size; count++)
   {
      int index = rand() % size;
      if (list.InsertHead(num[index]))
	 cout << "InsertHead " << num[index] << " ok\n";
      else
	 cout << "InsertHead " << num[index] << " failed\n";
   }
   list.Print();

   // Test copy
   cout << "Copy\n";
   List copy(list);
   copy.Print();

   // Test search
   for (int count = 0; count < size; count++)
   {
      int index = rand() % size;
      if (list.Search(num[index]))
	 cout << "Search " << num[index] << " found\n";
      else
	 cout << "Search " << num[index] << " not found\n";
   }
   list.Print();

   // Test delete
   for (int count = 0; count < size; count++)
   {
      int index = rand() % size;
      if (list.Delete(num[index]))
	 cout << "Delete " << num[index] << " ok\n";
      else
	 cout << "Delete " << num[index] << " failed\n";
   }
   list.Print();

   // Test copy
   cout << "Copy\n";
   List copy2(list);
   copy2.Print();

   // Test insert tail
   for (int count = 0; count < size; count++)
   {
      int index = rand() % size;
      if (copy2.InsertTail(num[index]))
	 cout << "InsertTail " << num[index] << " ok\n";
      else
	 cout << "InsertTail " << num[index] << " failed\n";
   }
   copy2.Print();
}
