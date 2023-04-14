#include <iostream>
//include  <fstream>
#include <string>
#include "windows.h"
#include "instruct.cpp"
using namespace std;

int SelectedTask;
const char emptyspace = '0';
string Stripe, StartWord;
unsigned short WordSize;

int Rules2[8][13][3] = {
        {{11, 1, 0},
                {11, 1, 0},
                {11, 1, 0},
                {11, 1, 0},
                {11, 1, 0},
                {11, 1, 0},
                {11, 1, 0},
                {11, 1, 0},
                {11, 1, 0},
                {11, 1, 0},
                {11, -1, 1},
                {0, 0, 0},
                {11, 1, 0}},
        {{9, -1, 1},
                {0, -1, 2},
                {1, -1, 2},
                {2, -1, 2},
                {3, -1, 2},
                {4, -1, 2},
                {5, -1, 2},
                {6, -1, 2},
                {7, -1, 2},
                {8, -1, 2},
                {0, 0, 0},
                {0, 0, 0},
                {10, 1, 6}},
        {{11, -1, 2},
                {11, -1, 2},
                {11, -1, 2},
                {11, -1, 2},
                {11, -1, 2},
                {11, -1, 2},
                {11, -1, 2},
                {11, -1, 2},
                {11, -1, 2},
                {11, -1, 2},
                {0, 0, 0},
                {0, 0, 0},
                {11, -1, 3}},
        {{9, -1, 3},
                {0, -1, 4},
                {1, 1, 0},
                {2, 1, 0},
                {3, 1, 0},
                {4, 1, 0},
                {5, 1, 0},
                {6, 1, 0},
                {7, 1, 0},
                {8, 1, 0},
                {11, 1, 6},
                {0, 0, 0},
                {0, 0, 0}},
        {{11, 1, 0},
                {11, 1, 0},
                {11, 1, 0},
                {11, 1, 0},
                {11, 1, 0},
                {11, 1, 0},
                {11, 1, 0},
                {11, 1, 0},
                {11, 1, 0},
                {11, 1, 0},
                {11, 1, 5},
                {0, 0, 0},
                {0, 0, 0}},
        {{10, 1, 5},
                {0, 0, 0},
                {0, 0, 0},
                {0, 0, 0},
                {0, 0, 0},
                {0, 0, 0},
                {0, 0, 0},
                {0, 0, 0},
                {0, 0, 0},
                {11, 1, 0},
                {0, 0, 0},
                {0, 0, 0},
                {10, 1, 7}},
        {{0, 0, 0},
                {0, 0, 0},
                {0, 0, 0},
                {0, 0, 0},
                {0, 0, 0},
                {0, 0, 0},
                {0, 0, 0},
                {0, 0, 0},
                {0, 0, 0},
                {10, 1, 6},
                {11, 0, -1},
                {0, 0, 0},
                {10, 0, -1}},
        {{10, 1, 7},
                {11, 0, -1},
                {11, 0, -1},
                {11, 0, -1},
                {11, 0, -1},
                {11, 0, -1},
                {11, 0, -1},
                {11, 0, -1},
                {11, 0, -1},
                {11, 0, -1},
                {11, 0, -1},
                {0, 0, 0},
                {0, 0, 0}}

};
int Rules1[15][2][3] = {
        {{0, 1,  1},
                {0, 0,  -1}},
        {{0, 1,  2},
                {1, 1,  1}},
        {{0, 0,  -1},
                {1, -1, 3}},
        {{0, -1, 4},
                {0, 0,  -1}},
        {{0, 0,  12},
                {1, -1, 5}},
        {{1, 1,  6},
                {1, -1, 5}},
        {{0, 0,  -1},
                {0, 1,  7}},
        {{0, 1,  8},
                {1, 1,  7}},
        {{0, 1,  9},
                {1, 1,  8}},
        {{1, -1, 10},
                {1, 1,  9}},
        {{0, -1, 11},
                {1, -1, 10}},
        {{0, 0,  3},
                {1, -1, 11}},
        {{1, -1, 13},
                {0, 0,  -1}},
        {{0, 1,  14},
                {1, -1, 13}},
        {{0, 0,  -1},
                {0, 0,  -1}}

};
int Rules3[6][2][3]={
        {{0,0,-1},
                {1,1,1}},
        {{0,-1,3},
                {1,1,2}},
        {{0,-1,4},
                {1,1,1}},
        {{0,1,5},
                {0,-1,3}},
        {{0,1,-1},
                {0,-1,4}},
        {{1,0,-1},
                {0,0,-1}}

};

int CharToInt(char num) {
    return num - '0';
}
char IntToChar(int i) {
    string t = to_string(i);
    char const *n_char = t.c_str();
    return *n_char;
}
class Carriage {
public:
    void setTerminalState(int State) {
        TerminalState = State;
    }

    void setState(int state) {
        CurrentState = state;
    }

    void setPlace(int place) {
        CurrentPlace = place;
    }

    int getState() {
        return CurrentState;
    }

    int CurrentCharacter() {
        int charID = 0;
        while (Stripe[CurrentPlace] != alph[charID]) {
            charID++;
        }
        return charID;
    }

    void ChangeStateHandler(int NextState) {
        CurrentState = NextState;
    }

    void MoveHandler(int Move) {
        CurrentPlace += Move;
    }

    void WriteHandler(int ToWrite) {
        Stripe[CurrentPlace] = IntToChar(ToWrite);
    }

    void Iterate() {
        switch(SelectedTask){
            case(1):
                if (CurrentState != TerminalState) {
                    int c = CurrentCharacter();
                    WriteHandler(Rules1[CurrentState][c][0]);
                    MoveHandler(Rules1[CurrentState][c][1]);
                    ChangeStateHandler(Rules1[CurrentState][c][2]);

                } else Stripe = "3";
                break;
            case(2):
                if (CurrentState != TerminalState) {
                    int c = CurrentCharacter();
                    WriteHandler(Rules2[CurrentState][c][0]);
                    MoveHandler(Rules2[CurrentState][c][1]);
                    ChangeStateHandler(Rules2[CurrentState][c][2]);

                } else Stripe = "3";
                break;
            case(3):
                if (CurrentState != TerminalState) {
                    int c = CurrentCharacter();
                    WriteHandler(Rules3[CurrentState][c][0]);
                    MoveHandler(Rules3[CurrentState][c][1]);
                    ChangeStateHandler(Rules3[CurrentState][c][2]);

                } else Stripe = "3";
                break;
            default:
                cout<<"Incorrect number of task value >_<";
                break;
        }

    }

private:
    char alph[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'e','x', '-'};
    int CurrentState = 0, CurrentPlace = 0, TerminalState = 0;
};

int main() {
    cout<<"Enter number of task"<<"\n";
    cin>>SelectedTask;
    int start, terminate;
    Carriage carriage;
    unsigned int IterateStep = 0;
    cout << "Enter Start and Terminal state";
    cin >> start >> terminate;
    carriage.setState(start);
    carriage.setTerminalState(terminate);
    cout << "Enter start word: \n";
    cin >> StartWord;
    carriage.setPlace(StartWord.length());
    carriage.setState(0);
    Stripe = string(StartWord.length(), emptyspace) + StartWord + string(StartWord.length(), emptyspace);
    //cout << Stripe << "\n";
    while (Stripe != "3") {
        cout << IterateStep << " | " << Stripe << " | " << carriage.CurrentCharacter() << "\n" << " | "
             << carriage.getState();
        carriage.Iterate();
        IterateStep++;
        Sleep(500);
    }
    system("pause");
}

