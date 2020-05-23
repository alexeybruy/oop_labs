#include <iostream>
#include <ctime>
#include <windows.h>
#include <vector>
#include "MapsGenerator.h"
//#include "GetMaps.cpp"
#define N 10

using namespace std;


//void SetRandShips1(int Playermap[N][N], int SizeShips, int NumShips)
//{
//	int x, y;
//	int direction = 0;
//	int CountShip = 0;
//
//	while (CountShip < NumShips)
//	{
//		x = 0 + rand() % N;
//		y = 0 + rand() % N;
//
//		int tempX = x;
//		int tempY = y;
//
//		direction = rand() % 4;
//
//		bool SettingIsPossible = 1;
//
//		if (x < 0 || y < 0 || x >= N || y >= N)
//		{
//			SettingIsPossible = 0;
//			break;
//		}
//
//		for (int i = 0; i < SizeShips; i++)
//		{
//
//			if (Playermap[x][y] == 1 ||
//				Playermap[x][y + 1] == 1 ||
//				Playermap[x][y - 1] == 1 ||
//				Playermap[x + 1][y] == 1 ||
//				Playermap[x + 1][y + 1] == 1 ||
//				Playermap[x + 1][y - 1] == 1 ||
//				Playermap[x - 1][y] == 1 ||
//				Playermap[x - 1][y + 1] == 1 ||
//				Playermap[x - 1][y - 1] == 1)
//			{
//				SettingIsPossible = 0;
//				break;
//			}
//
//
//			switch (direction)
//			{
//			case 0:
//
//				x++;
//				break;
//
//			case 1:
//
//				y++;
//				break;
//
//			case 2:
//
//				x--;
//				break;
//
//			case 3:
//
//				y--;
//				break;
//
//			}
//
//			if (x > 0 && x < 9 && y > 0 && y < 9)
//			{
//				if (SettingIsPossible == 1)
//				{
//					x = tempX;
//					y = tempY;
//
//					for (int i = 0; i < SizeShips; i++)
//					{
//
//						Playermap[x][y] = 1;
//
//						switch (direction)
//						{
//
//						case 0:
//
//							x++;
//							break;
//
//						case 1:
//
//							y++;
//							break;
//
//						case 2:
//
//							x--;
//							break;
//
//						case 3:
//
//							y--;
//							break;
//
//						}
//
//					}
//
//					CountShip++;
//
//				}
//			}
//
//
//		}
//	}
//}
//
//
//void SetRandShips2(int Enemymap[N][N], int SizeShips, int NumShips)
//{
//	int x, y;
//	int direction = 0;
//	int CountShip = 0;
//
//	while (CountShip < NumShips)
//	{
//		x = 0 + rand() % N;
//		y = 0 + rand() % N;
//
//		int tempX = x;
//		int tempY = y;
//
//		direction = rand() % 4;
//
//		bool SettingIsPossible = 1;
//
//		if (x < 0 || y < 0 || x >= N || y >= N)
//		{
//			SettingIsPossible = 0;
//			break;
//		}
//
//		for (int i = 0; i < SizeShips; i++)
//		{
//
//			if (Enemymap[x][y] == 1 ||
//				Enemymap[x][y + 1] == 1 ||
//				Enemymap[x][y - 1] == 1 ||
//				Enemymap[x + 1][y] == 1 ||
//				Enemymap[x + 1][y + 1] == 1 ||
//				Enemymap[x + 1][y - 1] == 1 ||
//				Enemymap[x - 1][y] == 1 ||
//				Enemymap[x - 1][y + 1] == 1 ||
//				Enemymap[x - 1][y - 1] == 1)
//			{
//				SettingIsPossible = 0;
//				break;
//			}
//
//
//			switch (direction)
//			{
//			case 0:
//
//				x++;
//				break;
//
//			case 1:
//
//				y++;
//				break;
//
//			case 2:
//
//				x--;
//				break;
//
//			case 3:
//
//				y--;
//				break;
//
//			}
//
//			if (x > 0 && x < 9 && y > 0 && y < 9)
//			{
//				if (SettingIsPossible == 1)
//				{
//					x = tempX;
//					y = tempY;
//
//					for (int i = 0; i < SizeShips; i++)
//					{
//
//						Enemymap[x][y] = 1;
//
//						switch (direction)
//						{
//
//						case 0:
//
//							x++;
//							break;
//
//						case 1:
//
//							y++;
//							break;
//
//						case 2:
//
//							x--;
//							break;
//
//						case 3:
//
//							y--;
//							break;
//
//						}
//
//					}
//
//					CountShip++;
//
//				}
//			}
//
//
//		}
//	}
//}

void BattleShip()
{

}

