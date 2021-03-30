#include <stdio.h>
#include <math.h>
#include "chess.h"

int x_pom, y_pom;
int chessboard[L][L];

void podmienky(int i, int j)
{
	if (chessboard[i][j] == -1)
	{
		printf("[p]");
	}
	if (chessboard[i][j] == -2)
	{
		printf("[v]");
	}
	if (chessboard[i][j] == -3)
	{
		printf("[j]");
	}
	if (chessboard[i][j] == -4)
	{
		printf("[s]");
	}
	if (chessboard[i][j] == -5)
	{
		printf("[d]");
	}
	if (chessboard[i][j] == -6)
	{
		printf("[k]");
	}
	if (chessboard[i][j] == 1)
	{
		printf("[P]");
	}
	if (chessboard[i][j] == 2)
	{
		printf("[V]");
	}
	if (chessboard[i][j] == 3)
	{
		printf("[J]");
	}
	if (chessboard[i][j] == 4)
	{
		printf("[S]");
	}
	if (chessboard[i][j] == 5)
	{
		printf("[D]");
	}
	if (chessboard[i][j] == 6)
	{
		printf("[K]");
	}
	if (chessboard[i][j] == 0)
	{
		printf("[ ]");
	}

}

void print_chessboard()
{
	int  i;
	int  j;
	int x = 1;
	for (int i = 1; i <= 8; i++)
	{
		printf("%d ", x);
		x++;
		for (int j = 1; j <= 8; j++)
		{
			
			podmienky(i, j);
		}
		printf("\n");
	}
	printf("   a  b  c  d  e  f  g  h");
}
void init()
{
	for (int i = 2; i < 3; i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			chessboard[i][j] = -1;
		}
	}
	for (int i = 7; i < 8; i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			chessboard[i][j] = 1;
		}
	}
	chessboard[1][1] = -2;
	chessboard[1][8] = -2;
	chessboard[1][2] = -3;
	chessboard[1][7] = -3;                         // CIERNE FIGURKY
	chessboard[1][3] = -4;
	chessboard[1][6] = -4;
	chessboard[1][4] = -5;
	chessboard[1][5] = -6;
	chessboard[8][1] = 2;
	chessboard[8][8] = 2;
	chessboard[8][2] = 3;
	chessboard[8][7] = 3;                          // BIELE FIGURKY
	chessboard[8][3] = 4;
	chessboard[8][6] = 4;
	chessboard[8][4] = 5;
	chessboard[8][5] = 6;
}
void pohyb(int srow, int scol, int trow, int tcol, int H)
{
	int v = vertpodmienka(trow, tcol, srow, scol);
	int d = diagpodmienka(trow, tcol, srow, scol);
	scol = scol - 96;
	tcol = tcol - 96;
	if (scol > 8 || scol < 1 || srow>8 || srow < 1 || tcol>8 || tcol < 1 || scol>8 || scol < 1)
	{
		printf("\nNEPLATNY VSTUP\n");

	}
	else
	{
		if (H == 0)
		{
			if (chessboard[trow][tcol] <= 0)
			{
				if (chessboard[srow][scol] == 1 && v == 1)
				{
					if (trow == srow - 1 && scol == tcol)
					{
						chessboard[srow][scol] = 0;
						chessboard[trow][tcol] = 1;
					}
					else if (chessboard[trow][tcol] < 0)
					{
						chessboard[srow][scol] = 0;
						chessboard[trow][tcol] = 1;
					}
					else if (srow == 7 && scol == tcol)
					{
						chessboard[srow][scol] = 0;
						chessboard[trow][tcol] = 1;
					}
					else
					{
						printf("\nNEPLATNY VSTUP\n");
					}
				}
				else if (chessboard[srow][scol] == 2 && v == 1)
				{
					if (trow == srow || tcol == scol)
					{
						chessboard[srow][scol] = 0;
						chessboard[trow][tcol] = 2;
					}
					else
						printf("\nNEPLATNY VSTUP\n");

				}
				else if (chessboard[srow][scol] == 3)
				{
					if ((srow + 2 == trow) || (srow - 2 == trow) && (scol + 1 == tcol) || (scol - 1 == tcol))
					{
						chessboard[srow][scol] = 0;
						chessboard[trow][tcol] = 3;
					}
					else if ((scol + 2 == tcol) || (scol - 2 == tcol) && (srow + 1 == trow) || (srow - 1 == trow))
					{
						chessboard[srow][scol] = 0;
						chessboard[trow][tcol] = 3;
					}
					else
						printf("\nNEPLATNY VSTUP\n");
				}
				
				else if (chessboard[srow][scol] == 4 && d == 1)
				{
					if (trow > srow)
					{
						x_pom = trow - srow;
					}
					else if (srow > trow)
					{
						x_pom = srow - trow;
					}
					if (tcol > scol)
					{
						y_pom = tcol - scol;
					}
					else if (scol > tcol)
					{
						y_pom = scol - tcol;
					}
					if (x_pom == y_pom)
					{
						chessboard[srow][scol] = 0;
						chessboard[trow][tcol] = 4;
					}

					else
						printf("\nNEPLATNY VSTUP\n");

				}
				else if (chessboard[srow][scol] == 5 && v==1 && d==1)
				{

					if (trow > srow)
					{
						x_pom = trow - srow;
					}
					else if (srow > trow)
					{
						x_pom = srow - trow;
					}
					if (tcol > scol)
					{
						y_pom = tcol - scol;
					}
					else if (scol > tcol)
					{
						y_pom = scol - tcol;
					}
					if (x_pom == y_pom || trow == srow || tcol == scol)
					{
						chessboard[srow][scol] = 0;
						chessboard[trow][tcol] = 5;
					}
					else
						printf("\nNEPLATNY VSTUP\n");
				}
				else if (chessboard[srow][scol] == 6)
				{
					int x_plu = srow + 1;
					int x_min = srow - 1;
					int y_plu = scol + 1;
					int y_min = scol - 1;

					if (x_plu == trow || x_min == trow || srow == trow && y_plu == tcol || y_min == tcol || scol == tcol)
					{
						chessboard[srow][scol] = 0;
						chessboard[trow][tcol] = 6;
					}
					else
						printf("\nNEPLATNY VSTUP\n");

				}
				else
					printf("\nNEPLATNY VSTUP\n");

			}
			else
			printf("\nNEPLATNY VSTUP\n");
		}
		else if (H == 1)
		{
			if (chessboard[trow][tcol] >= 0)
			{
				if (chessboard[srow][scol] == -1 )
				{
					if (trow == srow + 1 && scol == tcol && chessboard[trow][tcol] == 0)
					{
						chessboard[srow][scol] = 0;
						chessboard[trow][tcol] = -1;
					}
					else if (chessboard[trow][tcol] > 0)
					{
						chessboard[srow][scol] = 0;
						chessboard[trow][tcol] = -1;
					}
					else if (srow == 2 && scol == tcol)
					{
						chessboard[srow][scol] = 0;
						chessboard[trow][tcol] = -1;
					}
					else
					{
						printf("\nNEPLATNY VSTUP\n");
					}
				}
				else if (chessboard[srow][scol] == -2 && v == 1 )
				{
					if (trow == srow || tcol == scol)
					{
						chessboard[srow][scol] = 0;
						chessboard[trow][tcol] = -2;
					}
					else
						printf("\nNEPLATNY VSTUP\n");

				}
				else if (chessboard[srow][scol] == -3)
				{
					if ((srow + 2 == trow) || (srow - 2 == trow) && (scol + 1 == tcol) || (scol - 1 == tcol))
					{
						chessboard[srow][scol] = 0;
						chessboard[trow][tcol] = -3;
					}
					else if ((scol + 2 == tcol) || (scol - 2 == tcol) && (srow + 1 == trow) || (srow - 1 == trow))
					{
						chessboard[srow][scol] = 0;
						chessboard[trow][tcol] = -3;
					}
					else
						printf("\nNEPLATNY VSTUP\n");
				}
				else if (chessboard[srow][scol] == -4 && d==1)
				{
					if (trow > srow)
					{
						x_pom = trow - srow;
					}
					else if (srow > trow)
					{
						x_pom = srow - trow;
					}
					if (tcol > scol)
					{
						y_pom = tcol - scol;
					}
					else if (scol > tcol)
					{
						y_pom = scol - tcol;
					}
					if (x_pom == y_pom)
					{
						chessboard[srow][scol] = 0;
						chessboard[trow][tcol] = -4;
					}

					else
						printf("\nNEPLATNY VSTUP\n");

				}
				else if (chessboard[srow][scol] == -5 && v == 1 && d == 1)
				{

					if (trow > srow)
					{
						x_pom = trow - srow;
					}
					else if (srow > trow)
					{
						x_pom = srow - trow;
					}
					if (tcol > scol)
					{
						y_pom = tcol - scol;
					}
					else if (scol > tcol)
					{
						y_pom = scol - tcol;
					}
					if (x_pom == y_pom || trow == srow || tcol == scol)
					{
						chessboard[srow][scol] = 0;
						chessboard[trow][tcol] = -5;
					}
					else
						printf("\nNEPLATNY VSTUP\n");
				}
				else if (chessboard[srow][scol] == -6 )
				{
					int x_plu = srow + 1;
					int x_min = srow - 1;
					int y_plu = scol + 1;
					int y_min = scol - 1;

					if (x_plu == trow || x_min == trow || srow == trow && y_plu == tcol || y_min == tcol || scol == tcol)
					{
						chessboard[srow][scol] = 0;
						chessboard[trow][tcol] = -6;
					}
					else
						printf("\nNEPLATNY VSTUP\n");

				}
				else 
					printf("\nNEPLATNY VSTUP\n");
			}
			else
				printf("\nNEPLATNY VSTUP\n");

		}
	}
}
int vertpodmienka(int srow, int scol, int trow, int tcol)
{
	scol = scol - 96;
	tcol = tcol - 96;
	int x = trow - srow;
	int y = scol - tcol;
	if (abs(x) < abs(y))
	{
		
		if (y > 0)
		{
			while (y != 1)
			{
				if (chessboard[trow][scol - y+1] == 0)
					y--;
				else 
					return 0;
					
			}
		}
		else if (y < 0)
		{
			while (y != -1)
			{
				if (chessboard[trow][scol + y-1] == 0)
					y++;
				else
					return 0;

			}
		}
	}
	else if (abs(x) > abs(y))
	{
		
		if (x > 0)
		{
			while (x != 1)
			{
				if (chessboard[srow + x-1][tcol] == 0)
					x--;
				else
					return 0;

			}
		}
		else if (x < 0)
		{
			while (x != -1)
			{
				if (chessboard[srow - x+1][tcol] == 0)
					x++;
				else
					return 0;

			}
		}
	}
	return 1;
}
int diagpodmienka(int trow, int tcol, int srow, int scol)
{
	scol = scol - 96;
	tcol = tcol - 96;
	int x = trow - srow;
	int y = scol - tcol;

	if (x < 0 && y>0)
	{
		while (x != -1 && y != 1)
		{

			if (chessboard[trow + abs(x) -1][tcol + y - 1] == 0)
			{
				x++;
				y--;
			}
			else
				return 0;
		}
	}
	else if (x < 0 && y < 0)
	{
		while (x != -1 && y != -1)
		{
			if (chessboard[trow + abs(x) - 1][tcol - abs(y) + 1] == 0)
			{
				x++;
				y++;
			}
			else
				return 0;
		}
	}
	else if (x > 0 && y > 0)
	{
		while (x != 1 && y != 1)
		{

			if (chessboard[trow - x + 1][tcol + y - 1] == 0)
			{
				x--;
				y--;
			}
			else
				return 0;
		}
	}
	else if (x > 0 && y < 0)
	{
		while (x != 1 && y != -1)
		{

			if (chessboard[trow - abs(x) + 1][tcol - abs(y) + 1] == 0)
			{
				x--;
				y++;
			}
			else
				return 0;
		}
	}
	
	return 1;
}
