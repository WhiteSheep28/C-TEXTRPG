#include <iostream>

#include "MainSystem.h"
#include "Warrior.h"

cWarrior::cWarrior()
{
	m_strName = "Warrior";
	m_nHealth = 100;
	m_nAttack = 20;
	m_nHungry = 100;
}

cWarrior::~cWarrior()
{

}

void cWarrior::SkillTreeUi()
{
	cout << "{ ��ųƮ�� }" << endl;
	cout << "1. �Ϲ� ����" << endl;
	cout << "2. ���ϰ� ����" << endl;
	cout << "3. ������ ����" << endl;
	cout << "4. ���� ����" << endl;
	cout << "5. �κ��丮" << endl;
	cout << "6. ������" << endl;
}