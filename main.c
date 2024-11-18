/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:44:13 by dlippelt          #+#    #+#             */
/*   Updated: 2024/11/14 13:10:18 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "test.h"

static void	test_with_file(void)
{
	int		fd;
	char	*line;
	char	*filename;

	filename = "files/variable_nls.txt";

	printf("\n================= Get All Lines ==================\n");
	printf("Name of test file: %s, BUFFER_SIZE = %d\n", filename, BUFFER_SIZE);

	fd = open(filename, O_RDONLY);

	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	printf("======================= END ======================\n");
}

int	main(void)
{
	setbuf(stdout, NULL);

	test_with_file();

	return (0);
}
