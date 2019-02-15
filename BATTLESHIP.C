//Battle Ship board game simulator

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int p1[8][8];
int p2[8][8];
int datap1[3][5];
int datap2[3][5];
int hitp1[1][5];
int hitp2[1][5];

void makezero(int a[8][8]);
void set(int a[1][5]);
void introscreen();
void player_call(int i);
void display_layout(int a[8][8]);
void display_placement(int a[8][8]);
void clear_ship(int n,int a[8][8],int b[3][5]);
void print_char(int n);
void placeship(int n,int a[8][8],int b[3][5]);
void placeturn();





void makezero(int a[8][8])
{
	int i,j;
	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
		{
			a[i][j]=0;
			a[i][j]=0;
		}
}

void set(int a[1][5])
{
	a[0][0]=0;
	a[0][1]=5;
	a[0][2]=4;
	a[0][3]=3;
	a[0][4]=2;
}

void player_call(int i)
{
	if(i==1)
	{
		printf("****   *       ***   *   *  *****  ****     *  \n*   *  *      *   *   * *   *      *   *   **  \n*   *  *      *   *    *    *      *   *  * *  \n****   *      *****    *    *****  ****     *  \n*      *      *   *    *    *      * *      *  \n*      *      *   *    *    *      *  *     *  \n*      *****  *   *    *    *****  *   *  *****\n");
	}
	else
	{
		printf("****   *       ***   *   *  *****  ****    *** \n*   *  *      *   *   * *   *      *   *  *   *\n*   *  *      *   *    *    *      *   *     * \n****   *      *****    *    *****  ****     *  \n*      *      *   *    *    *      * *     *   \n*      *      *   *    *    *      *  *   *    \n*      *****  *   *    *    *****  *   *  *****\n");
	}
}

void display_layout(int a[8][8])
{
	
	int i,j;
	printf("    A   B   C   D   E   F   G   H  \n");
	for(i=0;i<8;i++)
	{
		printf("  +---+---+---+---+---+---+---+---+\n%d ",i+1);
		for(j=0;j<8;j++)
		{
			printf("|");
			if(a[i][j]/10==0||a[i][j]/10==1)
			{
				printf("   ");
			}
			else if(a[i][j]/10==2)
			{
				printf("HIT");
			}
			else
			{
				printf(" X ");
			}
		}
		printf("|\n");
	}
	printf("  +---+---+---+---+---+---+---+---+\n");

}

void display_placement(int a[8][8])
{
	
	int i,j;
	printf("    A   B   C   D   E   F   G   H  \n");
	for(i=0;i<8;i++)
	{
		printf("  +---+---+---+---+---+---+---+---+\n%d ",i+1);
		for(j=0;j<8;j++)
		{
			printf("|");
			if(a[i][j]/10==0)
			{
				printf("   ");
			}
			else if(a[i][j]/10==1)
			{
				printf(" %d ",a[i][j]%10);
			}
			
		}
		printf("|\n");
	}
	printf("  +---+---+---+---+---+---+---+---+\n");

}

void introscreen()
{
	char ch;
	clrscr();
	printf("*   * ***** *      ****  ***  *   * *****\t*****  *** \n*   * *     *     *     *   * ** ** *    \t  *   *   *\n*   * *     *     *     *   * * * * *    \t  *   *   *\n*   * ***** *     *     *   * *   * *****\t  *   *   *\n* * * *     *     *     *   * *   * *    \t  *   *   *\n** ** *     *     *     *   * *   * *    \t  *   *   *\n*   * ***** *****  ****  ***  *   * *****\t  *    *** \n");
	printf("\n\n****   ***  ***** ***** *     *****  ***  *   * ***** ****  \n*   * *   *   *     *   *     *     *   * *   *   *   *   * \n*   * *   *   *     *   *     *     *     *   *   *   *   * \n****  *****   *     *   *     *****  ***  *****   *   ****  \n*   * *   *   *     *   *     *         * *   *   *   *     \n*   * *   *   *     *   *     *     *   * *   *   *   *     \n****  *   *   *     *   ***** *****  ***  *   * ***** *     \n");
	printf("\n\n\t\tSTART? (Y/N) :");
	scanf("%c",&ch);
	if(ch=='n'||ch=='N')
		exit(0);
	clrscr();
}

