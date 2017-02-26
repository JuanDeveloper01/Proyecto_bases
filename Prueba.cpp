/*--------------------------------------------------------------------
AUTORES: JUAN CARLOS PATIÑO HERNANDEZ (1088023446) 
PROGRAMA: REGISTROS BASES DE DATOS
FECHA:07/02/2017
VERCION:1.0
----------------------------------------------------------------------*/

//librerias c
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

using namespace std;

FILE *DataBase0;
FILE *DataBase3; 
FILE *DataBase2; 

int menu(){  
   int program = 0;	
      printf( " ......................PROGRAMA DE REGISTROS..................  \n\n");
      printf("         Menu para ingreso al programa      \n\n\n 1.Archivos de longitud fija \n 2.Archivos de longitud variable \n 3.Archivos en txt \n\n");
      cout<< "opcion:  ";  
      cin >> program;    
  return program;	
};

int modificar(){
  int Basedat3 = 0;
  cout<<" Que quieres hacer con la base de datos. \n\n 1.Listar Todas Las Personas \n 2.Adicionar un registro \n 3.Buscar Registro Dado Nombre \n 4.Buscar Registro Dada Cedula \n 5.Eliminar registro por cedula \n 6.Actualizar registro por cedula \n 7. Ir a un numero de registro\n 8.Cargar archivo\n\n\n\n";
  cout<<"\n\n ingresa Opcion:";
  cin>> Basedat3;
  return Basedat3;
	
};


