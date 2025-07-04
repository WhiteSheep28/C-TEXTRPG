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

void cWarrior::SkillTree(cMainSystem* pMainSystem, cMainSystem* Character, cMainSystem* Monster)
{
	int nDamage = 0;

	cout << "{ ��ųƮ�� }" << endl;
	cout << "1. �Ϲ� ����" << endl;
	cout << "2. ���ϰ� ����" << endl;
	cout << "3. ������ ����" << endl;
	cout << "4. ���� ����" << endl;
	cout << "5. �κ��丮" << endl;
	cout << "6. ������" << endl;

	pMainSystem->Setm_nSelect();

	switch (Getm_nSelect())
	{
	case 1:
	{
		nDamage = m_nAttack;
		Monster->Setm_nHealth(nDamage);
		break;
	}
	case 2:
	{
		nDamage = m_nAttack * 2;
		Monster->Setm_nHealth(nDamage);
		break;
	}
	case 3:
	{
		nDamage = m_nAttack * 10;
		Monster->Setm_nHealth(nDamage);
		break;
	}
	case 4:
	{
		nDamage = m_nAttack * 100;
		Monster->Setm_nHealth(nDamage);
		break;
	}
	case 5:
	{
		break;
	}
	case 6: break;
	default: break;
	}
}