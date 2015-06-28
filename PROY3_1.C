#include <stdio.h>
#include <conio.h>
#include <time.h>

/////////////////////DATOS////////////////////
char nombre[10];
char cedula[12];
char seguro[9];
int pla, dep, sec, empl, catg;
float bruto, s_social, isr, seduc, fcps, sueldo;
int nche = 0;
//////////FUNCION PARA LEER DATOS Y CALCULAR EL SALARIO NETO///////////
void datos();


void main()
{   char s = 's';
    ////////////////FECHA//////////////////
    time_t t;
    struct tm *tm;
    char datehour[100];
    t=time(NULL);
    tm=localtime(&t);
    strftime(datehour, 100, "%d/%m/%y",tm);

    do
    {
    clrscr();
    gotoxy(2,7);printf("%s",datehour);
    ////////////////ENCABEZADO///////////////
    gotoxy(30,3);printf("FERRETERÖA CLARK S.A.");
    gotoxy(37,4);printf("PLANILLA");
    gotoxy(2,6);printf("FECHA DE PAGO");
    gotoxy(65,6);printf("Nø CHEQUE");
    gotoxy(2,9);printf("NOMBRE");
    gotoxy(15,9);printf("CEDULA");
    gotoxy(25,9);printf("S. SOCIAL");
    gotoxy(37,9);printf("PLA.");
    gotoxy(45,9);printf("DEP.");
    gotoxy(53,9);printf("SEC.");
    gotoxy(60,9);printf("EMPL.");
    gotoxy(70,9);printf("CATG.");
    gotoxy(25,15);printf("*************REGULAR*************");
    gotoxy(2,17);printf("S. BRUTO");
    gotoxy(15,17);printf("S. SOCIAL");
    gotoxy(30,17);printf("ISR");
    gotoxy(40,17);printf("S. EDUC.");
    gotoxy(55,17);printf("FCPS.");
    gotoxy(65,17);printf("S. NETO");
    datos();
    printf("\n\n¨DESEA CONTINUAR? s/n: ");
    fflush(stdin);
    scanf("%c",&s);
    fflush(stdin);
    }while(s == 's' || s == 'S' );
}

void datos()
{

    nche++;
    gotoxy(69,7);
    printf("%d",nche);
    gotoxy(2,10);
    fflush(stdin);
    gets(nombre);
    fflush(stdin);
    gotoxy(15,10);
    fflush(stdin);
    gets(cedula);
    fflush(stdin);
    gotoxy(25,10);
    fflush(stdin);
    gets(seguro);
    fflush(stdin);
    gotoxy(37,10);
    scanf("%d",&pla);
    gotoxy(45,10);
    scanf("%d",&dep);
    gotoxy(53,10);
    scanf("%d",&sec);
    gotoxy(60,10);
    scanf("%d",&empl);
    gotoxy(70,10);
    scanf("%d",&catg);
    gotoxy(2,18);
    scanf("%f",&bruto);
    gotoxy(15,18);
    scanf("%f",&s_social);
    gotoxy(30,18);
    scanf("%f",&isr);
    gotoxy(40,18);
    scanf("%f",&seduc);
    gotoxy(55,18);
    scanf("%f",&fcps);
    sueldo = (bruto)-(s_social+isr+seduc+fcps);
    gotoxy(65,18);
    printf("%.2f",sueldo);

}