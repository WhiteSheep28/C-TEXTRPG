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
	cout << "{ 스킬트리 }" << endl;
	cout << "1. 일반 공격" << endl;
	cout << "2. 강하게 베기" << endl;
	cout << "3. 힘차게 베기" << endl;
	cout << "4. 진심 베기" << endl;
	cout << "5. 인벤토리" << endl;
	cout << "6. 나가기" << endl;
}