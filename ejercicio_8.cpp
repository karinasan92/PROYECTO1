#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void guardar ();
int main(){
	guardar();
}


void guardar() {
	int tipo;
	//string servicio;
	int costo;
	int area;
	float exedente=0;
	float costototal=0;

	cout<<"-----MENU PRINCIPAL------"<<endl;
	cout<<"1. MALA HIERVA......10.00"<<endl;
	cout<<"2. LANGOSTAS........20.00"<<endl;
	cout<<"3. GUSANOS..........30.00"<<endl;
	cout<<"4. TODO LO ANTERIOR 50.00"<<endl<<endl;
	
	cout<<"INGRESE EL TIPO DE SERVICIO: "<<endl;
	cin>>tipo;
	cout<<"INGRESE LA CANTIDAD DE HECTAREAS A FUMIGAR: "<<endl;
	cin>>area;

	if (tipo==1){
		costo = 10;	
	}
	else if (tipo==2){
		costo = 20;
	}else if (tipo==3){
		costo = 30;
	}else if (tipo==4){
		costo = 50;
	}
	

	
	if (area > 500){
		costototal= (costo*area)*0.95;
		cout<<"TOTAL A PAGAR: "<<costototal<<endl;
	}else {
		costototal=costo*area;
		cout<<"TOTAL A PAGAR: "<<costototal<<endl;
	}
	
	if (costototal>1500){
		exedente=(costototal-1500)*0.90;
		cout<<"PAGO TOTAL CON DESCUENTO DEL 10% SOBRE EL EXCEDENTE: "<<exedente<<endl;
	}else{
		exedente= 0;
		cout<<"EL TOTAL NO CONTIENE EXCEDENTE: "<<exedente<<endl;
	}


	ofstream archivo;
	archivo.open("fumigacion.text",ios::app);
		if(archivo.fail()){
		cout<<"no se pudo abrir el archivo";
		exit(1);
	}
	archivo<<tipo<<"\t"<<costo<<"\t"<<area<<"\t"<<costototal<<"\t"<<exedente<<endl;
	archivo.close();

}

/*
void leerarchivo(string na){
	ifstream archivo;
	archivo.open("fumigacion.txt",ios::in);
	int lineas,i=0;
	string s,linea;
	if(archivo.fail()){
		cout<<"no se pudo abrir el archivo";
		exit(1);	
	}
	while (getline(archivo,s))
	lineas++;
	archivo.close();
	
	recordset[lineas];
	archivo.open("fumigacion.txt",ios::in);
	if(archivo.fail()){
		cout<<"no se pudo abrir el archivo";
		exit(1);
	}
	for (int i=0;i<lineas;i++){
		if (!archivo){
			cerr<<"no puede abrir el archivo"<<endl;
			system ("pause");
			break;
		}
		archivo>>recordset[i].tipo>>recordset[i].costo>>recordset[i].area>>recordset[i].costototal>>recordset[i].exedente;
	}
	archivo.close();
	for(int i=0;i<lineas;i++){
		cout<<recordset[i].tipo<<recordset[i].costo<<recordset[i].area<<recordset[i].costototal<<recordset[i].exedente<<endl;
	}
	system("pause");
}*/
