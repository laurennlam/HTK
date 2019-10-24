#include "htkWriteOutputFile.h"

#include <iostream>
#include <fstream>

void htk::common::io::WriteOutputFile(const std::string& filePath, const std::string& content,
  const bool appendContent)
{
  std::ofstream myfile;
  if (appendContent)
  {
    myfile.open(filePath, std::ios::app);
  }
  else
  {
    myfile.open(filePath);
  }
  myfile << content.c_str();
  myfile.close();
}
