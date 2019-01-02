from math import sqrt
from math import fabs
T = int(raw_input())
for c in xrange(T):
	if c != 0:
		s = raw_input()
	ax, ay = map(float, raw_input().strip().split(' '))
	bx, by = map(float, raw_input().strip().split(' '))
	cx, cy = map(float, raw_input().strip().split(' '))
	dx, dy = map(float, raw_input().strip().split(' '))

	distanceDiagonal1 = sqrt((ax-cx)**2 + (ay-cy)**2)
	distanceDiagonal2 = sqrt((bx-dx)**2 + (by-dy)**2)
	
	ladoAB = sqrt((ax-bx)**2 + (ay-by)**2)
	ladoBC = sqrt((bx-cx)**2 + (by-cy)**2)
	ladoCD = sqrt((cx-dx)**2 + (cy-dy)**2)
	ladoDA = sqrt((ax-dx)**2 + (ay-dy)**2)
	a = distanceDiagonal1 * distanceDiagonal2
	b = ladoAB * ladoCD + ladoDA * ladoBC
	if fabs(a - b) <= 1e-4:
		print "Schnitzel la acepta."
	else :
		print "Sigue buscando, Moroni."

