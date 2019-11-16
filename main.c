#include "get_next_line.c"
#include "get_next_line.h"
#include "get_next_line_utils.c"
#include "stdio.h"
int		main(int ac, char **av)
{
	int		fd, i, r;
	char	*line;
	
	fd = open (av[1], O_RDONLY);
	i = 0;
	while ((r = get_next_line(fd, &line)) == 1)
	{
		printf ("%d, L[%i], || %s || \n", r, i, line);
		i++;
	}
	printf("\n%d",r);
	return 0;
}
