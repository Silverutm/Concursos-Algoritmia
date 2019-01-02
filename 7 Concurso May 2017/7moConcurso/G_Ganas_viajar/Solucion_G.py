T = int(raw_input())
for caso in xrange(T):
	n = int(raw_input())
	p1, p2, p3, f = map(int, raw_input().strip().split(' '))
	contador_cdmx = 0
	contador_estado = 0
	for estados in xrange(n):
		e, t1 = raw_input().strip().split(' ')
		t = int(t1)
		if e == 'B' and t < f:
			contador_cdmx += 1
		elif e == 'S' and t > f:
			contador_estado += 1
	contador_intermedios = (n / 2) - contador_cdmx - contador_estado 
	print contador_intermedios * p2 + contador_estado * p3 + contador_cdmx * p1
	