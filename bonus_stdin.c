/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_stdin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:45:42 by dlippelt          #+#    #+#             */
/*   Updated: 2024/11/14 12:33:00 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "test.h"

static void	test_with_standard_input(void)
{
	int		fd;
	char	*line;

	printf("\n================= Standard Input (BONUS) =================\n");
	printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);

	fd = 0;
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	printf("=========================== END ==========================\n");
}

int	main(void)
{
	setbuf(stdout, NULL);

	test_with_standard_input();

	return (0);
}
