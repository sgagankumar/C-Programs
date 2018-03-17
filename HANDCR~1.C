#include <stdio.h>
#include <conio.h>

#define max 6
int myscore,pcscore,toss,mychoice,pcchoice,ball,out,remain;

int generate();
int enterscreen();
void pcBattingFirst();
void meBattingFirst();
void pcBattingSecond();
void meBattingSecond();

void main()
{
	clrscr();
	toss=enterscreen();
	getch();
	if(toss==0)   //pc batting first
	{
		ball=0;
		out=0;
		pcBattingFirst();
		out=0;
		ball=0;
		meBattingSecond();
		if(out==1)
		{	
			clrscr();
			printf("\n\n\t\t PC WINS...!!!\n\n\t\tby %d runs",remain);
		}
		else
		{	
			clrscr();
			printf("\n\n\t\t YOU WIN...!!\n\n\t\tbeating target %d runs",pcscore);
		}
	}
	else
	{
		ball=0;
		out=0;
		meBattingFirst();
		out=0;
		ball=0;
		pcBattingSecond();
		if(out==1)
		{	
			clrscr();
			printf("\n\n\t\t YOU WIN...!!!\n\n\t\tby %d runs",remain);
		}
		else
		{	
			clrscr();
			printf("\n\n\t\t PC WINS...!!\n\n\t\tbeating target %d runs",myscore);
		}
	}
	getch();

}

int generate()
{
	int x;
	x=rand()%max;
	return(x+1);
}

int enterscreen()
{
	int x,y,c;
	printf("\n\tWELCOME TO HAND CRICKET SIMULATOR\n\n\t\tEnter to continue...");
	getch();
	clrscr();
	printf("\n\t\t\t----RULES----\n\n\tYour choice must be in between 1-%d",max);
	getch();
	clrscr();
	fflush(stdin);
	printf("\nCall the toss..\n1.Heads\t2.Tails\n\nYour choice(1,2)=");
	scanf("%d",&x);
	if(x==1)
		printf("\nYou have choosen Heads.");
	else
		printf("\nYou have choosen Tails.");
	y=rand()%2;
	y++;
	if(y==1)
		printf("\nThe result was Heads, ");
	else
		printf("\nThe result was Tails, ");
	if(x!=y)
	{
		printf("\nYou have lost, the PC chooses to bat first.");
		return 0;
	}
	else
	{
		printf("\nWould you like to bat or ball first?");
		printf("\n1.Bat\t2.Ball\nYour Choice=");
		scanf("%d",&c);
	}
	if(c==1)
		return 1;
	else
		return 0;

}

void pcBattingFirst()
{     
	clrscr();
	fflush(stdin);
	while(out==0)
	{
		clrscr();
		printf("\t\tPC is BATTING..\n");
		printf("RUNS : %d\tOvers : %d.%d",pcscore,(ball/6),(ball%6));
		ball++;
		printf("\n\nYour Choice :: ");
		fflush(stdin);
		scanf("%d",&mychoice);
		pcchoice=generate();
		printf("\nPC's Choice :: %d",pcchoice);
		if(mychoice==pcchoice)
		{
			out=1;
		}
		else
		{
			pcscore+=pcchoice;
		}
		getch();
	}

}

void meBattingFirst()
{
	clrscr();
	fflush(stdin);
	while(out==0)
	{
		clrscr();
		printf("\t\tYOU ARE BATTING..\n");
		printf("RUNS : %d\tOvers : %d.%d",myscore,(ball/6),(ball%6));
		ball++;
		printf("\n\nYour Choice :: ");
		fflush(stdin);
		scanf("%d",&mychoice);
		pcchoice=generate();
		printf("\nPC's Choice :: %d",pcchoice);
		if(mychoice==pcchoice)
		{
			out=1;
		}
		else
		{
			myscore+=mychoice;
		}
		getch();
	}
}

void  meBattingSecond()
{
	clrscr();
	fflush(stdin);
	remain=pcscore;
	while(out==0&&remain>=0)
	{
		clrscr();
		printf("\t\tYOU ARE BATTING..\n");
		printf("RUNS : %d\tOvers : %d.%d",myscore,(ball/6),(ball%6));
		ball++;
		printf("\tTarget : %d\tRun required : %d",pcscore,remain);
		printf("\n\nYour Choice :: ");
		fflush(stdin);
		scanf("%d",&mychoice);
		pcchoice=generate();
		printf("\nPC's Choice :: %d",pcchoice);
		if(mychoice==pcchoice)
		{
			out=1;
		}
		else
		{
			myscore+=mychoice;
			remain=remain-mychoice;
		}
		getch();
	}
}

void  pcBattingSecond()
{
	clrscr();
	fflush(stdin);
	remain=myscore;
	while(out==0&&remain>=0)
	{
		clrscr();
		printf("\t\tPC ARE BATTING..\n");
		printf("RUNS : %d\tOvers : %d.%d",pcscore,(ball/6),(ball%6));
		ball++;
		printf("\tTarget : %d\tRun required : %d",myscore,remain);
		printf("\n\nYour Choice :: ");
		fflush(stdin);
		scanf("%d",&mychoice);
		pcchoice=generate();
		printf("\nPC's Choice :: %d",pcchoice);
		if(mychoice==pcchoice)
		{
			out=1;
		}
		else
		{
			pcscore+=pcchoice;
			remain=remain-mychoice;
		}
		getch();
	}
}