//FUNCION PRINCIPAL DEL PROGRAMA
	
 int main () {
 bool salir= true;
 
 while(salir!=false){  	

 switch (menu()) {
case 1:
//programa de registros de longitud	

  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
case 2:
//programa de registros variables	

  

break;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	  
 case 3: 	
  system("cls");	
 //programa de registros en modo txt 
  int abrir;
  int recorre;
  long int identificador3;
  char cedula3[20];
  char nombre3[50];
  char Dia_nacimiento3[2];
  char Mes_nacimiento3[2]; 
  unsigned short int  Ano_nacimiento3;
  unsigned long int Ganancia_anual3; 
  int paso=0;
  char continuar;   
  char guardar;
  bool sal;
  bool encontro=false;
  int volver=0;
  bool salto=false;				
  int next=1;								//variable para identidad de datos y ademas saber cual es su nobre
  bool nexti=false;							//variable que me permite dar identidad a los datos
  char nombreG[50];                       //variable que me guarda el nombre cuando consukto por cedula
  char  identificadorG[5];					//varibale que me guarda el identificador cuando consulto por cedula	
  int i=1;			
  int N=0;						//esta es la variable de nombre						
	  switch (modificar()) {
		case 1: 
		        
  				DataBase3 = fopen("Base_Datos.txt","r");
				cout<<"                               Base de Datos\n\n";
				if (DataBase3 == NULL)
					{
						cout << "EL ARCHIVO ORIGEN DE LA BASE DE DATOS NO EXISTE ...... INSERTAR ARCHIVO  ";
						return 1;
					}
					
					while((abrir = getc(DataBase3)) != EOF)
						{
						    if(paso==0){
						    cout<<"Nombre:  ";	
							 paso ++;
						    }
							if(abrir == '|' )
							{
								cout<<"\n";	
									if(paso==1&& sal == false)
										{
									    	cout<<"identificador:  ";	
										 	paso ++;
										 	sal=true;
										 	
									    }	
										if(paso==2 && sal == false)
											{
										    	cout<<"cedula:  ";	
											 	paso ++;
											 	sal=true;
										    }	
											if(paso==3&& sal == false)
												{
											    	cout<<"Dia de nacimiento:  ";	
												 	paso ++;
												 	sal=true;
											    }							
	               								if(paso==4&& sal == false)
													{
												    	cout<<"Mes de nacimiento:  ";	
													 	paso ++;
													 	sal=true;
												    }	
													if(paso==5&& sal == false)
														{
													    	cout<<"Anio nacimiento:  ";	
														 	paso ++;
														 	sal=true;
													    }		
														if(paso==6&& sal == false)
															{
														    	cout<<"Ganancia anual:  ";
																sal=true;	
															 	paso=1;
														    }		             
							}
							else {
									printf("%c",abrir);	
									sal=false;
		                         }
						}
				cout<<"\n\n\n Fin... Presiona  S  para volver al menu principal o N para finaliza \n\n\n";
				cin>>continuar;
				if(continuar == 's')
				{
					system ("cls");
				}else{
					system ("cls");
					cout<<"Adios un placer Servirte\n\n\n";
					salir=false;
				}
				fclose(DataBase3);
				             		
		
		break;
		
		case 2: 
		DataBase3 = fopen("Base_Datos.txt","a+");
		system ("cls");
		cout<<" \n\n                   Adicion de personas...        \n\n";
		
		cout <<"Nombre:  ";
		cin.getline(nombre3, sizeof(nombre3), '.');	
		cout <<"identificador:  ";
		cin>>identificador3;			
		cout <<"Cedula:  ";
		cin>>cedula3;			
		cout <<"Dia_nacimiento:  ";
		cin>>Dia_nacimiento3;		
		cout <<"Mes_nacimiento:  ";
		cin>>Mes_nacimiento3;
		cout <<"Ano_nacimiento:  ";
		cin>>Ano_nacimiento3;
		cout <<"Ganancia_anual:  ";
		cin>>Ganancia_anual3;
				
		cout << "       Desea Guardar La información      S guardar y N para volver al menu ";
		cin>>guardar;
		if(guardar == 's')
			{   
				fprintf(DataBase3,"\n%s|",nombre3);
				fprintf(DataBase3,"%i|",identificador3);
				fprintf(DataBase3,"%s|",cedula3);
				fprintf(DataBase3,"%s|",Dia_nacimiento3);
				fprintf(DataBase3,"%s|",Mes_nacimiento3);	
				fprintf(DataBase3,"%i|",Ano_nacimiento3);
				fprintf(DataBase3,"%i",Ganancia_anual3);				
			
			}else{
				cout<<"datos no guardados...";
			} 	
				
	
		cout<<"\n\n\n Fin... Presiona  S  para volver al menu principal o N para finaliza.... \n\n\n";
		cin>>continuar;
		if(continuar == 's')
		{
			system ("cls");
		}else{
			system ("cls");
			cout<<"Adios un placer Servirte\n\n\n";
			salir=false;
		}
		fclose(DataBase3);
			
		break;  
  		case 3: 
  		DataBase3 = fopen("Base_Datos.txt","a+");
  		char Buscar[50];
  		cout<<"Ingresa el nombre, para buscar el registro:  ";
  		cin.getline(Buscar, sizeof(Buscar), '.');
  		cout<<"\n\n\n\n\n\n";
  		
				if (DataBase3 == NULL)
					{
						cout << "EL ARCHIVO ORIGEN DE LA BASE DE DATOS NO EXISTE ...... INSERTAR ARCHIVO  ";
						return 1;
					}
					
					while((recorre = getc(DataBase3)) != EOF)					
						{   
							if(Buscar[volver]==recorre)
							{  
								volver++;
								if(volver==(strlen(Buscar)))
								{	
								    encontro=true;				
									system ("cls");				
									cout<<"\n\n\nEncontre La Persona\n\n\n";
									cout<<"__________________________________________________________________________________________________";
									cout<<Buscar;
								}
							}else if(encontro!=true){
									volver=1;
								} else if(recorre == '|' ){
									cout<<"\n";		
									if(next==1&& nexti==false)
										{
									    	cout<<"identificador:  ";	
										 	next ++;
										 	nexti=true;
										 	
									    }	
										if(next==2 && nexti==false)
											{
										    	cout<<"cedula:  ";	
											 	next ++;
											 	nexti=true;
										    }	
											if(next==3&& nexti==false)
												{
											    	cout<<"Dia de nacimiento:  ";	
												 	next ++;
												 	nexti=true;
											    }							
	               								if(next==4 && nexti==false)
													{
												    	cout<<"Mes de nacimiento:  ";	
													 	next ++;
													 	nexti=true;
												    }	
													if(next==5&& nexti==false)
														{
													    	cout<<"Anio nacimiento:  ";	
														 	next ++;
														 	nexti=true;
													    }		
														if(next==6&& nexti==false)
															{
														    	cout<<"Ganancia anual:  ";	
																nexti=true;
																next=1;														 	
														    }							
																							    		             
											}else if(recorre=='\n'){
												salto=true;
												break;
											}
											else if (salto!=true){ 																						
													printf("%c",recorre);	
													nexti=false;
						                         }  		
				  		               
  		                }
  		
  		
	if(encontro!=true){
		 cout<<"\n\n\n No se encontro la persona..\n\n\n";
		 
		 }
	cout<<"\n\n\n Fin... Presiona  S  para volver al menu principal o N para finaliza.... \n\n\n";
		cin>>continuar;
		if(continuar == 's')
		{
			system ("cls");
		}else{
			system ("cls");
			cout<<"Adios un placer Servirte\n\n\n";
			salir=false;
		}
		
		fclose(DataBase3);  		
  		
		break;
		case 4: 
		
		DataBase3 = fopen("Base_Datos.txt","a+");
  		cout<<"Ingresa la cedula, para buscar el registro:  ";
  		cin.getline(Buscar, sizeof(Buscar), '.');
  		cout<<"\n\n\n\n\n\n";
  		
					while((recorre = getc(DataBase3)) != EOF)					
						{  
						if(recorre =='\n' )
							{	
							  i=1;									
									
							}else{	
								nombreG[i]=recorre;
								i++;									
										
								}
							if(Buscar[volver]==recorre)
							{  
								volver++;
								if(volver==(strlen(Buscar)))
								{	
								    encontro=true;				
									system ("cls");				
									cout<<"\n\n\nEncontre La Persona\n\n\n";
									cout<<"\n\n__________________________________________________________________________________________________\n\n";
									cout<<Buscar;
								}
							}else if(encontro!=true){
									volver=1;
								} else if(recorre == '|' ){
									cout<<"\n";		
									if(next==1&& nexti==false)
										{   i=1;
										    N=1;
											while(1){
												if(nombreG[i]=='|'){												
														break;												       
												}else {
													i++;
												}
												
											}
											cout<<"Nombre:  ";	
											while(1){
												if(i==N){
													break;
												}else{
													cout<<nombreG[N];
													N++;
												} 
												
											}
											N=1;
											cout<<"\nIdentificador:  ";
											while(1){
												if(nombreG[i+N]=='|'){
													break;
												}else{
													cout<<nombreG[i+N];
													N++;
												}
												
											}								
									    	cout<<"\nDia de nacimiento:  ";	
										 	next ++;
										 	nexti=true;
										 	
									    }	
										if(next==2 && nexti==false)
											{
										    	cout<<"Mes de nacimiento:  ";	
											 	next ++;
											 	nexti=true;
										    }	
											if(next==3&& nexti==false)
												{
											    	cout<<"Anio de nacimiento:  ";	
												 	next ++;
												 	nexti=true;
											    }							
	               								if(next==4 && nexti==false)
													{
												    	cout<<"Ganancia anual:  ";	
													 	nexti=true;
													 	next=1;	
												    }	
																				
																							    		             
											}else if(recorre=='\n'){
												salto=true;
												break;
											}
											else if (salto!=true){ 																						
													printf("%c",recorre);	
													nexti=false;
						                         }  		
				  		               
  		                }
				  		               
  		                
  		
  	
	if(encontro!=true){
		 cout<<"\n\n\n NO SE ENCONTRO LA PERSONA..\n\n\n";
		 
		 }  		
	cout<<"\n\n\n Fin... Presiona  S  para volver al menu principal o N para finaliza.... \n\n\n";
		cin>>continuar;
		if(continuar == 's')
		{
			system ("cls");
		}else{
			system ("cls");
			cout<<"Adios un placer Servirte\n\n\n";
			salir=false;
		}
		
		fclose(DataBase3);
		
		break;		
		
  		case 5: 
		cout<<"5";
		break;
		case 6: 
		cout<<"6";
		break;
		case 7: 
		cout<<"7";
		break;			
		case 8: 
		char c[50];
		int i=0;
				cout<<"ingresa el nombre del txt el cual se va a cargar:   ";
				cin>>c;				
		  		DataBase3 = fopen("Base_Datos.txt","a+");							
				DataBase0= fopen(c,"a+");									
				if (DataBase0 == NULL)
					{
						cout << "EL ARCHIVO ORIGEN DE LA BASE DE DATOS NO EXISTE ...... INSERTAR ARCHIVO  ";
						return 1;
					}
					
					while((abrir = getc(DataBase0)) != EOF)
						{		
						if(abrir=='|'){
							i++;
						}					
						fprintf(DataBase3,"%c",abrir);							                         
						}
				cout<<"\n\n\n " <<i/6<<"  Registros Exportados con exito \n\n\n";		
				cout<<"\n\n\n Fin... Presiona  S  para volver al menu principal o N para finaliza \n\n\n";
				cin>>continuar;
				if(continuar == 's')
				{
					system ("cls");
				}else{
					system ("cls");
					cout<<"Adios un placer Servirte\n\n\n";
					salir=false;
				}
				fclose(DataBase3);
				fclose(DataBase0);
				             
		
		break;			
		
  		};
  
  break; 

};   
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7/////  

};

system("PAUSE");
return 0;


}





