/**
Charlie liu
2274468
liu305@mail.chapman.edu
CPSC 350-02
Assignment 3 - Syntax Checker
*/

#include "Delimiter.h"

char Delimiter::flip(char del)
{
  switch (del)
  {
    case '[': return ']';
    case ']': return '[';
    case '(': return ')';
    case ')': return '(';
    case '{': return '}';
    case '}': return '{';
    default: return '\0';
  }
}
