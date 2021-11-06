import time
from eight_puzzle import *
from search import *

def main():
    
    problem_miss = EightPuzzleMiss((1, 2, 3, 4, 8, 0, 7, 6, 5), (1, 2, 3, 4, 5, 6, 7, 8, 0))
    problem_mht = EightPuzzleMht((1, 2, 3, 4, 8, 0, 7, 6, 5), (1, 2, 3, 4, 5, 6, 7, 8, 0))

    t1 = time.time()
    path = astar_search(problem_miss).solution()
    t2 = time.time()
    t3 = time.time()
    path2 = astar_search(problem_mht).solution()
    t4 = time.time()
    print(path, '\n', t2 - t1)
    print(path2, '\n', t4 - t3)

    """ Compare searchers """
    compare_searchers(problems=[problem_miss, problem_mht],
                      header=['Searcher', 'A* h1(n)',
                              'A* h2(n)'], searchers=[
            astar_search,
            recursive_best_first_search])
    """ The compare_searchers function displays on the console a table to compare the perfomances of different searchers on resolving different problems.
    This table contains informations such as: the number of succesive actions made by the search algorith (self.succs), the number of tests if the goal state 
    was reached (self.goal_tests), the number of states changed by the searcher in our problem (self.states) and the final state (which is the in any case 
    equal with the goal state defined by the user) """


    problem_15 = FifteenthPuzzle((1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0, 13, 14, 11, 15, 12), (1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0))
    path3 = astar_search(problem_15).solution()
    print(path3)
    """ For the corectness of the given solution, check the file "Rezolvare pas cu pas 15-puzzle exemplu.txt".
        You can see the implementation of the 15-puzzel problem in the "search.py" file, at the line 493"""


if __name__ == "__main__":
    main()
