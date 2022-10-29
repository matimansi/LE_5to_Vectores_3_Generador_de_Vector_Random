
/*
    Desarrollar un programa que pida un valor máximo y uno mínimo por
	pantalla para poder inicializar un vector de 10 elementos con valores
	random en ese rango. Imprimir el vector. 

    a. *buscar el internet el uso de la función rand()

	https://www.chuidiang.org/clinux/funciones/rand.php#:~:text=En%20C%2C%20para%20obtener%20n%C3%BAmeros,como%20de%202%20mil%20millones

	>>> TERMINADO <<<
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIM 10

void Vector_Random (int min, int max, int vector[], char rango);

int main()
{
	int min, max, vector[LIM] = {0};
	char rango;
	printf("\nBienvenido a nuestro programa...\n");
	printf("Ingrese el valor MINIMO\n>>> ");
	scanf("%d", &min);
	printf("Ingrese el valor MAXIMO\n>>> ");
	scanf("%d", &max);
	printf("Desea que el valor MINIMO y el valor MAXIMO puedan generarse en el VECTOR? [S/N]\n>>> ");
	fflush(stdin);
	scanf("%c", &rango);
	Vector_Random (min, max, vector, rango);
    return 0;
}

void Vector_Random (int min, int max, int vector[], char rango)
{
	srand(time(NULL));
	printf("Vector Random Generado entre %d y %d -> ", min, max);
	printf("{");
	if ((rango == 's') || (rango == 'S'))
	{
		for (int i = 0; i < LIM; i++)
		{
			vector[i] = rand()%(max - min + 1) + min;
			if (i == (LIM - 1))
			{
				printf("%d}\n\n", vector[i]);
				break;
			}
			printf("%d, ", vector[i]);
		}
	}
	else if ((rango == 'n') || (rango == 'N'))
	{
		for (int i = 0; i < LIM; i++)
		{
			do
			{
				vector[i] = rand()%(max - min + 1) + min;
			}
			while ((vector[i] == min) || (vector[i] == max));
			if (i == (LIM - 1))
			{
				printf("%d}\n\n", vector[i]);
				break;
			}
			printf("%d, ", vector[i]);
		}
	}
}
