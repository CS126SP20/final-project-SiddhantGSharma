// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "hangman_app.h"

#include <cinder/app/App.h>


namespace hangman_app {

using cinder::app::KeyEvent;
using cinder::Color;

cinder::audio::VoiceRef openingSound;

Hangman::Hangman() { }

void Hangman::setup() {
  setWindowSize(1572,884);
  cinder::audio::SourceFileRef sourceFile = cinder::audio::load(
      cinder::app::loadAsset("mark-hamill-joker-laugh-ringtone.mp3"));
  openingSound = cinder::audio::Voice::create(sourceFile);
  openingSound->start();
}

void Hangman::update() { }

void Hangman::draw() {
  cinder::gl::enableAlphaBlending();
  cinder::gl::clear(Color(0.0f,0.0f,0.0f));
  DrawBackground();
}

void Hangman::keyDown(KeyEvent event) { }

void Hangman::DrawBackground() {
  // for personalised background image
  cinder::gl::color(1,1,1);
  cinder::gl::Texture2dRef texture = cinder::gl::Texture::create(
      cinder::loadImage(loadAsset("background 1.jpg")));
  cinder::gl::draw(texture);
}

}  // namespace myapp
