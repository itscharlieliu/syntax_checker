/**
Charlie liu
2274468
liu305@mail.chapman.edu
CPSC 350-02
Assignment 3 - Syntax Checker
*/


#include "UserInput.h"


using namespace std;

UserInput::UserInput()
{
  fileName = "";
  userInput = "";

}

UserInput::UserInput(string fileName)
{
  UserInput();
  this->fileName = fileName;
  setString();
}

UserInput::~UserInput()
{
  myFile.close();
}

//saves the file name.
void UserInput::addFile(string fileName)
{
  this->fileName = fileName;
  setString();
}


//opens a file and sets the string userInput to the contents of the file.
void UserInput::setString()
{
  myFile.open(fileName.c_str());
  string line;

  cout << "Attempting to read file: " << fileName << "..." << '\n';

  if (myFile.is_open())
  {
    while (getline (myFile,line))
    {
      userInput += line + '\n';
    }
  }
  else cout << "Unable to open file\n";
}

string UserInput::getString()
{
  return userInput;
}
