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
	//������� ������
	system("cls");
	cout << "{ " << m_strName << " }" << endl << endl;
	cout << "{ ���� }" << endl;
	cout << "ü�� : " << m_nHealth << endl;
	cout << "���ݷ� : " << m_nAttack << endl;
	cout << "��� : " << m_nHungry << endl << endl;
}