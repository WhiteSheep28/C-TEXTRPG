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

		//-------------------------------------------------------------------------------------

		//캐릭터 선택
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

				//캐릭터 설명창
				pUi->CharacterIntroduceUi(pMainSystem, pWarrior);

				pMainSystem->Setm_nSelect();

				//-------------------------------------------------------------------------------------
				switch (pMainSystem->Getm_nSelect())
				{
					//전사
				case 1:
				{
					while (1)
					{
						//메인 화면
						pUi->MainUi(pMainSystem, pWarrior);

						pMainSystem->Setm_nSelect();

						switch (pMainSystem->Getm_nSelect())
						{
							//던전
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
						//농장
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
						//인벤토리
						case 3:
						{
							pInventory->InventoryUi(pMainSystem, pWarrior);

							break;
						}
						//나가기
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

				//캐릭터 설명창	
				pUi->CharacterIntroduceUi(pMainSystem, pSocerer);

				pMainSystem->Setm_nSelect();

				switch (pMainSystem->Getm_nSelect())
				{
					//소서러
				case 1:
				{
					while (1)
					{
						//메인 화면
						pUi->MainUi(pMainSystem, pSocerer);

						pMainSystem->Setm_nSelect();

						switch (pMainSystem->Getm_nSelect())
						{
							//던전
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
						//농장
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
						//인벤토리
						case 3:
						{
							pInventory->InventoryUi(pMainSystem, pSocerer);

							break;
						}
						//나가기
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

				//캐릭터 설명창
				pUi->CharacterIntroduceUi(pMainSystem, pArcher);

				pMainSystem->Setm_nSelect();

				switch (pMainSystem->Getm_nSelect())
				{
					//소서러
				case 1:
				{
					while (1)
					{
						//메인 화면
						pUi->MainUi(pMainSystem, pArcher);

						pMainSystem->Setm_nSelect();

						switch (pMainSystem->Getm_nSelect())
						{
							//던전
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
						//농장
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
						//인벤토리
						case 3:
						{
							pInventory->InventoryUi(pMainSystem, pArcher);

							break;
						}
						//나가기
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