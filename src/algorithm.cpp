#include "../include/algorithm.hpp"

void Algorithm::swap(Bar& a, Bar& b)
{
  Bar t;
  t=a;
  a=b;
  b=t;
}

bool Algorithm::isGreater(Bar& a, Bar& b)
{
  return(a>b);
}

bool Algorithm::isLesser(Bar& a, Bar& b)
{
  return (a<b);
}


