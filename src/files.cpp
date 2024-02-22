#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>
#include <random>
#include "files.hpp"

int Kanji::count_utf8(const std::string &str)
{
    int count = 0;
    for (char c : str)
    {
        if ((c & 0xC0) != 0x80)
        {
            count++;
        }
    }
    return count;
}

int Kanji::findPosByIdx(std::string str, int idx)
{
    int pos = 0;

    for (int i = 0; i < idx; i++)
    {
        pos = str.find(',', pos);
        pos++;
    }

    return pos;
}
void Kanji::filterRepeats(std::vector<std::pair<std::string, std::string>> &new_words)
{

    std::vector<std::string> rep = this->repeats;

    new_words.erase(std::remove_if(new_words.begin(), new_words.end(), [&rep](const std::pair<std::string, std::string> &pair)
                                   {
                                       for (const auto &st : rep)
                                       {
                                           if (pair.first.substr(0, st.size()) == st)
                                           {
                                                return false;
                                               
                                           }
                                       }

                                       return true; 
                                       
                                    }),
                    new_words.end());
}
void Kanji::appendFile(std::string filename, std::vector<std::pair<std::string, std::string>> &new_words)
{
    std::cout << "appendFile: " + filename << std::endl;
    std::ofstream myfile;
    myfile.open(filename, std::ios_base::app);

    if (myfile.is_open())
    {

        // myfile<< "Question,Answers,Comment,Instructions,Render as\n";
        for (const auto &pair : new_words)
        {
           // std::cout << " pair: " << pair.first << " " << pair.second <<std::endl;
            myfile << pair.first << "," << pair.second << "," << pair.first << " " << this->meanings[pair.first] << ",,\n";
        }
    }
    else
    {

        std::cout << "cant append: " + filename << std::endl;
    }
}
void Kanji::writeFileHeader(std::string filename)
{
    std::cout << "writeFileHeader: " + filename << std::endl;
    std::ofstream myfile;
    myfile.open(filename);

    if (myfile.is_open())
    {

        myfile << "Question,Answers,Comment,Instructions,Render as\n";
        
    }
    else
    {
        std::cout << "cant write: " + filename << std::endl;
    }

    // outFile << ss.rdbuf();
}

void Kanji::readFileJouyou(std::string filename)
{

    // std::stringstream ss;
    std::cout << "readFileJouyou: " + filename << std::endl;
    this->meanings.clear();
    std::fstream file;
    file.open(filename);

    if (file.is_open())
    {

        //  ss << file.rdbuf();

        // printDebug(ss.str());
        std::string line;
        int num = 0;
        while (std::getline(file, line))
        {
            num++;
            if (line.length() > 2)
            {

                int pos1 = findPosByIdx(line, 1);
                int len = findPosByIdx(line, 2) - pos1 - 1;
                std::string kanji = line.substr(pos1, len);

                //   std::cout<<    line << std::endl;

                pos1 = findPosByIdx(line, 7);
                len = findPosByIdx(line, 8) - pos1 - 1;
                std::string meaning = line.substr(pos1, len);

                // lines.push_back({kanji,hiragana});
                this->meanings[kanji] = meaning;
                // std::cout << this->meanings[kanji]  << std::endl;
                // entry.push_back({kanji,hiragana});
            }
        }
    }
    else
    {

        std::cout << "cant open: " + filename << std::endl;
    }
}
void Kanji::readFileRepeat(std::string filename)
{
    std::cout << "readFileRepeat: " + filename << std::endl;

    this->repeats.clear();
    std::stringstream ss;
    std::fstream file;
    file.open(filename);
    if (file.is_open())
    {

        ss << file.rdbuf();

        // printDebug(ss.str());
        std::string line;

        while (ss >> line)
        {


            if (line.length() > 2)
            {

                this->repeats.push_back(line);
            }
        }
    }
    else
    {

        std::cout << "cant open: " + filename << std::endl;
    }
}
void Kanji::readFileEntries(std::string filename)
{
    std::cout << "readFileEntries: " + filename << std::endl;
    this->entries.clear();
    std::stringstream ss;
    std::fstream file;
    file.open(filename);
    if (file.is_open())
    {

        ss << file.rdbuf();

    
        std::string line;
       
        while (ss >> line)
        {
           
          

            if (line.length() > 2)
            {
                std::string delimiter = "、";
                std::string kanji = line.substr(0, line.find(delimiter));
                std::string hiragana = line.substr(line.find(delimiter) + delimiter.length(), line.length());

                  std::cout << ": " << kanji << " ---- "<<hiragana << std::endl;

                // lines.push_back({kanji,hiragana});
                // entry[kanji]=hiragana;

                this->entries.push_back({kanji, hiragana});
            }
        }
    }
    else
    {

        std::cout << "cant open : " + filename << std::endl;
    }

     std::cout << "total entries: " << this->entries.size() << std::endl;
    
}
