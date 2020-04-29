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
  std::vector<std::string> ReadTxtFile(const std::string &file_path);
};

}

#endif  // FINALPROJECT_READ_FILE_H
