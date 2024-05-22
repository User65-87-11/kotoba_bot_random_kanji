import subprocess

# Replace 'script.py' with the name of the script you want to run
script_rep = '.\\scripts\\replace1_3.py'

script_csv = '.\\scripts\\3_to_csv.py'

# Run the script
subprocess.run(['py', script_rep, ".\\data\\reps.txt", ".\\data\\decks\\all.csv", ".\\kotoba_csv\\out_reps.txt"])
# subprocess.run(['python', script_rep, ".\\kotoba_csv\\out_reps.txt", ".\\data\\decks\\minna02.csv", ".\\kotoba_csv\\out_reps.txt"])
# subprocess.run(['python', script_rep, ".\\kotoba_csv\\out_reps.txt", ".\\data\\decks\\minna03.csv", ".\\kotoba_csv\\out_reps.txt"])
  

subprocess.run(['py', script_csv, ".\\kotoba_csv\\out_reps.txt", ".\\kotoba_csv\\out_reps.csv"])
 
