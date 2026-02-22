#include <stdio.h>
#include <stdlib.h>
#include <string.h>


float suma(float a, float b) {
    return a + b;
}
float resta(float a, float b) {
    return a - b;
}
float multiplicacion(float a, float b) {
    return a * b;
}
float division(float a, float b) {
    if (b == 0) {
        printf("Error: No se puede dividir entre cero.\n");
        exit(1);
    }
    return a / b;
}


int es_numero(const char *str, float *resultado) {
    char *fin;
    *resultado = strtof(str, &fin);
    
    return fin != str && *fin == '\0';
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Ha ingresado valores inadecuados para el programa.\n");
        printf("USO: ./<ejecutable> <num1> <operador> <num2>\n");
        return 1;
    }

    float num1, num2;

    if (!es_numero(argv[1], &num1)) {
        printf("Error: '%s' no es un número válido.\n", argv[1]);
        printf("USO: ./<ejecutable> <num1> <operador> <num2>\n");
        return 1;
    }

    if (!es_numero(argv[3], &num2)) {
        printf("Error: '%s' no es un número válido.\n", argv[3]);
        printf("USO: ./<ejecutable> <num1> <operador> <num2>\n");
        return 1;
    }

    char *operador = argv[2];
    float (*operacion)(float, float) = NULL;

    if (strcmp(operador, "+") == 0) {
        operacion = suma;
    }
    else if (strcmp(operador, "-") == 0) {
        operacion = resta;
    }
    else if (strcmp(operador, "*") == 0 || strcmp(operador, "x") == 0) {
        operacion = multiplicacion;
    }
    else if (strcmp(operador, "/") == 0) {
        operacion = division;
    }
    else {
        printf("Error: '%s' no es un operador válido.\n", operador);
        printf("USO: ./<ejecutable> <num1> <operador> <num2>\n");
        return 1;
    }

    float resultado = operacion(num1, num2);
    printf("El resultado de la operación es: %.2f\n", resultado);
    return 0;
}