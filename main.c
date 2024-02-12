/**************************************
* GITHUB: #santistockcode#
* EJERCICIO: #practica-tema-6-uned#
**************************************/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/*
Imprime carácteres requeridos con 
posibilidad de calado en simetría, esto es,
off es 2 para una serie de modulo 4, lo que 
consigue el efecto de simetría en el rombo,
que de @.o. pasa a .o.@.
*/
int	print_line_chars(int iter, int off)
{
	if ((iter + off) % 4 == 0)
		write(1, "@", 1);
	else if ((iter + off) % 4 == 1)
		write(1, ".", 1);
	else if ((iter + off) % 4 == 2)
		write (1, "o", 1);
	else if ((iter + off) % 4 == 3)
		write (1, ".", 1);
	return (iter);
}
/*
Función que imprime un triángulo, dividido a su
vez en dos triángulos, cuya impresión de 
caracteres depende de la fila en ccuestión
*/
int	print_triangle(int half_size, int row)
{
	int position;
	int iter_char;

	position = 1;
	iter_char = 0;
	while (position < (half_size * 2))
	{
		// lado izquierdo
		if (position <= half_size)
		{
			if (position < (half_size - row))
			write (1, " ", 1);
			else
			{
				iter_char = print_line_chars(iter_char, 0);
				iter_char++;
			}
		}
		// lado derecho
		if (position > half_size)
		{
			if (position <= half_size + row) 
			{
				iter_char = print_line_chars(iter_char, 2);
				iter_char--;
			}
			else
				write (1, " ", 1);
		}
		position++;
	}
	write (1, "\n", 1);
	return (row);
}

/*
Imprime la mitad superior del rombo y luego 
la mitad inferior. row -= 2 por que no es 
simétrico, la fila más larga solo debe 
aparecer una vez.
*/
void	print_turbot(int size_turbot)
{
	int row;

	row = 0;
	while (row < size_turbot)
	{
		row = print_triangle(size_turbot, row);
		row++;
	}
	row -= 2;
	while (row >= 0)
	{
		row = print_triangle(size_turbot, row);
		row--;
	}
}

int main()
{
	int size;
	
	while(1)
	{
		printf("¿Lado del Rombo?");
		scanf("%d", &size);
		if (size < 1 || size > 10)
		{
			printf("Lado no válido");
		}
		else
		{
			print_turbot(size);
			break;
		}
	}

	return (0);
}
