// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "hangman_app.h"

#include <cinder/app/App.h>


namespace hangman_app {

using cinder::app::KeyEvent;
using cinder::Color;

cinder::audio::VoiceRef openingSound;
cinder::audio::VoiceRef gameSound;


Hangman::Hangman()
  : state_{GameState::kPlaying},
    movie_name_{""},
    paused_{false} {};

void Hangman::setup() {
  engine_.GetMovieFromList();
  cinder::audio::SourceFileRef sourceFile = cinder::audio::load(
      cinder::app::loadAsset("mark-hamill-joker-laugh-ringtone.mp3"));
  openingSound = cinder::audio::Voice::create(sourceFile);
  openingSound->start();
}

void Hangman::update() {
  if (movie_name_ == "Game Over" || engine_.getIncorrectGuess() == 8) {
    state_ = GameState::kGameOver;
  }

  if (paused_) return;

  cinder::audio::SourceFileRef sourceFile2 = cinder::audio::load(
      cinder::app::loadAsset("01. Arkham Knight- Main Theme.mp3"));
  gameSound = cinder::audio::Voice::create(sourceFile2);

  if (!openingSound->isPlaying()) {
    if (!gameSound->isPlaying() && state_ == GameState::kPlaying) {
      gameSound->start();
    }
  }
}

void Hangman::draw() {
  cinder::gl::enableAlphaBlending();
  cinder::gl::clear(Color(0.0f,0.0f,0.0f));
  DrawBackground();
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

}  // namespace myapp
