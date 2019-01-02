listaAdj = None
visitado = None
m = 0
n = 0

def dfs(vertex):
	global listaAdj
	global m
	visitado[vertex] = True
	for vecino in listaAdj[vertex]:
		if not visitado[vecino]:
			dfs(vecino)

T = int(raw_input())
for caso in xrange(T):
	if caso != 0:
		espacio = raw_input()
	m, n  = map(int, raw_input().strip().split(' '))
	m -= 1
	listaAdj = [[] for i in xrange(m+1)]
	visitado = [False for i in xrange(m+1)]
	for vertice in xrange(n):
		v, u = map(int, raw_input().strip().split(' '))
		v -= 1
		u -= 1
		listaAdj[v].append(u)
	dfs(0)
	if visitado[m]:
		print "Corre, Schnitzel."
	else:
		print "No te molestes."

