#include <iostream>

#include "MainSystem.h"
#include "Ui.h"

using namespace std;

int cMainSystem::m_nSelect = 0;
int cMainSystem::m_nScore = 0;
int cMainSystem::m_nHighScore = 0;

void main()
{
	cMainSystem* pUi = new cUi();

	pUi->StartMainUi();

	delete pUi;
}