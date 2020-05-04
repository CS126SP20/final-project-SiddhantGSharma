// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include <cinder/audio/audio.h>
#include <cinder/gl/draw.h>
#include <cinder/gl/gl.h>
#include <mylibrary/leaderboard.h>

#include "mylibrary/game_engine.h"
#include "mylibrary/player.h"

namespace hangman_app {

enum class GameState {
    kPlaying,
    kCountDown,
    kGameOver,
};

class Hangman : public cinder::app::App {
 public:
  Hangman();
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;
  void Reset();

 private:
  void DrawBackground();
  void DrawMovieName();
  void DrawGameOver();

 private:
  hangman::Engine engine_;
  hangman::LeaderBoard leaderboard_;
  GameState state_;
  std::string movie_name_;
  bool paused_;
  bool printed_game_over_;
  std::vector<hangman::Player> top_players_;
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
