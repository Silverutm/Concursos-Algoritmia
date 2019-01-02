def sumaDigitos(n):
	suma = 0
	while n > 0:
		suma += (n % 10)
		n /= 10
	ans = str(suma)
	if len(ans) == 1:
		print str(suma) + ",",
	else:
		sumaDigitos(suma)

T = int(raw_input())
for caso in xrange(T):
	n = int(raw_input())
	fibo = [None for i in range(n+5)]
	fibo[0] = 1
	fibo[1] = 1
	for i in xrange(2,n):
		fibo[i] = fibo[i-1] + fibo[i-2] 
	sumaDigitos(fibo[n-1])	