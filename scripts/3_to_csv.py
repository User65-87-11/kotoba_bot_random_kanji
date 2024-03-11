import sys

#gen reading 省上小生
input_file = sys.argv[1]
output_file = sys.argv[2]


with open(input_file, 'r', encoding='utf-8') as f_in:
    kompounds = f_in.readlines()
    
with open(output_file, "w",encoding='utf-8') as file:
    file.write("Question,Answers,Comment,Instructions,Render as\n")
    for line in kompounds:
        line=line.rstrip("\n")
        file.write(line+",,\n")