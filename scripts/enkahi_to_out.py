import sys

#gen reading 省上小生
input_file = sys.argv[1]
output_file = sys.argv[2]
order=sys.argv[3] #012 of input

if len(input_file) == 0 :
    print("[input] file not specified")
    exit()

if len(output_file) == 0 :
    print("[output] file not specified")
    exit()

if len(order) == 0:
    print("[order] not specified")
    exit()


with open(input_file, 'r', encoding='utf-8') as f_in:
    kompounds = f_in.readlines()
    
with open(output_file, "w",encoding='utf-8') as file:
    file.write("Question,Answers,Comment,Instructions,Render as\n")
    for line in kompounds:
        line=line.rstrip("\n")
        if len(line) < 5 :
            continue
        parts=line.split(",")
        file.write(parts[int(order[0])]+","+parts[int(order[1])]+","+parts[int(order[2])]+",,\n")