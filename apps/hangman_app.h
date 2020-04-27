// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include <cinder/gl/draw.h>
#include <cinder/gl/gl.h>
#include <cinder/audio/audio.h>

namespace hangman_app {

class Hangman : public cinder::app::App {
 public:
  Hangman();
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;
  void Hangman::DrawBackground();
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
