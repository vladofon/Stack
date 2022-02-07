#pragma once
#include<string>
#include"List.h"
#include"Stack.h"
#include"ArrayList.h"
#include "TableSchema.h"
#include "SchemaParser.h"

using namespace std;

class StackFormatter
{
public:
   StackFormatter(TableSchema* schema)
   {
      this->schema = schema;
   }

   StackFormatter()
   {
      // If constructor empty define default schema
      this->schema = new TableSchema();
      initDefaultSchema();
   }

   string format(Stack<long>* rangeBasic, Stack<long>* rangeFiltered,
      Stack<long>* evenNumbersBasic, Stack<long>* evenNumbersFiltered,
      Stack<string>* reverseBasic, Stack<string>* reverseFiltered)
   {
      List<string>* firstColumn = new ArrayList<string>();
      List<string>* secondColumn = new ArrayList<string>();
      List<string>* thirdColumn = new ArrayList<string>();
      List<string>* fourthColumn = new ArrayList<string>();
      List<string>* fifthColumn = new ArrayList<string>();
      List<string>* sixthColumn = new ArrayList<string>();

      firstColumn = parseNumbers(rangeBasic);
      secondColumn = parseNumbers(rangeFiltered);
      thirdColumn = parseNumbers(evenNumbersBasic);
      fourthColumn = parseNumbers(evenNumbersFiltered);

      fifthColumn->merge(reverseBasic);
      sixthColumn->merge(reverseFiltered);

      schema->fillColumn(0, 0, firstColumn);
      schema->fillColumn(0, 1, secondColumn);
      schema->fillColumn(1, 0, thirdColumn);
      schema->fillColumn(1, 1, fourthColumn);
      schema->fillColumn(2, 0, fifthColumn);
      schema->fillColumn(2, 1, sixthColumn);

      SchemaParser* parser = new SchemaParser(*schema);
      return parser->parseSchema();
   }

private:
   TableSchema* schema;

   void initDefaultSchema()
   {
      schema->createRow("=======+ Filter by range (+-50) +=======");
      schema->getRow(0).createColumn("Basic stack");
      schema->getRow(0).createColumn("Filtered stack");
      schema->createRow("=======+ Filter by even numbers +=======");
      schema->getRow(1).createColumn("Basic stack");
      schema->getRow(1).createColumn("Filtered stack");
      schema->createRow("=======+ Reverse stack operation +=======");
      schema->getRow(2).createColumn("Basic stack");
      schema->getRow(2).createColumn("Reversed stack");
   }

   List<string>* parseNumbers(Stack<long>* numbers)
   {
      List<string>* stringNumbers = new ArrayList<string>();

      long size = numbers->getSize();
      for (long i = 0; i < size; i++)
      {
         stringNumbers->add(to_string(numbers->get()));
      }

      return stringNumbers;
   }
};