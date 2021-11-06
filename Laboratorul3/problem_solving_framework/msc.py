from search import Problem


def is_valid(state):
    canibalistanga, misionaristanga, barca, canibalidreapta, misionaridreapta = state
    if (canibalidreapta > misionaridreapta and misionaridreapta > 0) or (canibalistanga > misionaristanga and \
        misionaristanga > 0) or (canibalidreapta > 3) or (canibalistanga > 3) or (canibalidreapta < 0) or \
        (canibalistanga < 0) or (misionaridreapta > 3) or (misionaristanga > 3) or (misionaristanga < 0) or \
        (misionaridreapta < 0):
        return False
    return True

class MSC(Problem):
    def result(self, state, action):
        """The result of going to a neighbor is just that neighbor."""
        return action

    def value(self, state):
        pass

    def __init__(self, initial, goal):
        self.goal = goal
        self.initial = initial
        self.visited_states = []
        Problem.__init__(self, self.initial, self.goal)

    def __repr__(self):
        return "< State (%s, %s) >" % (self.initial, self.goal)

    def goal_test(self, state):
        return state == self.goal

    def actions(self, cur_state):
        actions = []

        self.visited_states.append(cur_state)
        if cur_state[2] == 'STANGA':
            
            #mutam 1 canibal in partea dreapta
            new_state = (cur_state[0] - 1, cur_state[1], 'DREAPTA', cur_state[3] + 1, cur_state[4])
            if is_valid(new_state):
                actions.append(new_state)
            
            #mutam 1 misionar in partea dreapta
            new_state = (cur_state[0], cur_state[1] - 1, 'DREAPTA', cur_state[3], cur_state[4] + 1)
            if is_valid(new_state):
                actions.append(new_state)

            #mutam 1 misionar si 1 canibal in partea dreapta
            new_state = (cur_state[0] - 1, cur_state[1] - 1, 'DREAPTA', cur_state[3] + 1, cur_state[4] + 1)
            if is_valid(new_state):
                actions.append(new_state)

            #mutam 2 canibali in partea dreapta
            new_state = (cur_state[0] - 2, cur_state[1], 'DREAPTA', cur_state[3] + 2, cur_state[4])
            if is_valid(new_state):
                actions.append(new_state)
            
            #mutam 2 misionari in partea dreapta
            new_state = (cur_state[0], cur_state[1] - 2, 'DREAPTA', cur_state[3], cur_state[4] + 2)
            if is_valid(new_state):
                actions.append(new_state)

            

        else:
            
            #mutam 1 canibal in partea stanga
            new_state = (cur_state[0] + 1, cur_state[1], 'STANGA', cur_state[3] - 1, cur_state[4])
            if is_valid(new_state):
                actions.append(new_state)
            
            #mutam 1 misionar in partea stanga
            new_state = (cur_state[0], cur_state[1] + 1, 'STANGA', cur_state[3], cur_state[4] - 1)
            if is_valid(new_state):
                actions.append(new_state)

            #mutam 1 misionar si 1 canibal in partea stanga
            new_state = (cur_state[0] + 1, cur_state[1] + 1, 'STANGA', cur_state[3] - 1, cur_state[4] - 1)
            if is_valid(new_state):
                actions.append(new_state)
                
            #mutam 2 canibali in partea stanga
            new_state = (cur_state[0] + 2, cur_state[1], 'STANGA', cur_state[3] - 2, cur_state[4])
            if is_valid(new_state):
                actions.append(new_state)

            #mutam 2 misionari in partea stanga
            new_state = (cur_state[0], cur_state[1] + 2, 'STANGA', cur_state[3], cur_state[4] - 2)
            if is_valid(new_state):
                actions.append(new_state)

        return actions