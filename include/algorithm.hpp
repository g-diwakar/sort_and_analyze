#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include"bar.hpp"
#include<chrono>
#include<thread>
class Algorithm
{
protected:
  void swap(Bar& a, Bar& b);
  bool isGreater(Bar&a, Bar&b);
  bool isLesser(Bar&a, Bar& b);
public:
  Algorithm(){};
  ~Algorithm()=default;

  virtual void sort(std::vector<Bar>& array)=0;

  };


#endif 
