#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <unistd.h>
#include <conio.h>

typedef struct
{
    char* dni;
    char* nombre,*telefono,*mail,*direccion;
    int edad;
}Contacto;

void nuevoContacto(Contacto *agenda,int *p)
{

        //printf("Contacto %d: \n", (*p)+1);

        (agenda+(*p))->nombre = malloc(sizeof(char)*20);
        printf("Ingrese nombre: ");
        fflush(stdin);
        scanf("%[^\n]", (agenda+(*p))->nombre);


        (agenda+(*p))->dni = malloc(sizeof(char)*10);
        printf("Ingrese el dni: ");
        scanf("%s", (agenda+(*p))->dni);

        (agenda+(*p))->telefono = malloc(sizeof(char)*16);
        printf("Ingrese el telefono: ");
        scanf("%s", (agenda+(*p))->telefono);

        (agenda+(*p))->mail = malloc(sizeof(char)*30);
        printf("Ingrese el mail: ");
        scanf("%s", (agenda+(*p))->mail);

        (agenda+(*p))->direccion= malloc(sizeof(char)*25);
        printf("Ingrese la direccion: ");
        fflush(stdin);
        scanf("%[^\n]", (agenda+(*p))->direccion);

        (agenda+(*p))->edad= malloc(sizeof(int)*2);
        printf("Ingrese la edad: ");
        scanf("%d",& (agenda+(*p))-> edad);

        (*p)++;
        system("cls");
      
        printf("\n\tLA OPERACION HA SIDO EJECUTADA EXITOSAMENTE.\n");
        sleep(1.5);
        system("cls");


}
void imprimirContactos(Contacto *agenda, int *p)
{
    int c=0;
    int d=0;

  while(c<(*p))
    {
        if(((agenda+c)->nombre)!=NULL)
        {
        //minuscula(agenda,p);
        printf("\nPersona %d: \n",c+1);
        printf("El nombre es: %s \n", (agenda+c)->nombre);
        printf("El DNI es: %s \n", (agenda+c)->dni);
        printf("El telefono es: %s \n", (agenda+c)->telefono);
        printf("El mail es: %s \n", (agenda+c)->mail);
        printf("La direccion es: %s \n", (agenda+c)->direccion);
        printf("La edad es: %d \n", (agenda+c)->edad);

        }
c++;
    }
}

void nombre(char *cadena)
{
int c;

    fflush(stdin);
    scanf("%[^\n]",cadena);
    for(c=0;c<strlen(cadena);c++)
    {
        cadena[c]=tolower(cadena[c]);
    }
}


void buscarContactosNombre(Contacto *agenda, int *p)
{
    int c=0,k=0;
    char *cadena;

minuscula(agenda,p);
    cadena=malloc(sizeof(char )*20);
    printf("Ingrese el nombre \n");
    nombre(cadena);
  while(c<(*p))
    {
    if(strcmp(cadena,((agenda+c)->nombre))==0)
    {
        printf("\nPersona %d: \n",c+1 );
        printf("El nombre es: %s \n", (agenda+c)->nombre);
        printf("El DNI es: %s \n", (agenda+c)->dni);
        printf("El telefono es: %s \n", (agenda+c)->telefono);
        printf("El mail es: %s \n", (agenda+c)->mail);
        printf("La direccion es: %s \n", (agenda+c)->direccion);
        printf("La edad es: %d \n", (agenda+c)->edad);
    }
    else
    {
        k++;
    }

c++;
    }
    if(k==(*p))
    {
        printf("\nNo se encontro el contacto\n");
    }
    free(cadena);
}


void buscarContactosLetra(Contacto *agenda, int *p)
{
    int c=0,k=0;
    char *cadena;

    minuscula(agenda,p);
    cadena=malloc(sizeof(char)*20);
    printf("Ingrese el nombre \n");
    nombre(cadena);

    while(c<(*p))
    {
        if(strncmp(cadena,((agenda+c)->nombre),1)==0)
        {
        printf("\nPersona %d: \n",c+1 );
        printf("El nombre es: %s \n", (agenda+c)->nombre);
        printf("El DNI es: %s \n", (agenda+c)->dni);
        printf("El telefono es: %s \n", (agenda+c)->telefono);
        printf("El mail es: %s \n", (agenda+c)->mail);
        printf("La direccion es: %s \n", (agenda+c)->direccion);
        printf("La edad es: %d \n", (agenda+c)->edad);
        }
        else
        {
            k++;
        }

        c++;
    }
    if(k==(*p))
    {
        printf("\nNo se encontro el contacto\n");
    }

free(cadena);
}


void telefono(char *tel)
{
    printf("Ingrese telefono: \n");
    scanf("%s",tel);

}


