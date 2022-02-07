#include <iostream>
#include <string>
#include "Stack.h"
#include "StackFormatter.h"
#include "FilterExpression.h"
#include "EvenNumbersFilter.h"

using namespace std;

int main()
{
   class : public FilterExpression<long>
   {
      bool apply(long item) override
      {
         return item > -50 && item < 50;
      }

   } filterByRange;

   class : public FilterExpression<long>
   {
      bool apply(long item) override
      {
         return item % 2 == 0;
      }

   } filterByEvenNumbers;

   Stack<long>* numbers = new Stack<long>();
   numbers->add(11);
   numbers->add(100);
   numbers->add(1001);
   numbers->add(10000);
   numbers->add(100001);
   numbers->add(1000010);

   Stack<string>* names = new Stack<string>();
   names->add("Gilgamesh");
   names->add("Sargon");
   names->add("Hammurabi");
   names->add("Tiglath-Pileser");
   names->add("Nebuchadnezzar");

   numbers->filter(&filterByEvenNumbers);

   names->reverse();

   StackFormatter* formatter = new StackFormatter();

   string result = formatter->format(numbers, names);

   cout << result << endl;

   return 0;
}
