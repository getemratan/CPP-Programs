/*
Author: Getem Ratan
Date: 18-06-2021
Description:
Example:
*/

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <algorithm>
#include <map>
#include <time.h>
#include <vector>
#include <windows.h>
#include <unistd.h>
#define DOWN_KEY 80
#define UP_KEY 72
#define ESC 27

using namespace std;

class TicTacToe
{


  public:
    int ch1, ch2;

    int cursor = 0;

    int userinput;

    vector<int> occupiedboxvector;

    vector<int> availableboxvector {1, 2, 3, 4, 5, 6, 7, 8, 9};

    enum GameOverStates
    {
      PlayerWin = 1,
      Draw  = 0,
      ComputerWin = -1,
      Default = 2
    };

    string currentcomputer;

    GameOverStates currentgamestate = Default;

    bool gameover = false;

    map<int, string> BoardDataMap;

    int datacounter = 1;

    string BoardNumbers[9] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

    void MainMenu(int x)
    {
        cout << "...................Tem's Tic Tac Toe..................\n";
        cout << "======================================================\n";
        x == 0 ? cout << "-->Select Player X\n" : cout << "Select Player X\n";
        x == 1 ? cout << "-->Select Player O\n\n" : cout << "Select Player O\n\n";
        cout << "Press Esc Key To Exit\n\n";
        cout << "Use UP and DOWN arrow key to navigate\n\n";
        cout << "Press Enter to select the option...";
    }

    void DrawBoardLineOne();

    void DrawBoardLineTwo();

    void ShowBoard();

    void InitializeBoardData();

    void UpdateBoardData(int input, string currentplayer);

    void GamePlay(string currentplayer);

    void CheckForGameOver(string currentplayer);

    void SetCurrentGameState(string valueone, string valuetwo, string valuethree, string currentplayer);

    void ComputerTurn();
};

void TicTacToe :: DrawBoardLineOne()
{
  cout << "\t\t";

  for(int i = 0; i < 4; i++)
  {
    cout << "+";
    if(i != 3)
    {
      for(int j = 0; j < 3; j++)
      {
        cout << "-";
      }
    }
  }
  // auto it = BoardDataMap.find(2);
  //
  // cout << "Key: " << it->first << "Val: " << it->second;
}

void TicTacToe :: DrawBoardLineTwo()
{
  cout << "\t\t";
  for(int i = 0; i < 4; i++)
  {
    cout << "|";
    if(i != 3)
    {
      for(int j = 0; j < 3; j++)
      {
        if(j == 1)
        {
          auto iterator = BoardDataMap.find(datacounter);
          cout << iterator->second;
          datacounter++;
        }
        else
        {
          cout << " ";
        }
      }
    }
  }
}

void TicTacToe :: ShowBoard()
{
    cout << "\n";

    for(int i = 0; i < 4; i++)
    {
      DrawBoardLineOne();

      cout << endl;

      if(i != 3)
      {
        DrawBoardLineTwo();
      }

      cout << endl;
    }

    datacounter = 1;
}

void TicTacToe :: InitializeBoardData()
{
  for(int i = 0; i < 9; i++)
  {
      BoardDataMap.insert({i + 1, BoardNumbers[i]});
  }
}

void TicTacToe :: UpdateBoardData(int input, string currentplayer)
{
  auto iterator  = BoardDataMap.find(input);

  if(availableboxvector.empty())
  {
    currentgamestate = Draw;
  }

  if(find(occupiedboxvector.begin(), occupiedboxvector.end(), input) == occupiedboxvector.end())
  {
    iterator -> second = currentplayer;
    occupiedboxvector.push_back(input);
    availableboxvector.erase(remove(availableboxvector.begin(), availableboxvector.end(), input), availableboxvector.end());

    CheckForGameOver(currentplayer);
    if(!availableboxvector.empty() && currentgamestate == Default)
      ComputerTurn();
  }

  else
  {
    cout << "\nEntered box number is already filled!!\n\n";
  }
}

void TicTacToe :: ComputerTurn()
{
  srand(time(NULL));

  int randomplace = rand() % availableboxvector.size() + 1;

  auto iterator = BoardDataMap.find(availableboxvector[randomplace]);

  iterator->second = currentcomputer;

  occupiedboxvector.push_back(availableboxvector[randomplace]);

  availableboxvector.erase(remove(availableboxvector.begin(), availableboxvector.end(), availableboxvector[randomplace]), availableboxvector.end());
}

