#pragma once
#include"Stack.h"
#include<string>

using namespace std;

template<class T>
class TaskProcessor
{
public:

   Stack<T> evenNumbers(Stack<T> numbers)
   {
      Stack<T> result = Stack<T>();

      long size = numbers.getSize();
      for (long i = 0; i < size; i++)
      {
         T item = numbers.get();

         if (item % 2 == 0)
         {
            result.add(item);
         }
      }

      return result;
   }

   string toString(Stack<T> stack)
   {
      string result = "";

      long size = stack.getSize();
      for (long i = 0; i < size; i++)
      {
         result += to_string(stack.get()) + "\r\n";
      }

      return result;
   }
};