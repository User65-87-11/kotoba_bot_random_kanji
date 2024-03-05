import sys
from collections import OrderedDict

input_file = sys.argv[1]
out_file = sys.argv[2]

with open(input_file, 'r', encoding='utf-8') as f_in:
    kompounds = f_in.readlines()


def katakana_to_hiragana(katakana_string):
    hiragana_string = ''.join(chr(ord(char) - 96) if '\u30A1' <= char <= '\u30F6' else char for char in katakana_string)
    return hiragana_string

with open(".\\data\\jouyou_v5.txt", 'r', encoding='utf-8') as f_in:
    jouyou = f_in.readlines()


out_lines=OrderedDict()


for line in kompounds:
    parts=line.split(",")
    out_lines[int(parts[0])]=line
    


cnt=0
for line in jouyou:
    parts=line.split(",")
    k=int(parts[0])
    if k not in out_lines:
        cnt+=1
        out_lines[k]=line

print("added:",cnt)

sorted_dict = OrderedDict(sorted(out_lines.items()))

with open(out_file, 'w', encoding='utf-8') as out:
    for _,v in sorted_dict.items():
        out.write(v)



# cnt=0
# with open(out_file, 'w', encoding='utf-8') as out:
#     for line in kompounds:
#         cnt+=1
#         line=line.rstrip("\n")
#         parts=line.split(",")
#         diff = int(parts[0]) - cnt
#         if  diff > 0:
#             for i in range(diff):
#                 out.write(jouyou[cnt+i])

#             cnt+=diff        
#         out.write(line+"\n")
     #   hira = katakana_to_hiragana(parts[8])
      #  out.write(','.join(parts[:8])+","+hira+"\n")