void ApplyMap(int map[N][N], int mapNumber)
{
	MapsGenerator generator;
	
	vector<vector<int>> mapToApply = generator.GetMaps()[mapNumber];

	for (int i =0;i<N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			map[i][j] = mapToApply[i][j];
		}
	}
}


int main()
{
	srand(time(NULL));
	int Playermap[N][N] = { 0 };
	int Enemymap[N][N] = { 0 };

	int mapNumber = rand() % 5;

	ApplyMap(Playermap, mapNumber);
	ApplyMap(Enemymap, (mapNumber + 1) % 5);
	

	int WarShadow[N][N] = { 0 };

	//SetRandShips1(Playermap, 4, 1);
	//SetRandShips1(Playermap, 3, 2);
	//SetRandShips1(Playermap, 2, 3);
	//SetRandShips1(Playermap, 1, 4);

	//SetRandShips2(Enemymap, 4, 1);
	//SetRandShips2(Enemymap, 3, 2);
	//SetRandShips2(Enemymap, 2, 3);
	//SetRandShips2(Enemymap, 1, 4);

	int PlayerDecks = 0;
	int EnemyDecks = 0;

	int PlayerKilledDecks = 0;
	int EnemyKilledDecks = 0;

	cout << "---------------------------------------------------SeaBattle------------------------------------------------------------" << endl << endl;

	cout << "(Note : 0 - WarShadow; 1 - PlayerDeck; 2 - HitDeck; 3 - Miss;)" << endl << endl << endl;

	cout << "   PLAYER BATTLEFIELD :              ENEMY BATTLEFIELD :" << endl << endl;
	cout << "   0 1 2 3 4 5 6 7 8 9" << "           " << "    0 1 2 3 4 5 6 7 8 9" << endl;
	cout << "   = = = = = = = = = =" << "           " << "    = = = = = = = = = =" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << i << "| ";
		for (int j = 0; j < N; j++)
		{
			cout << Playermap[i][j] << " ";
			//PrintDisplayValue(Playermap[i][j]);

			if (Playermap[i][j] == 1)
			{
				PlayerDecks++;
			}
		}
		cout << "           ";

		cout << i << "| ";
		for (int j = 0; j < N; j++)
		{
			//cout << Enemymap[i][j] << " ";
			cout << WarShadow[i][j] << " ";

			if (Enemymap[i][j] == 1)
			{
				EnemyDecks++;
			}
		}
		cout << endl;
	}

	bool go = true;

	while (go)
	{
		// атака гравця

		int x, y;



		cout << endl << "Enter target coordinates : " << endl;
		cout << "x = ";
		cin >> x;
		cout << endl << "y = ";
		cin >> y;

		bool input = 1;

		if (x < 0 || y < 0 || x > N || y > N)
		{
			input = 0;
			cout << "Wrong input! Try again!" << endl;
		}

		if (EnemyKilledDecks == EnemyDecks)
		{
			cout << endl << endl << endl << endl << endl << "                                             Game over. You win !                 " << endl;
			//go = false;
			break;
			return 0;
		}

		if (input == 1)
		{
			if (Enemymap[y][x] == 1)
			{
				cout << endl << "Your attack : " << endl;
				cout << "hit !" << endl << endl;

				Enemymap[y][x] = 2;
				WarShadow[x][y] = 2;

				EnemyKilledDecks++;

				cout << "Killed decks : " << EnemyKilledDecks << endl;
				cout << "Existing decks : " << EnemyDecks << endl;

				cout << "==================" << endl;

				if (EnemyKilledDecks == EnemyDecks)
				{
					cout << endl << endl << endl << endl << endl << "                                             Game over. You win !                 " << endl;
					//go = false;
					break;
					return 0;
				}

				cout << "---------------------------------------------------SeaBattle------------------------------------------------------------" << endl << endl;

				cout << "(Note : 0 - WarShadow; 1 - PlayerDeck; 2 - HitDeck; 3 - Miss;)" << endl << endl << endl;

				cout << "   PLAYER BATTLEFIELD :              ENEMY BATTLEFIELD :" << endl << endl;
				cout << "   0 1 2 3 4 5 6 7 8 9" << "           " << "    0 1 2 3 4 5 6 7 8 9" << endl;
				cout << "   = = = = = = = = = =" << "           " << "    = = = = = = = = = =" << endl;

				for (int i = 0; i < N; i++)
				{
					cout << i << "| ";
					for (int j = 0; j < N; j++)
					{
						cout << Playermap[i][j] << " ";
					}
					cout << "           ";

					cout << i << "| ";
					for (int j = 0; j < N; j++)
					{
						//cout << Enemymap[i][j] << " ";
						cout << WarShadow[i][j] << " ";
					}
					cout << endl;
				}

			}
			else
			{
				cout << endl << "Your attack :" << endl;
				cout << "miss !" << endl << endl;
				//Enemymap[x][y] = 3;

				if (WarShadow[x][y] != 2 or WarShadow[x][y] != 3)
				{
					WarShadow[x][y] = 3;
				}

				cout << "---------------------------------------------------SeaBattle------------------------------------------------------------" << endl << endl;

				cout << "(Note : 0 - WarShadow; 1 - PlayerDeck; 2 - HitDeck; 3 - Miss;)" << endl << endl << endl;

				cout << "   PLAYER BATTLEFIELD :              ENEMY BATTLEFIELD :" << endl << endl;
				cout << "   0 1 2 3 4 5 6 7 8 9" << "           " << "    0 1 2 3 4 5 6 7 8 9" << endl;
				cout << "   = = = = = = = = = =" << "           " << "    = = = = = = = = = =" << endl;

				for (int i = 0; i < N; i++)
				{
					cout << i << "| ";
					for (int j = 0; j < N; j++)
					{
						cout << Playermap[i][j] << " ";
					}
					cout << "           ";

					cout << i << "| ";
					for (int j = 0; j < N; j++)
					{
						//cout << Enemymap[i][j] << " ";
						cout << WarShadow[i][j] << " ";
					}
					cout << endl;
				}

			}
		}



		// атака компьютера 

		int x1, y1;

		x = 0;
		y = 0;

		x = 0 + rand() % N;
		y = 0 + rand() % N;

		bool inputPC = 1;

		if (Playermap[x][y] == 2 or Playermap[x][y] == 3)
		{
			inputPC = 0;
		}

		if (PlayerKilledDecks == PlayerDecks)
		{
			cout << endl << endl << endl << endl << endl << "                                             Game over. You loose !                 " << endl;
			//go = 0;
			break;
			return 0;
		}

		if (inputPC == 1)
		{
			if (Playermap[y][x] == 1)
			{
				cout << endl << "Enemy atack :" << endl;
				cout << "hit !" << endl << endl;

				Playermap[x][y] = 2;
				PlayerKilledDecks++;

				cout << "Killed decks : " << PlayerKilledDecks << endl;
				cout << "Existing decks : " << PlayerDecks << endl;

				cout << "==================" << endl;

				if (PlayerKilledDecks == PlayerDecks)
				{
					cout << endl << endl << endl << endl << endl << "                                             Game over. You loose !                 " << endl;
					//go = 0;
					break;
					return 0;
				}

				system("pause");
				system("cls");

				cout << "---------------------------------------------------SeaBattle------------------------------------------------------------" << endl << endl;

				cout << "(Note : 0 - WarShadow; 1 - PlayerDeck; 2 - HitDeck; 3 - Miss;)" << endl << endl << endl;

				cout << "   PLAYER BATTLEFIELD :              ENEMY BATTLEFIELD :" << endl << endl;
				cout << "   0 1 2 3 4 5 6 7 8 9" << "           " << "    0 1 2 3 4 5 6 7 8 9" << endl;
				cout << "   = = = = = = = = = =" << "           " << "    = = = = = = = = = =" << endl;

				for (int i = 0; i < N; i++)
				{
					cout << i << "| ";
					for (int j = 0; j < N; j++)
					{
						cout << Playermap[i][j] << " ";
					}
					cout << "           ";

					cout << i << "| ";
					for (int j = 0; j < N; j++)
					{
						//cout << Enemymap[i][j] << " ";
						cout << WarShadow[i][j] << " ";
					}
					cout << endl;
				}
				//system("cls");

			}
			else
			{
				cout << endl << "Enemy atack :" << endl;
				cout << "miss !" << endl << endl;

				if (Playermap[x][y] = !2 or Playermap[x][y] != 3)
				{
					Playermap[x][y] = 3;
				}


				system("pause");
				system("cls");

				cout << "---------------------------------------------------SeaBattle------------------------------------------------------------" << endl << endl;

				cout << "(Note : 0 - WarShadow; 1 - PlayerDeck; 2 - HitDeck; 3 - Miss;)" << endl << endl << endl;

				cout << "   PLAYER BATTLEFIELD :              ENEMY BATTLEFIELD :" << endl << endl;
				cout << "   0 1 2 3 4 5 6 7 8 9" << "           " << "    0 1 2 3 4 5 6 7 8 9" << endl;
				cout << "   = = = = = = = = = =" << "           " << "    = = = = = = = = = =" << endl;

				for (int i = 0; i < N; i++)
				{
					cout << i << "| ";
					for (int j = 0; j < N; j++)
					{
						cout << Playermap[i][j] << " ";
					}
					cout << "           ";

					cout << i << "| ";
					for (int j = 0; j < N; j++)
					{
						//cout << Enemymap[i][j] << " ";
						cout << WarShadow[i][j] << " ";
					}
					cout << endl;
				}
				//system("cls");
			}
		}
	}


	system("pause");
	return 0;
}
