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


	//Character.h
	virtual void CharacterUi() { ; }
	virtual void SkillTree(cMainSystem* pMainSystem, cMainSystem* Character, cMainSystem* Monster) { ; }
	virtual void CauseAttack() { ; }
	
	virtual string Getm_strName() { return m_strName; }
	virtual void Setm_nHealth(int nDamage) { ; }
	virtual int Getm_nHealth() { return m_nHealth; }
	virtual int Getm_nAttack() { return m_nAttack; }
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