//
// Created by SIDDHANT on 4/27/2020.
//

#ifndef FINALPROJECT_GAME_ENGINE_H
#define FINALPROJECT_GAME_ENGINE_H

#include "read_file.h"

namespace hangman {

const std::string kVowels = "aeiou";

class Engine {
 public:
  Engine();
  void CreateList();
  void GetMovieFromList();
  void Step();
  void PlayRound();
  bool IsCorrectGuess(char user_guess);
  int getScore() const;
  void setScore(int score);
  int getIncorrectGuess() const;
  void setIncorrectGuess(int incorrectGuess);
  char getUserGuess() const;
  void setUserGuess(char userGuess);
  const std::vector<char>& getMovieName() const;
  void setMovieName(const std::vector<char>& movieName);
  void Reset();

 private:
  int score_;
  int incorrect_guess_;
  char user_guess_{};
  std::string movie;

 public:
  const std::string& getMovie() const;
  void setMovie(const std::string& movie);
 private:
  std::vector<char> movie_name_;
  std::vector<char> incomplete_movie_name_;

 public:
  const std::vector<char>& getIncompleteMovieName() const;
  void setIncompleteMovieName(const std::vector<char>& incompleteMovieName);
 private:
  bool round_over_;
  std::vector<std::string> movies_list_;

 public:
  bool isRoundOver() const;
  void setRoundOver(bool roundOver);

 private:
  bool isVowel(char c);
};

}

#endif  // FINALPROJECT_GAME_ENGINE_H
