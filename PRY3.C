#include <stdio.h>
#include <conio.h>
#include <time.h>

void main()
{
    int nche=0;
    ////////////////FECHA//////////////////
    time_t t;
    struct tm *tm;
    char datehour[100];
    clrscr();
    t=time(NULL);
    tm=localtime(&t);
    strftime(datehour, 100, "%d/%m/%y",tm);
    gotoxy(2,7);printf("%s",datehour);
    ////////////////ENCABEZADO///////////////
    gotoxy(30,3);printf("FERRETERÖA CLARK S.A.");
    gotoxy(37,4);printf("PLANILLA");
    gotoxy(2,6);printf("FECHA DE PAGO");
    gotoxy(65,6);printf("Nø CHEQUE");
    gotoxy(2,9);printf("NOMBRE");
    gotoxy(15,9);printf("CEDULA");
    gotoxy(25,9);printf("S. SOCIAL");
    gotoxy(40,9);printf("PLA.");
    gotoxy(50,9);printf("DEP.");
    gotoxy(60,9);printf("SEC.");
    gotoxy(70,9);printf("EMPL.");
    gotoxy(25,15);printf("*************REGULAR*************");
    gotoxy(2,17);printf("S. BRUTO");
    gotoxy(15,17);printf("S. SOCIAL");
    gotoxy(25,17);printf("ISR");
    gotoxy(40,17);printf("S. EDUC.");
    gotoxy(50,17);printf("FCPS.");
    gotoxy(60,17);printf("S. NETO");
    getch();
}