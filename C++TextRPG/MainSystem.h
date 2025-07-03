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


	//Ui.h
	virtual void StartMainUi() { ; }
	virtual void CharacterSelectUi() { ; }
	virtual void CharacterIntroduceUi() { ; }
	virtual void MainUi() { ; }
	

	//DungeonUi.h
	virtual void DungeonRandomMob(cMainSystem* pMainSystem, cMainSystem* Character) { ; }
	virtual void DungeonFightUi() { ; }


	//Inventory.h
	virtual void InventoryUi(cMainSystem* pMainSystem, cMainSystem* Character) { ; }


	//Character.h
	virtual void CharacterUi() { ; }
	virtual void SkillTree(cMainSystem* pMainSystem, cMainSystem* Character, cMainSystem* Monster) { ; }
	virtual void CauseAttack() { ; }
	
	virtual string Getm_strName() { return m_strName; }
	virtual void Setm_nHealth(int nDamage) { m_nHealth -= nDamage; } //상대의 체력 감소
	virtual void Setm_nPlusHealth() { m_nHealth += 10; } //체력 물약
	virtual int Getm_nHealth() { return m_nHealth; } 
	virtual int Getm_nAttack() { return m_nAttack; }
	virtual void Setm_nMinusHungry() { m_nHungry -= 10; } //플레이어 허기 감소
	virtual void Setm_nPlusHungry() { m_nHungry += 100; } //플레이어 허기 증가
	virtual int Getm_nHungry() { return m_nHungry; }
	
protected:
	static int m_nScore;
	static int m_nHighScore;
	static int m_nSelect;

	string m_strName;
	int m_nHealth;
	int m_nAttack;
	int m_nHungry;

private:

};