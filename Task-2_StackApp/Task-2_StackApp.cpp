#include <iostream>
#include"Stack.h"

using namespace std;

int main()
{
   Stack<long> numbers = Stack<long>();
   numbers.add(10);
   numbers.add(100);

   numbers.remove();

   cout << numbers.get() << endl;

   return 0;
}
