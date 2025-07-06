#include <iostream>

#include "MainSystem.h"
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
	while (1)
	{
		cMainSystem* pMainSystem = new cMainSystem();
		cMainSystem* pUi = new cUi();

		//-------------------------------------------------------------------------------------

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

		//-------------------------------------------------------------------------------------

		//ĳ���� ����
		while (1)
		{
			cMainSystem* pDungeonUi = new cDungeonUi();
			cMainSystem* pInventory = new cInventory();
			cMainSystem* pFarmUi = new cFarmUi();

			pUi->CharacterSelectUi(pMainSystem);

			pMainSystem->Setm_nSelect();

			switch (pMainSystem->Getm_nSelect())
			{
			case 1:
			{
				cMainSystem* pWarrior = new cWarrior();

				//ĳ���� ����â
				pUi->CharacterIntroduceUi(pMainSystem, pWarrior);

				pMainSystem->Setm_nSelect();

				//-------------------------------------------------------------------------------------
				switch (pMainSystem->Getm_nSelect())
				{
					//����
				case 1:
				{
					while (1)
					{
						//���� ȭ��
						pUi->MainUi(pMainSystem, pWarrior);

						pMainSystem->Setm_nSelect();

						switch (pMainSystem->Getm_nSelect())
						{
							//����
						case 1:
						{
							pDungeonUi->DungeonRandomMob(pMainSystem, pWarrior, pInventory);

							if (pWarrior->Getm_nHealth() <= 0)
							{
								delete pMainSystem;
								delete pUi;
								delete pWarrior;
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
								pFarmUi->FarmUi(pMainSystem, pWarrior, pInventory);

								pMainSystem->Setm_nSelect();

								switch (pMainSystem->Getm_nSelect())
								{
								case 1:
								{
									pInventory->InputInventory(1, pMainSystem->Getm_nBreadCost());

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
							break;
							}

							break;
						}
						//�κ��丮
						case 3:
						{
							pInventory->InventoryUi(pMainSystem, pWarrior);

							break;
						}
						//������
						case 4:
						{
							delete pMainSystem;
							delete pUi;
							delete pWarrior;
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
				case 2:
				{
					break;
				}
				default:
				{
					break;
				}
				}
				break;
			}
			case 2:
			{
				cMainSystem* pSocerer = new cSocerer();

				//ĳ���� ����â	
				pUi->CharacterIntroduceUi(pMainSystem, pSocerer);

				pMainSystem->Setm_nSelect();

				switch (pMainSystem->Getm_nSelect())
				{
					//�Ҽ���
				case 1:
				{
					while (1)
					{
						//���� ȭ��
						pUi->MainUi(pMainSystem, pSocerer);

						pMainSystem->Setm_nSelect();

						switch (pMainSystem->Getm_nSelect())
						{
							//����
						case 1:
						{
							pDungeonUi->DungeonRandomMob(pMainSystem, pSocerer, pInventory);

							if (pSocerer->Getm_nHealth() <= 0)
							{
								delete pMainSystem;
								delete pUi;
								delete pSocerer;
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
								pFarmUi->FarmUi(pMainSystem, pSocerer, pInventory);

								pMainSystem->Setm_nSelect();

								switch (pMainSystem->Getm_nSelect())
								{
								case 1:
								{
									pInventory->InputInventory(1, pMainSystem->Getm_nBreadCost());

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
							break;
							}

							break;
						}
						//�κ��丮
						case 3:
						{
							pInventory->InventoryUi(pMainSystem, pSocerer);

							break;
						}
						//������
						case 4:
						{
							delete pMainSystem;
							delete pUi;
							delete pSocerer;
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
			case 3:
			{
				cMainSystem* pArcher = new cArcher();

				//ĳ���� ����â
				pUi->CharacterIntroduceUi(pMainSystem, pArcher);

				pMainSystem->Setm_nSelect();

				switch (pMainSystem->Getm_nSelect())
				{
					//�Ҽ���
				case 1:
				{
					while (1)
					{
						//���� ȭ��
						pUi->MainUi(pMainSystem, pArcher);

						pMainSystem->Setm_nSelect();

						switch (pMainSystem->Getm_nSelect())
						{
							//����
						case 1:
						{
							pDungeonUi->DungeonRandomMob(pMainSystem, pArcher, pInventory);

							if (pArcher->Getm_nHealth() <= 0)
							{
								delete pMainSystem;
								delete pUi;
								delete pArcher;
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
								pFarmUi->FarmUi(pMainSystem, pArcher, pInventory);

								pMainSystem->Setm_nSelect();

								switch (pMainSystem->Getm_nSelect())
								{
								case 1:
								{
									pInventory->InputInventory(1, pMainSystem->Getm_nBreadCost());

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
							break;
							}

							break;
						}
						//�κ��丮
						case 3:
						{
							pInventory->InventoryUi(pMainSystem, pArcher);

							break;
						}
						//������
						case 4:
						{
							delete pMainSystem;
							delete pUi;
							delete pArcher;
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
			default:
			{
				continue;
			}
			}
		}
	}
}