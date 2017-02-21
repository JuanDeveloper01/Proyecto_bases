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
  cout<<" Que quieres hacer con la base de datos. \n\n 1.Listar Todas Las Personas \n 2.Adicionar un registro \n 3.Buscar Registro Dado Nombre \n 4.Actualizar registro dada cedula \n 5.Actualizar registro por nombre \n 6.Buscar registro por cedula \n 7. Ir a un numero de registro\n 8.Cargar archivo\n\n\n\n";
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
  int next=1;
  bool nexti=false;
  
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
									cout<<"\n\n\nEncontre La Persona\n\n\n";
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
		cout<<"4";
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
  		};
  
  break; 

};   
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7/////  

};

system("PAUSE");
return 0;


}



