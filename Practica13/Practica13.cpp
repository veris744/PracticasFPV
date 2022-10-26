// Practica13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class CImage
{
public:
  CImage() {  };
  ~CImage() {  };

  enum class EType
  {
    PNG,
    JPG
  };

  EType m_eType = EType::PNG;
};

class CPng : public CImage
{
public:
  CPng() { m_eType = EType::PNG; };
  ~CPng() {  };

  void RemoveAlphaChannel() { printf("Eliminando canal alpha\n"); }

};

class CJpg : public CImage
{
public:
  CJpg() { m_eType = EType::JPG; };
  ~CJpg() {  };

};

void RemoveAlphaChannelFromPng(CImage* tImages[], int _iSize)
{
  printf("%d", sizeof(*tImages));
  for (int i = 0; i < _iSize; i++)
  {
    CImage image = *tImages[i];
    if (image.m_eType == CImage::EType::PNG) {
      CPng* opng = static_cast<CPng*>(tImages[i]);
      opng->RemoveAlphaChannel();
    }
  }
}


int main()
{
  CImage* tImages[10];
  tImages[0] = new CPng();
  tImages[1] = new CPng();
  tImages[2] = new CJpg();
  tImages[3] = new CPng();
  tImages[4] = new CPng();
  tImages[5] = new CJpg();
  tImages[6] = new CPng();
  tImages[7] = new CPng();
  tImages[8] = new CPng();
  tImages[9] = new CPng();


  unsigned int iSize = sizeof(tImages) / sizeof(tImages[0]);
  RemoveAlphaChannelFromPng(tImages, iSize);
}
