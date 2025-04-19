#include "unistd.h"
#include "stdarg.h"


static int	ft_format(va_list args, const char c)
{
	int	print;

	print = 0;
	if (c == 'c')
		print += ft_pchar(va_arg(args, int));
	else if (c == 's')
		print += ft_pstr(va_arg(args, char *));
	else if (c == 'p')
		print += ft_pptr(va_arg(args, unsigned long), c);
	else if (c == 'd' || c == 'i')
		print += ft_pnbr(va_arg(args, int));
	else if (c == 'u')
		print += ft_punsigned(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		print += ft_phex(va_arg(args, unsigned int), c);
	else
		print += ft_pchar(c);
	return (print);
}

int	my_scanf(const char *format, ...)
{
    // int number;
    // printf("Enter a number: ");
    // scanf("%d", &number);
    // printf("You entered: %d\n", number);
	int		i;
	va_list	args;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1])
				count += ft_format(args, format[++i]);
		}
		else
			count += ft_pchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}