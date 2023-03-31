#include <iostream>
#include  <fstream>
#include <string>
#include "windows.h"

using namespace std;
// Write | Move | State change
int Rules[2][3][3] = {
        {{0,1,0},
         {1,1,0},
         {2, -1, 1}},
        {{1,0,3},
         {0, -1, 1},
         {1, 0, 3}}
};
string Stripe, StartWord;
unsigned short WordSize;

int CharToInt(char num){
    return num - '0';
}
char IntToChar(int i){
    string t = to_string(i);
    char const *n_char = t.c_str();
    return *n_char;
}
class Carriage {
public:
    int CurrentState=0, CurrentPlace;

int  CurrentCharacter() {
    return CharToInt(Stripe[CurrentPlace]);
}
void ChangeStateHandler(int NextState){
    CurrentState = NextState;
}
void MoveHandler(int Move){
    CurrentPlace +=Move;
}
void WriteHandler(int ToWrite){
    Stripe[CurrentPlace] = IntToChar(ToWrite);
}
void Iterate() {
    if (CurrentState != 3) {
        int c = CurrentCharacter();
        WriteHandler(Rules[CurrentState][c][0]);
        MoveHandler(Rules[CurrentState][c][1]);
        ChangeStateHandler(Rules[CurrentState][c][2]);

    }else Stripe=  "3";
}
};

int main() {
  //  string filename = "Plus1ult.csv"
   // ifsteam inputrules(filename);
    Carriage carriage;
    unsigned int IterateStep=0;

    cout << "Enter start word: \n";
    cin >> StartWord;
    Stripe = string(StartWord.length(), 'e') + StartWord + string(StartWord.length(), 'e');
    //cout << Stripe << "\n";
    carriage.CurrentPlace = StartWord.length();
    while(Stripe!="3"){

        cout <<IterateStep << " | "<< Stripe <<" | pos:" << carriage.CurrentCharacter()<< " | st:" << carriage.CurrentState << "\n";
        carriage.Iterate();
        IterateStep ++;
        Sleep(500);
    }
    system("pause");
}

/*{
 {{0,1,1},
{0,0,-1}},

{{0,1,2},
{1,1,1}},

{{0,0,-1},
{1,-1,3}},

{{0,-1,4},
{0,0,-1}},

{{0,0,12},
{1,-1,5}},

{{1,1,6},
{1,-1,5}},

{{0,0,-1},
{0,1,7}},

{{0,1,8},
{1,1,7}},

{{0,1,9},
{1,1,8}},

{{1,-1,10},
{1,1,9}},

{[0,-1,11},
{1,-1,10}},

{{0,0,3},
{1,-1,11}},

{{1,-1,13},
{0,0,-1}},

{{0,1,14},
{1,-1,13}},

{{0,0,-1},
{0,0,-1}}
}; */