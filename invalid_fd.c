/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:11:16 by dlippelt          #+#    #+#             */
/*   Updated: 2024/11/14 13:13:03 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "test.h"

static void	test_with_invalid_fd(void)
{
	int		fd;
	char	*line;
	char	*filename;

	filename = "files/variable_nls.txt";

	printf("\n================= Invalid FD ==================\n");
	printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);

	fd = -1;

	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	printf("===================== END =====================\n");
}

int	main(void)
{
	setbuf(stdout, NULL);

	test_with_invalid_fd();

	return (0);
}
