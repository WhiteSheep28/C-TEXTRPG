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
		cout << "1. 게임 시작하기" << endl;
		cout << "2. 게임 나가기" << endl;

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
		cout << "{ 캐릭터를 선택해 주세요. }" << endl;
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

		cout << "{ 선택지 }" << endl;
		cout << "1. 계속하기" << endl;
		cout << "2. 뒤로가기" << endl;

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

		cout << "{ 최고 던전 탐사 기록 }" << endl;
		cout << pMainSystem->Getm_nHighScore() << "층" << endl << endl;

		cout << "{ 선택지 }" << endl;
		cout << "1. 던전" << endl;
		cout << "2. 농장" << endl;
		cout << "3. 인벤토리" << endl;
		cout << "4. 나가기" << endl;

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