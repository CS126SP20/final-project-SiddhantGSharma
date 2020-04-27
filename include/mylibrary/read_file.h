//
// Created by SIDDHANT on 4/27/2020.
//

#ifndef FINALPROJECT_READ_FILE_H
#define FINALPROJECT_READ_FILE_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

namespace hangman {

class ReadFile {
 public:
  vector<string> ReadTxtFile(const string &file_path);
};

}

#endif  // FINALPROJECT_READ_FILE_H
