#pragma once

#include "MainSystem.h"
#include "Character.h"

using namespace std;

class cItem : public cMainSystem
{
public:
	cItem();
	~cItem();

	//������ �ڵ忡 �´� �������� ã����
	virtual void SearchItemCode(cMainSystem* Character, int ItemNum, int SelectTool);

	//������ ���
	virtual void UseBread(cMainSystem* Character);
	virtual void UseHealingPotion(cMainSystem* Character);

protected:
	//������ ����
	int m_nMyBread;
	int m_nMyHealingPotion;

private:

	friend class cInventory;
	friend class cCharacter;
};