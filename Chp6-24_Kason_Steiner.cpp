/*Title: Chapter 6 Exercise 24 - Rock Paper Scissors 
File:Chp6Exc24_Kason_Steiner
Programmer: Kason Steiner
Date: 11/2024
Create a new branch that uses a file to store the results of each new session along
with previous sessions. When starting you should provide a menu that
that lets the user start a new session, display previous sessions for yourself of any others
*/

#include <iostream>
#include <random>
#include <fstream>
#include <string>
using namespace std;

int cpuChoice();
int playerChoice();
void winner(int, int, int&);
void previousGames(const string& , string&, int); //displays results of previous games

int main() { 
  char playAgain = 0;
  string name;   //players name
  int winCount = 0; //win counter
  int choice; //menu selection
  string player; // used to show player name from previous game
  int wins = 0; //used to display previous win total from previous game

  
  cout << "Rock Paper Scissors Game\n";
  cout << "------------------------\n";
  cout << "Please select an option.\n";
  cout << "Press 1 to view past results.\nPress 2 to play a new game. ";
  cin >> choice;

  switch (choice)
    {
    case 1: 
      previousGames("gameRecords.txt", player, wins);
      break; 
    case 2:
  cout << "Enter your name: ";
  cin >> name;

  while (playAgain != 'n' && playAgain != 'N')
  {  
    int cpu = cpuChoice(); 
    int player;    //players choice

    player = playerChoice();
    cout << "Computer's choice: " << cpu << endl;
    winner(player, cpu, winCount); 


    cout << "Number of games " << name << " has won: " << winCount << endl;
    cout << "Would you like to play again? ";
    cout << "Press (y) to play again. Press (n) to quit.\n";
    cin >> playAgain;


  }
      ofstream outputFile("gameRecords.txt", ios::app);
      outputFile << name << ": " << winCount << endl;
      outputFile.close();

      
    cout << "The game is over. ";
    }

return 0; 
}

int cpuChoice()
{
  random_device myEngine;
  uniform_int_distribution <int> cpuPick(1, 3);
  return cpuPick(myEngine);
}

int playerChoice()
{
  int choice;
    cout << "1. Rock\n";
    cout << "2. Paper\n";
    cout << "3. Scissors\n";
    cout << "Enter your choice (1, 2, or 3): ";
    cin >> choice;

  while (choice < 1 || choice > 3)
    {
      cout << "Please enter a number 1-3\n";
      cout << "1. Rock\n";
      cout << "2. Paper\n";
      cout << "3. Scissors\n";
      cout << "Enter your choice (1, 2, or 3): ";
      cin >> choice;
    }
  return choice;
}

void winner(int player, int cpu, int& winCount) 
{
  if (player == 1 && cpu == 2)
    cout << "Paper wraps the rock. You lose!\n\n";
  if (player == 2 && cpu ==1)
  {
    cout << "Paper wraps the rock. You win!\n\n";
    winCount++; //adds player win
  }
  if (player == 1 && cpu == 3)
  {
    cout << "Rock smashes scissors. You win!\n\n";
    winCount++; //adds player win
  }
  if (player == 3 && cpu == 1)
    cout << "Rock smashes scissors. You lose!\n\n";
  if (player == 2 && cpu == 3)
    cout << "Scissors cuts paper. You lose!\n\n";
  if (player == 3 && cpu == 2)
  {
    cout << "Scissors cuts paper. You win!\n\n";
    winCount++; //adds player win
  }
  if (player == cpu)
    cout << "It's  draw!\n\n";
}

void previousGames(const string& filename, string& player, int wins) {      ifstream     inputFile(filename); // Open the file
      if (inputFile.is_open()) {
          while (inputFile >> player >> wins) {
              cout << player << " " << wins << endl;
          }
          inputFile.close(); 
      } else {
          cout << "Error opening " << filename << " for reading.\n";
      }
    }

