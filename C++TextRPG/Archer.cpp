#include <iostream>

#include "MainSystem.h"
#include "Archer.h"

cArcher::cArcher()
{
	m_strName = "Archer";
	m_nHealth = 100;
	m_nAttack = 10;
	m_nHungry = 100;
}

cArcher::~cArcher()
{

}

void cArcher::SkillTreeUi()
{
	cout << "{ ��ųƮ�� }" << endl;
	cout << "1. �Ϲ� ����" << endl;
	cout << "2. ���� ��" << endl;
	cout << "3. ũ��Ƽ�� ��" << endl;
	cout << "4. ��� �߻�" << endl;
	cout << "5. �κ��丮" << endl;
	cout << "6. ������" << endl;
}


