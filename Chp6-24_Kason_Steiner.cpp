/*Title: Chapter 6 Exercise 24 - Rock Paper Scissors 
File:Chp6-24_Kason_Steiner
Programmer: Kason Steiner
Date: 11/2024
When the program begins, a random number in the range of 1 through 3 is generated. If the number is 1, then the computer has chosen rock. 
If the number is 2, then the computer has chosen paper. If the number is 3, then the computer has chosen scissors. (Don’t display the computer’s choice yet.)
2. The user enters his or her choice of “rock”, “paper”, or “scissors” at the keyboard. (You can use a menu if you prefer.) 
3. The computer’s choice is displayed.
4. A winner is selected according to the following rules:
If one player chooses rock and the other player chooses scissors, then rock wins. (The rock smashes the scissors.)
If one player chooses scissors and the other player chooses paper, then scissors wins. (Scissors cuts paper.)
If one player chooses paper and the other player chooses rock, then paper wins. (Paper wraps rock.)
If both players make the same choice, the game must be played again to determine the winner.
*/

#include <iostream>
#include <random>
using namespace std;

int cpuChoice();
int playerChoice();
void winner(int, int);

int main() { 

  int cpu = cpuChoice(); 
  int player;

  cout << "Rock Paper Scissors Game\n";
  cout << "------------------------\n";

  player = playerChoice();
  cout << "Computer's choice: " << cpu << endl;
  winner(player, cpu);

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
  return choice;
}

void winner(int player, int cpu)
{

  if (player == 1 && cpu == 2)
    cout << "Paper wraps the rock. You lose!";
  if (player == 2 && cpu ==1)
    cout << "Paper wraps the rock. You win!";
  if (player == 1 && cpu == 3)
    cout << "Rock smashes scissors. You win!";
  if (player == 3 && cpu == 1)
    cout << "Rock smashes scissors. You lose!";
  if (player == 2 && cpu == 3)
    cout << "Scissors cuts paper. You lose!";
  if (player == 3 && cpu == 2)
    cout << "Scissors cuts paper. You win!";
  if (player == cpu)
    cout << "It's  draw! Try again!";
}
