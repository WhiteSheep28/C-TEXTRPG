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

void cSocerer::CharacterUi()
{
	system("cls");
	cout << "{ " << m_strName << " }" << endl << endl;
	cout << "{ ���� }" << endl;
	cout << "ü�� : " << m_nHealth << endl;
	cout << "���ݷ� : " << m_nAttack << endl;
	cout << "��� : " << m_nHungry << endl << endl;
}

void cSocerer::SkillTree(cMainSystem* pMainSystem, cMainSystem* Character, cMainSystem* Monster)
{
	int nDamage = 0;

	cout << "{ ��ųƮ�� }" << endl;
	cout << "1. �Ϲ� ����" << endl;
	cout << "2. ���� ���ο�" << endl;
	cout << "3. ���׿�" << endl;
	cout << "4. ������ ��" << endl;
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
