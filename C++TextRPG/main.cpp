#include <iostream>

#include "MainSystem.h"
#include "Item.h"
#include "DungeonUi.h"
#include "Ui.h"
#include "FarmUi.h"
#include "Inventory.h"
#include "Warrior.h"
#include "Socerer.h"
#include "Archer.h"

using namespace std;

void main()
{
	cMainSystem* pMainSystem = new cMainSystem;
	cMainSystem* pItem = new cItem;
	cMainSystem* pUi = new cUi;
	cMainSystem* pDungeonUi = new cDungeonUi;
	cMainSystem* pFarmUi = new cFarmUi;
	cMainSystem* pInventory = new cInventory;
	cMainSystem* pCharacter;

	while (1)
	{
		//게임 시작
		while (1)
		{
			pUi->StartMainUi();
			pMainSystem->Setm_nSelect();

			switch (pMainSystem->Getm_nSelect())
			{
			case 1:
			{
				break;
			}
			case 2:
			{
				delete pMainSystem;
				delete pUi;
				return;
			}
			default: continue;
			}

			if (pMainSystem->Getm_nSelect() == 1)
			{
				break;
			}
		}

		//게임 캐릭터 선택
		while (1)
		{
			while (1)
			{
				pUi->CharacterSelectUi(pMainSystem);

				pMainSystem->Setm_nSelect();

				switch (pMainSystem->Getm_nSelect())
				{
				case 1:
				{
					cMainSystem* pWarrior = new cWarrior();

					pCharacter = pWarrior;

					break;
				}
				case 2:
				{
					cMainSystem* pSocerer = new cSocerer();

					pCharacter = pSocerer;

					break;
				}
				case 3:
				{
					cMainSystem* pArcher = new cArcher();

					pCharacter = pArcher;

					break;
				}
				default:
				{
					continue;
				}
				}
				break;
			}

			while (1)
			{
				pUi->CharacterIntroduceUi(pMainSystem, pCharacter);

				pMainSystem->Setm_nSelect();

				switch (pMainSystem->Getm_nSelect())
				{
				case 1:
				{
					break;
				}
				case 2:
				{
					break;
				}
				default:
				{
					continue;
				}
				}
				break;
			}

			if (pMainSystem->Getm_nSelect() == 1)
			{
				break;
			}
		}

		//게임 시작
		while (1)
		{
			//메인 화면
			pUi->MainUi(pMainSystem, pCharacter);

			pMainSystem->Setm_nSelect();

			switch (pMainSystem->Getm_nSelect())
			{
			//던전
			case 1:
			{
				pDungeonUi->DungeonStart(pMainSystem, pCharacter, pInventory, pItem);

				if (pCharacter->Getm_nHealth() <= 0)
				{
					delete pMainSystem;
					delete pUi;
					delete pCharacter;
					delete pInventory;
					delete pDungeonUi;
					delete pFarmUi;
					main();
				}
				break;
			}
			//농장
			case 2:
			{
				while (1)
				{
					pFarmUi->FarmUi(pMainSystem, pCharacter, pInventory);

					pMainSystem->Setm_nSelect();

					switch (pMainSystem->Getm_nSelect())
					{
					case 1:
					{
						pInventory->GetItem(pCharacter, pItem, 1, pMainSystem->Getm_nBreadCost());

						pMainSystem->Resetm_nBreadCost();

						break;
					}
					case 2:
					{
						break;
					}
					default:
					{
						continue;
					}
					}

					if (pMainSystem->Getm_nSelect() == 2)
					{
						break;
					}
				}

				if (pMainSystem->Getm_nSelect() == 2)
				{
					break;
				}
			}
			//인벤토리
			case 3:
			{
				pInventory->InventoryUi(pMainSystem, pCharacter, pItem);

				break;
			}
			//나가기
			case 4:
			{
				delete pMainSystem;
				delete pUi;
				delete pCharacter;
				delete pInventory;
				delete pDungeonUi;
				delete pFarmUi;
				return;
			}
			default:
			{
				continue;
			}
			break;
			}
		}
	}
}

//최적화
//아이템 코드 따로
//대기실로 돌아올 때 모든 체력 회복
//스태틱 캐스팅으로 함수 내에 들어갈 시 해당 직업에 맞는 형태로 캐스팅하면 됨 그러므로 부모 객체를 호출한다