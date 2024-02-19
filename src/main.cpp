#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <random>
#include <map>

#include "files.hpp"

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
            printDebug(word + " " + reading);
        }
    }
}
void genWords2(std::vector<std::pair<std::string, std::string>> &entries, std::vector<std::pair<std::string, std::string>> &outwords)
{

    generateWords(entries, outwords);

    randomizePairs(entries);

    generateWords(entries, outwords, 4);
}
int main(void)
{

    std::string f1 = "n4_kanji_all.txt";
    {
        std::vector<std::pair<std::string, std::string>> entries;
        const char *filename = "data/n4_kanji_alphabet1-50.txt";

        readFile(filename, entries);

        std::vector<std::pair<std::string, std::string>> kanji;

        genWords2(entries, kanji);

        writeFile(f1, entries);
        appendFile(f1, kanji);
    }
    {
        std::vector<std::pair<std::string, std::string>> entries;
        const char *filename = "data/n4_kanji_alphabet51-100.txt";

        readFile(filename, entries);

        std::vector<std::pair<std::string, std::string>> kanji;

        genWords2(entries, kanji);

        appendFile(f1, entries);
        appendFile(f1, kanji);
    }
    {
        std::vector<std::pair<std::string, std::string>> entries;
        const char *filename = "data/n4_kanji_alphabet101-150.txt";

        readFile(filename, entries);

        std::vector<std::pair<std::string, std::string>> kanji;

        genWords2(entries, kanji);

        appendFile(f1, entries);
        appendFile(f1, kanji);
    }
    {
        std::vector<std::pair<std::string, std::string>> entries;
        const char *filename = "data/n4_kanji_alphabet151-200.txt";

        readFile(filename, entries);

        std::vector<std::pair<std::string, std::string>> kanji;

        genWords2(entries, kanji);

        appendFile(f1, entries);
        appendFile(f1, kanji);
    }
    {
        std::vector<std::pair<std::string, std::string>> entries;
        const char *filename = "data/n4_kanji_alphabet201-250.txt";

        readFile(filename, entries);

        std::vector<std::pair<std::string, std::string>> kanji;

        genWords2(entries, kanji);

        appendFile(f1, entries);
        appendFile(f1, kanji);
    }
    {
        std::vector<std::pair<std::string, std::string>> entries;
        const char *filename = "data/n4_kanji_alphabet251-end.txt";

        readFile(filename, entries);

        std::vector<std::pair<std::string, std::string>> kanji;

        genWords2(entries, kanji);

        appendFile(f1, entries);
        appendFile(f1, kanji);
    }
    {
        std::vector<std::pair<std::string, std::string>> entries;
        const char *filename = "data/n4_kanji_alphabet.txt";

        readFile(filename, entries);

        std::vector<std::pair<std::string, std::string>> kanji;

        randomizePairs(entries);
        generateWords(entries, kanji);

        randomizePairs(entries);

        generateWords(entries, kanji, 4);

        // appendFile(f1, entries);
        appendFile(f1, kanji);
    }

    //  printDebug("こんにちは漢字です");

    return 1;
}