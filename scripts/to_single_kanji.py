from collections import OrderedDict
import sys

input_file = sys.argv[1]
output_file = sys.argv[2]



with open(input_file, 'r', encoding='utf-8') as f_in:
    kompounds = f_in.readlines()

separator = ","

split_and_get_first = lambda s: s.split(separator)[0]

result = list(map(split_and_get_first, kompounds))    

kanji_set=set()

 
for kanji in result:
    for kan in kanji:
        kanji_set.add(kan)


with open(output_file, "w",encoding='utf-8') as file:
    for kanji in kanji_set:
        file.write(kanji+",\n")
        for comp in kompounds:
            if kanji in comp:
               file.write("*"+comp)


# print("size: ",len(kanji_set))
# print(kanji_set)


# jouyou="data\\jouyou_a1_fixed.txt"

# with open(jouyou, 'r', encoding='utf-8') as f_jou:
#     jou_lines=f_jou.readlines()

# separator=","

# split_and_get_first = lambda s:(s.split(separator)[1], s.split(separator)[8].rstrip("\n"))

# jou_list = list(map(split_and_get_first, jou_lines))

# kanji_reading_all = OrderedDict(jou_list)


# for kanji in kanji_set:
#     if kanji in kanji_reading:
#         print(kanji," ",kanji_reading[kanji])


 