void placeturn()
{
	char ch;
	int n,i;
	printf("\t\t\tPLAYER 1s TURN\n");
	printf("\tTime to place your battleships !!!\n");
	getch();
	for(i=1;i<5;i++)
	{
		printf("PLACE SHIP WHICH HAS SIZE %d\n",6-i);
		placeship(6-i,p1,datap1);
	}
	phase_11:
	display_placement(p1);
	printf("Would u like to change the position of any ship?.....(n/y)");
	scanf("%c",&ch);
	if(ch=='y'||ch=='Y')
	{
		printf("Enter the ship number which is to be:");
		scanf("%d",&n);
		clear_ship(n,p1,datap1);
		placeship(6-n,p1,datap1);
		goto phase_11;
	}
	getch();
	

	clrscr();
	printf("Pass to PLAYER 2..");
	getch();
	clrscr();
	printf("\t\t\tPLAYER 2s TURN\n");
	printf("\tTime to place your battleships !!!\n");
	for(i=1;i<5;i++)
	{
		printf("PLACE SHIP WHICH HAS SIZE %d\n",6-i);
		placeship(6-i,p2,datap2);
	}
	phase_12:
	display_placement(p2);
	printf("Would u like to change the position of any ship?.....(n/y)");
	scanf("%c",&ch);
	if(ch=='y'||ch=='Y')
	{
		printf("Enter the ship number which is to be:");
		scanf("%d",&n);
		clear_ship(n,p2,datap2);
		placeship(6-n,p2,datap2);
		goto phase_12;
	}

}




void placeship(int n,int a[8][8],int b[3][5])//n is size of ship
{
	 char ori, jj;
	 int o, ip, jp,l,p;
	 display_placement(a);
	 printf("Would you like to places ship horizontally or vertically?\n(h/v)");
	 scanf("%c",&ori);

	 if(ori=='h'||ori=='H')
	 {
		o=0;
		printf("Placing horizontally\n");
	 }
	 else
	 {
		o=1;
		printf("Placing vertically\n");
	 }
	 getch();
	 display_placement(a);
	 if(o==1)
	 {
	 	label_repeat1:
	 	printf("Enter the starting coordinate to place the ship of size %d\nrow(1-%d)=\t",n,9-n);
	 	scanf("%d",&ip);
	 	ip--;
	 	printf("col(a-h)=");
	 	scanf("%c",&jj);
	 	jp=jj-'a';
	 	if(ip>(9-n)||ip<0)
	 	{
	 		printf("Invalid position !!!\n");
 			goto label_repeat1;
 		}
 		else if(jp>8||jp<0)
 		{
 			printf("Invalid position !!!\n");
 			goto label_repeat1;
 		}
 		else
 		{
 			b[0][6-n]=o;
 			b[1][6-n]=ip;
 			b[2][6-n]=jp;
			for(l=1;l<=n;l++)
 			{
				a[ip][jp]=10+(6-n);
 				ip++;
 			}
 		}
	 }
	 else
	 {
	 	label_repeat2:
	 	printf("Enter the starting coordinate to place the ship of size %d\nrow(1-8)=\t",n);
	 	scanf("%d",&ip);
	 	ip--;
	 	printf("col(a-");
	 	print_char(n);
		printf(")=");
	 	scanf("%c",&jj);
	 	jp=jj-'a';
	 	if(ip>8||ip<0)
	 	{
	 		printf("Invalid position !!!\n");
 			goto label_repeat2;
 		}
 		else if(jp>(9-n)||jp<0)
 		{
 			printf("Invalid position !!!\n");
 			goto label_repeat2;
 		}
 		else
 		{
 			b[0][6-n]=o;
 			b[1][6-n]=ip;
 			b[2][6-n]=jp;
			for(l=1;l<=n;l++)
 			{
				a[ip][jp]=10+(6-n);
 				jp++;
 			}
 		}
	 }

}

void clear_ship(int n,int a[8][8],int b[3][5])
{
	int i,j,o,l;
	o=b[0][n];
	i=b[1][n];
	j=b[2][n];
	if(o==0)
	{
		for(l=1;l<(6-n);l++)
		{
			a[i][j]=0;
			j++;
		}
	}
	else if(o==1)
	{
		for(l=1;l<(6-n);l++)
		{
			a[i][j]=0;
			i++;
		}
	}
}

void print_char(int n)
{
	switch(n)
	{
		case 5: printf("d");
				break;
		case 4: printf("e");
				break;
		case 3: printf("f");
				break;
		case 2: printf("g");
				break;
	}
}







void main()
{
	int i,j;
	clrscr();
	introscreen();
	makezero(p1);
	makezero(p2);
	set(hitp1);
	set(hitp2);
	//void rules();
	placeturn();






	getch();
}
