from search import EightPuzzle


class EightPuzzleMiss(EightPuzzle):
    def h(self, node):
        """ Return the heuristic value for a given state. Default heuristic function used is
        h(n) = number of misplaced tiles """
        return sum(s != g for (s, g) in zip(node.state, self.goal))
    
        
class EightPuzzleMht(EightPuzzle):
    def h(self, node):
        """ implement Manhattan distance. Hint! Look at
        Missplaced Tiles heuristic function above """

        mhtDist = 0
        for i, j in enumerate(self.initial):
            prev_row, prev_col = int(i/ 3), i % 3
            goal_row, goal_col = int(j/ 3), j % 3
            mhtDist += abs(prev_row - goal_row) + abs(prev_col - goal_col)
        return mhtDist
