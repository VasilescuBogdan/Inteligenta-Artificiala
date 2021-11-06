from search import *
from vcl import VCL
from msc import MSC


def main():
    problema_vcl = VCL((1, 1, 1, 'STANGA', 0, 0, 0), (0, 0, 0, 'DREAPTA', 1, 1, 1))
    path = breadth_first_tree_search(problema_vcl).solution()
    print(path, '\n')
    
    problema_msc = MSC((0, 0, 'DREAPTA', 3, 3), (3, 3, 'STANGA', 0, 0))
    path = breadth_first_tree_search(problema_msc).solution()
    print(path, '\n')

if __name__ == "__main__":
    main()
