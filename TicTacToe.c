#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

# define size 3

int i,j;
char turn;
char board[(size*size)+1];

void initializeboard()
{
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
			board[(i*size)+j+1]='-';
	};
	turn='X';
}

void updateturn()
{
	if(turn=='X')
		turn ='O';
	else turn='X';
}


void printboard()
{
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
			printf("%c ",board[(i*size)+j+1]);
		printf("\n");
	};
}

int gameover()
{
	if((((board[1]==board[5])&&(board[5]==board[9]))||((board[3]==board[5])&&(board[5]==board[7])))&&(board[5]!='-'))
	{
		return 1;
	};
	for(i=0;i<size;i++)
		if(((board[(i*size)+1]==board[(i*size)+2])&&(board[(i*size)+2]==board[(i*size)+3])&&(board[(i*size)+1]!='-'))||((board[i+1]==board[i+4])&&(board[i+4]==board[i+7])&&(board[i+4]!='-')))
		{
			return 1;
		};
	for(i=1;i<10;i++)
		if(board[i]=='-')
			return 0;
	return 2;
}

void takeinput()
{
	printboard();
	int gridinp;
	printf("Player %c's Turn!\nEnter the Grid Number : \n",turn);
	scanf("%d",&gridinp);
	if((gridinp<1)||(gridinp>9)||(board[gridinp]!='-'))
	{
		printf("Invalid Input\n");
		return;
	}else
	{
		board[gridinp]=turn;
		updateturn();
		return;
	};
}

void main()
{
	initializeboard();
	printboard();
	printf("Press anything to start the game!\n",gameover());
	getch();
	while(gameover()==0)
	{
		takeinput();
	}
	updateturn();
	if(gameover()==2)
		printf("It's a DRAW!\n");
	else printf("Player %c has won the game!\n",turn);
	printboard();
	getch();
}



