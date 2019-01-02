#complejidad o(n)

#para que no se muera la recursvidad en python
from sys import setrecursionlimit
setrecursionlimit(20000)

tabla_res = []   #las respuesta
valor = []   #cantidad de oro por cuadro
n = 0    #numero de cuadros

def f(i):
    if i >= n:  #condicion de paro, a partir de este lugar ya no hay oro
        return 0
    if tabla_res[i] != -1:  #si ya lo calcule antes
        return tabla_res[i]
    tabla_res[i] = max(f(i+1), valor[i] + f(i + 3))  #tengo dos opciones, si no tomo el oro en esa posicion
                                #me voy a la respuesta del siguiente cuadro f(i + 1), si tomo el oro en ese cuadro
                                #la respuesta el valor que me da ese cuadro v[i], mas la respuesta de 3 cuadros adelante f(i+3)
                                #debido a que i+1 e i+2 fueron detruidos, no me preocupo por los anteriores i-1 e i-2 porque si 
                                #puedo llegar a i, significa que no pase por i-1 ni i-2
    
    return tabla_res[i] #regresar la respuesta


t = int(input())
for i in range(t):
    n = int(input())
    valor = input().split()
    for j in range(n):
        valor[j] = int(valor[j])        
    tabla_res = [-1 for k in range(n)]   #limpiar mi tabla de respuestas
    print(   f(0)   )