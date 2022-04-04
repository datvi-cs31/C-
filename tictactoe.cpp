/*
	Project No 		: 1
	Programming language	: C++
	Project Name		: TicTacToe -cli
	Creator		: DaathwiNaagh (cs20b1031)
*/

// Conditional Compilation
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include<iostream>
#include<stdlib.h>
#define COL_NUM cout << "\t\t0\t1\t2\n"
#define BORDER1 cout << "\n"
#define NEW_LINE cout << endl
using namespace std;

/* Users (username, userCharecter) */
class users
{
	string uName;
	char uchar;
	friend class Board;
};

/* Board (users, choice, board[MATRIX]) */
class Board 
{
	private:
		users a[2];
		int choice;
		char A[3][3];

	public:
		Board()
		{
			cout << "Your Board is Ready \n\n";
			int i=0,j=0;
			for(i=0;i<3;i++) {
				for(j=0;j<3;j++) {
					A[i][j] = char(95);
				}
			}
		}
		
		// Member functions
		void displayGame();
		void help();
		int userInfo();
		int playGame(int &temp,int &count2);
		void showBoard();
		int checkDone(int t,int c);
};

void Board::displayGame()
{
	char ch = char(92);
	cout << " _____ _        _____            _____          " << endl;	
	cout << "|_   _(_) ___  |_   _|_ _  ___  |_   _|__   ___ " << endl;	
	cout << "  | | | |/ __|   | |/ _` |/ __|   | |/ _ "<< ch<<" / _ "<<ch<<endl;	
	cout << "  | | | | (__    | | (_| | (__    | | (_) |  __/" << endl;	
	cout << "  |_| |_|"<<ch<<"___|   |_|"<<ch<<"__,_|"<<ch<<"___|   |_|"<<ch<<"___/ "<<ch<<"___|"<<endl;	
}

/*  Board::checkDone();
    This function checks whether all rows or all columns or both diagonals 
    are filled with the same charecters or not
*/
int Board::checkDone(int t,int c)
{
	int i;
	bool b1, b2, b3, b4;

	b3 = (A[0][0]==A[1][1] && A[1][1]==A[2][2] && A[0][0]==a[t].uchar);
	b4 = (A[0][2]==A[1][1] && A[1][1]==A[2][0] && A[0][2]==a[t].uchar);
	
	for(i=0;i<3;i++)
	{
		b1 = A[i][0]==A[i][1] && A[i][1]==A[i][2] && A[i][0]==a[t].uchar;
		b2 = A[0][i]==A[1][i] && A[1][i]==A[2][i] && A[0][i]==a[t].uchar;
		if(b1||b2||b3||b4)
			return 1;
	}
	
	if(c == 9 && (b1||b2||b3||b4 == 0)) {
		cout << "The match is DRAW \n\n";
		showBoard();
	}
	
	return 0;
}

int Board::playGame(int &temp,int &count2)
{
	int rN, cN, win;
	bool b1, b2, b3;
	while(1)
	{
		cout << "\nCHOICE (TURN) :  (" << a[temp%2].uName << ")\n";
		showBoard();
		cout << "\n -> Enter Row No : ";
		cin >> rN;
		cout << " -> Enter Col No : ";
		cin >> cN;
		
		#ifdef __linux__
			system("clear");
		#elif __WIN32
			system("cls");
		#endif
		
		b1 = rN>=0 && rN<=2;
		b2 = cN>=0 && cN<=2; 
		b3 = b1 && b2;
		
		if(A[rN][cN]==char(95) && b3) {
			A[rN][cN] = a[temp%2].uchar;
			break;
		}
		else
			NEW_LINE;
	}
	
	win = checkDone(temp%2,count2);
	if(win==1)
	{
		cout << "\nCongratulations, " << a[temp%2].uName << endl;
		return 1;
	}	
	temp++;
	count2++;
	
	
	return 0;
}

// modification needed
void Board::showBoard()
{
	int i,j;
    cout << endl;
    cout << "\n\t\t(The BOARD)\n\n" << endl;
	COL_NUM;
	cout << "\t-----------------------------\n";
	cout << endl;
	for(i=0;i<3;i++) {
		cout << "\t"<< i <<"\t";
		for(j=0;j<3;j++) {
			cout << A[i][j] << "\t";
		}
		cout << endl << endl;
	}
	
	cout << endl;
}

