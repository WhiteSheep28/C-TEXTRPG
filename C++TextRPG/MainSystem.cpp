#include <iostream>

#include "MainSystem.h"

int cMainSystem::m_nBossCount = 1;
int cMainSystem::m_nScore = 1;
int cMainSystem::m_nSelect = 0;
int cMainSystem::m_nHighScore = 0;
int cMainSystem::m_nBreadCount = 1;

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

	m_nScore = 0;
}

void cMainSystem::CharacterUi()
{
	//상속으로 나누기
	system("cls");
	cout << "{ " << m_strName << " }" << endl << endl;
	cout << "{ 스텟 }" << endl;
	cout << "체력 : " << m_nHealth << endl;
	cout << "공격력 : " << m_nAttack << endl;
	cout << "허기 : " << m_nHungry << endl << endl;
}