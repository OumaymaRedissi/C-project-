#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include"bib.h"


/*----------------------------MENU-------------------------------------------------------------------------------*/
int main()
{
    system("COLOR 75");
    CABINET cab;
    cab.nbP=0;
    cab.pat =(PATIENT*)malloc(sizeof(PATIENT));
    if (!cab.pat) exit(-1);

    menuPrincipal(cab);

    exit(1);
}
