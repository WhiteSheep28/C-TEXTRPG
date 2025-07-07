#pragma once

using namespace std;

class cMainSystem
{
public:
	cMainSystem();
	virtual ~cMainSystem();

	void Setm_nSelect();
	static int Getm_nSelect() { return m_nSelect; }
	void Setm_nScore();
	static int Getm_nScore() { return m_nScore; }
	void Setm_nHighScore();
	static int Getm_nHighScore() { return m_nHighScore; }
	void Resetm_nBreadCost() { m_nBreadCost = 0; }
	int Getm_nBreadCost() { return m_nBreadCost; }
	static void Setm_nBreadCount() { m_nBreadCount++; }
	static void Setm_nBossCount() { m_nBossCount++; }
	static int Getm_nBossCount() { return m_nBossCount; }


	//Ui.h
	virtual void StartMainUi() { ; }
	virtual void CharacterSelectUi(cMainSystem* pMainSystem) { ; }
	virtual void CharacterIntroduceUi(cMainSystem* pMainSystem, cMainSystem* Character) { ; }
	virtual void MainUi(cMainSystem* pMainSystem, cMainSystem* Character) { ; }


	//DungeonUi.h
	virtual void DungeonRandomMob(cMainSystem* pMainSystem, cMainSystem* Character, cMainSystem* Inventory) { ; }
	virtual void DungeonFightUi(cMainSystem* pMainSystem, cMainSystem* Character, cMainSystem* Monster, cMainSystem* Inventory) { ; }
	virtual void DungeonRandomItem() { ; }


	//FarmUi.h
	virtual void FarmUi(cMainSystem* pMainSystem, cMainSystem* Character, cMainSystem* Inventory) { ; }


	//Inventory.h
	virtual void InventoryUi(cMainSystem* pMainSystem, cMainSystem* Character) { ; }
	virtual void InputInventory(int ItemCode, int ItemNum) { ; }
	virtual void CleanInventory() { ; }


	//Character.h
	void CharacterUi();
	void SkillTree(cMainSystem* pMainSystem, cMainSystem* Character, cMainSystem* Monster);
	virtual void SkillTreeUi() { ; }
	virtual void CauseAttack() { ; }
	
	virtual string Getm_strName() { return m_strName; }
	virtual void Setm_nHealth(int nDamage) { m_nHealth -= nDamage; } //상대의 체력 감소
	virtual void Setm_nPlusHealth() 
	{ 
		m_nHealth += 50; 
		
		if (m_nHealth > 100) //체력이 100을 넘지 않도록
		{
			m_nHealth = 100;
		}
	} //체력 물약
	virtual int Getm_nHealth() { return m_nHealth; } 
	virtual int Getm_nAttack() { return m_nAttack; }
	virtual void Setm_nMinusHungry() { m_nHungry -= 10;} //플레이어 허기 감소
	virtual void Setm_nPlusHungry()
	{ 
		m_nHungry += 100;

		if (m_nHungry > 100) //허기가 100을 넘지 않도록
		{
			m_nHungry = 100;
		}
	} //플레이어 허기 증가
	virtual int Getm_nHungry() { return m_nHungry; }
	
protected:
	static int m_nBossCount;

	static int m_nBreadCount;
	int m_nBreadCost;

	static int m_nScore;
	static int m_nHighScore;
	static int m_nSelect;

	string m_strName;
	int m_nHealth;
	int m_nAttack;
	int m_nHungry;
	int m_nCharacterCode;

private:

};