/*--------------------------------------------------------------------
AUTORES: JUAN CARLOS PATIÑO HERNANDEZ (1088023446) 
PROGRAMA: REGISTROS BASES DE DATOS
FECHA:07/02/2017
VERCION:1.0
----------------------------------------------------------------------*/

//librerias c
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

using namespace std;

FILE *DataBase0;
FILE *DataBase3; 
FILE *DataBase2; 

int menu(){  
   int program = 0;	
      printf( " ......................PROGRAMA DE REGISTROS..................  \n\n");
      printf("         Menu para ingreso al programa      \n\n\n 1.Archivos de longitud fija \n 2.Archivos de longitud variable \n 3.Archivos en txt \n\n");
      cout<< "opcion:  ";  
      cin >> program;    
  return program;	
};

int modificar(){
  int Basedat3 = 0;
  cout<<" Que quieres hacer con la base de datos. \n\n 1.Listar Todas Las Personas \n 2.Adicionar un registro \n 3.Buscar Registro Dada Cedula \n 4.Buscar Registro Dado Nombre \n 5.Eliminar registro por cedula \n 6.Actualizar registro por cedula \n 7. Ir a un numero de registro\n 8.Cargar archivo\n\n\n\n";
  cout<<"\n\n ingresa Opcion:";
  cin>> Basedat3;
  return Basedat3;
	
};


