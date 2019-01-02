from os import sys
sys.setrecursionlimit(100000)
COUNTER = 0
ADJ_LIST = []
VISITED = []
def dfs(vertex):
    global COUNTER, ADJ_LIST, VISITED
    VISITED[vertex] = True
    COUNTER += 1
    for neighbor in ADJ_LIST[vertex]:
        if not VISITED[neighbor]:
            dfs(neighbor)

def solution():
    global COUNTER, ADJ_LIST, VISITED
    TEST_CASES = int(raw_input())
    for case in xrange(TEST_CASES):
        COUNTER = 0
        places, immediate_connections = map(int, raw_input().split())
        ADJ_LIST = [[] for x in xrange(0, places)]
        VISITED = [False for x in xrange(places)]
        for connection in xrange(immediate_connections):
            _x, _y = map(int, raw_input().split())
            ADJ_LIST[_x - 1].append(_y - 1)
        dfs(0)
        if sum(VISITED) == places:
            print "Go, Mr. Malva!"
        else:
            print "Go to sleep, Mr. Malva."

for input_size in ['C', 'M', 'G']:
    for index in xrange(0,10):
        out = sys.stdout
        _in = sys.stdin
        sys.stdin = open(input_size + str(index) + '.in', 'r')
        sys.stdout = open(input_size + str(index) + '.outI', 'w')
        solution()
        sys.stdout = out
        sys.stdin = _in
        
