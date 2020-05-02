#include <iostream>
#include <fstream> 
//include <string>
//#include <stdlib.h>
#include <windows.h>


using namespace std;

int menu(){
	int x;
	system("cls");
	//menu principal
	cout<<"\t*************************"<<"\n";
	cout<<"\t*     MENU PRINCIPAL    *"<<"\n";
	cout<<"\t*************************"<<"\n";
	cout<<"\t1 - AGREGAR PRODUCTOS"<<"\n";
	cout<<"\t2 - LEER ARCHIVO"<<"\n";
	cout<<"\t3 - SALIR"<<"\n";
	cout<<"---------------------------\n";
	cout<<"QUE DESEA HACER? ";
	cin>>x;
	return x;	
}

void agregar(ofstream &es){
	system("cls");
	int codigo;
	string nombre;
	int nivmin;
	int nivactual;
	string proveedor;
	float precio;
	es.open("stock.txt", ios::out | ios::app);
	cout<<"INGRESE CODIGO: "<<endl;
	cin>>codigo;
	cout<<"INGRESE NOMBRE DEL PRODUCTO: "<<endl;
	cin>>nombre;
	cout<<"INGRESE NIVEL MINIMO: "<<endl;
	cin>>nivmin;
	cout<<"INGRESE NIVEL ACTUAL: "<<endl;
	cin>>nivactual;
	cout<<"INGRESE PROVEEDOR: "<<endl;
	cin>>proveedor;
	cout<<"INGRESE PRECIO: "<<endl;
	cin>>precio;
	
		if (nivactual<=nivmin){
			cout<<"hacer pedido";
		}
		
	es<<codigo<<"\t"<<nombre<<"\t"<<nivmin<<"\t"<<nivactual<<"\t"<<proveedor<<"\t"<<precio<<endl;
	es.close();	
}

void observar(ifstream &lec) {	
	system("cls");
	int codigo;
	string nombre;
	int nivmin;
	int nivactual;
	string proveedor;
	float precio;
	lec.open("stock.txt", ios::in);
		lec>>codigo;
	while (!lec.eof()){
		lec>>nombre;
		lec>>nivmin;
		lec>>nivactual;
		lec>>proveedor;
		lec>>precio;
		cout<<"codigo: "<<codigo<<endl;
		cout<<"producto: "<<nombre<<endl;
		cout<<"nivel minimo: "<<nivmin<<endl;
		cout<<"nivel actual: "<<nivactual<<endl;
		cout<<"proveedor: "<<proveedor<<endl;
		cout<<"precio: "<<precio<<endl;
		cout<<"_________________________________";
		lec>>codigo;
	}
	lec.close();
	system ("pause");
}	

int main(){
	ofstream esc;
	ifstream lec;
	int op;
	do{
		system("cls");
		op=menu();
		switch(op){
			case 1:
				agregar(esc);
				
			break;
			
			case 2:
				observar(lec);
				
			break;
		}
		
	}while(op !=3);
		
	
	return 0;
}
