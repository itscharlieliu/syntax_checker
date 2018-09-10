/**
Charlie liu
2274468
liu305@mail.chapman.edu
CPSC 350-02
Assignment 3 - Syntax Checker
*/



#ifndef SYNTAXCHECKER_H
#define SYNTAXCHECKER_H

#include "GenStack.h"
#include "UserInput.h"
#include <iostream>

class SyntaxChecker: public UserInput
{
private:
  GenStack<char>* buffer;
  string input;


public:
  SyntaxChecker();
  SyntaxChecker(string s);
  ~SyntaxChecker();

  bool isGood();

  void reset(string s);

};


#endif
