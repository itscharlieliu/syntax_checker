/**
Charlie liu
2274468
liu305@mail.chapman.edu
CPSC 350-02
Assignment 3 - Syntax Checker
*/


#ifndef USERINPUT_H
#define USERINPUT_H
#include <iostream>
#include <fstream>

using namespace std;

class UserInput
{
protected:
  string userInput;
  string fileName;
  void setString();
  ifstream myFile;

public:
  UserInput();
  UserInput(string fileName);
  ~UserInput();


  void addFile(string fileName);
  string getString();


};






#endif
