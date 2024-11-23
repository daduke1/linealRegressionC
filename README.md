# linealRegressionC

# Proyecto de Regresión Lineal

Para el proyecto libre de la asignatura de **Programación Estructurada**, decidimos crear un programa que realiza una **regresión lineal**. Este modelo estadístico relaciona una o varias variables independientes con una dependiente. Elegimos este proyecto ya que es relevante en el contexto de **ciencia de datos**.

## Tipos de Regresión Lineal

Existen dos tipos principales de regresión lineal:

- **Regresión Lineal Simple**: Se considera una sola variable independiente.
- **Regresión Lineal Múltiple**: Se consideran varias variables independientes.

En este proyecto implementamos la **regresión lineal simple**, cuyo modelo tiene la siguiente forma:

\[
y = \beta_0 + \beta_1 x
\]

Donde:
- \( y \): Valor predicho.
- \( \beta_0 \): Intercepto.
- \( \beta_1 \): Pendiente o peso de la variable independiente.
- \( x \): Variable independiente.

## Cálculo de los Parámetros

El cálculo de los coeficientes \(\beta_0\) y \(\beta_1\) se realiza con las siguientes fórmulas:

\[
\beta_1 = \frac{\sum_{i=1}^n (x_i - \bar{x})(y_i - \bar{y})}{\sum_{i=1}^n (x_i - \bar{x})^2}
\]

\[
\beta_0 = \bar{y} - \beta_1 \bar{x}
\]

Donde:
- \( x_i \): Valores de la variable independiente.
- \( y_i \): Valores de la variable dependiente.
- \( \bar{x} \): Promedio de \( x \).
- \( \bar{y} \): Promedio de \( y \).

## Evaluación del Modelo

Para evaluar el modelo, utilizamos la métrica del **error cuadrático medio (MSE)**, definida como:

\[
MSE = \frac{1}{n} \sum_{i=1}^n (Y_i - \tilde{Y}_i)^2
\]

Donde:
- \( Y_i \): Valor real.
- \( \tilde{Y}_i \): Valor predicho por el modelo.

Este proyecto nos permitió aplicar conceptos matemáticos y programáticos para resolver un problema práctico relacionado con ciencia de datos.
