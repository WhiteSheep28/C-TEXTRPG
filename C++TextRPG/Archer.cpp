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
	cout << "{ 스킬트리 }" << endl;
	cout << "1. 일반 공격" << endl;
	cout << "2. 더블 샷" << endl;
	cout << "3. 크리티컬 샷" << endl;
	cout << "4. 대궁 발사" << endl;
	cout << "5. 인벤토리" << endl;
	cout << "6. 나가기" << endl;
}


