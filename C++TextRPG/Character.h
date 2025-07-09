#pragma once

#include "MainSystem.h"
#include "Inventory.h"
#include "Item.h"

using namespace std;

class cCharacter: public cMainSystem
{
public:
	cCharacter();
	virtual ~cCharacter();

	virtual void SkillTreeUi() { ; }

	virtual void UseBread();
	virtual void UseHealingPotion();

protected:

private:
	
	friend class cInventory;
	friend class cItem;
};