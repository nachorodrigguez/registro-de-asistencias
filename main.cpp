#include <iostream>
#include "funciones.h"

using namespace std;

/*
Una empresa lleva un registro de asistencia de sus 30 empleados.
Cada vez que un empleado asiste al trabajo, se registra:
    -N�mero de empleado (valor entre 100 y 129).
    -Mes (1 a 12).
    -D�a (1 a 31).
    -Horas trabajadas en el d�a.
Los registros finalizan cuando se ingresa un n�mero de empleado igual a 0.
Al finalizar la carga, se debe calcular y mostrar:
    1- El total de horas trabajadas en el mes de abril entre todos los empleados.
    2- Para cada mes del a�o, la cantidad de d�as en los que al menos un empleado estuvo presente.
    3- Para cada empleado, su n�mero de empleado y la cantidad total de meses en los que trabaj�.
    4- Listar los d�as del a�o en los que ning�n empleado trabaj�.
*/

int main()
{
    float registros[30][12][31]{};

    registroEmpleado(registros);

    horasTrabajadasAbril(registros);

    mesEmpleadoPresente(registros);

    cantidadMesesPorEmpleado(registros);

    diasNadiePresente(registros);

    return 0;
}
