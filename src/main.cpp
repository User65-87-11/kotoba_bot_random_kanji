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

            //  std::cout << word + " " + reading << std::endl;
        }
    }
}
void genWordsN4Entries()
{
    Kanji kan;
    kan.readFileJouyou("data/jouyou_v5.txt");
    std::string fout = "out_n4_kanji_single.csv";

    const char *filename = "data/n4_kanji_alphabet.txt";
    kan.writeFileHeader(fout);
    kan.readFileEntries(filename);

    {

        std::vector<std::pair<std::string, std::string>> copy_entries(kan.entries);

        std::vector<std::pair<std::string, std::string>> kanji_words;

        kan.appendFile(fout, copy_entries);
    }
}
void genWordsN4Repeat()
{
    Kanji kan;
    kan.readFileJouyou("data/jouyou_v5.txt");
    kan.readFileRepeat("data/repeat_these.txt");

    if (kan.repeats.size() == 0)
    {
        std::cout << "no repeats yet " << std::endl;
        return;
    };
    std::string fout = "out_n4_repeat.csv";

     kan.writeFileHeader(fout);
    {
        const char *filename = "data/n4_kanji_alphabet.txt";

        kan.readFileEntries(filename);

        std::vector<std::pair<std::string, std::string>> copy_entries(kan.entries);

        kan.filterRepeats(copy_entries);

        std::vector<std::pair<std::string, std::string>> kanji_words;

        generateWords(copy_entries, kanji_words);

        kan.appendFile(fout, copy_entries);
        kan.appendFile(fout, kanji_words);
    }
}

void genWordsN4()
{
    Kanji kan;
    kan.readFileJouyou("data/jouyou_v5.txt");
    std::string fout = "out_n4_kanji_all.csv";
    const char *filename = "data/n4_kanji_alphabet.txt";
    kan.readFileEntries(filename);

    kan.writeFileHeader(fout);

    for (int i = 0; i < kan.entries.size(); i += 50)
    {
        {
            int right_margin = i + 50;
            if (right_margin > kan.entries.size())
            {
                right_margin = kan.entries.size();
            }

            std::vector<std::pair<std::string, std::string>> copy_entries;

            std::copy(kan.entries.begin() + i, kan.entries.begin() + right_margin, std::back_inserter(copy_entries));

            std::vector<std::pair<std::string, std::string>> kanji_words;

            randomizeEntries(copy_entries);

            generateWords(copy_entries, kanji_words);

            randomizeEntries(copy_entries);

            generateWords(copy_entries, kanji_words, 4);

            kan.appendFile(fout, copy_entries);

            kan.appendFile(fout, kanji_words);
        }
    }
    
}
int main(void)
{

    genWordsN4();

    genWordsN4Entries();

    genWordsN4Repeat();
    return 1;
}