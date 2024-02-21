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
void Kanji::appendFile(std::string filename, std::vector<std::pair<std::string, std::string>> &new_words)
{
    std::ofstream myfile;
    myfile.open(filename, std::ios_base::app);

    if (myfile.is_open())
    {

        std::cout << "append: " + filename << std::endl;

        // myfile<< "Question,Answers,Comment,Instructions,Render as\n";
        for (const auto &pair : new_words)
        {

            myfile << pair.first << "," << pair.second << "," << pair.first << " " <<this->meanings[pair.first]<<",,\n";
        }
    }
    else
    {

        std::cout << "cant append: " + filename << std::endl;
    }
}
void Kanji::writeFile(std::string filename, std::vector<std::pair<std::string, std::string>> &new_words)
{

    std::ofstream myfile;
    myfile.open(filename);

    if (myfile.is_open())
    {

        std::cout << "write: " + filename << std::endl;

        myfile << "Question,Answers,Comment,Instructions,Render as\n";
        for (const auto &pair : new_words)
        {

                 
            myfile << pair.first << "," << pair.second << "," << pair.first << " " <<this->meanings[pair.first]<<",,\n";
        }
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
    this->meanings.clear();
    std::fstream file;
    file.open(filename);
    if (file.is_open())
    {

        std::cout << "reading: " + filename << std::endl;
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

void Kanji::readFileEntries(std::string filename)
{

    this->entries.clear();
    std::stringstream ss;
    std::fstream file;
    file.open(filename);
    if (file.is_open())
    {

        std::cout << "reading: " + filename << std::endl;
        ss << file.rdbuf();

        // printDebug(ss.str());
        std::string line;
        int num = 0;
        while (ss >> line)
        {
            num++;
            if (line.length() > 2)
            {
                std::string delimiter = "、";
                std::string kanji = line.substr(0, line.find(delimiter));
                std::string hiragana = line.substr(line.find(delimiter) + delimiter.length(), line.length());

                //  std::cout << num << ": " << kanji << " ---- "<<hiragana << std::endl;

                // lines.push_back({kanji,hiragana});
                // entry[kanji]=hiragana;

                this->entries.push_back({kanji, hiragana});
            }
        }
    }
    else
    {

        std::cout << "cant open: " + filename << std::endl;
    }
}
