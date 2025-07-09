#include <iostream>

#include "MainSystem.h"
#include "Character.h"

cCharacter::cCharacter()
{

}

cCharacter::~cCharacter()
{
	
}

void cCharacter::UseBread()
{
	m_nHungry += 10;

	if (m_nHungry <= 100)
	{
		m_nHungry = 100;
	}
}

void cCharacter::UseHealingPotion()
{
	m_nHealth += 100;

	if (m_nHealth <= 100)
	{
		m_nHealth = 100;
	}
}