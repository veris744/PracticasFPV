// Practica3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

const char* tCadenas[] =
{
  "Hola",
  "Adios",
  "Fernando",
  "Pepito",
  "Juanito",
};
constexpr unsigned int size = sizeof(tCadenas) / sizeof(char*);

const char* getCadena(unsigned int _iIndex)
{
  if (_iIndex >= 0 && _iIndex < size)
  {
    return tCadenas[_iIndex];
  }
  return nullptr;
}

char* getCadenaInvertida(unsigned int _iIndex)
{
  if (_iIndex >= 0 && _iIndex < size)
  {
    const int sizeCadena = std::strlen(tCadenas[_iIndex]);
    char* invertida = new char[sizeCadena];

    for (unsigned int uIndex = 0; uIndex < sizeCadena; uIndex++)
    {
      invertida[uIndex] = tCadenas[_iIndex][sizeCadena - uIndex -1];
      
    }
    invertida[sizeCadena] = '\0';
    return(invertida);
    delete[]invertida;
  }
  return nullptr;
}



int main()
{
  printf("Cadena %d es %s\n", 1, getCadena(1));
  printf("Cadena %d es %s", 2, getCadenaInvertida(2));
}

