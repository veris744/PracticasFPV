// practica4.cpp
//
#include <stdio.h>
#include <windows.h>
#include "consola.h"

struct TEntity;
typedef void (*funcEntity)(TEntity*);

constexpr int s_iMaxHeight = 10;
constexpr int s_iMaxWidth = 15;

// ***************************************************************************************
// ENTIDAD
// ***************************************************************************************
struct TEntity
{
	int m_ix;
	int m_iy;
	funcEntity m_move;
	funcEntity m_draw;
	TEntity(funcEntity move, funcEntity draw, int x, int y)
	{
		m_ix = x;
		m_iy = y;
		m_move = move;
		m_draw = draw;
	}
};

void MoverDerecha(TEntity* _pEntity)
{
	_pEntity->m_ix++;
	if (_pEntity->m_ix > s_iMaxWidth)
	{
		_pEntity->m_ix = 0;
	}
}

void MoverDiagonal(TEntity* _pEntity)
{
	_pEntity->m_ix++;
	if (_pEntity->m_ix > s_iMaxWidth)
	{
		_pEntity->m_ix = 0;
	}
	_pEntity->m_iy++;
	if (_pEntity->m_iy > s_iMaxHeight)
	{
		_pEntity->m_iy = 0;
	}
}

void PintarA(TEntity* _pEntity)
{
	gotoxy(_pEntity->m_ix, _pEntity->m_iy);
	printf("A");
}

void PintarB(TEntity* _pEntity)
{
	gotoxy(_pEntity->m_ix, _pEntity->m_iy);
	printf("B");
}

void PintarC(TEntity* _pEntity)
{
	gotoxy(_pEntity->m_ix, _pEntity->m_iy);
	printf("C");
}

// ***************************************************************************************
// MAIN
// ***************************************************************************************
unsigned int uKey;
int main(int argc, char* argv[])
{
	TEntity* tEntities[4];
	funcEntity tFuncsEnt0[2];
	tEntities[0] = new TEntity(&MoverDerecha, &PintarA, 0, 0);
	tEntities[1] = new TEntity(&MoverDerecha, &PintarB, 7, 3);
	tEntities[2] = new TEntity(&MoverDiagonal, &PintarC, 4, 7);
	tEntities[3] = new TEntity(&MoverDiagonal, &PintarA, 3, 2);

	int i = 0;
	while (true)
	{
		clear();

		for (int i = 0; i < 4; ++i)
		{
			tEntities[i]->m_move(tEntities[i]);
			tEntities[i]->m_draw(tEntities[i]);
		}

		Sleep(500);
	}
}
