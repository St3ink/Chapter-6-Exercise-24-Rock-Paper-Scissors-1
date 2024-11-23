/*Title: Chapter 6 Exercise 24 - Rock Paper Scissors 
File:Chp6Exc24_Kason_Steiner
Programmer: Kason Steiner
Date: 11/2024
Revise your original Rock Paper Scissors Game so that it is repeatable
using  sentinel value to end. On each iteration of the game you should
accept the name of the player and keep count of how many times they
have won. Modify your program using a new branch of your project so that
you preserve the orginal main branch from Part 1.
Submit the code file as well as a screenshot of your testing.
*/

#include <iostream>
#include <random>
using namespace std;

int cpuChoice();
int playerChoice();
void winner(int, int, int&);

int main() { 
  char playAgain = 0;
  string name;   //players name
  int winCount = 0; //win counter
  cout << "Rock Paper Scissors Game\n";
  cout << "------------------------\n";
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
    cout << "The game is over. ";


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
