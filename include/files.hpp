#pragma once

#include <vector>
#include <string>
#include <map>

class Kanji
{
public:

  

    void readFileEntries(std::string filename );

    void readFileJouyou(std::string filename );

    void appendFile(std::string filename, std::vector<std::pair<std::string, std::string>> &new_words);

    void writeFile(std::string filename, std::vector<std::pair<std::string, std::string>> &new_words);

    void readFileRepeat(std::string filename);
    
    void filterRepeats(std::vector<std::pair<std::string, std::string>> &new_words);

private:
    static int findPosByIdx(std::string str, int idx);

    static int count_utf8(const std::string &str);

 

public:
    std::map<std::string, std::string> meanings;
    std::vector<std::pair<std::string, std::string>> entries;
    std::vector<std::string> repeats;
   
};
