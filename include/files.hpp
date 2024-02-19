#pragma once

#include <vector>
#include <string>
#include <map> 

 
void randomizePairs( std::vector<std::pair<std::string,std::string>>  &lines);

void printDebug(std::string msg);

int count_utf8(const std::string& str) ;

void readFile(std::string filename, std::vector<std::pair<std::string,std::string>>  &entry);

void writeFile(std::string filename, std::vector<std::pair<std::string,std::string>> &new_words);

void appendFile(std::string filename, std::vector<std::pair<std::string,std::string>> &new_words);