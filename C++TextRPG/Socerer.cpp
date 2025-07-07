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
	cout << "{ 스킬트리 }" << endl;
	cout << "1. 일반 공격" << endl;
	cout << "2. 매직 에로우" << endl;
	cout << "3. 메테오" << endl;
	cout << "4. 메지컬 빔" << endl;
	cout << "5. 인벤토리" << endl;
	cout << "6. 나가기" << endl;
}
