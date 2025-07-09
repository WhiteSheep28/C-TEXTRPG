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
		//���� ����
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

		//���� ĳ���� ����
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

		//���� ����
		while (1)
		{
			//���� ȭ��
			pUi->MainUi(pMainSystem, pCharacter);

			pMainSystem->Setm_nSelect();

			switch (pMainSystem->Getm_nSelect())
			{
			//����
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
			//����
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
			//�κ��丮
			case 3:
			{
				pInventory->InventoryUi(pMainSystem, pCharacter, pItem);

				break;
			}
			//������
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

//����ȭ
//������ �ڵ� ����
//���Ƿ� ���ƿ� �� ��� ü�� ȸ��
//����ƽ ĳ�������� �Լ� ���� �� �� �ش� ������ �´� ���·� ĳ�����ϸ� �� �׷��Ƿ� �θ� ��ü�� ȣ���Ѵ