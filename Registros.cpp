/* -------------------------------------------------------------------
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
#include <stdlib.h>

using namespace std; //maneja de librearias estandar
using std::cout;
using std::cin;
using std::endl;
using std::string;

FILE *DataBase0; //puntero que me apunta al fichero que quiero abrir
FILE *Database1;//puntero de archivo case 1
FILE *DataBase3; //puntero que me apunta al fichero que quiero abrir
FILE *DataBase2; //puntero que me apunta al fichero que quiero 
FILE *DataBaseB8;							
FILE  *DataBaseBP;

struct t_persona{
  long int identificador;															//variable que contiene el ID		
  char cedula[20];																	//variable que me contiene la cedula
  char nombre[50];																	//variable que me contiene el nombre	
  unsigned short int Dia_nacimiento;															//variable que me contiene el dia de nacimiento	
  unsigned short int Mes_nacimiento; 															//variable que me contiene el mes de nacimiento
  unsigned short int  Ano_nacimiento;												//variable que me contiene el anio de nacimiento
  unsigned long int Ganancia_anual;
};

t_persona cargar_persona ();  // CARGAR STRUCT CON UN CLIENTE


template <typename T> void write( FILE* , T ); // Etemplate para guardar en binario

template <typename T> T read(FILE* f); // template para leer 
//Funcion que solo me muestra las opciones del menu y me deja elegir una opcion.
int menu(){  
   int program = 0;	
      system("cls");
      printf( " ......................PROGRAMA DE REGISTROS..................  \n\n");
      printf("         Menu para ingreso al programa      \n\n\n 1.Archivos de longitud fija \n 2.Archivos de longitud variable \n 3.Archivos en txt \n\n");
      cout<< "opcion:  ";  
      cin >> program;    
  return program;	
};
//termina funcion de menu

//Funcion que solo me muestra las opciones del menu de modificacion y me deja elegir una opcion.
int modificar(){
  int Basedat3 = 0;
  cout<<" Que quieres hacer con la base de datos. \n\n 1.Listar Todas Las Personas \n 2.Adicionar un registro \n 3.Buscar Registro Dada Cedula \n 4.Buscar Registro Dado Nombre \n 5.Eliminar registro por cedula \n 6.Actualizar registro por cedula \n 7. Ir a un numero de registro\n 8.Cargar archivo\n\n\n\n";
  cout<<"\n\n ingresa Opcion:";
  cin>> Basedat3;
  return Basedat3;
	
};
//termina funcion modificar


//funcion que me busca por cedula un registro y me devuelve id para ser reemplazado
int Busqueda(char Buscar[18]){
  int recorre;  																    //variable que me recorre cada uno de los caracteres del fichero para case 2
 																					
  bool encontro=false;																//booleano que me da a saber si encontro cedula o nombre igual a la busqueda	
  int volver=0;																		//variable que me permite guardar despues de recorrer el fichero
  bool salto=false;																	//variable que me controla cuando debo salir case 1	
  int next=1;																		//variable para identidad de datos y ademas saber cual es su nobre
  bool nexti=false;																	//variable que me permite dar identidad a los datos
  char nombreG[50];                       											//variable que me guarda el nombre cuando consukto por cedula
  char  cedulaG[50];																//varibale que me guarda el identificador cuando consulto por cedula	
  int i=1;																			//variable que me recorre los char
  int N=0;																			//esta es la variable de nombre						
  char salida[4];
  int salidaPro=0;
  system("cls");	 
		DataBase3 = fopen("Base_Datos.txt","a+");
					while((recorre = getc(DataBase3)) != EOF)					
						{  
						if(recorre =='\n' )
							{	
							  i=1;							
									
							}else{	
								cedulaG[i]=recorre;
								i++;					
										
								}
							if(Buscar[volver]==recorre)
							{  
								volver++;
								if(volver==(strlen(Buscar)))
								{	
								    encontro=true;
								}
							}else if(encontro!=true){
									volver=1;
								} else if(recorre == '|' ){
									cout<<"\n";		
									if(next==1&& nexti==false)
										{   i=1;
										    N=1;
											while(1){
												if(cedulaG[i]=='|'){												
														break;												       
												}else {
													i++;
												      }												
											       }	
											while(1){
												if(i==N){
													break;
												}else{
													salida[N-1]=cedulaG[N];
													N++;
												}   
												
											}
											N=1;					
										 	next ++;
										 	nexti=true;
										 	
									    }
					        }  		
				  		               
  		                }				  		               
 
		
		fclose(DataBase3);
	
	salidaPro=atoi(salida);	
  	system("cls");	
  	return salidaPro;     
		
}







//FUNCION PRINCIPAL DEL PROGRAMA	
 int main () {
 																		//variable que me controla cuando debo poner la descripcion de la variable case 2
 char continuar;  	
 bool salir= true; //variable que me saca del programa
 
 //ciclo principal del programa que me permite repetir el menu
 while(salir!=false){  	

//Casos donde uso el menu principal y segun se elija la opcion lleva a funciiones diferentes
 switch (menu()) {
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//programa de registros de longitud	fija 	
case 1:  {
	system("cls");
	 switch (modificar()) 
	 {
	 	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	  	//Lectura del fichero 
		case 1: 
		{
		    FILE* arch_persona = fopen("BaseDatos.LFB", "rb");
		
		    t_persona persona_aux;
		
		    cout << endl;
		    cout << "  LISTADO DE PERSONAS EN LA BASE DE DATOS:" << endl;
		    cout << "  ================================================================================" << endl;
		    cout << endl;
		
		    fread ( &persona_aux, sizeof(t_persona), 1, arch_persona );
		    while ( !feof( arch_persona ) ){    
		        cout << "  ID: " << persona_aux.identificador << endl;
		        cout << "  CEDULA: " << persona_aux.cedula << endl;
		        cout << "  NOMBRE: " << persona_aux.nombre << endl;
		        cout << "  DIA NACIMIENTO: " << persona_aux.Dia_nacimiento << endl;
		        cout << "  MES NACIMIENTO: " << persona_aux.Mes_nacimiento << endl;
		        cout << "  ANIO NACIMIENTO: " << persona_aux.Ano_nacimiento << endl;
		        cout << "  GANANCIA ANUAL: " << persona_aux.Ganancia_anual << endl;
		        cout << endl;
		
		        fread ( &persona_aux, sizeof(t_persona), 1, arch_persona );
		    }
		
		    cout << endl;
		    cout << "Se completo la lectura del archivo..." << endl;
		    fclose(arch_persona);	
					
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
		
			break;
			
			
		}
	
		
	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////Escritura de archivos binarios//////////////////////////////////////////////////////////////////////////////////////////7		    
	
		 
		 case 2:
		 	{
			 
		 	system("cls");			
			FILE* arch_persona = fopen("BaseDatos.LFB", "ab");
			
			    string consulta = "si";
			    t_persona persona_aux;
			
			    while ( consulta != "no" ){
			        persona_aux = cargar_persona();
			        fwrite( &persona_aux, sizeof(t_persona), 1, arch_persona );
			        system ("cls");
			        cout << "Desea cargar mas datos ( si/no ): ";
			        cin>>consulta;
			    }
			
			    cout << endl;
			    system ("cls");
			    cout << "La carga del archivo fue exitosa..." << endl;
			    fclose(arch_persona);
		   }
		break;	   
		
		case 3:
		    {
		    	
			    FILE* arch_persona = fopen("BaseDatos.LFB", "rb");
			
			    t_persona persona_aux;
				char  cedula_aux[20];
				bool encontrar= false;
				cout<<"ingesa porfavor la cedula a buscar: ";
				cin>>cedula_aux;
			    cout << endl;
			    system("cls");
			    cout << "  BUSCAS LA PERSONA POR CEDULA:"<<cedula_aux << endl;
			    cout << "  ================================================================================" << endl;
			    cout << endl;
			
			    fread ( &persona_aux, sizeof(t_persona), 1, arch_persona );
			    
			    while ( !feof( arch_persona ) ){ 
			    if((strcmp(persona_aux.cedula,cedula_aux))==0)
						{	encontrar=true;			
					        cout << "  ID: " << persona_aux.identificador << endl;
					        cout << "  CEDULA: " << persona_aux.cedula << endl;
					        cout << "  NOMBRE: " << persona_aux.nombre << endl;
					        cout << "  DIA NACIMIENTO: " << persona_aux.Dia_nacimiento << endl;
					        cout << "  MES NACIMIENTO: " << persona_aux.Mes_nacimiento << endl;
					        cout << "  ANIO NACIMIENTO: " << persona_aux.Ano_nacimiento << endl;
					        cout << "  GANANCIA ANUAL: " << persona_aux.Ganancia_anual << endl;
					        cout << endl;
					        break;
						}else{
							fread ( &persona_aux, sizeof(t_persona), 1, arch_persona );
						}
			        
			    }
			   if(encontrar==false){			   
			    cout << endl;
			    cout << "NO SE ENCONTRO LA PERSONA..." << endl;
			    fclose(arch_persona);
			}else{
				cout << endl;
			    cout << "He encontrado..." << endl;
			    fclose(arch_persona);
				
				
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
		   	
		    	
		    	
		    	break;
			 } 
		
		case 4:
		    {
		    	
			    FILE* arch_persona = fopen("BaseDatos.LFB", "rb");
			
			    t_persona persona_aux;
				char  nombre_aux[50];
				bool encontrar= false;
				cout<<"ingesa porfavor el nombre a buscar: "<<flush;
				cin.get(); 
				cin.getline(nombre_aux, sizeof(nombre_aux), '.');	
			    system("cls");
			    cout << "  BUSCAS LA PERSONA POR CEDULA:"<<nombre_aux << endl;
			    cout << "  ================================================================================" << endl;
			    cout << endl;
			
			    fread ( &persona_aux, sizeof(t_persona), 1, arch_persona );
			    
			    while ( !feof( arch_persona ) ){ 
			    if((strcmp(persona_aux.nombre,nombre_aux))==0)
						{	encontrar=true;			
					        cout << "  ID: " << persona_aux.identificador << endl;
					        cout << "  CEDULA: " << persona_aux.cedula << endl;
					        cout << "  NOMBRE: " << persona_aux.nombre << endl;
					        cout << "  DIA NACIMIENTO: " << persona_aux.Dia_nacimiento << endl;
					        cout << "  MES NACIMIENTO: " << persona_aux.Mes_nacimiento << endl;
					        cout << "  ANIO NACIMIENTO: " << persona_aux.Ano_nacimiento << endl;
					        cout << "  GANANCIA ANUAL: " << persona_aux.Ganancia_anual << endl;
					        cout << endl;
					        break;
						}else{
							fread ( &persona_aux, sizeof(t_persona), 1, arch_persona );
						}
			        
			    }
			    
			   if(encontrar==false){			   
			    cout << endl;
			    cout << "NO SE ENCONTRO LA PERSONA..." << endl;
			    fclose(arch_persona);
			}else{
				cout << endl;
			    cout << "He encontrado..." << endl;
			    fclose(arch_persona);
				
				
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
		    	
		    	
		    	
		    	break;
			 } 			 
			 
		case 5:
		    {
		    	
		    	
		    	
		    	break;
			 } 
			 
			 
		case 6:
		    {
			
				FILE* arch_persona = fopen("BaseDatos.LFB", "r+b");
			
			    t_persona persona_aux;
				char  cedula_aux[20];
				int pos_cedula=0;
				bool encontrar= false;
				cout<<"ingresa porfavor la cedula a buscar  *nota: si reemplazas sera irecuperable el registro: ";
				cin>>cedula_aux;
			    cout << endl;
			    system("cls");
			    cout << "  INGRESA LA CEDULA DE LA PERSONA A REEMPLAZAR:"<<cedula_aux << endl;
			    cout << "  ================================================================================" << endl;
			    cout << endl;
			
			    fread ( &persona_aux, sizeof(t_persona), 1, arch_persona );
			    
			    while ( !feof( arch_persona ) ){ 
			    if((strcmp(persona_aux.cedula,cedula_aux))==0)
						{	encontrar=true;
					        break;
						}else{
							pos_cedula++;
							fread ( &persona_aux, sizeof(t_persona), 1, arch_persona );
						}
			        
			    }
			   if(encontrar==false){			   
			    cout << endl;
			    cout << "NO SE ENCONTRO LA PERSONA..." << endl;
			    fclose(arch_persona);
						}else{
								cout << endl;
							    cout << "He encontrado...la persona a reemplazar" << endl;							    			
						        cout << "  ID: " << persona_aux.identificador << endl;
						        cout << "  CEDULA: " << persona_aux.cedula << endl;
						        cout << "  NOMBRE: " << persona_aux.nombre << endl;
						        cout << "  DIA NACIMIENTO: " << persona_aux.Dia_nacimiento << endl;
						        cout << "  MES NACIMIENTO: " << persona_aux.Mes_nacimiento << endl;
						        cout << "  ANIO NACIMIENTO: " << persona_aux.Ano_nacimiento << endl;
						        cout << "  GANANCIA ANUAL: " << persona_aux.Ganancia_anual << endl;
						        cout << endl;
							    t_persona persona_reemplazo;
							    
								persona_reemplazo = cargar_persona();								
							    							
						        cout << endl;						  
							    fseek ( arch_persona, pos_cedula * sizeof(t_persona), SEEK_SET );
							    
								fwrite (&persona_reemplazo, sizeof(t_persona), 1, arch_persona);							
							    cout << "modificacion de registro exitosa..." << endl;
							    
							    fclose(arch_persona);
				
				
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
		    	
		    	
		    	
		    	
		    	break;
			 } 			 			 
			 
		case 7:
		    {
						    	  
				    FILE* arch_persona = fopen( "BaseDatos.LFB", "r+b");
				    int pos=0;
				    cout << endl;
				
				    // nos posicionamos en un registro en particular
				
				    // ejemplo 1: nos movemos tantos registros ( en este caso, pos )
					cout<<"\n\n ingresa porfavor la posicion al registro que quieras ir...\n\n";
				    cin>>pos;				
				    fseek ( arch_persona, pos * sizeof(t_persona), SEEK_SET );
				    
				
				    t_persona persona1;
				    
				    system("cls");
				    fread ( &persona1, sizeof( t_persona ), 1, arch_persona );
				
				    cout << "  Saltamos al registro: "<<pos<< endl;
				    cout << "  ======================" << endl;
				    cout << endl;
			        cout << "  ID: " << persona1.identificador << endl;
			        cout << "  CEDULA: " << persona1.cedula << endl;
			        cout << "  NOMBRE: " << persona1.nombre << endl;
			        cout << "  DIA NACIMIENTO: " << persona1.Dia_nacimiento << endl;
			        cout << "  MES NACIMIENTO: " << persona1.Mes_nacimiento << endl;
			        cout << "  ANIO NACIMIENTO: " << persona1.Ano_nacimiento << endl;
			        cout << "  GANANCIA ANUAL: " << persona1.Ganancia_anual << endl;
			        cout << endl;
				    cout << endl;
					    	
				    fclose(arch_persona);	
							
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
		    		    	
		    	
		    	break;
			 } 
			 
		case 8:
		    {
		    	
		    char data[50];
			int ip=0;
				cout<<"ingresa el nombre del archivo binario el cual se va a cargar:   ";
				cin>>data;				
		  		FILE* arch_persona = fopen( "BaseDatos.LFB", "r+b");							
				DataBaseBP= fopen(data,"r+b");			
				fseek ( arch_persona, 0, SEEK_END ); 			
				int tam_total = ftell( arch_persona );	
				int tamano=tam_total/sizeof(t_persona);				
				fclose(arch_persona);
						
				FILE* arch_personax =fopen( "BaseDatos.LFB", "r+b");
						
				if (DataBaseBP == NULL)
					{
						cout << "EL ARCHIVO ORIGEN DE LA BASE DE DATOS NO EXISTE ...... INSERTAR ARCHIVO  ";
						return 1;
					}
					
				
			    t_persona persona_carga;
			    
				
				fread ( &persona_carga, sizeof(t_persona), 1, DataBaseBP ); 
				 while ( !feof( DataBaseBP) )
				 	{	ip++;	
						cout << endl;
				        cout << "  ID: " << persona_carga.identificador << endl;
				        cout << "  CEDULA: " << persona_carga.cedula << endl;
				        cout << "  NOMBRE: " << persona_carga.nombre << endl;
				        cout << "  DIA NACIMIENTO: " << persona_carga.Dia_nacimiento << endl;
				        cout << "  MES NACIMIENTO: " << persona_carga.Mes_nacimiento << endl;
				        cout << "  ANIO NACIMIENTO: " << persona_carga.Ano_nacimiento << endl;
				        cout << "  GANANCIA ANUAL: " << persona_carga.Ganancia_anual <<"aqui ta"<<tamano <<endl;
				        cout << endl;				        
						//fseek ( arch_persona, sizeof(t_persona), SEEK_END ); 						 		    
			    		fseek(arch_personax,tamano*sizeof(t_persona),1,SEEK_SET );
			    		fwrite(&persona_carga,sizeof(t_persona),arch_personax);
						tamano++;						
					 	fread ( &persona_carga, sizeof(t_persona), 1, DataBaseBP ); 	
					}
					
				cout<<"\n\n\n " <<ip<<"  Registros Exportados con exito \n\n\n";		
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
				fclose(arch_personax);
				fclose(DataBaseBP);	
		    	
		    	
		    	
		    	break;
			 } 			 			 

	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//programa de registros variables
	break;
}
case 2:
	
	
	cout<<"hola mundo";
	
		
	
	
	
	
	
	
break;
 //programa de registros en modo txt  
 case 3: 	
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
//************************************************************************************************************************************************************//
//************************************************************************************************************************************************************//
// ***********************************************************************************************************************************************************//
//************************************************************************************************************************************************************//
//*******************************************************MANEJO DE ARCHIVOS TEXTO*****************************************************************************//
//************************************************************************************************************************************************************//
//************************************************************************************************************************************************************//
//************************************************************************************************************************************************************//
//************************************************************************************************************************************************************//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	  
  system("cls");  																	//limpia totalmente la pantalla para mejor visualizacion	
  int abrir;      																	//variable que me recorre cada uno de los caracteres del fichero para case 1
  int recorre;   																    //variable que me recorre cada uno de los caracteres del fichero para case 2
  long int identificador3;															//variable que contiene el ID		
  char cedula3[20];																	//variable que me contiene la cedula
  char nombre3[50];																	//variable que me contiene el nombre	
  char Dia_nacimiento3[2];															//variable que me contiene el dia de nacimiento	
  char Mes_nacimiento3[2]; 															//variable que me contiene el mes de nacimiento
  unsigned short int  Ano_nacimiento3;												//variable que me contiene el anio de nacimiento
  unsigned long int Ganancia_anual3; 												//variable que me contiene la ganancia anual				
  int paso=1;																		//variable que me controla cuando debo poner la descripcion de la variable case 1					
  int paso2=0; 																//variable que me controla cuando cerrar el programa
  char guardar;																		//variable que me permite escojer si deseo guardar la persona o no
  bool sal;																			//variable que me controla cuando debo poner la descripcion de la variable case 1						
  bool encontro=false;																//booleano que me da a saber si encontro cedula o nombre igual a la busqueda	
  int volver=0;																		//variable que me permite guardar despues de recorrer el fichero
  bool salto=false;																	//variable que me controla cuando debo salir case 1	
  int next=1;																		//variable para identidad de datos y ademas saber cual es su nobre
  bool nexti=false;																	//variable que me permite dar identidad a los datos
  char nombreG[50];                       											//variable que me guarda el nombre cuando consukto por cedula
  char cedulaG[50];																//varibale que me guarda el identificador cuando consulto por cedula	
  int i=1;																			//variable que me recorre los char
  int N=0;																			//esta es la variable de nombre						
  int nm=1;																			//variable que me recorre los char				
  char nombrado[50];	  															//variable temporal de nombre
  int borrar=0;
  int uno=0;
  bool salto2=false;
  char Buscar[50];
  
	  switch (modificar()) {
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	  	//Lectura del fichero 
		case 1: 
		        
  				DataBase3 = fopen("Base_Datos.txt","r");       						// Me abre el fichero solo para lectura
  				
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
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		
		case 2: 
//adicionar personas al fichero por consola		
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		
        
		DataBase3 = fopen("Base_Datos.txt","a+"); // me abre el fichero para lectura y escritura
		system ("cls"); //limpia la pantalla
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
				fprintf(DataBase3,"\n\n%i|",identificador3);
				fprintf(DataBase3,"%s|",cedula3);
				fprintf(DataBase3,"%s|",nombre3);
				fprintf(DataBase3,"%s|",Dia_nacimiento3);
				fprintf(DataBase3,"%s|",Mes_nacimiento3);	
				fprintf(DataBase3,"%i|",Ano_nacimiento3);
				fprintf(DataBase3,"%i\n",Ganancia_anual3);				
			
			}else{
				cout<<"\n datos no guardados...\n";
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
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////			
		break;  
  		case 3: 
//Busqueda por cedula///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  		
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  		
		DataBase3 = fopen("Base_Datos.txt","r");
  		cout<<"Ingresa La Cedula, para buscar el registro:  ";
  		cin>>Buscar;
  		cout<<"\n\n\n\n\n\n";
  		char cedulaGo[50];  ///ojo con esta variable
//////////////////////Ciclo que me busca por cedula///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
					while((recorre = getc(DataBase3)) != EOF)					
						{  
						if(recorre =='\n' )
							{	
							  i=1;							
									
							}else{	
								cedulaGo[i]=recorre;
								i++;					
										
								}
							if(Buscar[volver]==recorre)
							{  
								volver++;
								if(volver==(strlen(Buscar)))
								{	
								    encontro=true;				
									//system ("cls");				
									cout<<"\n\n\nEncontre La Persona\n\n\n";
									cout<<"\n\n__________________________________________________________________________________________________\n\n";
									cout<<"Encontre A a la persona que buscas por la cedula:  "<<Buscar<<"\n\n\n";
								}
							}else if(encontro!=true){
									volver=1;
								} else if(recorre == '|' ){									
									cout<<"\n";		
									if(next==1&& nexti==false)
										{
										   i=1;
										    N=1;
											while(1){
												if(cedulaGo[i]=='|'){												
														break;												       
												}else {
													i++;
												      }												
											       }
											cout<<"ID:  ";	
											while(1){
												if(i==N){													
													cout<<"\n";
													cout<<"cedula: "<<Buscar;
													break;
												}else{
													cout<<cedulaGo[N];
													N++;
												}   
												
											}
											N=1;								
									    	cout<<"\nNombre:  ";	
										 	next ++;
										 	nexti=true;
										 	
									    }	
										if(next==2 && nexti==false)
											{
										    	cout<<"Dia de nacimiento:  ";	
											 	next ++;
											 	nexti=true;
										    }	
											if(next==3&& nexti==false)
												{
											    	cout<<"Mes de nacimiento:  ";	
												 	next ++;
												 	nexti=true;
											    }							
	               								if(next==4 && nexti==false)
													{
												    	cout<<"anio de nacimiento:  ";	
													 	nexti=true;
													 	next++;	
												    }
													if(next==5 && nexti==false)
													{
												    	cout<<"Ganacia anual:  ";	
													 	nexti=true;
													 	next++;	
												    }																				
																							    		             
											}else if(recorre=='\n'){
												salto=true;
												break;
											}else if (salto!=true){ 																						
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
  		
  		
  		
  		
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  		
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  		
  		
  		break;
		case 4: 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		
		DataBase3 = fopen("Base_Datos.txt","a+");
		char nombreGos[50];
  		cout<<"Ingresa El Nombre, para buscar el registro:  ";
  		cin.getline(Buscar, sizeof(Buscar), '.');
  		cout<<"\n\n\n\n\n\n";
  		
					while((recorre = getc(DataBase3)) != EOF)					
						{  
						if(recorre =='\n' )
							{	
							  i=1;									
									
							}else{	
								nombreGos[i]=recorre;
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
												if(nombreGos[i]=='|'){												
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
													cout<<nombreGos[N];
													N++;
												} 
												
											}
											N=1;
											cout<<"\nCedula:  ";
											while(1){
												if(nombreGos[i+N]=='|'){
													break;
												}else{
													cout<<nombreGos[i+N];
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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7		
  		case 5: 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  		
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  		
//////////////////////////////////////////////////Eliminar registro por cedula/////////////////////////////////////////////////////////////////////////////////  		
	    DataBase3 = fopen("Base_Datos.txt","r+");
	    char cedulaComp[50];
		system("cls");
		cout<<"\n\n RECUERDA QUE SI ELIMINAS UN REGISTRO NO LO PODRAS RECUPERAR...\n";
		cout<<"ingresa la cedula:  ";
  		cin>>Buscar;
  		cout<<"\n\n\n\n\n\n";
//////////////////////Ciclo que me busca por cedula///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
					while((recorre = getc(DataBase3)) != EOF)					
						{  
						if(recorre =='\n' )
							{	
							  i=1;							
									
							}else{	
								cedulaComp[i]=recorre;
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
									cout<<"Se ha eliminado la persona con registro de cedula:  "<<Buscar<<"\n\n\n";
								}
							}else if(encontro!=true){
									volver=1;
								} else if(recorre == '|' and salto2==false){
									if(next==1&& nexti==false)
										{   i=1;
										    N=1;
											while(1){
												if(cedulaComp[i]=='|'){								
														break;												       
												}else {
													i++;
												      }												
											       }	
											while(1){												
												if(i==N){													
													cout<<"REGISTRO ELIMINADO EXITOSAMENTE....";
													borrar=	i+strlen(Buscar);																							
													break;
												}else{
													N++;
												}   
												
											}
											N=1;
											salto2=true;	
										 	next ++;
										 	nexti=true;
										 	
									    }															
																							    		             
											}else if(recorre=='\n'){
												salto=true;
												break;
											}
											else if (salto!=true){
											
											while(uno<=strlen(cedulaComp)){
											    if(uno==0)
												{			
									            fseek(DataBase3,-(borrar+2), SEEK_CUR);
												}
									            fputc(' ', DataBase3);
									            fflush(DataBase3);
									            uno++;
									            nexti=false;
									            next=1;
												}
											}
				  		               
  		                }
  		                

		if(encontro!=true){
			cout<<"\n\n\n NO SE ENCONTRO EL REGISTRO DE LA CEDULA.....\n\n\n\n";
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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7		
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
		case 6: 
	    DataBase3 = fopen("Base_Datos.txt","r+");
	    char cedulaRe[50];
	    char cedulaBe[50];
		system("cls");
		cout<<"\n\n RECUERDA QUE SI REEMPLAZAS UN REGISTRO NO LO PODRAS RECUPERAR...\n";
		cout<<"ingresa la cedula:  ";
  		cin>>Buscar;
  		cout<<"\n\n\n\n\n\n";
  		char cedulas[50];
  		char cedulab[50];
///////////////////////////////////////////////////////Ciclo que me busca por cedula///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

				while((recorre = getc(DataBase3)) != EOF)					
						{  
						if(recorre =='\n' )
							{	
							  i=1;							
									
							}else{	
								cedulas[i]=recorre;
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
									cout<<"Encontre A a la persona que buscas por la cedula para actulizar el registro:  "<<Buscar<<"\n\n\n";
								}
							}else if(encontro!=true){
									volver=1;
								} else if(recorre == '|' ){									
									cout<<"\n";		
									if(next==1&& nexti==false)
										{
										   i=1;
										    N=1;
											while(1){
												if(cedulas[i]=='|'){												
														break;												       
												}else {
													i++;
												      }												
											       }
											cout<<"ID:  ";	
											while(1){
												if(i==N){													
													cout<<"\n";
													cout<<"cedula: "<<Buscar;
													break;
												}else{
													cout<<cedulas[N];
													N++;
												}   
												
											}
											N=1;								
									    	cout<<"\nNombre:  ";	
										 	next ++;
										 	nexti=true;
										 	
									    }	
										if(next==2 && nexti==false)
											{
										    	cout<<"Dia de nacimiento:  ";	
											 	next ++;
											 	nexti=true;
										    }	
											if(next==3&& nexti==false)
												{
											    	cout<<"Mes de nacimiento:  ";	
												 	next ++;
												 	nexti=true;
											    }							
	               								if(next==4 && nexti==false)
													{
												    	cout<<"anio de nacimiento:  ";	
													 	nexti=true;
													 	next++;	
												    }
													if(next==5 && nexti==false)
													{
												    	cout<<"Ganacia anual:  ";	
													 	nexti=true;
													 	next++;	
												    }																				
																							    		             
											}else if(recorre=='\n'){
												salto=true;
												break;
											}else if (salto!=true){ 																						
													printf("%c",recorre);	
													nexti=false;
						                         }  		
				  		               
  		                }             
  		                
  		
  	
	if(encontro!=true){
		 cout<<"\n\n\n NO SE ENCONTRO LA PERSONA..\n\n\n";
		 
		 }				
		fclose(DataBase3);
///////////////////////////////////////////////PETICION DE DATOS//////////////////////////////////////////////////////////////////////////////////////////////////					
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if(encontro==true){
	
		DataBase3 = fopen("Base_Datos.txt","r+");
		cout<<"\n\n\n..............ingresa los nuevos Datos del registro..............";
		cout <<"\n\n\nidentificador:  ";
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
		i=1;
		volver=1;
		encontro=false;					
		next=1;
		nexti=false;
		salto=false;
		salto2=false;
					while((recorre = getc(DataBase3)) != EOF)					
						{ 
						if(recorre =='\n' )
							{	
							  i=1;							
									
							}else{	
								cedulaBe[i]=recorre;
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
									cout<<"Se ha reemplazado la persona con registro de cedula:  "<<Buscar<<"\n\n\n";
								}
							}else if(encontro!=true){
									volver=1;
								} else if(recorre == '|' and salto2==false){
									if(next==1&& nexti==false)
										{   i=1;
										    N=1;
											while(1){
												if(cedulaBe[i]=='|'){								
														break;												       
												}else {
													i++;
												      }												
											       }	
											while(1){												
												if(i==N){													
													cout<<"REGISTRO ACTUALIZADO  EXITOSAMENTE....";
													borrar=	i+strlen(Buscar);																							
													break;
												}else{
													N++;
												}   
												
											}
											N=1;
											salto2=true;	
										 	next ++;
										 	nexti=true;
										 	
									    }															
																							    		             
											}else if(recorre=='\n'){
												salto=true;
												break;
											}
											else if (salto!=true){											
											while(uno<=7){
											    if(uno==0)
												{			
									            fseek(DataBase3,-(borrar+2), SEEK_CUR);
												}
												if(uno==0){
									            fprintf(DataBase3,"%i|",identificador3);
												fprintf(DataBase3,"%s|",cedula3);
												fprintf(DataBase3,"%s|",nombre3);
												fprintf(DataBase3,"%s|",Dia_nacimiento3);
												fprintf(DataBase3,"%s|",Mes_nacimiento3);	
												fprintf(DataBase3,"%i|",Ano_nacimiento3);
												fprintf(DataBase3,"%i        ",Ganancia_anual3);	
									            fflush(DataBase3);
												}		

									            uno++;
									            
									            nexti=false;
									            next=1;
												}
											}
				  		               
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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		
		case 7: 
  		DataBase3 = fopen("Base_Datos.txt","a+");
  		
  		cout<<"Ingresa Numero de registro para ir al registro:  ";
  		cin>>Buscar;
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
									cout<<"\n\n\nEncontre El Registro\n\n\n";
									cout<<"__________________________________________________________________________________________________";
									cout<<" \n"<<"ID:"<<Buscar;
								}
							}else if(encontro!=true){
									volver=1;
								} else if(recorre == '|' ){
									cout<<"\n";		
									if(next==1&& nexti==false)
										{
									    	cout<<"Cedula:  ";	
										 	next ++;
										 	nexti=true;
										 	
									    }	
										if(next==2 && nexti==false)
											{
										    	cout<<"Nombre:  ";	
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

//Termina funcion princiapal


// FUNCION PARA CARGAR UN STRUCT

t_persona cargar_persona(){
  t_persona persona;
  string nombre;																	//variable que me contiene el nombre	
  string cedula;
    
	cout<<" \n\n                   Adicion de personas...        \n\n";
	cout <<"identificador:  ";
	cin>>persona.identificador;	
	cin.ignore();		
    cout << "cedula: ";    
    cin>>persona.cedula;
    cin.ignore();
    cout << "Nombre: ";
    getline(cin,nombre);
    strcpy( persona.nombre, nombre.c_str()); // función strcpy( destino, origen ) y método c_str() de la clase string
    cout << endl;	
	cout <<"Dia_nacimiento:  ";
	cin>>persona.Dia_nacimiento;		
	cout <<"Mes_nacimiento:  ";
	cin>>persona.Mes_nacimiento;
	cout <<"Ano_nacimiento:  ";
	cin>>persona.Ano_nacimiento;
	cout <<"Ganancia_anual:  ";
	cin>>persona.Ganancia_anual;


    return persona;
}

// DESARROLLO DEL TEMPLATE para lectura
template <typename T> T read(FILE* f){
   T S_AUX;
   fread(&S_AUX,sizeof(T),1,f);
   return S_AUX;
}

// DESARROLLO DEL TEMPLATE para escritura

template <typename T> void write(FILE* f, T v){
   fwrite(&v,sizeof(T),1,f);
   return;
}
