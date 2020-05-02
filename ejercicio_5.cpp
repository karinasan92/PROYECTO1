#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct jugadores {
	string nombre;
	string nacionalidad;
	int edad;
	float sueldo;
};
void mp();
void agregardatos();
void leerdatos();
int main(){
	mp();
	
	return 0;
}

void mp(){
	int resp;

		do {
		system("CLS");
		cout<<"------------------------"<<"\n";
		cout<<"    MENU PRINCIPAL      "<<"\n";
		cout<<"------------------------"<<"\n";
		cout<<"1 - INGRESAR DATOS"<<"\n";
		cout<<"2 - REPORTE "<<"\n";
		cout<<"3 - SALIR "<<"\n";
		cout<<"------------------------"<<"\n";
		cout<<"SELECCIONE SU OPCION: "<<"\n";
		cin>>resp;
			if (resp==1){
				system ("CLS");
				agregardatos();
			}
			else if (resp==2){
				system ("CLS");
				leerdatos();
			}
			else if (resp==3)
				break;
			else
				break;
			
		} while(resp!=3);	
}

void agregardatos(){
	string nombre_agr;
	string nacionalidad_agr;
	int edad_agr;
	float sueldo_agr;
	fflush(stdin);
	cout<<"INGRESE NOMBRE: "<<endl;
	getline(cin,nombre_agr);
	fflush(stdin);
	cout<<"INGRESE NACIONALIDAD: "<<endl;
	getline(cin,nacionalidad_agr);
	cout<<"INGRESE EDAD: "<<endl;
	cin>>edad_agr;
	cout<<"INGRESE SUELDO: "<<endl;
	cin>>sueldo_agr;
	float aumento=0;
	float sueldoliquido=0;
	
	
	ofstream archivo;
	fflush(stdin);
	archivo.open("jugadores.txt",ios::app);
	if(archivo.fail()){
		cout<<"no se pudo abrir el archivo";
		exit(1);
	}	
	archivo<<nombre_agr<<"\t"<<nacionalidad_agr<<"\t"<<edad_agr<<"\t"<<sueldo_agr<<endl;
	
		if (nacionalidad_agr == "extranjero"){
			aumento=sueldo_agr+500;
			cout<<"sueldo fijo con aumento de 500 = "<<aumento<<endl;
		}
		else{
			aumento=sueldo_agr;
			cout<<"sueldo fijo = "<<aumento<<endl;
		}
		
		if ((edad_agr>=15)&&(edad_agr<=20)){
			sueldoliquido=aumento+1400;
			cout<<"sueldo liquido = "<<sueldoliquido<<endl;
		}
		else if((edad_agr>=21)&&(edad_agr<=25)){
			sueldoliquido=aumento+1500;
			cout<<"sueldo liquido = "<<sueldoliquido<<endl;
		}
		else if((edad_agr>=26)&&(edad_agr<=30)){
			sueldoliquido=aumento+1200;
			cout<<"sueldo liquido = "<<sueldoliquido<<endl;
		}
		else if(edad_agr>30){
			sueldoliquido=aumento+800;
			cout<<"sueldo liquido = "<<sueldoliquido<<endl;
		}
		system("pause");
		
		
		
	archivo.close();	
}

void leerdatos(){
	ifstream archivo;
	archivo.open("jugadores.txt",ios::in);
	int lineas,i=0;
	string s,linea;
	if (archivo.fail()){
			cout<<"no se pudo abrir el archivo";
			exit(1);
	}
	while (getline(archivo, s))
	lineas++;
	archivo.close();
	
	jugadores recordset[lineas];
		//fflush(stdin);
		archivo.open("jugadores.txt",ios::in);
		if(archivo.fail()) {
		cout<<"no se pudo abrir el archivo";
		exit(1);
		}
		for (int i = 0; i < lineas; i++)
	{
		if(!archivo)
		{
			cerr<<"no se puede abrir el archivo"<<endl;
			system("pause");
		}
archivo>>recordset[i].nombre>>recordset[i].nacionalidad>>recordset[i].edad>>recordset[i].sueldo;
	
	}
	archivo.close();

	for (int i = 0; i < lineas; i++) {
		cout<<recordset[i].nombre<<"\t"<<recordset[i].nacionalidad<<"\t"<<recordset[i].edad<<"\t"<<recordset[i].sueldo<<endl;
	}

	system("pause");		
}
