#include<iostream>
using namespace std;

bool drawTable(char *spaces);
void currentPlayer(string *names, int x);
int switchP(int x);
bool playerinput(char *spaces, int x);
bool checkWin(char *spaces);
void home(char *spaces, int *player, int *count, string *names, bool *running);

int main(){
    char spaces[9]={' ',' ',' ',' ',' ',' ',' ',' ',' ',};
    int player=0; int count=0;
    string names[2];
    bool running=true;
    cout << "Name Player 1:\t"; getline(cin,names[0]);
    cout << "Name Player 2:\t"; getline(cin,names[1]);
    while(running){
    home(spaces, &player,&count,names,&running);
    }
    return 0;
}
void home(char *spaces, int *player, int *count, string *names, bool *running){
        while(*running){
        system("clear");
        currentPlayer(names,*player);        // Prints Name of Current Player. Starting from current Player.
        drawTable(spaces);          // Draws the Tic Tac Toe Table on Screen. 
        if(!playerinput(spaces,*player)) {return;};
        if(checkWin(spaces)){
            system("clear");
            currentPlayer(names,*player);
            drawTable(spaces);
            cout << "\n\t" << names[*player] << " Wins!\n"; *running=false;}
        else{++*count; if(*count>=9){
            system("clear");
            currentPlayer(names,*player);
            drawTable(spaces);
            cout << "\n\t DRAW!\n"; *running=false;}}
        *player = switchP(*player);        // To Switch Player After a Move.
    }
    return;
}

bool drawTable(char *spaces){
    cout << "\n       |       |\n";
    cout << "   "<< spaces[0] <<"   |   "<<spaces[1]<<"   |   "<<spaces[2] << "   \n";
    cout << "_______|_______|_______\n";
    cout << "       |       |\n";
    cout << "   "<< spaces[3] <<"   |   "<<spaces[4]<<"   |   "<<spaces[5] << "   \n";
    cout << "_______|_______|_______\n";
    cout << "       |       |\n";
    cout << "   "<< spaces[6] <<"   |   "<<spaces[7]<<"   |   "<<spaces[8] << "   \n";
    cout << "       |       |\n";
    return 0;
}

int switchP(int x){
    if(x==0) return ++x;
    else return --x;
}
void currentPlayer(string *names, int x){
    cout <<"\n\t"<< "Player: " << names[x] << endl;
}

bool playerinput(char *spaces, int x){
    cout << "\nEnter Table Box to Fill: \t";
    int input; cin >> input;
    if(input <=0 || input >= 10) { cout << " \tInvalid Input!"; cin.ignore(); cin.get(); return 0; }
    if(spaces[input-1] != ' '){ cout << "Feeling Naughty? can't change checked Boxes :)\n";cin.ignore(); cin.get(); return 0;}
    if(x==0){
        spaces[input-1]= 'O';
    }
    else{
        spaces[input-1] = 'X';
    }
    return 1;
}
bool checkWin(char *spaces){
    if(spaces[0]=='O' && spaces[3]=='O' && spaces[6]=='O') { return true;}
    if(spaces[0]=='X' && spaces[3]=='X' && spaces[6]=='X') { return true;}
    if(spaces[0]=='O' && spaces[4]=='O' && spaces[8]=='O') { return true;}
    if(spaces[0]=='X' && spaces[4]=='X' && spaces[8]=='X') { return true;}
    if(spaces[1]=='O' && spaces[4]=='O' && spaces[7]=='O') { return true;}
    if(spaces[1]=='X' && spaces[4]=='X' && spaces[7]=='X') { return true;}
    if(spaces[2]=='O' && spaces[4]=='O' && spaces[6]=='O') { return true;}
    if(spaces[2]=='X' && spaces[4]=='X' && spaces[6]=='X') { return true;}
    if(spaces[2]=='O' && spaces[5]=='O' && spaces[8]=='O') { return true;}
    if(spaces[2]=='X' && spaces[5]=='X' && spaces[8]=='X') { return true;}
    return false;
}
