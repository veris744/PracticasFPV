// Practica1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
unsigned int iPers;


int getNumBalas()
{
  return (iPers >> 16) & 0xFF;
}

void addBala(int n)
{
  if ((n <= 0) & (abs(n) >= getNumBalas()))
  {
    iPers = iPers & 0xFF00FFFF;
  }
  else if (n + getNumBalas() >= 255) {
    iPers = iPers | 0x00FF0000;
  }
  else {
    iPers = iPers + (n << 16);
  };
}

bool isInfinito()
{
  return iPers & 0x02;
}

void setInfinito()
{
  iPers = iPers | 0x02;
}


int main()
{
  iPers = 0xAE1A3AAC;

  printf("Numero de balas: %d\n", getNumBalas());

  printf("Es infinito: %d\n", isInfinito());

  addBala(45);
  printf("Numero de balas: %d\n", getNumBalas());

  iPers = 0xAE1A3AAC;

  addBala(-3);
  printf("Numero de balas: %d\n", getNumBalas());

  iPers = 0xAE1A3AAC;

  addBala(70000000000);
  printf("Numero de balas: %d\n", getNumBalas());

  setInfinito();
  printf("Es infinito: %x\n", isInfinito());

}

//


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
