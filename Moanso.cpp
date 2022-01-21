#include<iostream>
#include<conio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#define rep1 "Luis Gonzales"
#define rep2 "Ana Garcia"
#define rep3 "Pedro Suarez"
#define rep4 "Javier Avila"
#define rep5 "Yazmin Ulloa"
#define rep6 "Johana Mendoza"
#define rep7 "Hugo Villaran"
#define rep8 "Piero Pino"
#define rep9 "Raul Caceres"
#define rep10 "Rosa Velasquez"
using namespace std;
struct venta {
	int codigo;
	char producto[30];
	double precio;
	double descuento;
	int tiempo;
	venta* sig;
}*p, * aux, * u;
void menu();
int r1 = 0, r2 = 0, r3 = 0, r4 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0;
double importe = 0, ganancia = 0, perdida = 0;
void registrar();
void lista();
void reporte();
int main() {
	setlocale(LC_CTYPE, "Spanish");
	srand(time(NULL));
	int opc;
	do
	{
		menu();
		cin >> opc;
		switch (opc)
		{
		case 1: registrar();
			break;
		case 2: lista();
			break;
		case 3: reporte();
			break;
		case 4: exit(1); break;
		default: cout << endl << " Opcion no valida!!" << endl << endl; break;
		}
		system("pause");
	} while (opc != 4);
	return 0;
}
void menu() {
	system("cls");
	cout << endl;
	cout << " ********************************" << endl;
	cout << " * SERVICIO ENTREGA A DOMICILIO *" << endl;
	cout << " ********************************" << endl << endl;
	cout << " .Registrar Venta............[1]" << endl;
	cout << " .Lista de Ventas............[2]" << endl;
	cout << " .Reporte General de Ventas..[3]" << endl;
	cout << " .Salir del programa.........[4]" << endl;
	cout << " -------------------------------" << endl;
	cout << " Ingrese opcion: ";
}
void registrar() {
	aux = new(venta);
	cout << endl;
	cout << " ------------------" << endl;
	cout << " Registro de Venta: " << endl;
	cout << " ------------------" << endl;
	aux->codigo = 1001 + rand() % (1011 - 1001);
	cout << " Codigo del vendedor: " << aux->codigo << endl;
	if (aux->codigo == 1001)
		r1++;
	else if (aux->codigo == 1002) r2++;
	else if (aux->codigo == 1003) r3++;
	else if (aux->codigo == 1004) r4++;
	else if (aux->codigo == 1005) r5++;
	else if (aux->codigo == 1006) r6++;
	else if (aux->codigo == 1007) r7++;
	else if (aux->codigo == 1008) r8++;
	else if (aux->codigo == 1009) r9++;
	else if (aux->codigo == 1010) r10++;
	cout << " Producto: "; cin >> aux->producto;
	cout << " Precio Neto: "; cin >> aux->precio;
	importe += aux->precio;
	aux->tiempo = 10 + rand() % (60 + 1 - 10);
	cout << " Tiempo de entrega: " << aux->tiempo << " min" << endl;
	if (aux->tiempo > 30) {
		aux->descuento = aux->precio * 0.30;
		cout << " Descuento: S/." << aux->descuento << endl;
		perdida += aux->descuento;
	}
	else aux->descuento = 0;
	cout << " Importe Final: S/." << aux->precio - aux->descuento;
	ganancia += aux->precio - aux->descuento;
	if (u)
	{
		u->sig = aux;
		aux->sig = NULL;
		u = aux;
	}
	else {
		p = u = aux;
		aux->sig = NULL;
	}
	cout << endl << endl << " ---------------------------------" << endl;
	cout << " Venta registrada exitósamente!!!" << endl;
	cout << " ---------------------------------" << endl << endl << endl;
}
void lista() {
	int i = 1;
	if (u == NULL)
	{
		cout << endl << " -----------------------" << endl;
		cout << " No hay datos en la cola" << endl;
		cout << " -----------------------" << endl << endl;
	}
	else {
		aux = p;
		cout << endl;
		cout << " ----------------------------" << endl;
		cout << " LISTA DE VENTAS EFECTUADAS " << endl;
		cout << " ----------------------------" << endl;
		while (aux != NULL)
		{
			cout << endl << endl;
			cout << " Venta [" << i << "]" << endl;
			cout << " -----------" << endl;
			cout << " Codigo del vendedor: " << aux->codigo << endl;
			cout << " Nombre: ";
			if (aux->codigo == 1001) cout << rep1;
			else if (aux->codigo == 1002) cout << rep2;
			else if (aux->codigo == 1003) cout << rep3;
			else if (aux->codigo == 1004) cout << rep4;
			else if (aux->codigo == 1005) cout << rep5;
			else if (aux->codigo == 1006) cout << rep6;
			else if (aux->codigo == 1007) cout << rep7;
			else if (aux->codigo == 1008) cout << rep8;
			else if (aux->codigo == 1009) cout << rep9;
			else if (aux->codigo == 1010) cout << rep10;
			cout << endl;
			cout << " Producto: " << aux->producto << endl;
			cout << " Precio Neto: " << aux->precio << endl;
			cout << " Tiempo de entrega: " << aux->tiempo << " min" << endl;
			if (aux->tiempo > 30) {
				cout << " Descuento: S/." << aux->descuento << endl;
			}
			cout << " Importe Final: S/." << aux->precio - aux->descuento << endl;
			aux = aux->sig;
			i++;
		}
	}
	cout << endl << endl << endl;
}
void reporte() {
	cout << endl;
	system("cls");
	cout << " -------------------------" << endl;
	cout << " REPORTE GENERAL DE VENTAS" << endl;
	cout << " -------------------------" << endl;
	cout << " Codigo Nombre\t N°Ventas" << endl;
	cout << " ------ ------\t --------" << endl;
	cout << " 1001 " << rep1 << "\t" << r1 << endl;
	cout << " 1002 " << rep2 << "\t\t" << r2 << endl;
	cout << " 1003 " << rep3 << "\t" << r3 << endl;
	cout << " 1004 " << rep4 << "\t" << r4 << endl;
	cout << " 1005 " << rep5 << "\t" << r5 << endl;
	cout << " 1006 " << rep6 << "\t" << r6 << endl;
	cout << " 1007 " << rep7 << "\t" << r7 << endl;
	cout << " 1008 " << rep8 << "\t\t" << r8 << endl;
	cout << " 1009 " << rep9 << "\t" << r9 << endl;
	cout << " 1010 " << rep10 << "\t" << r10 << endl;
	cout << endl;
	cout << " ---------------------------" << endl;
	cout << " RESUMEN DEL TOTAL DE VENTAS" << endl;
	cout << " ---------------------------" << endl;
	cout << " Venta Ideal: S/." << importe << endl;
	cout << " Utilidad Real: S/." << ganancia << endl;
	cout << " Pérdida: S/." << perdida << endl;
	cout << endl << endl << endl;
}