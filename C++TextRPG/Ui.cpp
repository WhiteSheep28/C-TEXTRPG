#include <iostream>

#include "MainSystem.h"
#include "DungeonUi.h"
#include "Ui.h"
#include "Inventory.h"
#include "Warrior.h"
#include "Socerer.h"
#include "Archer.h"

cUi::cUi()
{

}

cUi::~cUi()
{

}

void cUi::StartMainUi()
{
	cMainSystem* pMainSystem = new cMainSystem();

	while (1)
	{
		system("cls");
		cout << "{ Text RPG }" << endl;
		cout << "1. ���� �����ϱ�" << endl;
		cout << "2. ���� ������" << endl;

		pMainSystem->Setm_nSelect();

		switch (Getm_nSelect())
		{
		case 1:
		{
			CharacterSelectUi(pMainSystem);

			break;
		}
		case 2:
		{
			delete pMainSystem;

			exit(1);
		}
		default: continue;
		}
	}
}

void cUi::CharacterSelectUi(cMainSystem* pMainSystem)
{
	while (1)
	{
		system("cls");
		cout << "{ ĳ���͸� ������ �ּ���. }" << endl;
		cout << "1. Warrior" << endl;
		cout << "2. Socerer" << endl;
		cout << "3. Archer" << endl;

		pMainSystem->Setm_nSelect();

		switch (Getm_nSelect())
		{
		case 1:
		{
			cMainSystem* pWarrior = new cWarrior;

			CharacterIntroduceUi(pMainSystem, pWarrior);

			delete pWarrior;

			break;
		}
		case 2:
		{
			cMainSystem* pSocerer = new cSocerer;

			CharacterIntroduceUi(pMainSystem, pSocerer);
			
			delete pSocerer;

			break;
		}
		case 3:
		{
			cMainSystem* pArcher = new cArcher;

			CharacterIntroduceUi(pMainSystem, pArcher);
			
			delete pArcher;

			break;
		}
		default: continue;
		}
	}
}

void cUi::CharacterIntroduceUi(cMainSystem* pMainSystem, cMainSystem* Character)
{
	while (1)
	{
		Character->CharacterUi();

		cout << "{ ������ }" << endl;
		cout << "1. ����ϱ�" << endl;
		cout << "2. �ڷΰ���" << endl;

		pMainSystem->Setm_nSelect();

		switch (Getm_nSelect())
		{
		case 1:
		{
			MainUi(pMainSystem, Character);

			break;
		}
		case 2: break;
		default: continue;
		}
	}
}

void cUi::MainUi(cMainSystem * pMainSystem, cMainSystem * Character)
{
	cMainSystem* pInventory = new cInventory;

	while (1)
	{

		Character->CharacterUi();

		cout << "{ �ְ� ���� Ž�� ��� }" << endl;
		cout << pMainSystem->Getm_nHighScore() << "��" << endl << endl;

		cout << "{ ������ }" << endl;
		cout << "1. ����" << endl;
		cout << "2. ����" << endl;
		cout << "3. �κ��丮" << endl;
		cout << "4. ������" << endl;

		pMainSystem->Setm_nSelect();

		switch (Getm_nSelect())
		{
		case 1:
		{
			cMainSystem* pDungeonUi = new cDungeonUi;

			Character->Setm_nMinusHungry();
			
			pDungeonUi->DungeonRandomMob(pMainSystem, Character);

			delete pDungeonUi;

			break;
		}
		case 2:
		{

		}
		case 3:
		{
			pInventory->InventoryUi(pMainSystem, Character);
		}
		case 4:
		{
			delete pMainSystem;
			delete Character;
			delete pInventory;

			exit(1);
		}
		default: continue;
		}
 	}
}