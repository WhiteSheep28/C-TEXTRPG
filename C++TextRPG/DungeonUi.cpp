#include <iostream>

#include "DungeonUi.h"
#include "MainSystem.h"
#include "Goblin.h"
#include "Slime.h"
#include "Wolf.h"

cDungeonUi::cDungeonUi()
{
	m_nRandomMonster = 0;
}

cDungeonUi::~cDungeonUi()
{

}

void cDungeonUi::DungeonRandomMob(cMainSystem* pMainSystem, cMainSystem* Character)
{
	while (1)
	{
		m_nRandomMonster = rand() % 3;

		switch (m_nRandomMonster)
		{
		case 0:
		{
			cMainSystem* pGoblin = new cGoblin;
			DungeonFightUi(pMainSystem, Character, pGoblin);
			delete pGoblin;
			break;
		}
		case 1:
		{
			cMainSystem* pSlime = new cSlime;
			DungeonFightUi(pMainSystem, Character, pSlime);
			delete pSlime;
			break;
		}
		case 2:
		{
			cMainSystem* pWolf = new cWolf;
			DungeonFightUi(pMainSystem, Character, pWolf);
			delete pWolf;
			break;
		}
		}

		if (Getm_nSelect() == 6)
		{
			pMainSystem->Setm_nHighScore();
			break;
		}
	}
}

void cDungeonUi::DungeonFightUi(cMainSystem* pMainSystem, cMainSystem* Character, cMainSystem* Monster)
{
	while (1)
	{
		system("cls");
		cout << "{ ���� �� : " << pMainSystem->Getm_nScore() << "��" << endl << endl;
		cout << "{ " << Character->Getm_strName() << " }";
		cout << "         { " << Monster->Getm_strName() << " }" << endl;
		cout << "ü��   : " << Character->Getm_nHealth();
		cout << "       ü��   : " << Monster->Getm_nHealth() << endl;
		cout << "���ݷ� : " << Character->Getm_nAttack();
		cout << "        ���ݷ� : " << Monster->Getm_nAttack() << endl << endl << endl;

		Character->SkillTree(pMainSystem, Character, Monster);

		if (Monster->Getm_nHealth() <= 0)
		{
			pMainSystem->Setm_nScore();
			break;
		}

		if (Getm_nSelect() == 6)
		{
			pMainSystem->Setm_nHighScore();
			break;
		}
	}
}