#pragma once
#include"Stack.h"
#include<string>

using namespace std;

template<class T>
class TaskProcessor
{
public:

   Stack<T>* evenNumbers(Stack<T>* numbers)
   {
      Stack<T>* result = new Stack<T>();

      long size = numbers->getSize();
      for (long i = 0; i < size; i++)
      {
         T item = numbers->get();

         if (item % 2 == 0)
         {
            result->add(item);
         }
      }

      return result;
   }

   string toString(Stack<T>* stack)
   {
      string result = "";

      long size = stack->getSize();
      for (long i = 0; i < size; i++)
      {
         T item = stack->get();
         result += to_string(item) + "\r\n";
      }

      return result;
   }

   string appendAll(Stack<string>* stack)
   {
      string result = "";

      long size = stack->getSize();
      for (long i = 0; i < size; i++)
      {
         string item = stack->get();
         result += item + "\r\n";
      }

      return result;
   }
};