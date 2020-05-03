//
// Created by SIDDHANT on 4/27/2020.
//

#include <mylibrary/game_engine.h>

namespace hangman {

Engine::Engine() {
  score_ = 0;
  incorrect_guess_ = 0;
  round_over_ = false;
}

void Engine::GetMovieFromList() {
  ReadFile readFile;
  std::vector<std::string> movies_list = readFile.ReadFile::ReadTxtFile("C:\\Users\\SIDDHANT\\cinder_0.9.2_vc2015\\my-projects\\final-project-SiddhantGSharma\\assets\\movie_list.txt");

  if (movies_list.empty()) {
    setMovie("Game Over");
  }

  std::string movie = movies_list.back();
  movies_list.pop_back();
  setMovie(movie);
  std::vector<char> temp(movie.begin(), movie.end());
  std::vector<char> temp_two;

  for (char i : temp) {
    if (isVowel(i) || i == ' ') {
      temp_two.push_back(i);
    } else {
      temp_two.push_back('.');
    }
  }

  setMovieName(temp);
  setIncompleteMovieName(temp_two);
  setIncorrectGuess(0);
  setRoundOver(false);
}

void Engine::PlayRound() {
  if (IsCorrectGuess(getUserGuess())) {
    for (size_t i = 0; i < movie_name_.size(); i++) {
      if (movie_name_.at(i) == user_guess_) {
        incomplete_movie_name_.at(i) = user_guess_;
      }
    }
  } else {
    incorrect_guess_++;
  }

  if (movie_name_ == incomplete_movie_name_) {
    score_ += movie_name_.size();
    round_over_= true;
  }
}

bool Engine::IsCorrectGuess(char user_guess) {
  for (size_t i = 0; i < movie_name_.size(); i++) {
    if (user_guess == movie_name_.at(i) &&
        user_guess != incomplete_movie_name_.at(i)) {
      return true;
    }
  }

  return true;
}

int Engine::getScore() const { return score_; }

void Engine::setScore(int score) { score_ = score; }

int Engine::getIncorrectGuess() const { return incorrect_guess_; }

void Engine::setIncorrectGuess(int incorrectGuess) {
  incorrect_guess_ = incorrectGuess;
}

char Engine::getUserGuess() const { return user_guess_; }

void Engine::setUserGuess(char userGuess) { user_guess_ = userGuess; }

const std::vector<char>& Engine::getMovieName() const { return movie_name_; }

void Engine::setMovieName(const std::vector<char>& movieName) {
  movie_name_ = movieName;
}

bool Engine::isRoundOver() const { return round_over_; }

void Engine::setRoundOver(bool roundOver) { round_over_ = roundOver; }

const std::vector<char>& Engine::getIncompleteMovieName() const {
  return incomplete_movie_name_;
}

void Engine::setIncompleteMovieName(
    const std::vector<char>& incompleteMovieName) {
  incomplete_movie_name_ = incompleteMovieName;
}

const std::string& Engine::getMovie() const { return movie; }

void Engine::setMovie(const std::string& movie) { Engine::movie = movie; }

bool Engine::isVowel(char c) {
  for (char vowel : kVowels) {
    if (vowel == c) {
      return true;
    }
  }

  return false;
}

}