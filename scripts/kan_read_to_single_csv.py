import sys

#kanji,reading type of file to csv

input_file = sys.argv[1]
output_file = sys.argv[2]


with open(input_file, 'r', encoding='utf-8') as f_in:
    lines = f_in.readlines()

with open(".\\data\\jouyou.txt", 'r', encoding='utf-8') as f_in:
    jouyou = f_in.readlines()

joumap={}
for l in jouyou:
    l=l.rstrip("\n")
    parts=l.split(",")
    joumap[parts[1]]=parts

with open(output_file, "w",encoding='utf-8') as f_out:
    f_out.write("Question,Answers,Comment,Instructions,Render as\n")
    for line in lines:
        line=line.rstrip("\n")
        parts=line.split(",")
        f_out.write(parts[0]+","+joumap[parts[0]][8]+","+line.split(",")[0]+","+joumap[parts[0]][7]+",\n")
