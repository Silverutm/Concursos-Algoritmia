
Tabla_Res = [-1 for x in range (10000)]

#dinero(i) = la maxima cantidad de dinero que se puede obtener en el intervalo [i, n)
def dinero(i):

	#a partir de este lugar ya no hay dinero
    if i >= N: #condicion de paro | muy importate
		return False

	if Tabla_Res[i] != -1:  #si ya lo calculé antes
		return Tabla_Res[i]

	#si lo tomo aumento el dinero en valor[i] y debo irme a la casilla i + valor[i]
    Tomarlo = int(valor[i]) + dinero(int(i) + int(valor[i]))
	NoTomarlo = dinero(int(i)+1) # si no lo tomo me paso a la siguiente casilla

	Tabla_Res[i] = max(Tomarlo, NoTomarlo)  #guardar la respuesta, esto es programacion dinamica

	return Tabla_Res[i]  #regresar la respuesta


C = int(input())
for caso in range(C):
	N = int(input())
	valor = input()
	valor = valor.split()
	Tabla_Res = [-1 for x in range (10000)]
	print(dinero(0))