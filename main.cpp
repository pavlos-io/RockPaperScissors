#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <map>
#include "helpers.h"

using namespace std;
using namespace helpers;

int main(int argc, char **argv) {
  bool cont, play = true;
  string userChoice, userCont;
  uniform_int_distribution<int> distribution (0,2);
  unsigned seed = chrono::system_clock::now().time_since_epoch().count();

  if(argc > 1)
    seed = stoi(argv[1]);
  minstd_rand generator (seed);

  while(play){
    cout << "Enter (R)ock, (P)aper, or (S)cissors for your move: " << endl;
    getline(cin, userChoice);
    cont = true;

    if ( !isChoiceInputValid(userChoice) )
        continue;
    else {
      int aiChoice = distribution(generator);

      cout << "The ai played " << getAiToText(aiChoice) << "." <<  endl;

      if(getChoice(userChoice) == aiChoice){
        cout << "You and the AI both played " << getAiToText(aiChoice) << "." <<  endl;
        cout << "Keep playing until someone wins." << endl;
        continue;
      }
      else if( getWinner(getChoice(userChoice)) == aiChoice){
        cout << "You win!" << endl;
      }
      else {
        cout << "The AI wins :(" << endl;
      }

      while (cont) {
        cout << "Would you like to replay the game?" << endl;
        cout << "Enter (Y)es or (N)o: " << endl;
        getline(cin, userCont);

        if ( !isContInputValid(userCont) )
          continue;
        else {
          cont = false;
          if( !getCont(userCont) )
            play = false;
        }
      }
    }
  }

    return 0;
}