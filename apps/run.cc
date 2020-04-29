// Copyright (c) 2020 [Your Name]. All rights reserved.

#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>

#include "hangman_app.h"

using cinder::app::App;
using cinder::app::RendererGl;


namespace myapp {

const int kSamples = 8;
const int kWidth = 1572;
const int kHeight = 884;

void SetUp(App::Settings* settings) {
  settings->setWindowSize(kWidth, kHeight);
  settings->setTitle("Hangman Gotham");
}

}  // namespace myapp


// This is a macro that runs the application.
CINDER_APP(hangman_app::Hangman,
           RendererGl(RendererGl::Options().msaa(myapp::kSamples)),
           myapp::SetUp)
