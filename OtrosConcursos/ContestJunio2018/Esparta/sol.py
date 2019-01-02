t = raw_input()
t = int(t)
while t!=0:
    t = t - 1
    n = raw_input()
    n = int(n)
    res = str(2 ** n)
    suma = 0
    for c in res:
        suma = suma + int(c)
    print suma
#2 * 100000