void buscarContactosTelefono(Contacto *agenda, int *p)
{
    int c=0,k=0;
    char *tel;

minuscula(agenda,p);
    tel=malloc(sizeof(char)*20);
    telefono(tel);

  while(c<(*p))
    {
    if(strcmp(tel,(agenda+c)->telefono)==0)
    {
        printf("\nPersona %d: \n",c+1 );
        printf("El nombre es: %s \n", (agenda+c)->nombre);
        printf("El DNI es: %s \n", (agenda+c)->dni);
        printf("El telefono es: %s \n", (agenda+c)->telefono);
        printf("El mail es: %s \n", (agenda+c)->mail);
        printf("La direccion es: %s \n", (agenda+c)->direccion);
        printf("La edad es: %d \n", (agenda+c)->edad);
    }
   
    else
    {
        k++;
    }

c++;
    }
    if(k==(*p))
    {
        printf("\nNo se encontro el contacto\n");
    }
    free(tel);

}

void minuscula(Contacto *agenda, int *p)
{
    int c;
    int d;
    for(d=0;d<(*p);d++)
    {
    for(c=0;c<strlen((agenda+d)->nombre);c++)
    {
( (agenda+d)->direccion)[c]=tolower (( (agenda+d)->direccion)[c]);
       ( (agenda+d)->nombre)[c]=tolower (( (agenda+d)->nombre)[c]);
       ( (agenda+d)->mail)[c]=tolower (( (agenda+d)->mail)[c]);
    }
    }
}

void eliminarContactoNombre(Contacto *agenda, int *p)
{
    int c=0,d,k;
    char *cadena;
    cadena=malloc(sizeof(char)*20);
    printf("Ingrese el nombre \n");
    nombre(cadena);

 while(c<(*p))
 {
        if(strcmp(cadena,((agenda+c)->nombre))==0)
        {

            (agenda+c)->nombre=NULL;
            (agenda+c)->dni=NULL;
            (agenda+c)->telefono=NULL;
            (agenda+c)->direccion=NULL;
            (agenda+c)->mail=NULL;
            (agenda+c)->edad=NULL;



            d=c+1;
            k=c;
           
            while(d<=(*p))
            {

                (*(agenda+k))=(*(agenda+d));

                d++;k++;
            }

            (*p)=(*p)-1;
        }
        c++;
}

 free(cadena);

}


void eliminarTodosContactos(Contacto *agenda, int *p)
{
 int c=0;
char *cadena;
printf("ESTA SEGURO QUE DESEA ELIMINAR?\n");
printf("Escriba (si) o (no)\n ");
cadena=malloc(sizeof(char)*20);
nombre(cadena);
 if(strcmp(cadena,"si")==0)
     {
     
    system("cls");
 while(c<(*p))
 {
     free((agenda+c)->nombre);
     free((agenda+c)->dni);
     free((agenda+c)->telefono);
     free((agenda+c)->direccion);
     free((agenda+c)->mail);
     free((agenda+c)->edad);

     c++;
     }
     printf("\n\n\tSe han eliminado todos los contactos correctamente");


 (*p)=0;
 free(cadena);
 sleep(3);
 system("cls");

 main();
     }
     else
     {
        main();
        free(cadena);
     }
}



int main()
{
    int cont=0;
    int* p;
    p=&cont;

Contacto *agenda;
    agenda = malloc(sizeof(Contacto)*30);
    int seleccion = 0;

for(;;)
{
    printf("\n\t\t\tMENU DE LA AGENDA");
    printf("\n\n\t(1)\tIngresar contacto");
    printf("\n\t(2)\tMostrar contacto");
    printf("\n\t(3)\tBuscar contacto por nombre");
    printf("\n\t(4)\tBuscar contacto por letra ");
    printf("\n\t(5)\tBuscar contacto por telefono");
    printf("\n\t(6)\tEliminar contacto por nombre");
    printf("\n\t(7)\tEliminar TODOS los contactos");
    printf("\n\t(8)\tSalir de la agenda");
    printf("\n\nSelect an option from the menu? ");
    scanf("%d", &seleccion);

    switch(seleccion)
    {
        case 1:
            nuevoContacto(agenda,p);

            break;
             case 2:
            imprimirContactos(agenda,p);
            printf("\nPresione una tecla para volver al menu...  ");
            getch();
            system("cls");
            break;
             case 3:
                 buscarContactosNombre(agenda,p);
                 printf("\nPresione una tecla para volver al menu...  ");
                getch();
                system("cls");
                break;
             case 4:
                   buscarContactosLetra(agenda,p);
                   printf("\nPresione una tecla para volver al menu...  ");
                getch();
                system("cls");
                break;
             case 5:
                buscarContactosTelefono(agenda,p);
                printf("\nPresione una tecla para volver al menu...  ");
                getch();
                system("cls");
                break;
             case 6:
                eliminarContactoNombre(agenda,p);
                break;
             case 7:
                 eliminarTodosContactos(agenda,p);
                break;

        case 8:
            fprintf(stdout, "\nUsted ha elegido salir de la agenda.\n");
            getchar( );
            break;
        default:
            fprintf(stdout, "\n\tOpcion invalida, reintente: %d \a\n", seleccion);
            break;
    }


    if (seleccion == 8) break;
}

    return 0;
}
