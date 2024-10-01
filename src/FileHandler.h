#ifndef FILEHANDLER_H
#define FILEHANDLER_H

class FileHandler {
public:
  FileHandler(char *fileName)
      : m_fileName(fileName), m_fileSize{0}, m_lineCount{0}, m_wordCount{0},
        m_charCount{0} {};
  FileHandler(const FileHandler &rhs);
  FileHandler &operator=(const FileHandler &rhs);
  FileHandler(FileHandler &&rhs);
  FileHandler &operator=(FileHandler &&rhs);
  void extractData();
  int fileSize();
  int lineCount();
  int wordCount();
  int charCount();
  ~FileHandler() { delete[] m_fileName; }

private:
  char *m_fileName;
  int m_fileSize;
  int m_lineCount;
  int m_wordCount;
  int m_charCount;
};
#endif