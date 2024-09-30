#ifndef FILEHANDLER_H
#define FILEHANDLER_H

class FileHandler {
public:
  FileHandler(char *fileName) : m_filename(fileName){};
  FileHandler(const FileHandler &rhs);
  FileHandler &operator=(const FileHandler &rhs);
  FileHandler(FileHandler &&rhs);
  FileHandler &operator=(FileHandler &&rhs);
  int fileSize();
  int lineCount();
  int wordCount();
  int charCount();
  ~FileHandler() { delete[] m_filename; }

private:
  char *m_filename;
};
#endif