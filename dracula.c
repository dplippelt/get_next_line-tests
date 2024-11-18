/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dracula.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:09:23 by dlippelt          #+#    #+#             */
/*   Updated: 2024/11/14 12:32:24 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "test.h"

void	test_bonus_with_dracula_book()
{
	int		fd1;
	int		fd2;
	char	*line;
	char	*input;
	char	*output;

	input = "files/dracula.txt";
	output = "copy_dracula.txt";

	printf("\n================== Get Dracula ===================\n");
	printf("Name of test file: %s, BUFFER_SIZE = %d\n", input, BUFFER_SIZE);

	fd1 = open(input, O_RDONLY);
	fd2 = open(output, O_CREAT | O_WRONLY | O_TRUNC, 0644);

	line = get_next_line(fd1);
	while (line)
	{
		printf("%s", line);
		write(fd2, line, ft_strlen(line));
		free(line);
		line = get_next_line(fd1);
	}
	close(fd1);
	close(fd2);
	printf("======================= END ======================\n");
}

int	main(void)
{
	setbuf(stdout, NULL);

	test_bonus_with_dracula_book();

	return (0);
}
