import sys

#kanji,reading type of file to csv

input_file = sys.argv[1]
output_file = sys.argv[2]


with open(input_file, 'r', encoding='utf-8') as f_in:
    lines = f_in.readlines()



with open(output_file, "w",encoding='utf-8') as f_out:
    f_out.write("Question,Answers,Comment,Instructions,Render as\n")
    for line in lines:
        line=line.rstrip("\n")
        f_out.write(line+","+line.split(",")[0]+",,\n")
