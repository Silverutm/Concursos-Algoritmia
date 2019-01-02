TEST_CASES = int(raw_input())

COUNTER = 0
ADJ_LIST = []

def dfs(vertex):
    global COUNTER, ADJ_LIST
    COUNTER += 1
    for neighbor in ADJ_LIST[vertex]:
        dfs(neighbor)

for case in xrange(TEST_CASES):
    COUNTER = 0
    places, immediate_connections = map(int, raw_input().split())
    ADJ_LIST = [[] for x in xrange(0, places)]
    for connection in xrange(immediate_connections):
        _x, _y = map(int, raw_input().split())
        ADJ_LIST[_x - 1].append(_y - 1)
    dfs(0)
    if COUNTER == places:
        print "Go, Mr. Malva!"
    else:
        print "Go to sleep, Mr. Malva."
