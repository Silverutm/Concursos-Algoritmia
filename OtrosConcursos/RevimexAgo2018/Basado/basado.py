#por problemas de recursividad de python
from sys import setrecursionlimit
setrecursionlimit(20000)


tabla_res = []
valor = []
n = 0

#f(i) = maxima cantidad de puntos a obtener en el intervalo [i, n)
def f(i):
    #condicion de paro
    if i >= n:  #aqui ya no hay puntos de los jueces
        return 0

    #si ya lo calcule antes
    if tabla_res[i] != -1:
        return tabla_res[i]

    #guardar la respuesta, entre tomarlo y no tomarlo
    #si el juez me da puntos el siguiente(i+1) no me dara nada, entonces debo irme al i+2
    #si no me da puntos el i esimo juez, debo ir a ver al i + 1
    tabla_res[i] = max(f(i+1), valor[i] + f(i + 2))
    return tabla_res[i]

t = int(input())
for i in range(t):
    n = int(input())
    valor = input().split()
    for j in range(n):
        valor[j] = int(valor[j])
    tabla_res = [-1 for k in range(n)]
    print(f(0))
