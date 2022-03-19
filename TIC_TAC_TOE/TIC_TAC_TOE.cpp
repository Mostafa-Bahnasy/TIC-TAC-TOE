//----------------------------------------TIC_TAC_TOE-------------------------------
#include<bits-stdc++.h>
#include<Windows.h>
#include<cstring>
#define TIC_TAC_TOE 	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

//-----------------------------FUNCTIONS-----------------------------------------
void print_line(int n);

void make_move();

bool another_game();

void get_names();

bool check_exist(int r, int c);

string check_win();

void show_board();

struct point get_move(int turn);

void clear_board();

void title();
//---------------------------------------------------------------------------------
char board[3][3] = { {' ',' ',' '},
				     {' ',' ',' '},
				     {' ',' ',' '} };
int cnt = 1;
string player1, player2;
struct point {
	int row, col;
};
//---------------------------------------------------------------------------------

int main() {
	TIC_TAC_TOE;
	cout << "\t\t\tHELLO TO TIC_TAC_GAME\n"; Sleep(1000);
	while (true) {
		string state;
		clear_board();
		cnt = 1;
		get_names();
		cout << "LETS START A GAME ( " << player1 << " )  &&  ( " << player2 << " ).\n"; Sleep(1000);
		cout << "\t CHARACHTER ( X ) FOR:  " << player1 << ".\n"; Sleep(500);
		cout << "\t CHARACHTER ( O ) FOR:  " << player2 << ".\n";
		while (cnt < 10) {
			make_move();
			show_board();
			state = check_win();
			if (state == player1) {
				cout << "\t\t\tCONGRATS!!\n";
					cout << "\t YOU WON THE GAME, " << player1<<".\n";
					print_line(40);
					break;
			}
			else if(state==player2){
				cout << "\t\t\tCONGRATS!!\n";
				cout << "\t YOU WON THE GAME, " << player2 << ".\n";
				print_line(40);
				break;
			}
			cnt++;
		}
		if (state == "draw") {
			cout << "\t\t\tDRAW!!\n";
			cout << "\t\t  TRY NEXT TIME\n";
			print_line(40);
		}
	
		if (!another_game()) { break; }
	}
	print_line(40);
	cout << "\t\tTHANK YOU FOR USING OUR GAME\n";
}

//------------------------------------------------------------------------------------
void print_line(int n) {
	
	while (n--) {
		cout << "-";
	}
	cout << "\n";
}

void make_move() {
	point current = get_move(cnt);
	while (!check_exist(current.row, current.col)) {
		cout << "\tIT SEEMS LIKE YOU HAVE CHOSEN A FILLED CELL\n"; Sleep(1000);
		cout << "\t  OR YOU HAVE CHOSEN IMAGINARY CELL\n"; Sleep(1000);
		cout << "PLEASE, TRY AGAIN WITH ANOTHER CELL\n\n"; Sleep(1000);
		current=get_move(cnt);
	}
	(cnt % 2 == 0) ? board[current.row - 1][current.col - 1] = 'O' : board[current.row - 1][current.col - 1] = 'X';
	
}
bool another_game() {
	char ch;
	cout << "IF YOU WANT TO PLAY AGAIN PRESS( Y ) OR ANY KEY TO END THE GAME!!\n";
	cin >> ch;
	if (tolower(ch) == 'y') {
		return 1;
	}
	else {
		return 0;
	}
}
struct point get_move(int turn) {
	int r, c;
	if (cnt % 2 == 0) {
		cout << "MAKE YOUR MOVE, " << player2 << ".\n";
		cout << "PRESS ROW NUM:  "; cin >> r;
		cout << "PRESS COLUM NUM:  "; cin >> c;
	}
	else {
		cout << "MAKE YOUR MOVE, " << player1 << ".\n";
		cout << "PRESS ROW NUM:  "; cin >> r;
		cout << "PRESS COLUM NUM:  "; cin >> c;
	}
	point temp = { r,c };
	return temp;
}
void get_names() {
	print_line(40);
	cout << "PLEASE, ENTER FIRST PLAYER NAME:   "; cin >> player1; cout << "\n\n";
	cout << "PLEASE, ENTER SECOND PLAYER NAME:   "; cin >> player2; cout << "\n\n";
	print_line(40); cout << "\n";
}
bool check_exist(int r, int c) {
	if (board[r - 1][c - 1] == ' ') { return 1; }
	else { return 0 ; }
}
string check_win() {
	//                                 -----player1-----
	if ((board[0][0] == board[0][1] && board[0][2] == board[0][1] && board[0][0] == 'X') ||
		(board[1][0] == board[1][1] && board[1][2] == board[1][1] && board[1][0] == 'X') ||
		(board[2][0] == board[2][1] && board[2][2] == board[2][1] && board[2][0] == 'X') ||
		(board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] == 'X') ||
		(board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] == 'X') ||
		(board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] == 'X') ||
		(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == 'X') ||
		(board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] == 'X')) {
		return player1;
	}
	//                     ------------------player2------------
	else if ((board[0][0] == board[0][1] && board[0][2] == board[0][1] && board[0][0] == 'O') ||
		(board[1][0] == board[1][1] && board[1][2] == board[1][1] && board[1][0] == 'O') ||
		(board[2][0] == board[2][1] && board[2][2] == board[2][1] && board[2][0] == 'O') ||
		(board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] == 'O') ||
		(board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] == 'O') ||
		(board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] == 'O') ||
		(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == 'O') ||
		(board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] == 'O')) {
		return player2;
	}
	else return "draw";
}
void show_board() {
	system("cls");
	cout << "\n";
	title();
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0) { cout << "\t\t\t\t\t\t"; }
			if (board[i][j] == ' ') {
				cout << "_";
			}
			else { cout << board[i][j]; }
			if (j != 2) {
				cout << "|";
			}
		}
		cout << "\n";
	}
	cout << "\t\t\t\t \t    ";
	print_line(12);
}
void clear_board() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}
}

void title() {
	cout << "\n\t\t----------------------------------------------------------------------\n";
	cout << "						 TIC - TAC - TOE\n";
	cout << "\t\t----------------------------------------------------------------------\n";
}
