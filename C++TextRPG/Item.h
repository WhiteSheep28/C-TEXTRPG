#pragma once

#include "MainSystem.h"

using namespace std;

class cItem : public cMainSystem
{
public:
	cItem();
	~cItem();

	//������ �ڵ忡 �´� �������� ã����
	virtual void SearchItemCode();

	//������ ���
	virtual void UseBread(); 
	virtual void UseHealingPotion();

protected:
	//������ ����
	int m_nMyBread;
	int m_nMyHealingPotion;

private:

};