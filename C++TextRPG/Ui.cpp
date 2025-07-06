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

//ó�� ����
void cUi::StartMainUi()
{
	system("cls");
	cout << "{ Text RPG }" << endl;
	cout << "1. ���� �����ϱ�" << endl;
	cout << "2. ���� ������" << endl;
}

//ĳ���� ������
void cUi::CharacterSelectUi(cMainSystem* pMainSystem)
{
		system("cls");
		cout << "{ ĳ���͸� ������ �ּ���. }" << endl;
		cout << "1. Warrior" << endl;
		cout << "2. Socerer" << endl;
		cout << "3. Archer" << endl;
}

//ĳ���� ����â
void cUi::CharacterIntroduceUi(cMainSystem* pMainSystem, cMainSystem* Character)
{
		Character->CharacterUi();

		cout << "{ ������ }" << endl;
		cout << "1. ����ϱ�" << endl;
		cout << "2. �ڷΰ���" << endl;
}

//���� ����
void cUi::MainUi(cMainSystem * pMainSystem, cMainSystem * Character)
{
		Character->CharacterUi();

		cout << "{ �ְ� ���� Ž�� ��� }" << endl;
		cout << pMainSystem->Getm_nHighScore() << "��" << endl << endl;

		cout << "{ ������ }" << endl;
		cout << "1. ����" << endl;
		cout << "2. ����" << endl;
		cout << "3. �κ��丮" << endl;
		cout << "4. ������" << endl;
}