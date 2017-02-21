//============================================================================
// Name        : grep.cpp
// Author      : Alex
// Version     :
// Description : Mini Grep
//============================================================================

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

char* remove_left_white_spaces(char*);
void grep(const char*, const char*);

int
main(int argc, char* argv[])
{
      if (argc < 3){
         cout << "Uso: grep </fstream></string></iostream></ficheros...></firchero1></palabra><palabra a="a" buscar="buscar"> <firchero1><ficheros...>]>" < < endl;
         return -1;
      } else {
         for (int i = 2; i < argc; i++)
            grep(argv[1], argv[i]);
      }
}

char*
remove_left_white_spaces(char cad[])
{
   char* temp = new char[500];

   int indice = 0;

   for (unsigned int i = 0; cad[i] ; i++)
       if (cad[i] != ' ' || cad[i+1] != ' ')
         temp[indice++] = cad[i];

   return temp;
}

void
grep(const char* palabra, const char* nombre)
{
   ifstream fichero(nombre);
   char cadena[500];
   int nlinea = 0;

   if (fichero){
      while(fichero){
         fichero.getline(cadena, 500);
         nlinea++;
         if (fichero)
            if (strstr(cadena, palabra))
               cout << nombre << "(" << nlinea << ") t" << remove_left_white_spaces(cadena) << endl;
      }
