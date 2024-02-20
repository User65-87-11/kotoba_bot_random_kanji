#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>
#include <random>


void randomizePairs( std::vector<std::pair<std::string,std::string>> &lines)
{

    auto rng = std::default_random_engine{};
    std::shuffle(std::begin(lines), std::end(lines), rng);
}

 

int count_utf8(const std::string &str)
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
void printDebug(std::string msg)
{
    std::cout << msg << "[" << count_utf8(msg) << "]" << std::endl;
}
void appendFile(std::string filename, std::vector<std::pair<std::string,std::string>> &new_words)
{
     std::ofstream myfile;
    myfile.open(filename,std::ios_base::app);

    if (myfile.is_open())
    {

        printDebug("append: " + filename);

       // myfile<< "Question,Answers,Comment,Instructions,Render as\n";
       for (const auto& pair : new_words) {
            
            myfile<<pair.first<<","<<pair.second<<","<<pair.first<<",,\n";
        }
    }
    else
    {
        printDebug("cant append: " + filename);
    }

}
void writeFile(std::string filename, std::vector<std::pair<std::string,std::string>> &new_words)
{

    std::ofstream myfile;
    myfile.open(filename);

    if (myfile.is_open())
    {

        printDebug("write: " + filename);

        myfile<< "Question,Answers,Comment,Instructions,Render as\n";
        for (const auto& pair : new_words)
         {
            
            myfile<<pair.first<<","<<pair.second<<","<<pair.first<<",,\n";
        }
    }
    else
    {
        printDebug("cant write: " + filename);
    }

    // outFile << ss.rdbuf();
}

void readFile(std::string filename, std::vector<std::pair<std::string,std::string>>  &entry)
{

    std::stringstream ss;
    std::fstream file;
    file.open(filename);
    if (file.is_open())
    {
        printDebug("reading: " + filename);
        ss << file.rdbuf();

        //printDebug(ss.str());
        std::string line;
        int num = 0;
        while (ss >> line)
        {
            num++;
            if (line.length() > 2)
            {
                std::string delimiter = "、";
                std::string kanji = line.substr(0, line.find(delimiter));
                std::string hiragana = line.substr(line.find(delimiter)+delimiter.length(),line.length());
                

              //  std::cout << num << ": " << kanji << " ---- "<<hiragana << std::endl;

               // lines.push_back({kanji,hiragana});
               //entry[kanji]=hiragana;
               entry.push_back({kanji,hiragana});
            }
        }
    }
    else
    {
        printDebug("cant open: " + filename);
    }
}
