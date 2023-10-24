// lista enlazada C++.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;
struct Nodo {
	int dato;
	Nodo* siiguiente;
};
//funcion Agregar elementos a la lista 
void agregarNodo(Nodo*& cabeza, int valor) {
	Nodo* nuevoNodo = new Nodo;//creando el apuntador hacia el nuevo nodo 
	nuevoNodo->dato = valor;
	nuevoNodo->siiguiente = nullptr;

	if (cabeza == nullptr) {
		cabeza = nuevoNodo;
	}
	else {
		Nodo* actual = cabeza; 
		while (actual->siiguiente != nullptr) {
			actual = actual->siiguiente;
		}
		actual->siiguiente = nuevoNodo;
	}
}

void imprimirlista(Nodo* cabeza) {
	Nodo* actual = cabeza;
	while (actual != nullptr) {
		cout << actual->dato << " ";
		actual = actual->siiguiente;
	}
}

void borrarLista(Nodo* cabeza) {
	while (cabeza != nullptr) {
		Nodo* siguiente = cabeza->siiguiente;
		delete cabeza;
		cabeza = siguiente;
		cout << "Elemento borrado";
	}
}
int main()
{
	Nodo* cabeza = nullptr; //Declaramos un puntero de memoria nulo
	int tamanolista;
	cout << "Ingrese la cantidad de elementos que se desea agregar a la lista:";
	cin >> tamanolista;
	if (tamanolista <= 0) {
		cout << "Cantidad de elemnentos no valida" << endl;
		return 1;
	}
	for (int i = 0; i < tamanolista; i++) {
		int valor; 
		cout << "Ingrese dato" << i + 1 << ":";
		cin >> valor;
		//invocamos nuestra funcion de agregar Nodo
		agregarNodo(cabeza, valor);

	}
	
	cout << "Imprimiendo Lista de numeros " << endl;
	imprimirlista(cabeza);

	borrarLista(cabeza);
	return 0;
}


