#include <iostream>
#include <string>
#include"Stack.h"
#include"EvenNumbersFilter.h"

using namespace std;

int main()
{
   Stack<long>* numbers = new Stack<long>();
   numbers->add(11);
   numbers->add(100);
   numbers->add(1001);
   numbers->add(10000);
   numbers->add(100001);

   Stack<string>* names = new Stack<string>();
   names->add("Gilgamesh");
   names->add("Sargon");
   names->add("Hammurabi");
   names->add("Tiglath-Pileser");
   names->add("Nebuchadnezzar");

   TaskProcessor<long> processor = TaskProcessor<long>();

   Stack<long>* even = processor.evenNumbers(numbers);

   string evenNumbers = processor.toString(even);

   cout << evenNumbers;
   cout << "_____________" << endl;

   names->reverse();

   TaskProcessor<string> stringProcessor = TaskProcessor<string>();
   string reverseNames = stringProcessor.appendAll(names);

   cout << reverseNames;

   return 0;
}
