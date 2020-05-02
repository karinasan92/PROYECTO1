#include <fstream>
#include <iostream>
#include <string>
//#include <sstream>

using namespace std;

struct vehiculos {
	string nomconduc;
	int edad;
	string modelo;
	string color;
	
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
	string nomconduc_agr;
	int edad_agr;
	string modelo_agr;
	string color_agr;
	fflush(stdin);
	cout<<"INGRESE NOMBRE CONDUCTOR: "<<endl;
	getline(cin,nomconduc_agr);
	cout<<"INGRESE EDAD: "<<endl;
	cin>>edad_agr;
	fflush(stdin);
	cout<<"INGRESE MODELO DEL AUTOMOVIL: "<<endl;
	getline(cin,modelo_agr);
	fflush(stdin);
	cout<<"INGRESE COLOR DEL AUTOMOVIL: "<<endl;
	getline(cin,color_agr);
	float precio=0;
	float aumento=0;
	float totalpagar=0;
	
	ofstream archivo;
	fflush(stdin);
	archivo.open("vehiculos.txt",ios::app);
	if(archivo.fail()){
		cout<<"no se pudo abrir el archivo";
		exit(1);
	}	

	
		if ((modelo_agr == "a")&&(color_agr== "blanco")) {
			precio=240.50;
			cout<<"EL PRECIO DEL SEGURO DE SU AUTOMOVIL ES: "<<precio<<endl;
		}
		else if((modelo_agr == "a")&&(color_agr== "metalizado")){
			precio=330;
			cout<<"EL PRECIO DEL SEGURO DE SU AUTOMOVIL ES: "<<precio<<endl;
		}
		else if (modelo_agr == "a") {
			precio=270.50;
			cout<<"EL PRECIO DEL SEGURO DE SU AUTOMOVIL ES: "<<precio<<endl;
		}
		
		if ((modelo_agr == "b")&&(color_agr== "blanco")) {
			precio=300;
			cout<<"EL PRECIO DEL SEGURO DE SU AUTOMOVIL ES: "<<precio<<endl;
		}
		else if((modelo_agr == "b")&&(color_agr== "metalizado")){
			precio=360.50;
			cout<<"EL PRECIO DEL SEGURO DE SU AUTOMOVIL ES: "<<precio<<endl;
		}
		else if (modelo_agr == "b") {
			precio=330;
			cout<<"EL PRECIO DEL SEGURO DE SU AUTOMOVIL ES: "<<precio<<endl;
		}
		
				
		if (edad_agr < 31) {
			aumento=precio*0.25;
			totalpagar=aumento+precio;
			cout<<"TOTAL A PAGAR = "<<totalpagar<<endl;
		}
		else if((edad_agr>=31)&&(edad_agr<=65)){
			aumento=0;
			totalpagar=aumento+precio;
			cout<<"TOTAL A PAGAR = "<<totalpagar<<endl;
		}
		else if(edad_agr > 65) {
			aumento=precio*0.30;
			totalpagar=aumento+precio;
			cout<<"TOTAL A PAGAR = "<<totalpagar<<endl;
		}
		
		
	archivo<<nomconduc_agr<<"\t"<<edad_agr<<"\t"<<modelo_agr<<"\t"<<color_agr<<"\t"<<precio<<"\t"<<totalpagar<<endl;
			
		system("pause");
		
		
		
	archivo.close();	
}


void leerdatos(){
	ifstream archivo;
	archivo.open("vehiculos.txt",ios::in);
	int lineas,i=0;
	string s,linea;
	if (archivo.fail()){
			cout<<"no se pudo abrir el archivo";
			exit(1);
	}
	while (getline(archivo, s))
	lineas++;
	archivo.close();
	
	vehiculos recordset[lineas];
		//fflush(stdin);
		archivo.open("vehiculos.txt",ios::in);
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
	archivo>>recordset[i].nomconduc>>recordset[i].edad>>recordset[i].modelo>>recordset[i].color;	
	}
	archivo.close();

	for (int i = 0; i < lineas; i++) {
		cout<<recordset[i].nomconduc<<recordset[i].edad<<recordset[i].modelo<<recordset[i].color<<endl;
	}

	system("pause");		
}
