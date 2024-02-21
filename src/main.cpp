#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <random>
#include <map>

#include "files.hpp"

void randomizeEntries(std::vector<std::pair<std::string, std::string>> &out_entries)
{

    auto rng = std::default_random_engine{};
    std::shuffle(std::begin(out_entries), std::end(out_entries), rng);
}

void generateWords(
    std::vector<std::pair<std::string, std::string>> &entries,
    std::vector<std::pair<std::string, std::string>> &out,
    int len = 6)
{
    std::string word;
    std::string reading;

    int word_cnt = 0;
    std::stringstream buff;
    std::stringstream onyomi;

    // gen kanjis
    for (const auto &pair : entries)
    {

        buff << pair.first;
        word_cnt++;
        onyomi << pair.second;
        // just add them for now. phonology too thin

        if (word_cnt >= len)
        {
            word_cnt = 0;
            word = buff.str();
            buff.str("");

            reading = onyomi.str();
            onyomi.str("");
            out.push_back({word, reading});

            std::cout << word + " " + reading << std::endl;
        }
    }
}

void genWordsN4()
{
    Kanji kan;
    kan.readFileJouyou("data/jouyou_v5.txt");
    std::string fout = "out_n4_kanji_all.txt";

    {
        const char *filename = "data/n4_kanji_alphabet1-50.txt";

        kan.readFileEntries(filename);

        std::vector<std::pair<std::string, std::string>> copy_entries(kan.entries);

        std::vector<std::pair<std::string, std::string>> kanji_words;

        randomizeEntries(copy_entries);

        generateWords(copy_entries, kanji_words);

        randomizeEntries(copy_entries);

        generateWords(copy_entries, kanji_words, 4);

        kan.writeFile(fout, copy_entries);

        kan.appendFile(fout, kanji_words);

      
    }
    {
        const char *filename = "data/n4_kanji_alphabet51-100.txt";

        kan.readFileEntries(filename);

        std::vector<std::pair<std::string, std::string>> copy_entries(kan.entries);

        std::vector<std::pair<std::string, std::string>> kanji_words;

        randomizeEntries(copy_entries);

        generateWords(copy_entries, kanji_words);

        randomizeEntries(copy_entries);

        generateWords(copy_entries, kanji_words, 4);

        kan.appendFile(fout, copy_entries);

        kan.appendFile(fout, kanji_words);

     
    }
    {
        const char *filename = "data/n4_kanji_alphabet101-150.txt";

        kan.readFileEntries(filename);

        std::vector<std::pair<std::string, std::string>> copy_entries(kan.entries);

        std::vector<std::pair<std::string, std::string>> kanji_words;

        randomizeEntries(copy_entries);

        generateWords(copy_entries, kanji_words);

        randomizeEntries(copy_entries);

        generateWords(copy_entries, kanji_words, 4);

        kan.appendFile(fout, copy_entries);

        kan.appendFile(fout, kanji_words);

    
    }
    {
        const char *filename = "data/n4_kanji_alphabet151-200.txt";

        kan.readFileEntries(filename);

        std::vector<std::pair<std::string, std::string>> copy_entries(kan.entries);

        std::vector<std::pair<std::string, std::string>> kanji_words;

        randomizeEntries(copy_entries);

        generateWords(copy_entries, kanji_words);

        randomizeEntries(copy_entries);

        generateWords(copy_entries, kanji_words, 4);

        kan.appendFile(fout, copy_entries);

        kan.appendFile(fout, kanji_words);

       
    }
    {
        const char *filename = "data/n4_kanji_alphabet201-250.txt";

        kan.readFileEntries(filename);

        std::vector<std::pair<std::string, std::string>> copy_entries(kan.entries);

        std::vector<std::pair<std::string, std::string>> kanji_words;

        randomizeEntries(copy_entries);

        generateWords(copy_entries, kanji_words);

        randomizeEntries(copy_entries);

        generateWords(copy_entries, kanji_words, 4);

        kan.appendFile(fout, copy_entries);

        kan.appendFile(fout, kanji_words);

     
    }
    {
        const char *filename = "data/n4_kanji_alphabet251-end.txt";

        kan.readFileEntries(filename);

        std::vector<std::pair<std::string, std::string>> copy_entries(kan.entries);

        std::vector<std::pair<std::string, std::string>> kanji_words;

        randomizeEntries(copy_entries);

        generateWords(copy_entries, kanji_words);

        randomizeEntries(copy_entries);

        generateWords(copy_entries, kanji_words, 4);

        kan.appendFile(fout, copy_entries);

        kan.appendFile(fout, kanji_words);

  
    }
    {
        const char *filename = "data/n4_kanji_alphabet.txt";

        kan.readFileEntries(filename);

        std::vector<std::pair<std::string, std::string>> copy_entries(kan.entries);

        std::vector<std::pair<std::string, std::string>> kanji_words;

        randomizeEntries(copy_entries);

        generateWords(copy_entries, kanji_words);

        randomizeEntries(copy_entries);

        generateWords(copy_entries, kanji_words, 4);

        kan.appendFile(fout, kanji_words);

      
    }
}
int main(void)
{

    genWordsN4();

    return 1;
}