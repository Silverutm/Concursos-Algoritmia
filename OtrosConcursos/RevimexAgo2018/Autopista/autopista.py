#contar cuantos aristas forman ciclos
representate = [0 for i in range(10001)]
cantidad = [1 for i in range(10001)]

def inicializar(v):
    for i in range(1, v+1):
        representate[i] = i
        cantidad[i] = 1
    
def encontrar_representante(x):
    if representate[x] == x:
        return x
    representate[x] = encontrar_representante(representate[x])
    return representate[x]

def unir_conjuntos(x, y):
    rep_x = encontrar_representante(x)
    rep_y = encontrar_representante(y)
    if rep_x == rep_y:
        return 1
    if cantidad[rep_x] > cantidad[rep_y]:
        representate[rep_y] = rep_x
        cantidad[rep_x] += cantidad[rep_y]
    else:
        representate[rep_x] = rep_y
        cantidad[rep_y] += cantidad[rep_x]
    return 0



t = int(input())
for i in range(t):
    v, a = map(int, input().split())
    inicializar(v)
    contador = 0
    for j in range(a):
        x, y = map(int, input().split())
        contador += unir_conjuntos(x, y)
    print (contador)
    #componentes = [0 for k in range(v+1)]
    #for k in range(1, v+1):
    #    componentes[k] = (k == encontrar_representante(k))

    #print (v, a, contador, sum(componentes))

    