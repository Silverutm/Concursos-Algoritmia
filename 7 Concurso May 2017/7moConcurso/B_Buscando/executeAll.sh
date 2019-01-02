nombreArchivoEntrada=""
nombreArchivoSalida=""
loading=""
for ((caso=0; caso<3; caso++))
{
	for ((input=0; input<10; input++))
	{
		if [[ $caso -eq 0 ]]; then
			nombreArchivoEntrada="C"$input.in
			nombreArchivoSalida="C"$input.outI
		fi
		if [[ $caso -eq 1 ]]; then
			nombreArchivoEntrada="M"$input.in
			nombreArchivoSalida="M"$input.outI
		fi
		if [[ $caso -eq 2 ]]; then
			nombreArchivoEntrada="G"$input.in
			nombreArchivoSalida="G"$input.outI
		fi
		python $1 < $nombreArchivoEntrada > $nombreArchivoSalida

	}
}