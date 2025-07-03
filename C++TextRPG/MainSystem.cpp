#include <iostream>

#include "MainSystem.h"

cMainSystem::cMainSystem()
{

}

cMainSystem::~cMainSystem()
{

}

void cMainSystem::Setm_nSelect()
{
	cin >> m_nSelect;
}

void cMainSystem::Setm_nScore()
{
	m_nScore++;
}

void cMainSystem::Setm_nHighScore()
{
	if (m_nHighScore < m_nScore)
	{
		m_nHighScore = m_nScore;
	}
}