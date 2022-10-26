// Practica5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include"FileUtils.h"

int main()
{
  unsigned int uID = OpenFile("TEXT.txt","r");
  //CloseFile(uID);

  char buffer[255];
  printf("%d\n", ReadFile(uID, buffer, 255));

  const char* buffer2 = " asdf";
  WriteFile(uID, const_cast<char*>(buffer2), sizeof(buffer));
}