//FUNCION PRINCIPAL DEL PROGRAMA
	
 int main () {
 bool salir= true;
 
 while(salir!=false){  	

 switch (menu()) {
case 1:
//programa de registros de longitud	

  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
case 2:
//programa de registros variables	

  

break;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	  
 case 3: 	
  system("cls");	
 //programa de registros en modo txt 
 //programa de registros en modo txt 
  int abrir;
  int recorre;
  long int identificador3;
  char cedula3[20];
  char nombre3[50];
  char Dia_nacimiento3[2];
  char Mes_nacimiento3[2]; 
  unsigned short int  Ano_nacimiento3;
  unsigned long int Ganancia_anual3; 
  int paso=1;
  int paso2=0;
  char continuar;   
  char guardar;
  bool sal;
  bool encontro=false;
  int volver=0;
  bool salto=false;				
  int next=1;								//variable para identidad de datos y ademas saber cual es su nobre
  bool nexti=false;							//variable que me permite dar identidad a los datos
  char nombreG[50];                       //variable que me guarda el nombre cuando consukto por cedula
  char  identificadorG[5];					//varibale que me guarda el identificador cuando consulto por cedula	
  int i=1;			
  int N=0;						//esta es la variable de nombre						
  int nm=1;
  char nombrado[50];	  
	  switch (modificar()) {
		case 1: 
		        
  				DataBase3 = fopen("Base_Datosc.txt","r");
				cout<<"                               Base de Datos\n\n";
				if (DataBase3 == NULL)
					{
						cout << "EL ARCHIVO ORIGEN DE LA BASE DE DATOS NO EXISTE ...... INSERTAR ARCHIVO  ";
						return 1;
					}
					
					while((abrir = getc(DataBase3)) != EOF)
						{   												    
							if(abrir == '|' )
							{
								cout<<"\n";	
									if(paso==1&& sal == false)
										{
									    	cout<<"cedula:  ";	
										 	paso ++;
										 	sal=true;
										 	
									    }	
										if(paso==2 && sal == false)
											{
										    	cout<<"Nombre:  ";	
											 	paso ++;
											 	sal=true;
										    }	
											if(paso==3&& sal == false)
												{
											    	cout<<"Dia de nacimiento:  ";	
												 	paso ++;
												 	sal=true;
											    }							
	               								if(paso==4&& sal == false)
													{
												    	cout<<"Mes de nacimiento:  ";	
													 	paso ++;
													 	sal=true;
												    }	
													if(paso==5&& sal == false)
														{
													    	cout<<"Anio nacimiento:  ";	
														 	paso ++;
														 	sal=true;
													    }		
														if(paso==6&& sal == false)
															{
														    	cout<<"Ganancia anual:  ";
																sal=true;	
															 	paso=1;
														    }		             
							}
							else {
									printf("%c",abrir);	
									sal=false;
		                         }
						}
				cout<<"\n\n\n Fin... Presiona  S  para volver al menu principal o N para finaliza \n\n\n";
				cin>>continuar;
				if(continuar == 's')
				{
					system ("cls");
				}else{
					system ("cls");
					cout<<"Adios un placer Servirte\n\n\n";
					salir=false;
				}
				fclose(DataBase3);
				             		
		
		break;
		
		case 2: 
		

		DataBase3 = fopen("Base_Datosc.txt","a+");
		system ("cls");
		cout<<" \n\n                   Adicion de personas...        \n\n";

		cout <<"identificador:  ";
		cin>>identificador3;			
		cout <<"Cedula:  ";
		cin>>cedula3;		
		cout <<"Nombre:  "<<flush;
		cin.get(); 
		cin.getline(nombre3, sizeof(nombre3), '.');		
		cout <<"Dia_nacimiento:  ";
		cin>>Dia_nacimiento3;		
		cout <<"Mes_nacimiento:  ";
		cin>>Mes_nacimiento3;
		cout <<"Ano_nacimiento:  ";
		cin>>Ano_nacimiento3;
		cout <<"Ganancia_anual:  ";
		cin>>Ganancia_anual3;
				
		cout << "       Desea Guardar La información      S guardar y N para volver al menu ";
		cin>>guardar;
		if(guardar == 's')
			{   				
				fprintf(DataBase3,"\n%i|",identificador3);
				fprintf(DataBase3,"%s|",cedula3);
				fprintf(DataBase3,"%s|",nombre3);
				fprintf(DataBase3,"%s|",Dia_nacimiento3);
				fprintf(DataBase3,"%s|",Mes_nacimiento3);	
				fprintf(DataBase3,"%i|",Ano_nacimiento3);
				fprintf(DataBase3,"%i",Ganancia_anual3);				
			
			}else{
				cout<<"datos no guardados...";
			} 	
				
	
		cout<<"\n\n\n Fin... Presiona  S  para volver al menu principal o N para finaliza.... \n\n\n";
		cin>>continuar;
		if(continuar == 's')
		{
			system ("cls");
		}else{
			system ("cls");
			cout<<"Adios un placer Servirte\n\n\n";
			salir=false;
		}
		fclose(DataBase3);
			
		break;  
  		case 3: 
  		DataBase3 = fopen("Base_Datosc.txt","a+");
  		char Buscar[50];
  		cout<<"Ingresa el nombre, para buscar el registro:  ";
  		cin.getline(Buscar, sizeof(Buscar), '.');
  		cout<<"\n\n\n\n\n\n";
  		
				if (DataBase3 == NULL)
					{
						cout << "EL ARCHIVO ORIGEN DE LA BASE DE DATOS NO EXISTE ...... INSERTAR ARCHIVO  ";
						return 1;
					}
					
					while((recorre = getc(DataBase3)) != EOF)					
						{   
							if(Buscar[volver]==recorre)
							{  
								volver++;
								if(volver==(strlen(Buscar)))
								{	
								    encontro=true;				
									system ("cls");				
									cout<<"\n\n\nEncontre La Persona\n\n\n";
									cout<<"__________________________________________________________________________________________________";
									cout<<Buscar;
								}
							}else if(encontro!=true){
									volver=1;
								} else if(recorre == '|' ){
									cout<<"\n";		
									if(next==1&& nexti==false)
										{
									    	cout<<"identificador:  ";	
										 	next ++;
										 	nexti=true;
										 	
									    }	
										if(next==2 && nexti==false)
											{
										    	cout<<"cedula:  ";	
											 	next ++;
											 	nexti=true;
										    }	
											if(next==3&& nexti==false)
												{
											    	cout<<"Dia de nacimiento:  ";	
												 	next ++;
												 	nexti=true;
											    }							
	               								if(next==4 && nexti==false)
													{
												    	cout<<"Mes de nacimiento:  ";	
													 	next ++;
													 	nexti=true;
												    }	
													if(next==5&& nexti==false)
														{
													    	cout<<"Anio nacimiento:  ";	
														 	next ++;
														 	nexti=true;
													    }		
														if(next==6&& nexti==false)
															{
														    	cout<<"Ganancia anual:  ";	
																nexti=true;
																next=1;														 	
														    }							
																							    		             
											}else if(recorre=='\n'){
												salto=true;
												break;
											}
											else if (salto!=true){ 																						
													printf("%c",recorre);	
													nexti=false;
						                         }  		
				  		               
  		                }
  		
  		
	if(encontro!=true){
		 cout<<"\n\n\n No se encontro la persona..\n\n\n";
		 
		 }
	cout<<"\n\n\n Fin... Presiona  S  para volver al menu principal o N para finaliza.... \n\n\n";
		cin>>continuar;
		if(continuar == 's')
		{
			system ("cls");
		}else{
			system ("cls");
			cout<<"Adios un placer Servirte\n\n\n";
			salir=false;
		}
		
		fclose(DataBase3);  		
  		
		break;
		case 4: 
		
		DataBase3 = fopen("Base_Datosc.txt","a+");
  		cout<<"Ingresa El Nombre, para buscar el registro:  ";
  		cin.getline(Buscar, sizeof(Buscar), '.');
  		cout<<"\n\n\n\n\n\n";
  		
					while((recorre = getc(DataBase3)) != EOF)					
						{  
						if(recorre =='\n' )
							{	
							  i=1;									
									
							}else{	
								nombreG[i]=recorre;
								i++;									
										
								}
							if(Buscar[volver]==recorre)
							{  
								volver++;
								if(volver==(strlen(Buscar)))
								{	
								    encontro=true;				
									system ("cls");				
									cout<<"\n\n\nEncontre La Persona\n\n\n";
									cout<<"\n\n__________________________________________________________________________________________________\n\n";
									cout<<Buscar;
								}
							}else if(encontro!=true){
									volver=1;
								} else if(recorre == '|' ){
									cout<<"\n";		
									if(next==1&& nexti==false)
										{   i=1;
										    N=1;
											while(1){
												if(nombreG[i]=='|'){												
														break;												       
												}else {
													i++;
												}
												
											}
											cout<<"ID:  ";	
											while(1){
												if(i==N){
													break;
												}else{
													cout<<nombreG[N];
													N++;
												} 
												
											}
											N=1;
											cout<<"\nCedula:  ";
											while(1){
												if(nombreG[i+N]=='|'){
													break;
												}else{
													cout<<nombreG[i+N];
													N++;
												}
												
											}								
									    	cout<<"\nDia de nacimiento:  ";	
										 	next ++;
										 	nexti=true;
										 	
									    }	
										if(next==2 && nexti==false)
											{
										    	cout<<"Mes de nacimiento:  ";	
											 	next ++;
											 	nexti=true;
										    }	
											if(next==3&& nexti==false)
												{
											    	cout<<"Anio de nacimiento:  ";	
												 	next ++;
												 	nexti=true;
											    }							
	               								if(next==4 && nexti==false)
													{
												    	cout<<"Ganancia anual:  ";	
													 	nexti=true;
													 	next=1;	
												    }	
																				
																							    		             
											}else if(recorre=='\n'){
												salto=true;
												break;
											}
											else if (salto!=true){ 																						
													printf("%c",recorre);	
													nexti=false;
						                         }  		
				  		               
  		                }
				  		               
  		                
  		
  	
	if(encontro!=true){
		 cout<<"\n\n\n NO SE ENCONTRO LA PERSONA..\n\n\n";
		 
		 }  		
	cout<<"\n\n\n Fin... Presiona  S  para volver al menu principal o N para finaliza.... \n\n\n";
		cin>>continuar;
		if(continuar == 's')
		{
			system ("cls");
		}else{
			system ("cls");
			cout<<"Adios un placer Servirte\n\n\n";
			salir=false;
		}
		
		fclose(DataBase3);
		
		break;		
		
  		case 5: 
		cout<<"5";
		break;
		case 6: 
		cout<<"6";
		break;
		case 7: 
		cout<<"7";
		break;			
		case 8: 
		char c[50];
		int i=0;
				cout<<"ingresa el nombre del txt el cual se va a cargar:   ";
				cin>>c;				
		  		DataBase3 = fopen("Base_Datosc.txt","a+");							
				DataBase0= fopen(c,"a+");									
				if (DataBase0 == NULL)
					{
						cout << "EL ARCHIVO ORIGEN DE LA BASE DE DATOS NO EXISTE ...... INSERTAR ARCHIVO  ";
						return 1;
					}
					
					while((abrir = getc(DataBase0)) != EOF)
						{		
						if(abrir=='|'){
							i++;
						}					
						fprintf(DataBase3,"%c",abrir);							                         
						}
				cout<<"\n\n\n " <<i/6<<"  Registros Exportados con exito \n\n\n";		
				cout<<"\n\n\n Fin... Presiona  S  para volver al menu principal o N para finaliza \n\n\n";
				cin>>continuar;
				if(continuar == 's')
				{
					system ("cls");
				}else{
					system ("cls");
					cout<<"Adios un placer Servirte\n\n\n";
					salir=false;
				}
				fclose(DataBase3);
				fclose(DataBase0);
				             
		
		break;			
		
  		};
  
  break; 

};   
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7/////  

};

system("PAUSE");
return 0;


}



