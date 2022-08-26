#include <iostream>
#include <windows.h>
#include <fstream>
#include<string>
#include<conio.h>
#include<stdio.h>

using namespace std;
void option2()
{
	cout << "s for down movement of PACMAN " << endl;
	cout << "w for up movement of PACMAN " << endl;
	cout << "d for right movement of PACMAN " << endl;
	cout << "a for left movement of PACMAN " << endl;
	Sleep(1500);
	cout << "AND PRESSING ENTER " << endl;
	Sleep(1500);
	cout << "P is PACMAN" << endl;
	cout << "0 is BOUNDARY" << endl;
	cout << "        You CAN'T mover it " << endl;
	cout << "M is Enemy" << endl;
	cout << "        It will kill you if you 1 positon beyond from it in any direction" << endl;
	cout << "L is PowerPills" << endl;
	cout << "        Boost life by one and for next 6 moves of PACMAN, PACMAN can kill M parmentaly" << endl;
}
void loading1()
{
	cout << "                     P     " << endl;
	Sleep(112);
	system("cls");
	cout << "                     P A     " << endl;
	Sleep(222);
	system("cls");
	cout << "                     P A C    " << endl;
	Sleep(332);
	system("cls");
	cout << "                     P A C M     " << endl;
	Sleep(122);
	system("cls");
	cout << "                     P A C M A     " << endl;
	Sleep(332);
	system("cls");
	cout << "                     P A C M A N     " << endl;
	Sleep(1332);
	cout << "                     L O A D I N G     " << endl;
	cout << "||||||  10%" << endl;
	Sleep(132);
	system("cls");
	cout << "||||||||||  15%" << endl;
	Sleep(332);
	system("cls");
	cout << "|||||||||||||||  25%" << endl;
	Sleep(132);
	system("cls");
	cout << "|||||||||||||||||||||||||  35%" << endl;
	Sleep(432);
	system("cls");
	cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||| 80%    " << endl;
	Sleep(1132);
	system("cls");
	cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||| 90%    " << endl;

	Sleep(1132);
	system("cls");
	cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||| 100%  O K    " << endl;
	Sleep(1132);
	system("cls");
	cout << "1- GAME" << endl; Sleep(332);
	cout << "2- ABOUT" << endl; Sleep(332);
	cout << "3- HOW TO PLAY" << endl; Sleep(332);
	cout << "x- Cancal" << endl; Sleep(332);
}
void loading2()
{
	cout << "                     P     " << endl;
	Sleep(112);
	system("cls");
	cout << "                     P A     " << endl;
	Sleep(222);
	system("cls");
	cout << "                     P A C    " << endl;
	Sleep(332);
	system("cls");
	cout << "                     P A C M     " << endl;
	Sleep(122);
	system("cls");
	cout << "                     P A C M A     " << endl;
	Sleep(332);
	system("cls");
	cout << "                     P A C M A N     " << endl;
	Sleep(1332);
	cout << "                     L O A D I N G     " << endl;
	Sleep(332);
	cout << "1- Resume" << endl; Sleep(332);
	cout << "2- ABOUT" << endl; Sleep(332);
	cout << "3- HOW TO PLAY" << endl; Sleep(332);
	cout << "x- Cancal" << endl; Sleep(332);
}
void filingH(int score)
{
	int numH[5];
	ifstream Hfile;
	Hfile.open("data.txt");
	for (int i = 0; i<5; i++)
	{
		Hfile >> numH[i];

	}//reading
	for (int i = 0; i<5; i++)
	{
		if (score>numH[i])
		{
			numH[i] = score;
			break;

		}

	}
	for (int i = 0; i<5; i++)
	{
		if (score == numH[i])
		{
			cout << i + 1 << "- " << numH[i] << "    <= RECENTLY ADDED" << endl;
		}
		else if (score != numH[i])
		{
			cout << i + 1 << "- " << numH[i] << endl;
		}


	}









}
void enemy(bool &fore, int &enemyi, int &enemyj, char ary[][17], int &life, bool &noloss)
{
	int pii;
	int pjj;
	if (fore == false)
	{
		for (int k = 0; k <= 10; k++)//determmine location of pacman again
		{
			for (int l = 0; l <= 16; l++)
			{
				if (ary[k][l] == 'P')
				{
					pii = k;
					pjj = l;


				}
			}

		}

		if (pii > enemyi)
		{
			if ((enemyi + 1 == pii) && (enemyj == pjj))
			{
				if (noloss == false)
				{

					life--;
					ary[pii][pjj] = ' ';
					ary[8][6] = 'P';
				}
				else if (noloss == true)
				{
					life++;
					ary[pii][pjj] = 'P';
					fore = true;

				}

			}
			if ((enemyi - 1 == pii) && (enemyj == pjj))
			{
				if (noloss == false)
				{

					life--;
					ary[pii][pjj] = ' ';
					ary[8][6] = 'P';
				}
				else if (noloss == true)
				{
					life++;
					ary[pii][pjj] = 'P';
					fore = true;
				}

			}
			if ((enemyi == pii) && (enemyj + 1 == pjj))
			{
				if (noloss == false)
				{

					life--;
					ary[pii][pjj] = ' ';
					ary[8][6] = 'P';
				}
				else if (noloss == true)
				{
					life++;
					ary[pii][pjj] = 'P';
					fore = true;
				}

			}
			if ((enemyi == pii) && (enemyj - 1 == pjj))
			{
				if (noloss == false)
				{

					life--;
					ary[pii][pjj] = ' ';
					ary[8][6] = 'P';
				}
				else if (noloss == true)
				{
					life++;
					ary[pii][pjj] = 'P';
					fore = true;
				}

			}
			if (ary[enemyi + 1][enemyj] == '0')
			{



				if (ary[enemyi][enemyj + 1] == '.')
				{
					enemyj++;
				}
				else if (ary[enemyi][enemyj + 1] == ' ')
				{
					enemyj++;
				}
				else if (ary[enemyi][enemyj + 1] == 'L')
				{
					enemyj++;
				}

			}
			else if (ary[enemyi + 1][enemyj] != '0')
			{

				if (ary[enemyi + 1][enemyj] == ' ')
				{
					enemyi++;
				}
				else if (ary[enemyi + 1][enemyj] == 'L')
				{
					enemyi++;
				}
				else if (ary[enemyi + 1][enemyj] == '.')
				{
					enemyi++;
				}

			}

		}
		else if (pii < enemyi)
		{
			if ((enemyi + 1 == pii) && (enemyj == pjj))
			{
				if (noloss == false)
				{

					life--;
					ary[pii][pjj] = ' ';
					ary[8][6] = 'P';
				}
				else if (noloss == true)
				{
					life++;
					ary[pii][pjj] = 'P';
					fore = true;
				}

			}
			if ((enemyi - 1 == pii) && (enemyj == pjj))
			{
				if (noloss == false)
				{

					life--;
					ary[pii][pjj] = ' ';
					ary[8][6] = 'P';
				}
				else if (noloss == true)
				{
					life++;
					ary[pii][pjj] = 'P';
					fore = true;
				}

			}
			if ((enemyi == pii) && (enemyj + 1 == pjj))
			{
				if (noloss == false)
				{

					life--;
					ary[pii][pjj] = ' ';
					ary[8][6] = 'P';
				}
				else if (noloss == true)
				{
					life++;
					ary[pii][pjj] = 'P';
					fore = true;
				}

			}
			if ((enemyi == pii) && (enemyj - 1 == pjj))
			{
				if (noloss == false)
				{

					life--;
					ary[pii][pjj] = ' ';
					ary[8][6] = 'P';
				}
				else if (noloss == true)
				{
					life++;
					ary[pii][pjj] = 'P';
					fore = true;
				}

			}
			if (ary[enemyi - 1][enemyj] == '0')
			{



				if (ary[enemyi][enemyj + 1] == '.')
				{
					enemyj++;
				}
				else if (ary[enemyi][enemyj + 1] == ' ')
				{
					enemyj++;
				}
				else if (ary[enemyi][enemyj + 1] == 'L')
				{
					enemyj++;
				}

			}
			else if (ary[enemyi - 1][enemyj] != '0')
			{

				if (ary[enemyi - 1][enemyj] == ' ')
				{
					enemyi--;
				}
				else if (ary[enemyi - 1][enemyj] == 'L')
				{
					enemyi--;
				}
				else if (ary[enemyi - 1][enemyj] == '.')
				{
					enemyi--;
				}

			}
		}
		else if (pii == enemyi)
		{
			if ((enemyi + 1 == pii) && (enemyj == pjj))
			{
				//if (noloss == false)
				if (noloss == false)
				{

					life--;
					ary[pii][pjj] = ' ';
					ary[8][6] = 'P';
				}
				else if (noloss == true)
				{
					life++;
					ary[pii][pjj] = 'P';
					fore = true;
				}


			}
			if ((enemyi - 1 == pii) && (enemyj == pjj))
			{
				if (noloss == false)
				{

					life--;
					ary[pii][pjj] = ' ';
					ary[8][6] = 'P';
				}
				else if (noloss == true)
				{
					life++;
					ary[pii][pjj] = 'P';
					fore = true;


				}
			}
			if ((enemyi == pii) && (enemyj + 1 == pjj))
			{
				if (noloss == false)
				{

					life--;
					ary[pii][pjj] = ' ';
					ary[8][6] = 'P';
				}
				else if (noloss == true)
				{
					life++;
					ary[pii][pjj] = 'P';
					fore = true;


				}
			}
			if ((enemyi == pii) && (enemyj - 1 == pjj))
			{
				if (noloss == false)
				{

					life--;
					ary[pii][pjj] = ' ';
					ary[8][6] = 'P';
				}
				else if (noloss == true)
				{
					life++;
					ary[pii][pjj] = 'P';
					fore = true;


				}
			}


			if (pjj > enemyj)
			{
				if (ary[enemyi][enemyj + 1] != '0')
				{

					if (ary[enemyi][enemyj + 1] == ' ')
					{
						enemyj++;

					}
					else if (ary[enemyi][enemyj + 1] == '.')
					{
						enemyj++;

					}
					else if (ary[enemyi][enemyj + 1] == 'M')
					{
						enemyj++;

					}

					//adddinfsfgfdfghgfd
				}
				else if (ary[enemyi][enemyj + 1] == '0')
				{
					if (ary[enemyi + 1][enemyj] != '0')
					{

						if (ary[enemyi + 1][enemyj] == ' ')
						{
							enemyi++;
						}
						else if (ary[enemyi + 1][enemyj] == ' ')
						{
							enemyi++;
						}
					}
				}
			}
			else if (pjj < enemyj)
			{
				if (ary[enemyi][enemyj - 1] != '0')
				{

					if (ary[enemyi][enemyj - 1] == ' ')
					{
						enemyj--;

					}
					else if (ary[enemyi][enemyj + 1] == '.')
					{
						enemyj--;

					}



				}
				else if (ary[enemyi][enemyj + 1] == '0')
				{
					if (ary[enemyi - 1][enemyj] != '0')
					{

						if (ary[enemyi - 1][enemyj] == ' ')
						{
							enemyi--;
						}
						else if (ary[enemyi - 1][enemyj] == ' ')
						{
							enemyi--;
						}
					}
				}
			}
		}
	}
}
int main()
{


	ifstream file("dell.txt");//file handling
	char ary[11][17];

	for (int k = 0; k <= 10; k++)
	{
		for (int l = 0; l <= 16; l++)
		{
			file >> ary[k][l];
		}
	}



	file.end;//file handling


	char opr = '0';
	int pii;
	int pjj;


	int e1i = 1;
	int e1j = 1;
	int e2i = 8;
	int e2j = 12;
	char mainopr;
	bool continu = true;
	bool resumee = false;
	bool noloss = false;
	int count = 0;
	int warning = 0;
	bool noanmy = false;
	bool fore1 = false;
	bool fore2 = false;
	int score = 0;
	int life = 3;
	string name;

	cout << "Enter Your Name " << endl;
	cin >> name;
	while (mainopr = 'x')
	{


		if (resumee == false)
		{
			loading1();
		}
		else if (resumee == true)
		{
			loading2();
		}

		cin >> mainopr;

		if (mainopr == '1')
		{
			continu = true;

			for (int k = 0; k <= 10; k++)
			{
				for (int l = 0; l <= 16; l++)
				{
					cout << ary[k][l];
				}
				cout << endl;

			}
			while (continu == true)
			{



				opr = _getch();
				if ((opr == 'x') || (life<0) || (score >= 228))

				{

					resumee = true;
					cout << name << " score " << score << endl;
					filingH(score);
					Sleep(3333);
					continu = false;

				}//game check and high score

				if (noloss == true)
				{
					count++;
				}
				if (count > 6)
				{
					noloss = false;

				}
				for (int pi = 0; pi <= 10; pi++)//pacman starting
				{
					for (int pj = 0; pj <= 16; pj++)
					{
						if (ary[pi][pj] == 'P')
						{


							if (opr == 'a')//left movement
							{
								if (ary[pi][pj - 1] == '0')
								{
									warning++;
								}

								else if (ary[pi][pj - 1] != '0')//!0
								{

									if (ary[pi][pj - 1] == ' ')
									{

										ary[pi][pj] = ' ';
										ary[pi][pj - 1] = 'P';
									}
									else if (ary[pi][pj - 1] == '.')
									{
										score += 2;
										ary[pi][pj] = ' ';
										ary[pi][pj - 1] = 'P';
									}
									else if (ary[pi][pj - 1] == 'L')
									{
										ary[pi][pj] = ' ';
										ary[pi][pj - 1] = 'P';
										score += 10;
										noloss = true;
									}
								}
								break;

							}
							else if (opr == 's')//down
							{
								if (ary[pi + 1][pj] == '0')
								{
									warning++;
								}
								else if (ary[pi + 1][pj] != '0')
								{
									if (ary[pi + 1][pj] == '.')
									{
										score += 2;
										ary[pi][pj] = ' ';
										ary[pi + 1][pj] = 'P';
									}
									else if (ary[pi + 1][pj] == ' ')
									{

										ary[pi][pj] = ' ';
										ary[pi + 1][pj] = 'P';
									}
									else if (ary[pi + 1][pj] == 'L')
									{
										score += 10;
										noloss = true;
										ary[pi][pj] = ' ';
										ary[pi + 1][pj] = 'P';
								
									}
									
								}
								break;
							}
							else if (opr == 'd')//right
							{
								if (ary[pi][pj + 1] == '0')
								{
									warning++;
								}
								else if (ary[pi][pj + 1] != '0')
								{
									if (ary[pi][pj + 1] == '.')
									{
										score += 2;
										ary[pi][pj] = ' ';
										ary[pi][pj + 1] = 'P';
									}
									else if (ary[pi][pj + 1] == ' ')
									{

										ary[pi][pj] = ' ';
										ary[pi][pj + 1] = 'P';
									}
									else if (ary[pi][pj + 1] == 'L')
									{
										score += 10;
										noloss = true;
										ary[pi][pj] = ' ';
										ary[pi][pj + 1] = 'P';
									}
								}
								break;

							}
							else if (opr == 'w')//ip
							{
								if (ary[pi - 1][pj] == '0')
								{
									warning++;
								}
								else if (ary[pi - 1][pj] != '0')
								{
									if (ary[pi - 1][pj] == '.')
									{
										score += 2;
										ary[pi][pj] = ' ';
										ary[pi - 1][pj] = 'P';
									}
									else if (ary[pi - 1][pj] == ' ')
									{

										ary[pi][pj] = ' ';
										ary[pi - 1][pj] = 'P';
									}
									else if (ary[pi - 1][pj] == 'L')
									{
										score += 10;
										noloss = true;
										ary[pi][pj] = ' ';
										ary[pi - 1][pj] = 'P';
									}
								}
								break;
							}
						}

					}
				}
				enemy(fore1, e1i, e1j, ary, life, noloss);//1
				enemy(fore2, e2i, e2j, ary, life, noloss);//2
				system("cls");

				if ((fore1 == true) && (fore2 == true))
				{
					noanmy = true;

				}
				if (noanmy == true)
				{
					for (int gli = 0; gli <= 10; gli++)
					{
						for (int glj = 0; glj <= 16; glj++)
						{
							cout << ary[gli][glj];
						}
						cout << endl;
					}

				}
				//start
				if ((fore1 == false) || (fore2 == false))
				{

					for (int finali = 0; finali <= 10; finali++)
					{
						for (int finalj = 0; finalj <= 16; finalj++)
						{
							if ((finalj == e1j) && (finali == e1i))
							{
								if (fore1 == false)
								{
									cout << "M";
									for (int special = finalj + 1; special <= 16; special++)
									{
										cout << ary[finali][special];
									}
									break;
								}
							}
							if ((finalj == e2j) && (finali == e2i))
							{

								if (fore2 == false)
								{
									cout << "M";
									for (int special = finalj + 1; special <= 16; special++)
									{
										cout << ary[finali][special];
									}

									break;
								}
							}

							else
							{

								cout << ary[finali][finalj];
							}

						}
						cout << endl;

					}//loope

				}

				if (noloss == true)
				{
					cout << "                                                " << 6 - count << " SECOND" << endl;
					cout << "                                                NO LOSSING MODE" << endl;
				}
				else if (noloss == false)
				{
					cout << "                                                NORMAL MODE" << endl;
					count = 0;
				}
				cout << "                                                   Worng " << warning << endl;
				cout << "                                                   Life " << life << endl;
				cout << "                                                   Score " << score << endl;



			}



		}
		else if (mainopr == '2')
		{ 
			cout << "Credit" << endl;
			Sleep(1500);
			cout << "Huraira Tariq" << endl;
			Sleep(1500);
			cout << "Shahbaz Gondal" << endl;
		}
		else if (mainopr == '3')
		{

			option2();
		}
		else if (mainopr == 'x')
		{
			break;
		}

	}


	system("Pause");


}
