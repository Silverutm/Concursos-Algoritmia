T = int(raw_input())
for caso in xrange(T):
	n = int(raw_input())
	preproceso = [1, 1, 2, 3, 5, 8, 4, 3, 7, 1, 8, 9, 8, 8, 7, 6, 4, 1, 5, 6, 2, 8, 1, 9]
	index = n % 24
	index -= 1
	print preproceso[index]