#include <iostream>

#include "MainSystem.h"
#include "Socerer.h"

cSocerer::cSocerer()
{
	m_strName = "Socerer";
	m_nHealth = 100;
	m_nAttack = 5;
	m_nHungry = 100;
}

cSocerer::~cSocerer()
{

}

void cSocerer::SkillTreeUi()
{
	cout << "{ ��ųƮ�� }" << endl;
	cout << "1. �Ϲ� ����" << endl;
	cout << "2. ���� ���ο�" << endl;
	cout << "3. ���׿�" << endl;
	cout << "4. ������ ��" << endl;
	cout << "5. �κ��丮" << endl;
	cout << "6. ������" << endl;
}
