#!/bin/bash

#lists words that have input kanji
#words to check against jisho.org

freq="../data/freq_2022_10k.txt"
script_dir=$(dirname "$0")

grep -E -e "$1" "$script_dir/$freq" | awk -F '、' '{print $3  ($4 != "" ? "、"$4 : "")}'