int Board::userInfo()
{
	#ifdef __linux__
		system("clear");
	#elif __WIN32
		system("cls");
	#endif
		
	cout << "\n\n\t\t\t\t (USER INFORMATION)\n";
	
	while(1)
	{
		for(int i=0;i<2;i++) 
		{
			cout << "PLAYER " << i+1;
			NEW_LINE;
			NEW_LINE;
			cout << " -> Name   : ";
			cin >> a[i].uName;
			cout << " -> Symbol : ";
			cin >> a[i].uchar;
			NEW_LINE;
		}
		if(a[0].uName == a[1].uName) 
		{
			#ifdef __linux__
				system("clear");
			#elif __WIN32
				system("cls");
			#endif
				cout << "Two Players names must not be Identical!\n Try Again...\n\n";
				cout << "----------------------\n\n";
		}
			
		if(a[0].uchar == a[1].uchar) 
		{
			#ifdef __linux__
				system("clear");
			#elif __WIN32
				system("cls");
			#endif
			cout << "Two Player's symbols must not be identical\n Try Again...\n";
			cout << "----------------------\n\n";
		}
			
		if((a[0].uName != a[1].uName) && a[0].uchar != a[1].uchar) 
		{
			#ifdef __linux__
				system("clear");
			#elif __WIN32
				system("cls");
			#endif
			break;
		}
	}
	
	
	while(1)
	{
		cout << "\nSelect a player to play 1st\n";
		cout << "1. " << a[0].uName;
		NEW_LINE;
		cout << "2. " << a[1].uName;
		NEW_LINE;
		cout << "\n>> Enter your choice : ";
		cin >> choice;
		
		if(choice == 1 || choice == 2)
			break;
		else 
			cout << "Invalid Choice! \n Try Again..\n";
	}
		#ifdef __linux__
			system("clear");
		#elif __WIN32
			system("cls");
		#endif
	
	return choice;
}

void Board::help()
{
	char c;
	#ifdef __linux__
		system("clear");
	#elif __WIN32
		system("cls");
	#endif
	
	cout << "\n\n------------------------ (HELP FOR GAME) ----------------------------\n";
	cout << "--  STEP 1\n";
	cout << "\t1. Enter user information\n";
	cout << "\t2. Select who is going to play first turn\n";
	cout << "\n--  STEP 2\n";
	cout << "\t1. The board will be displayed with blank chars\n";
	cout << "\t2. Enter Row numbers (start from 0) \n";
	cout << "\t3. Enter Col numbers (start from 0)\n";
	cout << "\t4. The same is with Player 2 also\n";
	cout << "\n\t-> PROMPT WILL BE DISPLAYED ON THE SCREEN WHOSE TURN IS THIS\n";
	cout << "\n Do you Want To Display Board ? [y/n] ";
	cin >> c;
		#ifdef __linux__
			system("clear");
		#elif __WIN32
			system("cls");
		#endif
		
	if(c=='y')
		showBoard();
		
}

int main() 
{
	int choice,count=0,k,temp,done;
	int count2=1;
	char c;
		#ifdef __linux__
			cout << "You are using linux\n";
		#elif __WIN32
			cout << "You are using Windows\n"
		#elif __APPLE__
			cout << "You are using MacOS X\n";
		#endif

	cout << "Please Wait, Loading...\n\n";
	cout <<"[#";
	cout.flush();
	sleep(0.5);
	cout << "#";
	cout.flush();
	sleep(0.75);
	for(int i=0;i<10;i++)
	{
		cout << "#";
		cout.flush();
		sleep(1);
	}
	for(int i=0;i<10;i++)
	{
		cout << "#";
		cout.flush();
		sleep(0.5);
	}
	cout << "]" << endl;
	
	sleep(1);
	Board s1;
	
		#ifdef __linux__
			system("clear");
		#elif __WIN32
			system("cls");
		#elif __APPLE__
			cout << "You are using MacOS X\n";
			cout << "This game wont run in MacOS X systems\n"
			return 0;
		#endif
		
	s1.displayGame();
	while(1)
	{	
		NEW_LINE;
		NEW_LINE;
		BORDER1;
		cout << "1. How to play? (help)\n";
		cout << "2. Play Game\n";
		cout << "3. Quit Game\n\n";
		cout << ">> Enter your choice : ";
		cin >> choice;
		
		switch(choice)
		{
			case 1:
				s1.help();
				break;
				
			case 2:
				#ifdef __linux__
					system("clear");
				#elif __WIN32
					system("cls");
				#endif
				if(count==0) {
					 k = s1.userInfo(); 
					 temp = (k-1)%2;
					 count++; 
				}
				 
				done = s1.playGame(temp,count2);
				if(done == 1 && count2 != 10)
				{
					cout << "YOU WIN \n";
					s1.showBoard();
					exit(1);
				}
				if(count2 == 10)
				{
					exit(1);
					s1.showBoard();
				}
				s1.showBoard();
				break;
				
			case 3:
				cout << "Do you want to quit the game?  [y/n]";
				cin >> c;
				if(c=='y')
				{
					#ifdef __linux__
						system("clear");
					#elif __WIN32
						system("cls");
					#endif
					exit(1);
				}
				#ifdef __linux__
					system("clear");
				#elif __WIN32
					system("cls");
				#endif
				break;
					
			default:
				cout << "Invalid choice Try Again!\n";
				break;
		}
	}
	return 0;
}
