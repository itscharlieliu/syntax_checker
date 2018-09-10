/**
Charlie liu
2274468
liu305@mail.chapman.edu
CPSC 350-02
Assignment 3 - Syntax Checker
*/


#include "SyntaxChecker.h"
#include "Delimiter.h"

using namespace std;

SyntaxChecker::SyntaxChecker()
{

}

//creates a new stack depending on the number of delimiters in the file.
SyntaxChecker::SyntaxChecker(string fileName):UserInput(fileName)
{
  input = getString();
  int delimiters = 0;
  for (int i = 0; i < input.length(); ++i)
  {
    if (input[i] == '[' || input[i] == '(' || input[i] == '{')
    {
      delimiters++;
    }
  }
  buffer = new GenStack<char>(delimiters * 2);

}

SyntaxChecker::~SyntaxChecker()
{

}

//checks if the syntax is okay
bool SyntaxChecker::isGood()
{
  bool good = true;
  int line = 1;
    for (int i = 0; i < input.length(); ++i)
    {
      if (input[i] == '\n')
      {
        ++line;
      }
      if (input[i] == '[' || input[i] == '(' || input[i] == '{')
      {
        buffer->push(input[i]);
      }
      if (input[i] == ']' || input[i] == ')' || input[i] == '}')
      {
        if (Delimiter::flip(input[i]) != buffer->peek())
        {
          cout << "Delimiter does not match at line " << line << ", expected " << Delimiter::flip(buffer->peek()) << " but detected " << input[i] << '.' << endl;
          return false;
        }
        else
        {
          buffer->pop();
        }

      }
    }
    if (!buffer->isEmpty())
    {
      cout << "Reached end of file; missing " << Delimiter::flip(buffer->peek()) << '.' <<  endl;
      return false;
    }

    else if(myFile.is_open())
    {
      cout << "Delimiter syntax is correct." << endl;
      myFile.close();
      return true;
    }
  return false;
}


//Reinitiates the class with a different filename
void SyntaxChecker::reset(string s)
{
  delete buffer;
  fileName = "";
  userInput = "";
  fileName = s;
  setString();
  input = getString();
  int delimiters = 0;
  for (int i = 0; i < input.length(); ++i)
  {
    if (input[i] == '[' || input[i] == '(' || input[i] == '{')
    {
      delimiters++;
    }
  }
  buffer = new GenStack<char>(delimiters * 2);

}
