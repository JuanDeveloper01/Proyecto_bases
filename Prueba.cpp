#include <stdio.h>
#include <string.h>
 
#define MAX 50
 
int main() {
    
    char line[MAX];
    char *p;
    FILE *fp=fopen("code.txt","rt");
    int i=0;
    char aux[MAX];
    
    fgets(line,MAX,fp);
    while(!feof(fp)) {
                   i++;
                   if(p=strstr(line,"juan carlos patino hernandez")) { /* tomo como subpalabra "addres" 
                   si se encuentra, sscanf guarda en aux la palabra que contiene a la subpalabra "addres"*/
                     sscanf(p,"%s",aux);
                     }
                     if(!strcmp(aux,"juan carlos patino hernandez")) /* comparo las palabras, y en caso de ser iguales sale del while */
                         break;
                   fgets(line,MAX,fp);
    }
    
    printf("\nline: %d\n",i);
    
    return 0;
}
