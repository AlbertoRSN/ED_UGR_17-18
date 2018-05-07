#!/bin/csh
@ inicio = 100
@ fin = 60000
@ incremento = 500
set ejecutable = ejercicio_desc
set salida = tiempos_ejercicio_desc.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./ejercicio_desc $i ` >> $salida
  @ i += $incremento
end
