// Practica2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


void ReverseString(char* _sCadena_)
{

}

int main()
{

  int iEntero = 874996;

  unsigned char* p = (unsigned char*)&iEntero;

  for (unsigned int uIndex = 0; uIndex < sizeof(int); uIndex++)
  {
    printf("0x%02x\n", *(p+uIndex));
  }

  //////////////////////////////////////////

  int tabla[] = { 1,3,2,5,3,0xFFFFFFFF,2 };

  int iMax = INT_MIN;
  int* pTabla = tabla;
  unsigned int sizeTabla = sizeof(tabla) / sizeof(int);

  for (unsigned int uIndex = 0; uIndex < sizeTabla; uIndex++)
  {
    if (iMax < *(pTabla + uIndex))
    {
      iMax = *(pTabla + uIndex);
    }
  }

  printf("El entero maximo es %d\n", iMax);

  /////////////////////////////////////////////
  
  int tabla2[] = { 1,3,2,5,3,0xFFFFFFFF,2 };

  unsigned char cMax = 0u;
  unsigned char* pTabla2 = (unsigned char*)tabla2;
  unsigned int sizeTabla = sizeof(tabla);

  for (unsigned int uIndex = 0; uIndex < sizeTabla; uIndex++)
  {
    if (cMax < *(pTabla2 + uIndex))
    {
      cMax = *(pTabla2 + uIndex);
    }
  };

  printf("El byte maximo es %d\n", cMax);

  
  /////////////////////////////////////////////

  char cadena[] = "asdfg";
  char cadenaFinal[sizeof(cadena)];

  char* pCadenaFinal = cadenaFinal;
  for (int i = std::strlen(cadena)-1; i >= 0 ; i--)
  {
    *pCadenaFinal = static_cast<char>(cadena[i]);
    pCadenaFinal++;
  }

  for (int i = 0; i < std::strlen(cadena); i++)
  {
    cadena[i] = cadenaFinal[i];
    printf("%c", cadena[i]);
  }
}
