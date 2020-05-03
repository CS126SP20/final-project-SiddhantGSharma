//
// Created by SIDDHANT on 4/27/2020.
//

#ifndef FINALPROJECT_GAME_ENGINE_H
#define FINALPROJECT_GAME_ENGINE_H

#include "read_file.h"

namespace hangman {
  class Engine {
   public:
    Engine();
    std::string GetMovieFromList();
    bool PlayRound(std::string movie_name);
    void SetCharacter(char user_guess);
    bool IsCorrectGuess(char user_guess, std::string movie_name);
    int getScore() const;
    void setScore(int score);
    int getIncorrectGuess() const;
    void setIncorrectGuess(int incorrectGuess);
    char getUserGuess() const;
    void setUserGuess(char userGuess);

   private:
    int score_;
    const char* getMovieName() const;
    int incorrect_guess_;
    char user_guess_;
    char movie_name_[50];
  };
}

#endif  // FINALPROJECT_GAME_ENGINE_H
