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
	cout << "{ 스텟 }" << endl;
	cout << "체력 : " << m_nHealth << endl;
	cout << "공격력 : " << m_nAttack << endl;
	cout << "허기 : " << m_nHungry << endl << endl;
}

void cSocerer::SkillTree(cMainSystem* pMainSystem, cMainSystem* Character, cMainSystem* Monster)
{
	int nDamage = 0;

	cout << "{ 스킬트리 }" << endl;
	cout << "1. 일반 공격" << endl;
	cout << "2. 매직 에로우" << endl;
	cout << "3. 메테오" << endl;
	cout << "4. 메지컬 빔" << endl;
	cout << "5. 인벤토리" << endl;
	cout << "6. 나가기" << endl;

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
