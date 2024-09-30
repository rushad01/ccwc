#include "FileHandler.h"
#include <algorithm>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>

FileHandler::FileHandler(const FileHandler &rhs)
    : m_filename(new char[std::strlen(rhs.m_filename) + 1]) {
  // copy constructor
}

FileHandler::FileHandler(FileHandler &&rhs) : m_filename(rhs.m_filename) {
  // move constructor
  rhs.m_filename = nullptr;
}

FileHandler &FileHandler::operator=(const FileHandler &rhs) {
  // copy assignment
  if (this == &rhs)
    return *this;

  delete[] this->m_filename;
  m_filename = new char[std::strlen(rhs.m_filename) + 1];
  std::strcpy(m_filename, rhs.m_filename);

  return *this;
}
FileHandler &FileHandler::operator=(FileHandler &&rhs) {
  // move assignment
  if (this == &rhs)
    return *this;

  delete[] this->m_filename;
  m_filename = rhs.m_filename;
  rhs.m_filename = nullptr;
  return *this;
}

int FileHandler::fileSize() {
  std::filesystem::path textFile = m_filename;
  return std::filesystem::file_size(textFile);
}

int FileHandler::lineCount() {
  std::ifstream myTextFile(m_filename);
  myTextFile.unsetf(std::ios_base::skipws);

  unsigned line_cout = std::count(std::istream_iterator<char>(myTextFile),
                                  std::istream_iterator<char>(), '\n');

  return line_cout;
}

int FileHandler::wordCount() {
  std::ifstream mytextFile;
  mytextFile.open(m_filename);
  std::string line;
  int numLines{0};
  int numWord{0};
  while (std::getline(mytextFile, line)) {
    numLines++;

    std::stringstream lineStream(line);
    while (std::getline(lineStream, line, ' ')) {
      numWord++;
    }
  }
  mytextFile.close();
  return numWord;
}

int FileHandler::charCount() {
  std::fstream myTextFile(m_filename);
  myTextFile.seekg(0, std::ios_base::end);
  std::streampos end_pos = myTextFile.tellg();
  return end_pos;
}