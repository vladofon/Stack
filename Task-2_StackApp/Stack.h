#pragma once
#include"FilterExpression.h"

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
      for (long i = 0; i < arraySize; i++)
      {
         if (i != arraySize - 1)
            arrayStack[arraySize - 1 - i]->pPrev = arrayStack[arraySize - 2 - i];
         else
            arrayStack[arraySize - 1 - i]->pPrev = nullptr;
      }

      head = arrayStack[arraySize - 1];
   }

   void copy(Stack<T>& stk)
   {
      for (long i = 0; i < size; i++)
      {
         stk.add(skipTo(size - 1 - i)->item);
      }
   }

   void filter(FilterExpression<T>* expression, long skipCount = 0)
   {
      recursiveDeleting(expression, skipCount);

      isRecursionDone = false;
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

   bool isRecursionDone = false;

   bool recursiveDeleting(FilterExpression<T>* expression, long skipCount = 0)
   {
      Node* current = head;

      if (skipCount != 0)
         current = skipTo(skipCount);

      if (current == nullptr || isRecursionDone)
      {
         isRecursionDone = true;
         return true;
      }

      bool condition = expression->apply(current->item);

      if (!condition)
      {
         deleteNode(current, skipCount);

         recursiveDeleting(expression, skipCount);
      }

      if (current == nullptr || current->pPrev == nullptr || isRecursionDone)
      {
         isRecursionDone = true;
         return true;
      }

      skipCount++;
      recursiveDeleting(expression, skipCount);
   }

   void deleteNode(Node* current, long skipCount)
   {
      Node* toDelete = current;
      current = current->pPrev;
      delete toDelete;

      size--;

      if (skipCount == 0)
      {
         head = current;
      }
      else
      {
         Node* last = skipTo(skipCount - 1);
         last->pPrev = current;
      }
   }

   Node* skipTo(long skip = 0, bool end = false)
   {
      Node* current = head;

      if (end == true)
         skip = size - 1;

      long counter = 0;

      while (counter != skip)
      {
         current = current->pPrev;
         counter++;
      }

      return current;
   }
};