#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
        RENZO ORPELLI

        REPOSITORIO GIT =  https://github.com/renzoorpelli/OrpelliRenzo.P1.RecuProgI.1G


*/
typedef struct
{
    int id;
    char nombrePais[20];
    int infectados;
    int recuperados;
    int muertos;
}ePais;

/*1. Dada una estructura ePais cuyos campos son id(int), nombre(20 caracteres), infectados(int), recuperados(int) y muertos(int).
Desarrollar una función llamada actualizarRecuperados que reciba el país y los recuperados del dia y que acumule estos a los que ya tiene el país. La función no devuelve nada. * */
int actualizarRecuperados(ePais* pais, int recuperadosDia);
/*2. Crear una función que se llame invertirCadena que reciba una cadena de caracteres como parámetro y su responsabilidad es invertir los caracteres de la misma.
Ejemplo si le pasamos UTN-FRA la deja como ARF-NTU **/
int invertirCadena(char cadena[]);
/*3. Crear una función que se llame ordenarCaracteres que reciba una cadena de caracteres como parámetro y su responsabilidad es ordenarlos caracteres de manera ascendente dentro de la cadena.
Ejemplo si le pasamos "algoritmo" la deja como "agilmoort" **/
int ordenarCaracteres(char caracteres[]);


int main()
{
    printf("**********EJERCICIO 1**************\n");

    ePais pais;
    pais.id = 1000;
    pais.infectados= 20000;
    pais.muertos = 2500;
    strcpy(pais.nombrePais,"Alemania");
    pais.recuperados =500;
    int recuperadosArgentina = 250;

    printf("\n");
    printf("SIN CARGAR RECUPERADOS\n");
    printf("\n");
    printf("IDPAIS  NOMBRE PAIS   INFECTADOS    RECUPERADOS    MUERTOS\n");
    printf("%d     %-10s     %2d           %2d            %4d\n", pais.id, pais.nombrePais, pais.infectados, pais.recuperados, pais.muertos);

    printf("--------------------------------------------------------------\n");
    actualizarRecuperados(&pais, recuperadosArgentina);
    printf("\n");
    printf("RECUPERADOS DEL DIA\n");
    printf("\n");

    printf("IDPAIS  NOMBRE PAIS   INFECTADOS    RECUPERADOS    MUERTOS\n");


    printf("%d     %-10s     %2d           %2d            %4d\n\n", pais.id, pais.nombrePais, pais.infectados, pais.recuperados, pais.muertos);



    printf("**********EJERCICIO 2**************\n\n");
    char cadena[20] = "UTN-FRA";
    int retornoCadena;
    printf("LA CADENA ORIGINAL ES %s\n", cadena);
    retornoCadena=invertirCadena(cadena);
    if( retornoCadena ==1)
    {
        printf("ORDEN DE LA CADENA INVERTIDO CON EXITO\n");
        printf("LA CADENA CAMBIADA ES %s\n\n", cadena);
    }

    printf("**********EJERCICIO 3**************\n\n");
    char cadenaCaracteres[20] = "algoritmo";
    int retornoCaracteres;
    printf("LA CADENA ORIGINAL ES %s\n", cadenaCaracteres);
    retornoCaracteres = ordenarCaracteres(cadenaCaracteres);
    if (retornoCaracteres ==1)
    {
         printf("ORDEN DE LA CADENA ORDENADO CON EXITO\n");
        printf("LA CADENA ORIGINAL ES %s\n", cadenaCaracteres);
    }


    return 0;
}

int invertirCadena(char cadena[])

{
    int todoOk=0;
    int longitud = strlen(cadena);
    int i = 0;
    int j = longitud - 1;
    char auxCadena[longitud];

    strcpy(auxCadena, cadena);
    if(cadena != NULL)
    {
        while(cadena [i] != '\0')
        {
            cadena[i] = auxCadena[j];
            i++;
            j--;
        }
        todoOk = 1;
    }

    return todoOk;
}

int ordenarCaracteres(char caracteres[])
{
    int largoCadena = strlen(caracteres);
    char auxCadena;
    int todoOk =0;

    if (caracteres != NULL)
    {
    for (int i = 0; i < largoCadena - 1; i++)
    {
        for (int j = i + 1; j < largoCadena; j++)
        {
            if (caracteres[i] > caracteres[j])
            {
                auxCadena = caracteres[j];
                caracteres[j] = caracteres[i];
                caracteres[i] = auxCadena;
            }

        }

    }
        todoOk =1;
    }

    return todoOk;
}

int actualizarRecuperados(ePais* pais, int recuperadosDia)
{
    int todoOk= 0;
    if(pais != NULL && recuperadosDia >= 0)
    {
        pais->recuperados += recuperadosDia;
        todoOk = 1;
    }

    return todoOk;
}
