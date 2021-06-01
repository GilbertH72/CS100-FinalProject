#ifndef __FILE_READER_H__
#define __FILE_READER_H__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class FileReader {
public:
   std::vector<std::string> typeStatus;
   FileReader() {};
   FileReader(std::string fileName)
   {
      std::string word;
      std::ifstream file(fileName);
      if (file.is_open())
      {
         while (file >> word)
         {
            typeStatus.push_back(word);

            // file.get() allows us to obtain the newline character
            file.get();
         }
         file.close();
      }
      else
      {
         std::cout << "ERROR! Unable to open file.." << std::endl;
      }
   }
   int size() const { return typeStatus.size(); }

};

#endif
