/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 18:40:34 by icastell          #+#    #+#             */
/*   Updated: 2021/10/18 16:45:59 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	verleaks(void)
{
	system("leaks a.out");
}

int main(void)
{
	int		numchar;
	char	*s;
	
	numchar = 0;
	s = "Hola, me llamo Idoya";

	//Impresión sin argumentos:

	printf("I: El número de caracteres impresos sin argumentos es: %d\n", ft_printf(""));
	printf("O: El número de caracteres impresos sin argumentos es: %d\n", printf(""));

	//Impresión de un string sin argumentos:

	numchar = ft_printf("String: 123456789\n");
	printf("I: El número de caracteres impresos cuando hay un string es: %d\n", numchar);
	printf("O: El número de caracteres impresos cuando hay un string es: %d\n", printf("String: 123456789\n"));

	//Impresión de un carácter:

	numchar = ft_printf("Carácter: %kwc %c\n", 'I', 'C');
	numchar = printf("Carácter: %kwc %0c\n", 'I', 'C');
	numchar = ft_printf("Carácter: %kwc %rc\n", 'I', 'C');
	numchar = printf("Carácter: %kwc %rc\n", 'I', 'C');
	numchar = ft_printf("Carácter: %c %c\n", 'I', 'C');
	printf("I: El número de caracteres impresos cuando hay un carácter es: %d\n", numchar);
	printf("O: El número de caracteres impresos cuando hay un carácter es: %d\n", printf("Carácter: %c %c\n", 'I', 'C'));

	//Impresión de un string como argumento:

	numchar = ft_printf("String: %s %s\n", s, "y tengo 47 años");
	printf("I: El número de caracteres impresos cuando hay un string es: %d\n", numchar);
	printf("O: El número de caracteres impresos cuando hay un string es: %d\n", printf("String: %s %s\n", s, "y tengo 47 años"));

	numchar = ft_printf("String: {%s}\n", "");
	printf("I: El número de caracteres impresos cuando hay un string es: %d\n", numchar);
	printf("O: El número de caracteres impresos cuando hay un string es: %d\n", printf("String: {%s}\n", ""));

	//Impresión de un número entero/decimal (base 10) con signo:
	
	numchar = ft_printf("Número decimal: %i\n", -134);
	printf("I: El número de caracteres impresos cuando hay un decimal es: %d\n", numchar);
	printf("O: El número de caracteres impresos cuando hay un decimal es: %d\n", printf("Número decimal: %d\n", -134));
	numchar = ft_printf("I: Número decimal: %d\n", 134);
	numchar = printf("O: Número decimal: %d\n", 134);
/*	numchar = ft_printf("I: Número decimal (espacio): {% d}\n", 134);
	numchar = printf("O: Número decimal (espacio): {% d}\n", 134);
	numchar = ft_printf("I: Número decimal (espacio y +): {% +d}\n", 134);
	numchar = printf("O: Número decimal (espacio y +): {% +d}\n", 134);
	numchar = ft_printf("I: Número decimal (+ y espacio): {%+ d}\n", 134);
	numchar = printf("O: Número decimal (+ y espacio): {%+ d}\n", 134);
	numchar = ft_printf("I: Número decimal (varios): {%+++ #  d}\n", 134);
	numchar = printf("O: Número decimal (varios): {%+++ #  d}\n", 134);*/
	//printf("El número de caracteres impresos cuando hay un decimal es: %d\n", numchar);
	//numchar = ft_printf("Número decimal (espacio): % d\n", 134);
	//printf("El número de caracteres impresos cuando hay un decimal (espacio) es: %d\n", numchar);
	//numchar = printf("Número decimal: %d\n", 134);
	//printf("El número de caracteres impresos cuando hay un decimal por la original es: %d\n", numchar);
	//numchar = printf("Número decimal (espacio): % d\n", 134);
	//printf("El número de caracteres impresos cuando hay un decimal (espacio) por la original es: %d\n", numchar);

	//Impresión de un número entero/decimal (base 10) sin signo:

	numchar = ft_printf("Número decimal sin signo: %u\n", 4294967295);
	printf("I: El número de caracteres impresos cuando hay un decimal es: %d\n", numchar);
	printf("O: El número de caracteres impresos cuando hay un decimal es: %d\n", printf("Número decimal sin signo: %lu\n", 4294967295));

	//Impresión de un número hexadecimal (base 16):

	numchar = ft_printf("Número hexadecimal: %x\n", 430);
	printf("I: El número de caracteres impresos cuando hay un hexadecimal es: %d\n", numchar);
	printf("O: El número de caracteres impresos cuando hay un hexadecimal es: %d\n", printf("Número hexadecimal: %x\n", 430));

	numchar = ft_printf("Número hexadecimal en mayúsculas: %X\n", 430);
	printf("I: El número de caracteres impresos cuando hay un hexadecimal es: %d\n", numchar);
	printf("O: El número de caracteres impresos cuando hay un hexadecimal es: %d\n", printf("Número hexadecimal en mayúsculas: %X\n", 430));

	numchar = ft_printf("I: Número hexadecimal: %x\n", 430);
	numchar = printf("O: Número hexadecimal: %x\n", 430);
	numchar = ft_printf("I: Número hexadecimal: %X\n", 430);
	numchar = printf("O: Número hexadecimal: %X\n", 430);
	//numchar = ft_printf("I: Número hexadecimal (#): {%#x}\n", 430);
	//numchar = printf("O: Número hexadecimal (#): {%#x}\n", 430);

/*	printf("hola\n");
	numchar = ft_printf("I: Número hexadecimal (#): {%jkl}}}}\n", 4323);
	printf("I: caracteres impresos: %i\n", numchar);
	numchar = printf("O: Número hexadecimal (#): {%jkl}}}}\n", 4323);
	printf("O: caracteres impresos: %i\n", numchar);
	numchar = ft_printf("I: Número hexadecimal (#): %#X\n", 0);
	numchar = printf("O: Número hexadecimal (#): %#X\n", 0);
*/
	//numchar = ft_printf("I: String (espacio): % s\n", s);
	//numchar = printf("O: String (espacio): % s\n", s);


	//Impresión de un puntero:

	numchar = ft_printf("Puntero: %p\n", ULONG_MAX);
	printf("I: El número de caracteres impresos para un puntero es: %d\n", numchar);
	printf("O: El número de caracteres impresos para un puntero es: %d\n", printf("Puntero: %p\n", ULONG_MAX));
	numchar = ft_printf("Puntero: %p\n", s);
	printf("I: El número de caracteres impresos para un puntero es: %d\n", numchar);
	printf("O: El número de caracteres impresos para un puntero es: %d\n", printf("Puntero: %p\n", s));
	
	atexit(verleaks);
	return 0;
}