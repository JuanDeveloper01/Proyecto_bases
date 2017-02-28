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

FILE *DataBase0; //puntero que me apunta al fichero que quiero abrir
FILE *DataBase3; //puntero que me apunta al fichero que quiero abrir
FILE *DataBase2; //puntero que me apunta al fichero que quiero abrir

//Funcion que solo me muestra las opciones del menu y me deja elegir una opcion.
int menu(){  
   int program = 0;	
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

void eliminaRe(char cambio)
{
    FILE *arch;
    char car; 
    int uno=0;
    arch=fopen("Base_Datos2.txt","r+");
    if (!arch){
            perror("El archivo no se pudo abrir\n");
            return;
    }

    while (fscanf(arch,"%c",&car)!=EOF)
    {
        if (car==cambio&&uno==0)
        { while(uno<=7){
		    if(uno==0){			
            fseek(arch,-7, SEEK_CUR);
            
			}
            fputc('*', arch);
            fflush(arch);
            uno++;
            
			}
        }
    }
    fclose(arch);
}





//FUNCION PRINCIPAL DEL PROGRAMA	
 int main () {
 bool salir= true; //variable que me saca del programa
 
 //ciclo principal del programa que me permite repetir el menu
 while(salir!=false){  	

//Casos donde uso el menu principal y segun se elija la opcion lleva a funciiones diferentes
 switch (menu()) {
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//programa de registros de longitud	fija 	
case 1:


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//programa de registros variables
break;
case 2:
	

  

break;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	  
 //programa de registros en modo txt  
 case 3: 	
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
  int paso2=0;																		//variable que me controla cuando debo poner la descripcion de la variable case 2
  char continuar;   																//variable que me controla cuando cerrar el programa
  char guardar;																		//variable que me permite escojer si deseo guardar la persona o no
  bool sal;																			//variable que me controla cuando debo poner la descripcion de la variable case 1						
  bool encontro=false;																//booleano que me da a saber si encontro cedula o nombre igual a la busqueda	
  int volver=0;																		//variable que me permite guardar despues de recorrer el fichero
  bool salto=false;																	//variable que me controla cuando debo salir case 1	
  int next=1;																		//variable para identidad de datos y ademas saber cual es su nobre
  bool nexti=false;																	//variable que me permite dar identidad a los datos
  char nombreG[50];                       											//variable que me guarda el nombre cuando consukto por cedula
  char  cedulaG[50];																//varibale que me guarda el identificador cuando consulto por cedula	
  int i=1;																			//variable que me recorre los char
  int N=0;																			//esta es la variable de nombre						
  int nm=1;																			//variable que me recorre los char				
  char nombrado[50];	  															//variable temporal de nombre
  int borrar=0;
  int uno=0;
  bool salto2=false;
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
        eliminaRe('s');
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
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////			
		break;  
  		case 3: 
//Busqueda por cedula///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  		
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  		
  		
		//eliminaRe('s');
		char Buscar[50];
		DataBase3 = fopen("Base_Datos.txt","a+");
  		cout<<"Ingresa La Cedula, para buscar el registro:  ";
  		cin>>Buscar;
  		cout<<"\n\n\n\n\n\n";
//////////////////////Ciclo que me busca por cedula///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
									system ("cls");				
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
												if(cedulaG[i]=='|'){												
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
													cout<<cedulaG[N];
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
  		
  		
  		
  		
  		
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  		
  		
  		break;
		case 4: 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		
		DataBase3 = fopen("Base_Datos.txt","a+");
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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7		
  		case 5: 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  		
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  		
//////////////////////////////////////////////////Eliminar registro por cedula/////////////////////////////////////////////////////////////////////////////////  		
	    DataBase3 = fopen("Base_Datos.txt","r+");
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
								cedulaG[i]=recorre;
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
												if(cedulaG[i]=='|'){								
														break;												       
												}else {
													i++;
												      }												
											       }	
											while(1){												
												if(i==N){
													borrar=	i+strlen(Buscar);																							
													break;
												}else{
													cout<<"REGISTRO ELIMINADO EXITOSAMENTE....";
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
											
											while(uno<=strlen(cedulaG)){
											    if(uno==0)
												{			
									            fseek(DataBase3,-(borrar+2), SEEK_CUR);
												}
									            fputc(' ', DataBase3);
									            fflush(DataBase3);
									            uno++;
									            nexti=false;
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
		cout<<"6";
		break;
		case 7: 
		cout<<"7";
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
