def determina(z):
	num_1 = ""
	num_2 = ""
	for i, t in enumerate(z):
		if(t == " "):
			for a in range (0, i):
				num_1 = num_1 + z[a]
			for a in range(i+1,len(z)):
				num_2 = num_2 + z[a]
	return (num_1, num_2)

T = int (input())


for i in range (0, T):
	perso = int(input())
	ini = []
	fin = []

	aux = 0
	ese = 1
	for j in range(0, perso):
		#a = int(input())
		#b = int(input())
		z = input()
		a, b = determina(z)
		a = int(a)
		b = int(b)
		ini.append(a)
		fin.append(b)



	for j in range (1, perso):
		for k in range(j-1, 0, -1):
			if(ini[j] < fin[k]):
				aux += 1
			if(ini[j] == fin[k]):
				aux -= 1
		if(aux != 0 ):
			ese += 1

	if(ini[0] < fin[perso-1]):
		ese += 1

	print(ese)

