#include <iostream>
#include "funciones.h"

using namespace std;

void registroEmpleado(float registros[30][12][31]){
    int numeroEmpleado, dia, mes;
    float horasTrabajadas;

    do {
        cout << "Ingrese numero de empleado: ";
        cin >> numeroEmpleado;

        if (numeroEmpleado >=100 and numeroEmpleado <= 129){

            cout << "Ingrese dia trabajado: ";
            cin >> dia;

            cout << "Ingrese mes trabajado: ";
            cin >> mes;

            cout << "Ingrese horas trabajadas: ";
            cin >> horasTrabajadas;

            cargarRegistros(registros, numeroEmpleado, dia, mes, horasTrabajadas);
        }
        else {
            cout << "Numero de empleado invalido. Debe estar entre 100 - 129.\n";
        }
    }
    while (numeroEmpleado != 0);
}

void cargarRegistros (float registros[30][12][31], int numeroEmpleado, int dia, int mes, float horasTrabajadas){
    registros[numeroEmpleado-100][mes-1][dia-1] = horasTrabajadas;
}

void mostrarMatriz(float registros[30][12][31]){
    for (int i=0 ; i<30; i++){
        bool empleadoTrabajo = false;
        cout << "Empleado: " << i+1 << endl; // Mostrar número real del empleado
        for (int c=0; c<12; c++){
            for (int d=0; d<31; d++){
                if(registros[i][c][d] != 0){ // Solo mostrar días trabajados
                    cout << "  Mes: " << c+1 << ", Dia: " << d+1 << " - Horas: " << registros[i][c][d] << endl;
                    empleadoTrabajo = true;
                }
            }
        }
        if(empleadoTrabajo == false){
            cout << "  No registra horas trabajadas" << endl;
        }
        cout << "---------------------------------"<< endl;
    }
}

void horasTrabajadasAbril(float registros[30][12][31]){
    float horasTotales = 0;
    for (int i=0; i<30; i++){
            for (int d=0; d<31; d++){
                if(registros [i][3][d] != 0 ){
                    horasTotales += registros[i][3][d] ;
                }
            }
    }
    cout << "Las horas totales de abril son: " << horasTotales << endl;
    cout << "---------------------------------"<< endl;
}

void mesEmpleadoPresente(float registros[30][12][31]){
    for(int c=0; c<12; c++){
    int acu = 0;
        for (int d=0; d<31; d++){
            bool empleadoPresente = false;
            for (int i=0; i<30; i++){
                if(registros [i][c][d] != 0 and empleadoPresente == false ){
                    empleadoPresente = true;
                    acu += 1;
                }
            }
        }
        cout << "En el mes "<< c+1 << " Hubo " << acu << " dias en los que al menos un empleado estuvo presente." << endl;
        cout << "---------------------------------"<< endl;
    }
}

void cantidadMesesPorEmpleado(float registros[30][12][31]){
    for (int i=0; i<30; i++){
    int mesesTrabajados =0;
        for(int c=0; c<12; c++){
        bool empleadoPresente = false;
            for(int d=0; d<31; d++){
                if(registros [i][c][d] !=0 and empleadoPresente == false){
                empleadoPresente = true;
                mesesTrabajados += 1;
                break;
                }
            }
        }
        cout << "El empleado " << i+100 << " Trabajo " << mesesTrabajados << " Meses." << endl;
        cout << "---------------------------------"<< endl;
    }
}

void diasNadiePresente(float registros[30][12][31]){
    for (int d=0; d<12; d++){
    int empleadoAusente = 0;
        for (int c=0; c<31; c++){
            for (int i=0; i<30; i++){
                if(registros[i][c][d] == 0){
                    empleadoAusente += 1;
                    }
                }
            if (empleadoAusente !=0){
            cout << "El dia " << c+1 << " del mes " << d+1 << " no se presento ningun empleado."<< endl;
            cout << "---------------------------------"<< endl;
            }
        }
    }
}

