#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "helpers.h"

namespace helpers {

  bool isChoiceInputValid(std::string userInput) {

    prettify(userInput);
    return getChoice(userInput) == -1 ? false : true;
  }

  bool isContInputValid(std::string userInput) {
    prettify(userInput);
    return getCont(userInput) == -1 ? false : true;
  }

  int getChoice(std::string& userInput) {
    static const std::map<std::string, int> input = {
      {"r",          0},
      {"(r)ock",     0},
      {"rock",       0},

      {"p",          1},
      {"(p)aper",    1},
      {"paper",      1},

      {"s",          2},
      {"(s)cissors", 2},
      {"scissors",   2}
    };

    prettify(userInput);
    return input.count(userInput) ? input.at(userInput) : -1;
  }

  int getCont(std::string& userInput) {
    static const std::map<std::string, int> contInput = {
      {"yes", 1},
      {"y",     1},
      {"(y)es", 1},

      {"no", 0},
      {"n",     0},
      {"(n)o", 0}
    };

    prettify(userInput);
    return contInput.count(userInput) ? contInput.at(userInput) : -1;
  }

  int getWinner(const int& choice) {
   static const std::map<int, int> rules = {
     {0, 2},
     {1, 0},
     {2, 1}
   };

   return rules.at(choice);
  }

  void toLowercase(std::string& str) {
      for(auto& c : str){
          c = tolower(c);
      }
  }

  void stripInPlace(std::string& string, const std::string& charsToRemove) {
      lstripInPlace(string, charsToRemove);
      rstripInPlace(string, charsToRemove);
  }

  void lstripInPlace(std::string& string, const std::string& charsToRemove) {

    auto itr = string.begin();
    for(; itr != string.end(); ++itr){
        if(!contains(charsToRemove, *itr)){
            break;
        }
    }
    string.erase(string.begin(), itr);
  }

  void rstripInPlace(std::string& string, const std::string& charsToRemove) {
    auto itr = string.rbegin();
    for(; itr != string.rend(); ++itr){
        if(!contains(charsToRemove, *itr)){
            break;
        }
    }
    string.erase(itr.base(), string.end());
  }

  bool contains(const std::string& string, char letter) {
    return std::find(string.cbegin(), string.cend(), letter) != string.cend();
  }

  void prettify(std::string& string){
    toLowercase(string);
    stripInPlace(string);
  }

  std::string getAiToText(int index) {
    static const std::vector<std::string> aiToText = {"rock", "paper", "scissors"};

    return aiToText.at(index);
  }
}