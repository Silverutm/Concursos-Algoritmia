#cuando se crea una conexion entre dos lugares(x, y), x puede llegar a todos los lugares a los que
#y puede llegar y viceversa, es similar a unir dos conjuntos, el problema es verificar si
#todos los elementos pertenecen al mismo conjunto


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

def unir_conjunto(x, y):
    rep_x = encontrar_representante(x)
    rep_y = encontrar_representante(y)
    if rep_x == rep_y:
        return
    if cantidad[rep_x] > cantidad[rep_y]:
        representate[rep_y] = rep_x
        cantidad[rep_x] += cantidad[rep_y]
    else:
        representate[rep_x] = rep_y
        cantidad[rep_y] += cantidad[rep_x]



c = int(input())
for i in range(c):    
    v, a = input().split()
    v = int(v)
    a = int(a)
    inicializar(v)
    for j in range(a):
        x, y = input().split()
        x = int(x)
        y = int(y)        
        ####################
        ##se crea una conexion y se unen los conjuntos
        unir_conjunto(x, y)
    x = encontrar_representante(1)
    res = True
    #################3
    ###verificar que todos pertenezcan al mismo conjunto
    for j in range(1, v + 1):
        if encontrar_representante(j) != x:
            res = False
            break
    if res:
        print ("Go, Mr. Malva!")
    else:
        print("Go to sleep, Mr. Malva.")