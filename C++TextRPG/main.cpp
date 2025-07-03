#include <iostream>

#include "MainSystem.h"
#include "Ui.h"

using namespace std;

int cMainSystem::m_nBossCount = 1;
int cMainSystem::m_nScore = 1;
int cMainSystem::m_nSelect = 0;
int cMainSystem::m_nHighScore = 0;
int cMainSystem::m_nBreadCount = 1;

void main()
{
	cMainSystem* pUi = new cUi();

	pUi->StartMainUi();

	delete pUi;
}