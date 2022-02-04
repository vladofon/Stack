#pragma once
#include<string>
#include"List.h"
#include"Stack.h"
#include"ArrayList.h"
#include "TableSchema.h"
#include "SchemaParser.h"

using namespace std;

class FencersFormatter
{
public:
   FencersFormatter(TableSchema* schema)
   {
      this->schema = schema;
   }

   FencersFormatter()
   {
      // If constructor empty define default schema
      this->schema = new TableSchema();
      initDefaultSchema();
   }

   string format(Stack<long>* numbers, Stack<string>* names)
   {
      List<string>* firstColumn = new ArrayList<string>();
      List<string>* secondColumn = new ArrayList<string>();

      firstColumn = parseNumbers(numbers);
      secondColumn->merge(names);

      schema->fillColumn(0, 0, firstColumn);
      schema->fillColumn(0, 1, secondColumn);

      SchemaParser* parser = new SchemaParser(*schema);
      return parser->parseSchema();
   }

private:
   TableSchema* schema;

   void initDefaultSchema()
   {
      schema->createRow("=======+ Stack operations +=======");
      schema->getRow(0).createColumn("Stack of even numbers");
      schema->getRow(0).createColumn("Reversed stack of names");
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