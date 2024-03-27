import sys

#gen reading 省上小生
target_file = sys.argv[1]
replace_with_file = sys.argv[2]
output_file = sys.argv[3]

target_map = {}

with open(target_file, 'r', encoding='utf-8') as f_in:
    for line in f_in:
        target_lines = line.rstrip("\n")
        target_map[target_lines] = target_lines+"\n"

with open(replace_with_file, 'r', encoding='utf-8') as f_in:
    for line in f_in:
        replace_lines = line
        parts=replace_lines.split(",")
        if parts[0] in target_map:
            target_map[parts[0]] = replace_lines

    
with open(output_file, "w",encoding='utf-8') as file:

    for key, value in target_map.items():
        # Write the key-value pair to the file
        file.write(value)
  