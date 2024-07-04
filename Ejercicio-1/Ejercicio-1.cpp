/*
Un consorcio desea controlar la cobranza de las expensas en un edificio de 5 pisos
donde existen 15 departamentos en cada piso.
El valor de las expensas es de $ 3000.
Para registrar la cobranza se ingresa el n�mero de piso (1 a 5)
y el n�mero de departamento (correlativo de 1 a 15 en cada piso).
El ingreso finaliza con un piso igual a 0.
Al finalizar mostrar el dinero total recaudado y
una tabla con una X indicando aquellos departamentos
deudores de la siguiente manera:
TOTAL RECAUDADO
DEPARTAMENTOS DEUDORES
PISO    DPTO 1 DPTO2 � DPTO 15
PISO 1    X
PISO 2    X     X
PISO 3    X
PISO 4    X     X
PISO 5    X
*/

/*
- Contexto: Un consorcio desea controlar la cobranza de las expensas en un edificio de 5 pisos
donde existen 15 departamentos en cada piso
- importante valor de expensas $ 3000
*/
#include <iostream>

using namespace std;

void matrizInitial(const int, const int, bool[][15]);
void showingMatrix(const int, const int, bool[][15]);
void collectionRecord(bool[][15]);
int totalRaised(const int, const int, bool [][15]);

int main()
{
    const int dimColFloor = 5;
    const int dimFileDpto = 15;
    bool debtorDepartments[dimColFloor][dimFileDpto];

    // Poniendo todo en falso
    matrizInitial(dimColFloor, dimFileDpto, debtorDepartments);
    // Registrando los cobros piso-departamento
    collectionRecord(debtorDepartments);

    cout << "Mostrando el registro de departamentos deudores: " << endl;
    showingMatrix(dimColFloor, dimFileDpto, debtorDepartments);

    int quality = totalRaised(dimColFloor, dimFileDpto, debtorDepartments);

    cout<<"Total recaudado: "<<"$"<<quality * 3000<<endl;

    return 0;
}

int totalRaised(const int dimCol, const int dimFile, bool matriz[][15])
{
    int cont = 0;
    for (int i = 0; i < dimCol; i++)
    {
        for (int j = 0; j < dimFile; j++)
        {
            if (matriz[i][j] == true)
            {
                /* cout<<cont<<" "; */
                cont++;
            }
        }
    }
    return cont;
}

void matrizInitial(const int dimCol, const int dimFile, bool matriz[][15])
{
    for (int i = 0; i < dimCol; i++)
    {
        for (int j = 0; j < dimFile; j++)
        {
            matriz[i][j] = false;
        }
    }
}

void showingMatrix(const int dimCol, const int dimFile, bool matriz[][15])
{
    for (int i = 0; i < dimCol; i++)
    {
        for (int j = 0; j < dimFile; j++)
        {
            if (matriz[i][j] == true)
            {
                cout << "X ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

void collectionRecord(bool matriz[][15])
{
    int floor;
    int dpto;
    cout << "Registro de cobranza: " << endl;
    cout << "Piso: ";
    while (cin >> floor && floor != 0)
    {
        cout << "Departamento: ";
        cin >> dpto;
        if (matriz[floor - 1][dpto - 1] == true)
        {
            cout << "Esta departamento ya registrado. Digita otro" << endl;
        }
        else
        {
            matriz[floor - 1][dpto - 1] = true;
            cout << "Registrado: " << "piso: " << floor << " departamento: " << dpto << endl;
        }
        cout << "Piso: ";
    }
}