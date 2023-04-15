#include "Span.hpp"

int main() {
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;

  Span vec = Span(100);
  std::vector<int> copy(100, 42);
  copy[42] = 40;
  try {
  
  vec.addNumber(copy.begin() , copy.end());
  std::cout << vec.shortestSpan() << std::endl;
  std::cout << vec.longestSpan() << std::endl;
  }
  catch (std::exception const &e){ std::cout << e.what() << std::endl; }
return 0; }