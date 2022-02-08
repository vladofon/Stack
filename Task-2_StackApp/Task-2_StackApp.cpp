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
   numbers->add(-10);
   numbers->add(10);
   numbers->add(11);
   numbers->add(100);
   numbers->add(1001);
   numbers->add(10000);

   Stack<long>* filteredByRange = new Stack<long>();
   numbers->copy(*filteredByRange);

   Stack<long>* filteredByEvenNumbers = new Stack<long>();
   numbers->copy(*filteredByEvenNumbers);

   Stack<long>* basicByRange = new Stack<long>();
   numbers->copy(*basicByRange);

   Stack<long>* basicByEvenNumbers = new Stack<long>();
   numbers->copy(*basicByEvenNumbers);

   Stack<string>* names = new Stack<string>();
   names->add("Gilgamesh");
   names->add("Sargon");
   names->add("Hammurabi");
   names->add("Tiglath-Pileser");
   names->add("Nebuchadnezzar");

   Stack<string>* reversedStack = new Stack<string>();
   names->copy(*reversedStack);

   Stack<string>* basicReversedStack = new Stack<string>();
   names->copy(*basicReversedStack);

   filteredByEvenNumbers->filter(&filterByEvenNumbers);

   filteredByRange->filter(&filterByRange);

   reversedStack->reverse();

   StackFormatter* formatter = new StackFormatter();
   string result =
      formatter
      ->format(basicByRange, filteredByRange, basicByEvenNumbers, filteredByEvenNumbers, basicReversedStack, reversedStack);
   cout << result << endl;

   return 0;
}
