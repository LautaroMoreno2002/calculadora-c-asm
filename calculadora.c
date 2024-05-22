#include <stdio.h>
#include <stdlib.h> // atoi()
#include <string.h> // strtok()

#define MAX_LENGTH 100 // Define la longitud máxima de la cadena

extern int recibir_Operacion(int Operando1, char Operador, int Operando2);

int CalcularOperacion(int Operando1, char Operador, int Operando2)
{
    return recibir_Operacion(Operando1, Operador, Operando2);
}

void leerPregunta()
{
    char cadena[MAX_LENGTH];

    char *punteroOperador; // Puntero para el operador
    char *punteroOperando1; // Puntero para el primer operando
    char *punteroOperando2; // Puntero para el segundo operando

    int operando1Int;
    int operando2Int;
    char operadorChar;

    printf("\nPor favor, ingrese una consulta aritmética: \n");
    printf("El formato de la operación debe ser el siguiente: \"10 + 10\", \"20 * 2\", \"30 / 3\", \"40 - 20\", es decir, un espacio entre operando y operador. \n");
    // Lee una línea de texto desde la entrada estándar y la almacena en 'cadena'
    fgets(cadena, sizeof(cadena), stdin);

    // Elimina el carácter de nueva línea '\n' del final de la cadena, si está presente
    cadena[strcspn(cadena, "\n")] = '\0';

    /*printf("La cadena que ingresaste es: %s\n", cadena)*/;

    // Utilizamos strtok para dividir la expresión en operandos y operador
    punteroOperando1 = strtok(cadena, " "); // El espacio es el delimitador
    punteroOperador = strtok(NULL, " "); // NULL indica que continuamos desde donde terminamos
    punteroOperando2 = strtok(NULL, " ");

    operando1Int = atoi(punteroOperando1); // Transformo el puntero en un entero
    operando2Int = atoi(punteroOperando2); // Transformo el puntero en un entero
    operadorChar = (char)*punteroOperador;

    // Verificamos si los punteros son nulos (por si la expresión no es válida)
    if (punteroOperador != NULL && punteroOperando1 != NULL && punteroOperando2 != NULL) {
        /*printf("Operador: %s\n", punteroOperador);
        printf("Operando 1: %s\n", punteroOperando1);
        printf("Operando 2: %s\n", punteroOperando2);

        printf("Operando 2 Int: %d\n", operando2Int);
        printf("Operando 1 Int: %d\n", operando1Int);
        printf("Operador: %c\n", operadorChar);*/

        int resultado = CalcularOperacion(operando1Int, operadorChar, operando2Int);
        printf("El resultado de la operación solicitada es: %d\n", resultado);
    } else {
        printf("Lo siento, mis respuestas son limitadas.\n");
    }
}

int main(void) 
{
    leerPregunta();
}