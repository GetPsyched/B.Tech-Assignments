#include <vector>
#include <iostream>
#include <fstream>
#include <time.h>
#include <iomanip>


using namespace std;

//print solution in console
void printBoardinTerminal(int *board, int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (j == board[i])
            {
                cout << 1 << " ";
            }
            else
            {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}

//print solution in File
void printBoardinFile(int *board, int len)
{
    ofstream fp("output.txt", ios::out);

    fp << "Answer for " << len << " queen: \n \n";

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            fp << "----";
        }
        fp << "\n|";

        for (int j = 0; j < len; j++)
        {
            if (j == board[i])
            {
                fp << setw(4) << "* |" ;
            }
            else
            {
                fp << setw(4) << "  |";
            }
        }
        fp << "\n";
    }
}

//The number of queens couples who are threatened themself
int evaluate(int *board, int len)
{
    int score = 0;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (board[i] == board[j])
            {
                score++;
                continue;
            }
            if (board[i] - board[j] == i - j)
            {
                score++;
                continue;
            }
            if (board[i] - board[j] ==  j - i)
            {
                score++;
                continue;
            }
        }
    }
    return score;
}

//generate new state from current state
int* generateBoard(int *board,int len)
{
    vector <int> choice;

    int temp;
    int score;
    int eval = evaluate(board, len);
    int k;

    int *boardOut;
    boardOut = new int [len];


    for (int i = 0; i < len; i++)
    {
            boardOut[i] = board[i];
    }

    for (int i = 0; i < len; i++)
    {
        choice.clear();

        choice.push_back(boardOut[i]);
        temp = boardOut[i];

        for (int j = 0; j < len; j++)
        {
            boardOut[i] = j;

            k = evaluate(boardOut, len);

            if (k == eval)
            {
                choice.push_back(j);
            }

            if (k < eval)
            {
                choice.clear();
                choice.push_back(j);
                eval = k;
            }
        }
        boardOut[i] = choice[rand() % choice.size()];
    }

    return boardOut;
}

//in this function , genarate new state by pervious function and if it has better value then replaces that by current state
bool findNextState(int *board, int len)
{
    int maineval = evaluate(board, len);

    int *tempBoard;

    tempBoard = generateBoard(board, len);

    if (evaluate(tempBoard, len) < maineval)
    {
        for (int p = 0; p < len; p++)
        {
            board[p] = tempBoard[p];
        }

        return  true;
    }

    return false;
}

// make random initial state , put one queen in each row
void initialRandomBoard(int * board, int len)
{
    bool access;
    int col;

    for (int i = 0; i < len; i++)
    {
        board[i] = rand() % len;
    }
}

//this function include a loop that call findNextState function , and do that until reach solution
//if findNextState function return NULL then we reset current state
void SolveNQueen(int len)
{
    cout << "The program is under process! wait!" << endl;

    int *board;
    board = new int[len];


    initialRandomBoard(board, len);

    while (evaluate(board, len) != 0)
    {
        if (!findNextState(board, len))
        {
            initialRandomBoard(board, len);
        }
    }


    //
    cout << endl << "Anwser for " << len << " queens: "<< endl << endl;
    printBoardinTerminal(board, len);
    printBoardinFile(board, len);
    //
}


int main()
{
    int n;
    srand(time(NULL));

    cout << "Enter  number \'N\', \'N\' indicate numbers of queens in \"N * N\" chess board: " << endl;
    cin >> n;

    if (n < 4)
    {
        cout << "\'n\' must be uper than 3!" << endl;
        exit(1);
    }

    SolveNQueen(n);

    cout << endl << "As well , you can see result in output" << endl << endl;

    return 0;
}