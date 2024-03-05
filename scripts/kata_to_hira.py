import sys
from collections import OrderedDict

input_file = sys.argv[1]
out_file = sys.argv[2]

with open(input_file, 'r', encoding='utf-8') as f_in:
    kompounds = f_in.readlines()


def katakana_to_hiragana(katakana_string):
    hiragana_string = ''.join(chr(ord(char) - 96) if '\u30A1' <= char <= '\u30F6' else char for char in katakana_string)
    return hiragana_string

 
 


with open(out_file, 'w', encoding='utf-8') as out:
    for line in kompounds:
        line=line.rstrip("\n")
        parts=line.split(",")
        hira = katakana_to_hiragana(parts[8])
        out.write(','.join(parts[:8])+","+hira+"\n")
