#pragma once

template<class T>
class Stack
{
public:

   Stack()
   {
      this->head = nullptr;
      this->size = 0;
   }

   void add(T item)
   {
      if (head == nullptr)
      {
         head = new Node(item);
      }
      else
      {
         head = new Node(item, head);
      }

      size++;
   }

   T get()
   {
      T item = head->item;
      remove();

      return item;
   }

   void remove()
   {
      Node* toDelete = head;

      head = head->pPrev;

      delete toDelete;

      size--;
   }

   void clear()
   {
      while (size != 0)
      {
         remove();
      }
   }

   void reverse()
   {
      long arraySize = size;

      Node** arrayStack = new Node * [arraySize];

      Node* current = head;

      for (long i = 0; i < arraySize; i++)
      {
         arrayStack[i] = current;
         current = current->pPrev;
      }

      head = arrayStack[0];
   }

   void filterRange(long from, long to)
   {
      Node* current = head;
      Node* valid = nullptr;

      if (current == nullptr)
         return;

      long counter = 0;
      while (current->pPrev != nullptr)
      {
         T number = current->item;
         if (number < from || number > to)
         {
            if (current == head)
            {
               Node* toDelete = current;

               current = toDelete->pPrev;

               head = current;

               delete toDelete;

               size--;
            }
            else
            {

               Node* toDelete = current;

               current = toDelete->pPrev;

               delete toDelete;

               size--;
            }
         }
         else
         {
            if (valid == nullptr)
            {
               valid = current;
               current = current->pPrev;

               counter++;
            }
            else
            {
               Node* last = valid;

               long innerCounter = 0;
               while (innerCounter != counter - 1)
               {
                  last = last->pPrev;
                  innerCounter++;
               }

               last->pPrev = current;
               current = current->pPrev;

               counter++;
            }
         }
      }

      head = valid;
   }

   long getSize()
   {
      return size;
   }

private:

   class Node
   {
   public:
      Node* pPrev;
      T item;

      Node(T item, Node* pPrev = nullptr)
      {
         this->item = item;
         this->pPrev = pPrev;
      }
   };

   Node* head;
   long size;
};