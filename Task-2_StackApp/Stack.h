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

   bool filterRange(long from, long to, long skipCount = 0)
   {
      Node* current = head;

      if (current == nullptr)
         return true;

      if (skipCount != 0)
         current = skipTo(skipCount);

      bool condition = current->item < from || current->item > to;

      if (condition)
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
            Node* last = skipTo();
            last->pPrev = current;
         }

         filterRange(from, to);
      }

      if (current == nullptr || current->pPrev == nullptr || isRecursionDone)
      {
         isRecursionDone = true;
         return true;
      }

      skipCount++;
      filterRange(from, to, skipCount);
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

   Node* skipTo(long skip = 0)
   {
      Node* current = head;

      if (skip == 0)
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