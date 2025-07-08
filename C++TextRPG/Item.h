#pragma once

#include "MainSystem.h"

using namespace std;

class cItem : public cMainSystem
{
public:
	cItem();
	~cItem();

	//아이템 코드에 맞는 아이템을 찾아줌
	virtual void SearchItemCode();

	//아이템 사용
	virtual void UseBread(); 
	virtual void UseHealingPotion();

protected:
	//아이템 갯수
	int m_nMyBread;
	int m_nMyHealingPotion;

private:

};