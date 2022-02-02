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

      delete[] toDelete;

      size--;
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