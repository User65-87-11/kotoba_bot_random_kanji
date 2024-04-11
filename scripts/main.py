import subprocess

# Replace 'script.py' with the name of the script you want to run
script_mix = '.\\scripts\\kan_read_to_mix_csv.py'
script_single = '.\\scripts\\kan_read_to_single_csv.py'

script_comp = '.\\scripts\\3_to_csv.py'

# Run the script
subprocess.run(['py', script_single, ".\\data\\jlpt\\n5single.txt", ".\\kotoba_csv\\out_n5_single.csv"])
subprocess.run(['py', script_single, ".\\data\\jlpt\\n4single.txt", ".\\kotoba_csv\\out_n4_single.csv"])
subprocess.run(['py', script_single, ".\\data\\jlpt\\n3single.txt", ".\\kotoba_csv\\out_n3_single.csv"])

subprocess.run(['py', script_mix, ".\\data\\jlpt\\n5single.txt", ".\\kotoba_csv\\out_n5_mix.csv"])
subprocess.run(['py', script_mix, ".\\data\\jlpt\\n4single.txt", ".\\kotoba_csv\\out_n4_mix.csv"])
subprocess.run(['py', script_mix, ".\\data\\jlpt\\n3single.txt", ".\\kotoba_csv\\out_n3_mix.csv"])

subprocess.run(['py', script_comp, ".\\data\\jlpt\\n5comp.txt", ".\\kotoba_csv\\out_n5_comp.csv"])
subprocess.run(['py', script_comp, ".\\data\\jlpt\\n4comp.txt", ".\\kotoba_csv\\out_n4_comp.csv"])
subprocess.run(['py', script_comp, ".\\data\\jlpt\\n3comp.txt", ".\\kotoba_csv\\out_n3_comp.csv"])