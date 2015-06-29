#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*Integrantes:
Angel Espinosa 8-905-1352
Mar¡a T. Rodr¡guez 8-900-1207
Eduardo Perez [CED]
*/
void nntol(char npal[],float num );

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
    gotoxy(25,15);printf("**************************");
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
    char npal[500]="";
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
    switch(catg)
    {
	case 1: gotoxy(25,15); printf("***********REGULAR***************");break;
	case 2: gotoxy(25,15); printf("***********AGREGADO**************");
    }
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
    nntol(npal,sueldo);
    gotoxy(10,22);printf("*************************%s******************",npal);
    gotoxy(10,23);printf("*************************************************************");

}
void nntol(char npal[],float num )
{
    char mun[5];
    char armun[5];
    char spos[5];
    char dtext[30];
    //char npal[500]="";
    char uni[30][30]={"\0","UNO","DOS","TRES","CUATRO",
		   "CINCO","SEIS","SIETE","OCHO","NUEVE","DIEZ","ONCE","DOCE",
		   "TRECE","CATORCE","QUINCE","DICISIES","DIECISIETE","DIECIOCHO",
		   "DIECINUEVE","VEINTE","VIENTIUNO","VEINTIDOS","VEINTITRES","VEINTICUATRO",
		   "VEITICINCO","VEINTISEIS","VEINTISIETE","VEINTIOCHO","VEINTINUEVE"};
    char decc[10][30]={"\0","\0","\0","TREINTA","CUARENTA","CINCUENTA","SESENTA","SETENTA","OCHENTA",
			"NOVENTA"};
    char cent[30][30]={"CIEN","CIENTO","DOSCIENTOS","TRESCIENTOS","CUATROCIENTOS","QUINIENTOS",
			"SEISCIENTOS","SETECIENTOS","OCHOCIENTOS","NOVECIENTOS"};
    double nnmu,dnum,ddec;
    int i,k=0,j,pos,upos;
    //printf("%.0f",floor(num));
    sprintf(mun,"%.0f",floor(num));
    dnum=nnmu=atoi(mun);
    j=strlen(mun)-1;
    for(i=4;i>=0;i--)
    {
	if(j>=0)
	{
	    armun[i]=mun[j];
	    j--;
	}
	else
	    armun[i]='0';
    }
    if(armun[0]=='0' && armun[1]=='0' && armun[2]=='1' && armun[3]=='0' && armun[4]=='0')
	strcat(npal,cent[0]);
    else
    {
    for(i=0;i<5;i++)
    {
	switch(i)
	{
	     case 0:
		 if(armun[i]!='0' || armun[i+1]!='0')
		 {
		 for(j=0;j<2;j++)
		 {
		     spos[j]=armun[i+k];
		     k++;
		 }
		 pos=atoi(spos);
		 //printf("POS: %d",pos);
		 if (pos<29)
		 {
		     if(pos!=1)
			strcat(npal,uni[pos]);
		     strcat(npal,"MIL ");
		 }
		 else
		 {
		     pos=armun[i]-0x30;
		     upos=armun[i+1]-0x30;
		     if(upos != 0)
		     {
			strcat(npal,decc[pos]);
			strcat(npal," Y ");
		     }
		     else
		     {
			strcat(npal,decc[pos]);
		     }
		     strcat(npal,uni[upos]);
		     strcat(npal," MIL ");
		 }
		 }
		 break;
	     case 2:
		 if(armun[i] != '0')
		 {
		 pos=armun[i]-0x30;
		 //printf("%d",pos);
		 strcat(npal,cent[pos]);
		 strcat(npal," ");
		 //printf("%s",cent[pos]);
		 }
		 break;
	     case 3:
		 if(armun[i] != '0'|| armun[i+1]!=0)
		 {
		 for(j=0;j<2;j++)
		 {
		     spos[j]=armun[i+k];
		     k++;
		 }
		 pos=atoi(spos);
		 //printf("POS: %d",pos);
		 if (pos<29)
		 {
		     strcat(npal,uni[pos]);
		     strcat(npal," ");
		 }
		 else
		 {
		     pos=armun[i]-0x30;
		     upos=armun[i+1]-0x30;
		     if(upos!=0)
		     {
			strcat(npal,decc[pos]);
			strcat(npal," Y ");
		     }
		     else
			strcat(npal,decc[pos]);
		     strcat(npal,uni[upos]);
		     strcat(npal," ");
		 }
		 }
		 break;
	}
	k=0;
    }
    }
    ddec=num-dnum;
    if(ddec==0)
	sprintf(dtext,"CON 0%.0f/100",ddec*100);
    else
	sprintf(dtext,"CON %.0f/100",ddec*100);
    strcat(npal,dtext);
    //printf("%s",npal);
    //getch();

}
