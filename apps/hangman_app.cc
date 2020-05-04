// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "hangman_app.h"

#include <cinder/app/App.h>


namespace hangman_app {

using cinder::app::KeyEvent;
using cinder::Color;
using cinder::app::getWindowCenter;
using cinder::TextBox;
using cinder::ColorA;

cinder::audio::VoiceRef openingSound;
const char kNormalFont[] = "Arial";
const std::string kPlayerName = "Siddhant Sharma";
const char kDbPath[] = "hangman.db";
const int kLimit = 3;


Hangman::Hangman()
  : state_{GameState::kPlaying},
    movie_name_{""},
    paused_{false},
    printed_game_over_{false},
    leaderboard_{cinder::app::getAssetPath(kDbPath).string()} {};

void Hangman::setup() {
  engine_.CreateList();
  movie_name_ = engine_.getMovie();
  cinder::audio::SourceFileRef sourceFile = cinder::audio::load(
      cinder::app::loadAsset("01. Arkham Knight- Main Theme.mp3"));
  openingSound = cinder::audio::Voice::create(sourceFile);
  openingSound->start();
}

void Hangman::update() {
  if (engine_.isGameOver() || engine_.getIncorrectGuesses().size() == 8) {
    state_ = GameState::kGameOver;
  }

  if (state_ == GameState::kGameOver) {
    openingSound->stop();

    if (top_players_.empty()) {
      leaderboard_.AddScoreToLeaderBoard({kPlayerName, static_cast<size_t>(engine_.getScore())});
      top_players_ = leaderboard_.RetrieveHighScores(kLimit);
      // It is crucial the this vector be populated, given that `kLimit` > 0.
      assert(!top_players_.empty());
    }

    return;
  };

  if (paused_) return;

  if (engine_.isRoundOver()) {
    engine_.GetMovieFromList();
    movie_name_ = engine_.getMovie();
    return;
  }

  engine_.Step();
}

void Hangman::draw() {
  cinder::gl::enableAlphaBlending();

  if (state_ == GameState::kGameOver) {
    if (!printed_game_over_) cinder::gl::clear(Color(1, 0, 0));
    DrawGameOver();
    return;
  }

  cinder::gl::clear(Color(1,1,1));
  DrawMovieName();
  //DrawBackground();
}

void Hangman::keyDown(KeyEvent event) {
  char character = event.getChar();

  if (isalpha(character) == 0) {
    engine_.setUserGuess(character);
  }

  if (isdigit(character) == 0) {
    engine_.setUserGuess(character);
  }
}

void Hangman::DrawBackground() {
  // for personalised background image
  cinder::gl::color(1,1,1);
  cinder::gl::Texture2dRef texture = cinder::gl::Texture::create(
      cinder::loadImage(loadAsset("background 1.jpg")));
  cinder::gl::draw(texture);
}

template <typename C>
void PrintText(const std::string& text, const C& color, const cinder::ivec2& size,
               const cinder::vec2& loc) {
  cinder::gl::color(color);

  auto box = TextBox()
      .alignment(TextBox::CENTER)
      .font(cinder::Font(kNormalFont, 30))
      .size(size)
      .color(color)
      .backgroundColor(ColorA(0, 0, 0, 0))
      .text(text);

  const auto box_size = box.getSize();
  const cinder::vec2 locp = {loc.x - box_size.x / 2, loc.y - box_size.y / 2};
  const auto surface = box.render();
  const auto texture = cinder::gl::Texture::create(surface);
  cinder::gl::draw(texture, locp);
}

void Hangman::DrawMovieName() {
  const cinder::vec2 center = getWindowCenter();
  const cinder::ivec2 size = {500, 50};
  const Color color = Color::black();
  std::vector<char> to_convert = engine_.getIncompleteMovieName();
  std::string to_print(to_convert.begin(), to_convert.end());
  PrintText(to_print, color, size, center);
}

void Hangman::DrawGameOver() {
  const cinder::vec2 center = getWindowCenter();
  const cinder::ivec2 size = {500, 50};
  const Color color = Color::black();
  std::string score = std::to_string(engine_.getScore());
  PrintText("Game Over :(" + score, color, size, center);
  printed_game_over_ = true;
}

void Hangman::Reset() {
  engine_.Reset();
  state_ = GameState::kPlaying;
  movie_name_ = "";
  paused_ = false;
  printed_game_over_ = false;
}

}  // namespace myapp
