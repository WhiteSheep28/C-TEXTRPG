#include <iostream>

#include "DungeonUi.h"
#include "MainSystem.h"
#include "Inventory.h"
#include "MinoTauros.h"
#include "Goblin.h"
#include "Slime.h"
#include "Wolf.h"

cDungeonUi::cDungeonUi()
{
	m_nRandomMonster = 0;
	m_nRandomItem = 0;
}

cDungeonUi::~cDungeonUi()
{

}

void cDungeonUi::DungeonRandomItem()
{
	m_nRandomItem = rand() % 2 + 1;
}

void cDungeonUi::DungeonStart(cMainSystem* pMainSystem, cMainSystem* Character, cMainSystem* Inventory, cMainSystem* Item)
{
	pMainSystem->Setm_nBreadCount();
	Character->Setm_nMinusHungry();
	DungeonRandomMob(pMainSystem, Character, Inventory, Item);
}

void cDungeonUi::DungeonRandomMob(cMainSystem* pMainSystem, cMainSystem* Character, cMainSystem* Inventory, cMainSystem* Item)
{
	while (1)
	{
		//보스 몬스터
		if (pMainSystem->Getm_nBossCount() == 10)
		{
			cMainSystem* pMinoTauros = new cMinoTauros;
			DungeonFightUi(pMainSystem, Character, pMinoTauros, Inventory, Item);
			if (Character->Getm_nHealth() <= 0)
			{
				delete pMinoTauros;
				return;
			}
			delete pMinoTauros;
			break;
		}

		//일반 몬스터 
		m_nRandomMonster = rand() % 3;

		switch (m_nRandomMonster)
		{
		case 0:
		{
			cMainSystem* pGoblin = new cGoblin;
			DungeonFightUi(pMainSystem, Character, pGoblin, Inventory, Item);
			if (Character->Getm_nHealth() <= 0)
			{
				delete pGoblin;
				return;
			}
			delete pGoblin;
			break;
		}
		case 1:
		{
			cMainSystem* pSlime = new cSlime;
			DungeonFightUi(pMainSystem, Character, pSlime, Inventory, Item);
			if (Character->Getm_nHealth() <= 0)
			{
				delete pSlime;
				return;
			}
			delete pSlime;
			break;
		}
		case 2:
		{
			cMainSystem* pWolf = new cWolf;
			DungeonFightUi(pMainSystem, Character, pWolf, Inventory, Item);
			if (Character->Getm_nHealth() <= 0)
			{
				delete pWolf;
				return;
			}
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

void cDungeonUi::DungeonFightUi(cMainSystem* pMainSystem, cMainSystem* Character, cMainSystem* Monster, cMainSystem* Inventory, cMainSystem* Item)
{
	while (1)
	{
		if (Character->Getm_nHealth() <= 0)
		{
			m_nBossCount = 1;
			m_nScore = 1;
			m_nHighScore = 0;
			m_nBreadCount = 1;
			return;
		}

		system("cls");
		cout << "{ 현재 층 : " << pMainSystem->Getm_nScore() << "층 }" << endl << endl;
		cout << "{ " << Character->Getm_strName() << " }";
		cout << "         { " << Monster->Getm_strName() << " }" << endl;
		cout << "체력   : " << Character->Getm_nHealth();
		cout << "       체력   : " << Monster->Getm_nHealth() << endl;
		cout << "공격력 : " << Character->Getm_nAttack();
		cout << "        공격력 : " << Monster->Getm_nAttack() << endl << endl << endl;

		Character->SkillTree(pMainSystem, Character, Monster);

		if (Monster->Getm_nHealth() <= 0)
		{
			pMainSystem->Setm_nBossCount();
			pMainSystem->Setm_nScore();
			DungeonRandomItem();
			Inventory->InputInventory(Getm_nRandomItem(), 1);
			break;
		}

		if (Getm_nSelect() >= 1 && Getm_nSelect() <= 4)
		{
			Character->Setm_nHealth(Monster->Getm_nAttack());
		}

		if (Getm_nSelect() == 5)
		{
			Inventory->InventoryUi(pMainSystem, Character, Item, Inventory);
		}

		if (Getm_nSelect() == 6)
		{
			m_nBossCount = 1;
			break;
		}
	}
}