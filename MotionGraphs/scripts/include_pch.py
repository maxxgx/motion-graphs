import sys
import os

###
# Adds #include pch_h pre-compiled headers to .cpp file in the specified folder
# Usage: include_pch.py <folder> <path_of_pch>
###

pch_path = '../headers/pch.h'

def print_solution(slides, outfile):
    with open(outfile, 'a') as out:
        out.write(str(len(slides)) + '\n')
        for slide in slides:
            out.write(" ".join([str(i.id) for i in slide.images]) + '\n')

def add_pch(file_name, lines):
    include_flag = False
    with open(file_name, 'w') as out:
        for l in lines:
            if 'pch.h' in l:
                include_flag = True
            if not include_flag and l.startswith('#include'):
                out.write('#include "' + pch_path + '"\n')
                include_flag = True
            
            out.write(l)

def read_file(filename):
    with open(filename, 'r', encoding='utf-8', errors='ignore') as f:
        lines = [l for l in f.readlines()]
    return lines


folder = "./"
if len(sys.argv) > 1:
    folder = sys.argv[1]
if len(sys.argv) > 2:
    pch_path = sys.argv[2]

def main():  

    files = [folder + f for f in os.listdir(folder) if f.endswith('.cpp')]
    print('folder:', folder)
    print('pch path:', pch_path, end='\n\n')

    for i, f in enumerate(files):
        print(i+1,'Parsing', f , end=' ')
        lines = read_file(f)
        add_pch(f, lines)
        print('...done')

if __name__=="__main__":
    main()


