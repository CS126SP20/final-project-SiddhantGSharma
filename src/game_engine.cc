//
// Created by SIDDHANT on 4/27/2020.
//

#include <mylibrary/game_engine.h>

namespace hangman {

Engine::Engine() {
  score_ = 0;
  round_over_ = false;
  game_over_ = false;
}

void Engine::CreateList() {
  ReadFile readFile;
  movies_list_ = readFile.ReadFile::ReadTxtFile("C:\\Users\\SIDDHANT\\cinder_0.9.2_vc2015\\my-projects\\final-project-SiddhantGSharma\\assets\\movie_list.txt");
  GetMovieFromList();
}

void Engine::GetMovieFromList() {
  if (movies_list_.empty()) {
    game_over_ = true;
    return;
  }

  std::string movie = movies_list_.back();
  movies_list_.pop_back();
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

  while (!incorrect_guesses_.empty()) {
    incorrect_guesses_.pop_back();
  }

  setRoundOver(false);
}

void Engine::Step() {
  if (movie_name_ == incomplete_movie_name_) {
    score_ += movie_name_.size();
    round_over_= true;
  } else {
    PlayRound();
  }
}

void Engine::PlayRound() {
  if (IsCorrectGuess(getUserGuess())) {
    for (size_t i = 0; i < movie_name_.size(); i++) {
      if (movie_name_.at(i) == user_guess_) {
        incomplete_movie_name_.at(i) = user_guess_;
      }
    }
  } else {
    PopulateIncorrectGuessList();
  }
}

bool Engine::IsCorrectGuess(char user_guess) {
  for (size_t i = 0; i < movie_name_.size(); i++) {
    if (user_guess == movie_name_.at(i) &&
        user_guess != incomplete_movie_name_.at(i)) {
      return true;
    }
  }

  return false;
}

int Engine::getScore() const { return score_; }

void Engine::setScore(int score) { score_ = score; }

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

void Engine::Reset() {
  score_ = 0;
  round_over_ = false;
  user_guess_ = '\0';
  game_over_ = false;

  while (!incorrect_guesses_.empty()) {
    incorrect_guesses_.pop_back();
  }

  while (!movies_list_.empty()) {
    movies_list_.pop_back();
  }

  while (!movie_name_.empty()) {
    movie_name_.pop_back();
  }

  while (!incomplete_movie_name_.empty()) {
    incomplete_movie_name_.pop_back();
  }
}

bool Engine::isGameOver() const { return game_over_; }

void Engine::PopulateIncorrectGuessList() {
  if (isalpha(user_guess_) || isdigit(user_guess_)) {
    for (char character : movie_name_) {
      if (user_guess_ == character) return;
    }

    if (incorrect_guesses_.empty()) {
      incorrect_guesses_.push_back(user_guess_);
      return;
    }

    for (char incorrect_guess : incorrect_guesses_) {
      if (user_guess_ == incorrect_guess) {
        return;
      }
    }

    incorrect_guesses_.push_back(user_guess_);
  }
}

const std::vector<char>& Engine::getIncorrectGuesses() const {
  return incorrect_guesses_;
}

}