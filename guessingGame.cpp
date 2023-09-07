/*
 * Author | Sophia You
 * Date | 09/03/2023
 *
 * Description | The computer generates
 * a random number between 1 and 100. The
 * user guesses a number, and the
 * computer says if it is either too
 * high or too low. Once the user has
 * guessed correctly, the computer tells
 * you how many guesses it took and asks
 * if you want to play again.
 * 
 * Sources | https://www.digitalocean.com/community/tutorials/random-number-generator-c-plus-plus
 */

/*
 * Response | 3 Rules for the C++ Class
 * 1. Do not use global variables, although you can use global constants.
 * 2. Do not use strings. You have to use cstrings or character arrays.
 * 3. #include <iostream>, not stdio. Use "new" and "delete" instead of
 * "malloc" and "free."
 */

#include <iostream>
using namespace std;

int main()
{

  srand((unsigned)time(NULL)); // sets up initial "seed" value for the random number
  int num = 0; // initializing the random number, we will randomize it in WHILE 1
  bool playing = true; // lets us know if the user wants to keep playing
  int tries = 0; // keeps track of how many tries the user has attempted

  // WHILE 1: while the user wants to keep playing
  while (playing == true)
  {
    /*
     * the modulus is used to generate a remainder between 0 and 99.
     * Then 1 is added to the number to make the range 1 to 100.
     */
    num = 1 + (rand() % 100); // num is the randomized number
    int input = 0;

    // WHILE 2: while "num" is not equal to the input
    while (num != input)
    {
      cout << "Guess an integer between 1 and 100! Enter -1 to quit." << endl;
      cin >> input; // takes user input

      // allows the user to exit the game if they want
      if (input == -1)
      {
        break;
      }
      
      // remember, the number has to be from 1-100
      if (input < 1 || input > 100)
      {
        cout << "Numbers between 1 and 100 only!" << endl;
      }
        
      // compares the two numbers
      else if (input > num)
      { // guess is too high
        cout << "Your guess is too large" << endl;
      }
      else if (input < num)
      { // guess is too low
        cout << "Your guess is too small" << endl;
      }

      tries++; // tracks how many times the user has tried
    }
    
    // if they didn't exit early, it means they got the number right
    if (input != -1)
    {
      cout << "You got it! It took " << tries << " tries. "<< endl;    }

    tries = 0; // clear the tries

    // asks user if they want to play again
    cout << "Enter 0 to play again. Enter 101 to quit." << endl;
    cin >> input;

    // to exit WHILE 1
    if (input == 101) {
      playing = false;
    }

    cout << "Game over." << endl;
  }

  return 0;
}
