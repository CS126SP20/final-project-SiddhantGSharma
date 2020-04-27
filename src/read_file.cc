//
// Created by SIDDHANT on 4/27/2020.
//

#include <hangman/read_file.h>

namespace hangman {

vector<string> ReadFile::ReadTxtFile(const string &file_path) {
  vector<string> movies_list;
  fstream movies_list_file;
  movies_list_file.open(file_path);
  string line;
  getline(movies_list_file, line);

  while (getline(movies_list_file, line)) {
    movies_list.push_back(line);
  }

  return movies_list;
}

}