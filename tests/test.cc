// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <cinder/Rand.h>

#include <mylibrary/game_engine.h>
#include <mylibrary/read_file.h>
#include <mylibrary/leaderboard.h>

using std::string;
using std::vector;

TEST_CASE("Reading from a text file") {
  std::vector<std::string> test_movies_list = hangman::ReadFile::ReadTxtFile("C:\\Users\\SIDDHANT\\cinder_0.9.2_vc2015\\my-projects\\final-project-SiddhantGSharma\\assets\\movie_list.txt");

  REQUIRE(test_movies_list.size() == 6);
  REQUIRE(test_movies_list.at(2) == "The Dark Knight Rises");
}

TEST_CASE("Create and get movie from list") {
  hangman::Engine engine;
  engine.CreateList();
  std::vector<std::string> movies_list = engine.getMoviesList();

  REQUIRE(movies_list.at(1) == "The Dark Knight");

  SECTION("Getting movie from list") {
    REQUIRE(movies_list.size() == 5);
    REQUIRE(engine.getMovie() == "Under The Redhood");
    REQUIRE_FALSE(engine.isRoundOver());
    REQUIRE(engine.getIncorrectGuesses().empty());

    SECTION("Movie name vector") {
      std::vector<char> testing_vector{'U', 'n', 'd', 'e', 'r', ' ', 'T', 'h', 'e', ' ', 'R', 'e', 'd', 'h', 'o', 'o', 'd'};
      REQUIRE(engine.getMovieName() == testing_vector);
    }

    SECTION("Incomplete movie name vector") {
      std::vector<char> testing_vector{'U', '-', '-', 'e', '-', ' ', '-', '-', 'e', ' ', '-', 'e', '-', '-', 'o', 'o', '-'};
      REQUIRE(engine.getIncompleteMovieName() == testing_vector);
    }

    SECTION("Getting movie from list a second time") {
      engine.GetMovieFromList();
      movies_list = engine.getMoviesList();

      REQUIRE(movies_list.size() == 4);
    }
  }
}

TEST_CASE("Is correct guess") {
  hangman::Engine engine;
  engine.CreateList();

  REQUIRE(engine.IsCorrectGuess('R'));
  REQUIRE(engine.IsCorrectGuess('d'));
  REQUIRE_FALSE(engine.IsCorrectGuess('4'));
}

TEST_CASE("Populate incorrect guess list") {
  hangman::Engine engine;
  engine.setUserGuess('e');
  engine.PopulateIncorrectGuessList();
  REQUIRE(engine.getIncorrectGuesses().size() == 1);

  engine.setUserGuess('f');
  engine.PopulateIncorrectGuessList();
  REQUIRE(engine.getIncorrectGuesses().size() == 2);

  SECTION("Avoid repetition of incorrect characters") {
    engine.PopulateIncorrectGuessList();
    REQUIRE(engine.getIncorrectGuesses().size() == 2);
  }
}

TEST_CASE("Is a character vowel") {
  hangman::Engine engine;
  REQUIRE(engine.isVowel('a'));
  REQUIRE_FALSE(engine.isVowel('z'));
  REQUIRE_FALSE(engine.isVowel('3'));
}