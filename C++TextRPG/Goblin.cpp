#include <iostream>

#include "MainSystem.h"
#include "Goblin.h"

cGoblin::cGoblin()
{
	m_strName = "Goblin";
	m_nHealth = 100;
	m_nAttack = 5;
	m_nHungry = 100;
}

cGoblin::~cGoblin()
{

}

void cGoblin::Setm_nHealth(int nDamage)
{
	m_nHealth -= nDamage;
}