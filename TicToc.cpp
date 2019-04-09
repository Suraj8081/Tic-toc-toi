#include<iostream>
using namespace std;
char bord[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn='X';
int row, col,choice;
bool l=true;
void display()
{
	system("cls");
    cout<<"\t\t Welcome on Tic Toc Game\n\n";
	cout<<"\t Player1[X]\n \t Player2[O]\n\n";
	cout<<"\t\t  "<<bord[0][0]<<"  |  "<<bord[0][1]<<"  |  "<<bord[0][2]<<"   \n";
	cout<<"\t\t_____|_____|______\n";
	cout<<"\t\t  "<<bord[1][0]<<"  |  "<<bord[1][1]<<"  |  "<<bord[1][2]<<"   \n";
	cout<<"\t\t_____|_____|______\n";
	cout<<"\t\t  "<<bord[2][0]<<"  |  "<<bord[2][1]<<"  |  "<<bord[2][2]<<"   \n";
	cout<<"\t\t     |     |     \n";	
}
void playerTurn()
{
	if(turn=='X')
	{
		cout<<"Turn Palyer1[X]=";
		cin>>choice;
	}
	else  if(turn=='O')
	{
		cout<<"Turn Palyer2[O]=";
		cin>>choice;
	}
	switch(choice)
	{
		case 1:
		{
			row=0;
			col=0;
			break;
		}			
		case 2:
		{
			row=0;
			col=1;
			break;
		}
		case 3:
		{
			row=0;
			col=2;
			break;
		}
		case 4:
		{
			row=1;
			col=0;
			break;
		}	
		case 5:
		{
			row=1;
			col=1;
			break;
		}
		case 6:
		{
			row=1;
			col=2;
			break;
		}
		case 7:
		{
			row=2;
			col=0;
			break;
		}
		case 8:
		{
			row=2;
			col=1;
			break;
		}
		case 9:
		{
			row=2;
			col=2;
			break;
		}
		default:
			cout<<"You interd wrong number";
			break;								
	}
	if(turn=='X' && bord[row][col] !='X' && bord[row][col] !=  'O')
	{
		bord[row][col]='X';
		turn='O';
	}
	else if(turn=='O' && bord[row][col] !='X' && bord[row][col] !=  'O')
	{
		bord[row][col]='O';
		turn='X';
	}
	else
	{
		cout<<"\tThis field already fill!!!\n";
		playerTurn();
	}
}
bool gameOver()
{
	for(int j=0; j<3; j++)
	{
		if(bord[j][0]==bord[j][1] && bord[j][1]==bord[j][2])
		{
			return false;
		}
	}
	for(int j=0; j<3; j++)
	{
		if(bord[0][j]==bord[1][j] && bord[1][j]==bord[2][j])
		{
			return false;
		}
	}
	if(bord[0][0]==bord[1][1] && bord[1][1]==bord[2][2])
	{
		return false;
	}
	if(bord[0][2]==bord[1][1] && bord[1][1]==bord[2][0])
	{
		return false;
	}
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(bord[i][j] =='X' || bord[i][j] =='O')
			{
				if(i==2 && j==2)
				{
					turn='d';
					return false;
				}
			}
			else
			return true;
		}
	}
}
 main()
{
	while(l)
	{
		display();
		playerTurn();
		display();
	    l=gameOver();	
	    if(l==false && turn=='X')
	    {
	    	cout<<"Player2[O] win game!!!!";
		}
		if(l==false && turn=='O')
	    {
	    	cout<<"Player1[X] win game!!!!";
		}
		if(l==false && turn=='d')
	    {
	    	cout<<"Oop... game is graw!!!! \n plase play new game";
		}
	}
	
}