void TicTacToe :: SetCurrentGameState(string valueone, string valuetwo, string valuethree, string currentplayer)
{
  if((valueone == valuetwo) && (valueone == valuethree) && (valueone == currentplayer))
  {
    currentgamestate = PlayerWin;
  }
  else if((valueone == valuetwo) && (valueone == valuethree) && (valueone != currentplayer))
  {
    currentgamestate = ComputerWin;
  }
}

void TicTacToe :: CheckForGameOver(string currentplayer)
{
  string currentvalue;
  string previousvalue;

  // checking horizontally
  for(int i = 1; i < 10; i += 3)
  {
    auto iteratorOne = BoardDataMap.find(i);
    auto iteratorTwo = BoardDataMap.find(i + 1);
    auto iteratorThree = BoardDataMap.find(i + 2);

    SetCurrentGameState(iteratorOne->second, iteratorTwo-> second, iteratorThree->second, currentplayer);
  }

  // checking vertically
  for(int i = 1; i < 4; i++)
  {
    auto iteratorOne = BoardDataMap.find(i);
    auto iteratorTwo = BoardDataMap.find(i + 3);
    auto iteratorThree = BoardDataMap.find(i + 6);

    SetCurrentGameState(iteratorOne->second, iteratorTwo-> second, iteratorThree->second, currentplayer);
  }

  // checking diagonally
  for(int i = 1; i < 3; i++)
  {
    if(i == 1)
    {
      auto iteratorOne = BoardDataMap.find(1);
      auto iteratorTwo = BoardDataMap.find(5);
      auto iteratorThree = BoardDataMap.find(9);

      SetCurrentGameState(iteratorOne->second, iteratorTwo-> second, iteratorThree->second, currentplayer);
    }
    else
    {
      auto iteratorOne = BoardDataMap.find(3);
      auto iteratorTwo = BoardDataMap.find(5);
      auto iteratorThree = BoardDataMap.find(7);

      SetCurrentGameState(iteratorOne->second, iteratorTwo-> second, iteratorThree->second, currentplayer);
    }
  }
}

void TicTacToe :: GamePlay(string currentplayer)
{
  InitializeBoardData();
  ShowBoard();
  cout << "Player enter your box number for " << currentplayer << " : ";
  cin >> userinput;

  while(userinput < 0 || userinput > 9)
  {
    cout << "\nPlease enter correct box number!!" << endl;
    cout << "\nPlayer enter your box number for " << currentplayer << " : ";
    cin >> userinput;
  }

  while(currentgamestate == Default)
  {
    UpdateBoardData(userinput, currentplayer);
    ShowBoard();
    CheckForGameOver(currentplayer);

    if(currentgamestate == PlayerWin)
    {
      cout << "\nPlayer Won!!";
    }
    else if(currentgamestate == ComputerWin)
    {
      cout << "\nComputer Won!!";
    }
    else if(currentgamestate == Draw)
    {
      cout << "\nIt's a Tie!!";
    }
    else
    {
      cout << "Player enter your box number for " << currentplayer << " : ";
      cin >> userinput;

      while(userinput < 0 || userinput > 9)
      {
        cout << "\nPlease enter correct box number!!" << endl;
        cout << "\nPlayer enter your box number for " << currentplayer << " : ";
        cin >> userinput;
      }
    }
  }
}

int main()
{
  TicTacToe T;

  int i = 0;
  // to display a loading screen
  char load[26];
  while(i < 26)
  {
      system("cls");
      load[i++] = '#';
      load[i] = '\0';

      cout << "\n\n\t         Loading..." << endl;
      cout << "\t" << load;
      // usleep to hold the execution for given seconds in the argument
      Sleep(3);
  }

  do{
    system("cls");
    T.MainMenu(T.cursor);

    T.ch1 = getch();
    /* For function keys and arrow keys getch() needs to be called twice
    first time to check scroll key interrupt */
    if(T.ch1 == 0xE0)
    {
    // Reading the arrow key
        T.ch2 = getch();
        switch(T.ch2)
        {
            case DOWN_KEY: system("cls");
                           if(T.cursor < 1)
                              T.cursor++;
                           T.MainMenu(T.cursor);
                           break;

            case UP_KEY: system("cls");
                         if(T.cursor != 0)
                            T.cursor--;
                         T.MainMenu(T.cursor);
                         break;

            case ESC: break;
        }
    }
    else if(T.ch1 == 10 || T.ch1 == 13)
    {
        switch(T.cursor)
        {
            case 0: system("cls");
                    T.currentcomputer = "O";
                    T.GamePlay("X");

                    getch();
                    break;

            case 1: system("cls");
                    T.currentcomputer = "X";
                    T.GamePlay("O");

                    getch();
                    break;
        }
    }
  }while(T.ch1 != ESC);
  return 0;
}
