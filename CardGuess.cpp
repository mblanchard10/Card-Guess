//Mike Blanchard
//Program 5
//csc1720/programs/program5
//This program is a game in which the user can guess the value of the top card, the suit, or both. The deck of cards is implemented by a vector of structs. Use of the STL. 

#include <iostream>
#include <vector>
#include <string> 
#include <algorithm>   
using namespace std;

int main (){
   //struct to represent each card
   struct card{
      string suit; //suit of the card
      string value; //number or face of card
   };
 
   //vector of stucts, each stuct is a card
   vector<card> deck(52);
 
   //load cards into the vector
   int i; 
   for (i=0; i<=52; i++){
      //for values
      if (i == 0 || i == 13 || i == 26 || i == 39){
         deck[i].value = "ace";
      }
      if (i == 1 || i == 14 || i == 27 || i == 40){
         deck[i].value = "two";
      }
      if (i == 2 || i == 15 || i == 28 || i == 41){
         deck[i].value = "three";
      } 
      if (i == 3 || i == 16 || i == 29 || i == 42){
         deck[i].value = "four";
      } 
      if (i == 4 || i == 17 || i == 30 || i == 43){
         deck[i].value = "five";
      } 
      if (i == 5 || i == 18 || i == 31 || i == 44){
         deck[i].value = "six";
      } 
      if (i == 6 || i == 19 || i == 32 || i == 45){
         deck[i].value = "seven";
      } 
      if (i == 7 || i == 20 || i == 33 || i == 46){
         deck[i].value = "eight";
      } 
      if (i == 8 || i == 21 || i == 34 || i == 47){
         deck[i].value = "nine";
      } 
      if (i == 9 || i == 22 || i == 35 || i == 48){
         deck[i].value = "ten";
      } 
      if (i == 10 || i == 23 || i == 36 || i == 49){
         deck[i].value = "jack";
      } 
      if (i == 11 || i == 24 || i == 37 || i == 50){
         deck[i].value = "queen";
      } 
      if (i == 12 || i == 25 || i == 38 || i == 51){
         deck[i].value = "king";
      } 
      //for suits
      if (i <= 12){
         deck[i].suit = "spades";
      }
      if (i >= 13 && i <= 25){
         deck[i].suit = "clubs";
      }
      if (i >= 26 && i <= 38){
         deck[i].suit = "hearts";
      }
      if (i >= 39 && i <= 51){
         deck[i].suit = "diamonds";
      }
   } //end of inputing data into vector
   
   //delcare variables for the game
   int m = 0;
   int option;
   string valueGuess, suitGuess;
   char responce;
 
   //master while loop to control the game
   while (m == 0){
      //prompt user to select game mode
      cout << "Welcome to Mike's Guess That Card!" << endl << endl;
     
      cout << "Enter the number corresponding to the option you would like to choose" << endl;
      cout << "---------------------------------------------------------------------" << endl;
      cout << "Option 1: Guess the top card's value" << endl;
      cout << "Option 2: Guess the top cards's suit" << endl;
      cout << "Option 3: Guess both" << endl;
      cout << "Enter option: ";
      cin >> option;
   
      // if statement if user wants to guess top value
      if (option == 1){
         cout << "You have selected option 1. Please write out your guess." << endl; 
         cout << "(i.e ace, two, jack, queen etc. Please lowercase only." << endl;
         cin >> valueGuess;
         //shuffle deck
         random_shuffle(deck.begin(),deck.end());
         if (valueGuess == deck[0].value){
            cout << "You got it right!" << endl;
         }
         else if (valueGuess != deck[0].value){
            cout << "Wrong. Try again!" << endl;
            cout << "The answer was: " << deck[0].value << endl;
         }
         
         //if wrong the user can quit or try again
         cout << "Press Q to quit or C to go again." << endl;
         cin >> responce;
            if (responce == 'q' || responce == 'Q'){
               m = 1;
            }
            else if (responce == 'c' || responce == 'C'){
               m = 0;
            }     
      }
      //else if, if user wants to guess top suit
      else if (option == 2){
         cout << "You have selected option 2. Please write out your guess." << endl;
         cout << "(i.e hearts, spades, clubs, or diamonds). Please lowercase only." << endl;
         cin >> suitGuess;
         //shuffle deck
         random_shuffle(deck.begin(),deck.end());
         if (suitGuess == deck[0].suit){
            cout << "You got it right!" << endl;
         }
         else if (suitGuess != deck[0].suit){
            cout << "Wrong. Try again!" << endl;
            cout << "The answer was: " << deck[0].suit << endl;
         }
         //option to go again
         cout << "Press Q to quit or C to go again." << endl;
         cin >> responce;
            if (responce == 'q' || responce == 'Q'){
               m = 1;
            }
            else if (responce == 'c' || responce == 'C'){
               m = 0;
            }     
      }   
      //else if, if user wants to guess both
      else if (option == 3){
         cout << "You have selected option 3. Please write out your guesses seperated by a space and with the value first." << endl;
         cout << "(i.e three hearts, king diamonds, etc.) Please lowercase only." << endl;
         cin >> valueGuess;
         cin >> suitGuess;
         //shuffle deck
         random_shuffle(deck.begin(),deck.end());
         //series of ifs and else ifs for if user gets one right, both right etc.
         if (suitGuess == deck[0].suit && valueGuess == deck[0].value){
            cout << "You got both right!" << endl;
         }
         else if (suitGuess != deck[0].suit && valueGuess == deck[0].value){
            cout << "You got the value right!" << endl;
            cout << "The suit was: " << deck[0].suit << endl;
         }
         else if (suitGuess == deck[0].suit && valueGuess != deck[0].value){
            cout << "You got the suit right!" << endl;
            cout << "The value was: " << deck[0].value << endl;
         }
         else if (suitGuess != deck[0].suit && valueGuess != deck[0].value){
            cout << "You got both wrong!" << endl;
            cout << "The suit was: " << deck[0].suit << endl;
            cout << "The value was: " << deck[0].value << endl;
         }
         //option for user to go again
         cout << "Press Q to quit or C to go again." << endl;
         cin >> responce;
            if (responce == 'q' || responce == 'Q'){
               m = 1;
            }
            else if (responce == 'c' || responce == 'C'){
               m = 0;
            }
      }
      //else if and if to check for proper input 
      else if (option != 1 && option != 2 && option != 3){
         cout << endl;
         cout << "--Please enter an option of 1, 2, or 3--" << endl;
         cout << endl;
         m = 1;
      }
   }
      
return 0;
}
