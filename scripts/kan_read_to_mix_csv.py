import random
import sys

#gen reading 省上小生
input_file = sys.argv[1]
output_file = sys.argv[2]


with open(input_file, 'r', encoding='utf-8') as f_in:
    kompounds = f_in.readlines()


with open(".\\data\\jouyou.txt", 'r', encoding='utf-8') as f_in:
    jouyou = f_in.readlines()

joumap={}
for l in jouyou:
    l=l.rstrip("\n")
    parts=l.split(",")
    joumap[parts[1]]=parts

readings={}

words_1=[]
for line in kompounds:
    line=line.rstrip("\n");
    items=line.split(",")
    readings[items[0]]=items[1]
    words_1.append(items[0])




with open(output_file, "w",encoding='utf-8') as file:
    file.write("Question,Answers,Comment,Instructions,Render as\n")

    random.shuffle(words_1)

    sub_arrays = [words_1[i:i+50] for i in range(0, len(words_1), 50)]

    for sub in sub_arrays:
        l1 = lambda v: file.write(v+","+joumap[v][8]+","+v+","+joumap[v][7]+",\n")
        list(map(l1,sub))
        combined = [sub[i:i+4] for i in range(0, len(sub), 4)]
        for com in combined:
            s1="".join(com)
            file.write(s1+",")
            l2 = lambda v: file.write(joumap[v][8])
            list(map(l2,com))
            file.write(","+s1+",,\n")

    random.shuffle(words_1)
    sub_arrays = [words_1[i:i+50] for i in range(0, len(words_1), 50)]

    for sub in sub_arrays:
        #l1 = lambda v: file.write(v+","+readings[v]+","+v+",,\n")
        #list(map(l1,sub))
        combined = [sub[i:i+4] for i in range(0, len(sub), 4)]
        for com in combined:
            s1="".join(com)
            file.write(s1+",")
            l2 = lambda v: file.write(joumap[v][8])
            list(map(l2,com))
            file.write(","+s1+",,\n")

# combined = [words_1[i:i+4] for i in range(0, len(words_1), 4)]

# print(readings)

# print(combined)

