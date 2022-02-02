#include <iostream>
#include"Stack.h"
#include"EvenNumbersFilter.h"

using namespace std;

int main()
{
   Stack<long> numbers = Stack<long>();
   numbers.add(11);
   numbers.add(100);
   numbers.add(1001);
   numbers.add(10000);
   numbers.add(100001);

   TaskProcessor<long> processor = TaskProcessor<long>();

   Stack<long> even = processor.evenNumbers(numbers);

   string evenNumbers = processor.toString(even);

   cout << evenNumbers;

   return 0;
}
