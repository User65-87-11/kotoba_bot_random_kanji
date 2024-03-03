# Open the files
with open('..\\data\\jouyou_v5.txt', 'r', encoding='utf-8') as f1, open('..\\data\\freq_2022_10k.txt', 'r', encoding='utf-8') as f2:
    # Read the contents of the files
    file1_lines = f1.readlines()
    file2_lines = f2.readlines()
 
entry_count_map = {}

# Initialize a counter
count = 0

# Iterate through the lines of file2
for line in file1_lines:
 
    parts1 = line.split(',')
    k=parts1[1]
    for line2 in file2_lines:
        parts2 = line2.split('、')
        s=parts2[2]
      #  print("Entry:", k, " Entry2:", s)
        if k in s:
            if k in  entry_count_map:
                entry_count_map[k] +=1
            else:
                entry_count_map[k] = 1
        
#print(entry_count_map)
entry_above={}
cnt=0
with open('freq2more.txt', 'w',encoding='utf-8') as f:
    for entry, count in entry_count_map.items():
        if count > 1:
            cnt+=1
            f.write(entry + '\n')
            entry_above[entry] = count

print("Above 1:",len(entry_above))     
     
with open('jouyou_a1.txt', 'w',encoding='utf-8') as ff:
    for entry, count in entry_above.items():
        for line in file1_lines:
            parts1 = line.split(',')
            k=parts1[1]
            if entry == k:
                 
                ff.write(line )
            

