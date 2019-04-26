#ifndef ROCKPAPERSCISSORS_HELPERS_H
#define ROCKPAPERSCISSORS_HELPERS_H

#include <map>
#include <string>
#include <vector>

namespace helpers {
    //String helpers
    void toLowercase(std::string& str);
    void stripInPlace(std::string& string, const std::string& charsToRemove = " \t\n");
    void lstripInPlace(std::string& string, const std::string& charsToRemove = " \t\n");
    void rstripInPlace(std::string& string, const std::string& charsToRemove = " \t\n");
    bool contains(const std::string& string, char letter);
    void prettify(std::string& string);

    //Choice helpers
    bool isChoiceInputValid(std::string userInput);
    bool isContInputValid(std::string userInput);
    int getChoice(std::string& userInput);
    int getCont(std::string& userInput);
    int getWinner(const int& choice);
    std::string getAiToText(int index);
}

#endif //ROCKPAPERSCISSORS_HELPERS_H
