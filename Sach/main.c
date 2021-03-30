#include <stdio.h>
#include <math.h>
#include "chess.h"
void main()
{
	char p1, p2;
	int x1, x2;
	int H;
	init();
	print_chessboard();

	while (1 == 1)
	{
		H = 0;
		printf("\nTah bieleho hraca:");
		scanf_s(" %i", &x1);
		scanf_s(" %c", &p1);
		scanf_s(" %i", &x2);
		scanf_s(" %c", &p2);
		pohyb (x1,p1,x2,p2,H);
		print_chessboard();

		H = 1;
		printf("\nTah cierneho hraca:");
		scanf_s(" %i", &x1);
		scanf_s(" %c", &p1);
		scanf_s(" %i", &x2);
		scanf_s(" %c", &p2);
		pohyb(x1, p1, x2, p2, H);
		print_chessboard();
		
	}
}