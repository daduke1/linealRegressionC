# linealRegressionC

Para el proyecto libre de la asignatura de programación estructurada, decidimos crear un programa que hace una regresión lineal. La regresión lineal es un modelo estadístico que relaciona una o varias variables independientes con una dependiente. Elegimos este proyecto ya que es relevante en el contexto de ciencia de datos.
Hay dos tipos de regresión lineal, la simple y la múltiple. La diferencia entre ellas es el número de variables predictoras a considerar, en la simple se cuenta con una sola variable independiente, mientras que en la múltiple se toman en cuenta n cantidad de variables independientes.
Decidimos implementar la regresión lineal simple, que tiene la siguiente forma:

y= β_0+β_1 x
En donde y es el valor predicho, β_0 es el intercepto, β_1 es el peso de nuestra variable independiente o la pendiente, y x es nuestra variable independiente. 
El cálculo de la pendiente y el intercepto se hace usando las siguientes fórmulas:
β_1=(∑_(i=1)^n▒〖(x_i-x ̅)(y_i-y ̅)〗)/(∑_(i=1)^n▒〖(x_i-x ̅)〗^2 )
β_0=y ̅-β_1 x ̅

Donde x es nuestra variable independiente y x ̅ es el promedio de ella. Igualmente, con la y.

Para evaluar el modelo creado, decidimos implementar la métrica del error cuadrático medio, que tiene la siguiente forma:
1/n ∑_(i=1)^n▒〖(Y_i-Y ̃_i)〗^2

En donde Y_i es el valor real y Y ̃_i es el valor predicho por nuestro modelo.
