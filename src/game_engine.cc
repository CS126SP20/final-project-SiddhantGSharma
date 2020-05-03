//
// Created by SIDDHANT on 4/27/2020.
//

#include <mylibrary/game_engine.h>

namespace hangman {

Engine::Engine() {}

std::string Engine::GetMovieFromList() {
  ReadFile readFile;
  std::vector<std::string> movies_list = readFile.ReadFile::ReadTxtFile("hello.txt");

  if (movies_list.empty()) {
    return "Game Over";
  }

  std::string movie = movies_list.back();
  movies_list.pop_back();
  return movie;
}

bool Engine::PlayRound(std::string movie_name) {
  return false;
}

void Engine::SetCharacter(char user_guess) {}

bool Engine::IsCorrectGuess(char user_guess, std::string movie_name) {
  return false;
}

int Engine::getScore() const { return score_; }

void Engine::setScore(int score) { score_ = score; }

int Engine::getIncorrectGuess() const { return incorrect_guess_; }

void Engine::setIncorrectGuess(int incorrectGuess) {
    incorrect_guess_ = incorrectGuess;
}

char Engine::getUserGuess() const { return user_guess_; }

void Engine::setUserGuess(char userGuess) { user_guess_ = userGuess; }

const char* Engine::getMovieName() const { return movie_name_; }

}