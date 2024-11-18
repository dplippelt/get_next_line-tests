/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:46:54 by dlippelt          #+#    #+#             */
/*   Updated: 2024/11/14 12:45:54 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "test.h"

static void	ft_custom_print(char *line)
{
	if (line)
	{
		printf("%s", line);
		free(line);
	}
}

static void	test_with_file_multiple_fd(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*line1;
	char	*line2;
	char	*line3;
	char	*filename1;
	char	*filename2;
	char	*filename3;

	filename1 = "files/test1.txt";
	filename2 = "files/test2.txt";
	filename3 = "files/test3.txt";

	printf("\n================================ Get All Lines (BONUS) ================================\n");
	printf("Name of test files: %s, %s, %s, BUFFER_SIZE = %d\n", filename1, filename2, filename3, BUFFER_SIZE);

	fd1 = open(filename1, O_RDONLY);
	fd2 = open(filename2, O_RDONLY);
	fd3 = open(filename3, O_RDONLY);

	line1 = get_next_line(fd1);
	line2 = get_next_line(fd2);
	line3 = get_next_line(fd3);
	while (line1 || line2 || line3)
	{
		ft_custom_print(line1);
		ft_custom_print(line2);
		ft_custom_print(line3);
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		line3 = get_next_line(fd3);
	}
	close(fd1);
	close(fd2);
	close(fd3);
	printf("========================================= END =========================================\n");
}

int	main(void)
{
	setbuf(stdout, NULL);

	test_with_file_multiple_fd();

	return (0);
}
