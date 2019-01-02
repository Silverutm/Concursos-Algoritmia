#Contar cuantos conjuntos hay
#el numero de carreteras extras es conjuntos -1 
#como cada conjunto esta aislado de los demas, necesitamos 
#carreteras para conectarlos

#complejidad o(c + p) ciudaddes + propuestas, vertices mas aristas,

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
    if rep_x == rep_y:  #si no uno conjuntos, la cantidad de conjuntos permanece igual
        return 0
    if cantidad[rep_x] > cantidad[rep_y]:
        representate[rep_y] = rep_x
        cantidad[rep_x] += cantidad[rep_y]
    else:
        representate[rep_x] = rep_y
        cantidad[rep_y] += cantidad[rep_x]
    #cada vez que se unen dos conjuntos
    #se pierde un conjunto
    #por eso regreso un 1
    return 1



t = int(input())
for i in range(t):
    v, a = map(int, input().split())
    inicializar(v)
    componentes = v #al principio tengo esa cantidad de conjuntos
    for j in range(a):
        x, y = map(int, input().split())
        componentes -= unir_conjuntos(x, y)  #regresa 1 si se unieron dos conjuntos(disminuye en 1 la cantidad de conjuntos, por eso la resta)
    print (componentes - 1)
    

    