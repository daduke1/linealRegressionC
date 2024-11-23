#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX 100

// Funcion para calcular la pendiente (m)
double calcularPendiente(double x[], double y[], int n) {
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }
    double denominador = n * sumX2 - sumX * sumX;
    if (denominador == 0) {
        printf("Error: Division entre cero en el calculo de la pendiente.\n");
        return NAN;
    }
    return (n * sumXY - sumX * sumY) / denominador;
}

// Funcion para calcular el intercepto (b)
double calcularIntercepto(double x[], double y[], int n, double m) {
    double sumX = 0, sumY = 0;
    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
    }
    return (sumY - m * sumX) / n;
}

// Funcion para predecir Y en base a X
double predecir(double m, double b, double x) {
    return m * x + b;
}

// Funcion para evaluar el modelo usando el (MSE)
double evaluarModelo(double x[], double y[], int n, double m, double b) {
    double error = 0;
    for (int i = 0; i < n; i++) {
        double y_pred = predecir(m, b, x[i]);
        error += pow(y_pred - y[i], 2);
    }
    return error / n;
}

int main() {
    double x[MAX], y[MAX];
    int n = 0;
    FILE *archivo;
    char buffer[256];
    char nombreArchivo[100];

    printf("\nIngresa el nombre del archivo con su extension: ");
    scanf("%s", nombreArchivo);

    // Abrir el archivo
    archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo :( %s.\n", nombreArchivo);
        printf("\nSaliendo del programa..\n");
        return 1;
    }
    printf("\nLeyendo datos del archivo :) %s..\n", nombreArchivo);

    // Leer datos del archivo
    while (fgets(buffer, sizeof(buffer), archivo)) {
        if (sscanf(buffer, "%lf %lf", &x[n], &y[n]) == 2) {
            n++;
        } else {
            //Si encuentra una linea que no tenga lo que se pide devuelve el mensaje siguiente:
            printf("Advertencia: Linea no valida ignorada.\n");
        }
    }
    fclose(archivo);
    //Si el archivo no cuenta con la infro correcta, da un mensaje.
    if (n == 0) {
        printf("\nError: No se encontraron datos validos en el archivo.\n");
        return 1;
    }

    // Calcular el modelo
    double m = calcularPendiente(x, y, n);
    if (isnan(m)) {
        printf("Error en el calculo del modelo.\n");
        return 1;
    }
    double b = calcularIntercepto(x, y, n, m);
    printf("\nEl modelo calculado es: Y = %.2fX + %.2f\n", m, b);

    // Evaluar el modelo
    double mse = evaluarModelo(x, y, n, m, b);
    printf("\nEl error cuadratico medio (MSE) del modelo es: %.4f\n", mse);

    // Menú interactivo.
    int opcion;
    do {
        printf("\nMenu:\n");
        printf("1. Predecir Y para un valor de X\n");
        printf("2. Guardar el modelo en un archivo .txt\n");
        printf("3. Salir del programa\n");
        printf("Selecciona una opcion porfavor: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                double x_pred;
                printf("\nIngresa un valor para X: ");
                scanf("%lf", &x_pred);
                double y_pred = predecir(m, b, x_pred);
                printf("Prediccion: Y = %.2f\n", y_pred);
                break;
            }
            case 2: {
                FILE *salida;
                salida = fopen("regresion.txt", "w");
                if (salida == NULL) {
                    printf("No se pudo guardar el modelo (llora).\n");
                } else {
                    fprintf(salida, "Modelo: Y = %.2fX + %.2f\n", m, b);
                    fprintf(salida, "Error cuadratico medio (MSE): %.4f\n", mse);
                    fclose(salida);
                    printf("\nModelo guardado en regresion.txt.\n");
                }
                break;
            }
            case 3:
                printf("Saliendo..\n");
                break;
            default:
                printf("Opcion no valida.\n");
        }
    } while (opcion != 3);

    return 0;
}

