#pragma once

template<class T>
class FilterExpression
{
public:
   virtual bool apply(T) = 0;
};