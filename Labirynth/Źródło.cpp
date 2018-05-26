#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



int lucass(int* a, int i)
{
	if (i == 0)
	{
		a[i] = 2;
	}

	else if (i == 1)
	{
		a[i] = 1;
	}

	else if (i>1)
	{
		a[i] = a[i - 1] + a[i - 2];
	}
	return a[i];
}


int main()
{
	int lucas, i;
	printf("Ile liczb Lucasa wyswietlic?\n");
	scanf("%i", &lucas);
	//int l_tab[lucas];





	for (i = 0; i<lucas; i++)
	{
		//l_tab[i] = lucass(l_tab, i);
		//printf("%i ", l_tab[i]);
	}

	printf("\n");



	FILE *lab = fopen("LABIR17.txt", "r");
	FILE *labn = fopen("LABIR_NOWY.txt", "w");


	int warunek = 1;

	int x, y, obszar_x, obszar_y;
	char LABTAB[17][17];//4,1 start
	int powtorki[17][17];
	//while(!feof(lab))
	//{
	for (y = 0; y<17; y++)
	{
		for (x = 0; x<17; x++)
		{
			fscanf(lab, "%c ", &LABTAB[x][y]);
			powtorki[x][y] = 1;
			printf("%c ", LABTAB[x][y]);
		}
		printf("\n");
	}
	// }

	x = 1;
	y = 1;
	while (x != 13 || y != 15)
	{
		if (!((x<0 || x>17) || (y<0 || y>17)))
		{
			if ((LABTAB[x][y] != 'X'))
			{

				// if  (x!=4&&y!=6)
				// {

				LABTAB[x][y] = '.';

				if (LABTAB[x + 1][y] == '_')//||((LABTAB[x+1][y]=='.')&&(powtorki[x+1][y]==1)))
				{
					powtorki[x][y] = 1;
					x = x + 1;
					//printf("IDZIE W PRAWO\n");
				}
				else if (LABTAB[x - 1][y] == '_')//||((LABTAB[x-1][y]=='.')&&(powtorki[x-1][y]==1)))
				{
					powtorki[x][y] = 1;
					x = x - 1;
					//printf("IDZIE W LEWO\n");
				}
				else if (LABTAB[x][y - 1] == '_')//||((LABTAB[x][y-1]=='.')&&(powtorki[x][y-1]==1)))
				{
					powtorki[x][y] = 1;
					y = y - 1;
					//printf("IDZIE W GORE\n");

				}
				else if (LABTAB[x][y + 1] == '_')//||((LABTAB[x][y+1]=='.')&&(powtorki[x][y+1]==1)))
				{
					powtorki[x][y] = 1;
					y = y + 1;
					//printf("IDZIE W DOL\n");

				}
				else
				{
					powtorki[x][y] = 0;


					if ((LABTAB[x + 1][y] == '.') && (powtorki[x + 1][y] == 1))
					{
						x = x + 1;
						powtorki[x][y] = 0;
						//printf("IDZIE W PRAWO\n");
					}
					else if ((LABTAB[x - 1][y] == '.') && (powtorki[x - 1][y] == 1))
					{
						x = x - 1;
						powtorki[x][y] = 0;
						//printf("IDZIE W LEWO\n");
					}
					else if ((LABTAB[x][y - 1] == '.') && (powtorki[x][y - 1] == 1))
					{
						y = y - 1;
						powtorki[x][y] = 0;
						//printf("IDZIE W GORE\n");

					}
					else if ((LABTAB[x][y + 1] == '.') && (powtorki[x][y + 1] == 1))
					{
						y = y + 1;
						powtorki[x][y] = 0;
						//printf("IDZIE W DOL\n");
					}

				}
			}
			//  }
		}
	}

	printf("\n");
	for (y = 0; y<17; y++)
	{
		for (x = 0; x<17; x++)
		{
			fscanf(lab, "%c ", &LABTAB[x][y]);
			printf("%c ", LABTAB[x][y]);
		}
		printf("\n");
	}


	return 0;
}
