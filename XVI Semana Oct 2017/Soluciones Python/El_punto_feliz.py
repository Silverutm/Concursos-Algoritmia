from math import fabs
TEST_CASES = int(raw_input())

def are_collinear(a, b, m, n, x, y):
	epsilon = 1e-9
	return fabs((n - b) * (x - m) - (y - n) * (m - a)) < epsilon

for case in xrange(TEST_CASES):
	Ax, Ay = map(float, raw_input().split())
	Bx, By = map(float, raw_input().split())
	Cx, Cy = map(float, raw_input().split())

	D = 2.0 * (Ax * (By - Cy) + Bx * (Cy - Ay) + Cx * (Ay - By))

	Ux = ((Ax * Ax + Ay * Ay) * (By - Cy) + (Bx * Bx + By * By) * (Cy - Ay) + (Cx * Cx + Cy * Cy) * (Ay - By)) / D
	Uy = ((Ax * Ax + Ay * Ay) * (Cx - Bx) + (Bx * Bx + By * By) * (Ax - Cx) + (Cx * Cx + Cy * Cy) * (Bx - Ax)) / D
	if are_collinear(Ax, Ay, Bx, By, Ux, Uy) \
		 or are_collinear(Ax, Ay, Cx, Cy, Ux, Uy) \
		 or are_collinear(Cx, Cy, Bx, By, Ux, Uy):
		print "{:.4f} {:.4f} No Aceptado".format(round(Ux, 4), round(Uy, 4))
	else:
		print "{:.4f} {:.4f} Aceptado".format(round(Ux, 4), round(Uy, 4))
