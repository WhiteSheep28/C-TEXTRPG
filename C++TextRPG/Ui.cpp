#include <iostream>

#include "MainSystem.h"
#include "DungeonUi.h"
#include "Ui.h"
#include "FarmUi.h"
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

//처음 시작
void cUi::StartMainUi()
{
	system("cls");
	cout << "{ Text RPG }" << endl;
	cout << "1. 게임 시작하기" << endl;
	cout << "2. 게임 나가기" << endl;
}

//캐릭터 선택장
void cUi::CharacterSelectUi(cMainSystem* pMainSystem)
{
		system("cls");
		cout << "{ 캐릭터를 선택해 주세요. }" << endl;
		cout << "1. Warrior" << endl;
		cout << "2. Socerer" << endl;
		cout << "3. Archer" << endl;
}

//캐릭터 설명창
void cUi::CharacterIntroduceUi(cMainSystem* pMainSystem, cMainSystem* Character)
{
		Character->CharacterUi();

		cout << "{ 선택지 }" << endl;
		cout << "1. 계속하기" << endl;
		cout << "2. 뒤로가기" << endl;
}

//메인 게임
void cUi::MainUi(cMainSystem * pMainSystem, cMainSystem * Character)
{
		Character->CharacterUi();

		cout << "{ 최고 던전 탐사 기록 }" << endl;
		cout << pMainSystem->Getm_nHighScore() << "층" << endl << endl;

		cout << "{ 선택지 }" << endl;
		cout << "1. 던전" << endl;
		cout << "2. 농장" << endl;
		cout << "3. 인벤토리" << endl;
		cout << "4. 나가기" << endl;
}