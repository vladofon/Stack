﻿#include <iostream>
#include <string>
#include "Stack.h"
#include "StackFormatter.h"
#include "EvenNumbersFilter.h"

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

   numbers->filterRange(100, 1000);

   names->reverse();

   StackFormatter* formatter = new StackFormatter();

   string result = formatter->format(numbers, names);

   cout << result << endl;

   return 0;
}
