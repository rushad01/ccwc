#include "FileHandler.h"
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <sstream>
#include <string>

FileHandler::FileHandler(const FileHandler &rhs)
    : m_fileName{new char[std::strlen(rhs.m_fileName) + 1]},
      m_fileSize{rhs.m_fileSize}, m_lineCount{rhs.m_lineCount},
      m_wordCount{rhs.m_wordCount}, m_charCount{rhs.m_charCount} {
  // copy constructor
}

FileHandler::FileHandler(FileHandler &&rhs)
    : m_fileName(rhs.m_fileName), m_fileSize(std::move(rhs.m_fileSize)),
      m_lineCount(std::move(rhs.m_lineCount)),
      m_wordCount(std::move(rhs.m_wordCount)),
      m_charCount(std::move(rhs.m_charCount)) {
  // move constructor
  rhs.m_fileName = nullptr;
}

FileHandler &FileHandler::operator=(const FileHandler &rhs) {
  // copy assignment
  if (this == &rhs)
    return *this;

  delete[] this->m_fileName;
  m_fileName = new char[std::strlen(rhs.m_fileName) + 1];
  std::strcpy(m_fileName, rhs.m_fileName);
  m_fileSize = rhs.m_fileSize;
  m_lineCount = rhs.m_lineCount;
  m_wordCount = rhs.m_wordCount;
  m_charCount = rhs.m_charCount;

  return *this;
}
FileHandler &FileHandler::operator=(FileHandler &&rhs) {
  // move assignment
  if (this == &rhs)
    return *this;

  delete[] this->m_fileName;
  m_fileName = std::move(rhs.m_fileName);
  m_fileSize = std::move(rhs.m_fileSize);
  m_lineCount = std::move(rhs.m_lineCount);
  m_wordCount = std::move(rhs.m_wordCount);
  m_charCount = std::move(rhs.m_charCount);
  rhs.m_fileName = nullptr;
  return *this;
}

void FileHandler::extractData() {
  // file size
  std::filesystem::path textFile = m_fileName;
  m_fileSize = std::filesystem::file_size(textFile);

  std::ifstream mytextFile;
  mytextFile.open(m_fileName);

  // character count
  mytextFile.seekg(0, std::ios_base::end);
  m_charCount = mytextFile.tellg();
  mytextFile.seekg(0, std::ios_base::beg);
  std::string line;

  // line and word count
  while (std::getline(mytextFile, line)) {
    m_lineCount++;

    std::stringstream lineStream(line);
    while (std::getline(lineStream, line, ' ')) {
      m_wordCount++;
    }
  }
  mytextFile.close();
}

int FileHandler::fileSize() { return m_fileSize; }

int FileHandler::lineCount() { return m_lineCount; }

int FileHandler::wordCount() { return m_wordCount; }

int FileHandler::charCount() { return m_charCount; }