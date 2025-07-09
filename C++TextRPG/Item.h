#pragma once

#include "MainSystem.h"
#include "Character.h"

using namespace std;

class cItem : public cMainSystem
{
public:
	cItem();
	~cItem();

	//아이템 코드에 맞는 아이템을 찾아줌
	virtual void SearchItemCode(cMainSystem* Character, int ItemNum, int SelectTool);

	//아이템 사용
	virtual void UseBread(cMainSystem* Character);
	virtual void UseHealingPotion(cMainSystem* Character);

protected:
	//아이템 갯수
	int m_nMyBread;
	int m_nMyHealingPotion;

private:

	friend class cInventory;
	friend class cCharacter;
};