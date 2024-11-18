# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 08:50:02 by dlippelt          #+#    #+#              #
#    Updated: 2024/11/18 11:39:56 by dlippelt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

MAIN = main.c
BONUS = bonus.c
STDIN = stdin.c
BSTDIN = bonus_stdin.c
INVFD = invalid_fd.c
BINVFD = bonus_invalid_fd.c
DRACULA = dracula.c
BDRACULA = bonus_dracula.c

ORIGINAL = files/dracula.txt
COPY = copy_dracula.txt
BCOPY = copy_dracula_bonus.txt

CC = cc
CFLAGS = -Wall -Werror -Wextra

BUFFER_SIZE = 10

TESTFLAGS = -g -fsanitize=address -D BUFFER_SIZE=$(BUFFER_SIZE) -D BONUS=0 -Wall -Werror -Wextra
BTESTFLAGS = -g -fsanitize=address -D BUFFER_SIZE=$(BUFFER_SIZE) -D BONUS=1 -Wall -Werror -Wextra

# TESTFLAGS = -g -fsanitize=address -D BONUS=0 -Wall -Werror -Wextra
# BTESTFLAGS = -g -fsanitize=address -D BONUS=1 -Wall -Werror -Wextra

#change PDIR for eval
PDIR = $(HOME)/codam/main/get_next_line/2/

SRCS = 	get_next_line_utils.c \
		get_next_line.c
FSRCS = $(addprefix $(PDIR), $(SRCS))

BSRCS =	get_next_line_utils_bonus.c \
		get_next_line_bonus.c
FBSRCS = $(addprefix $(PDIR), $(BSRCS))

all: $(NAME)

$(NAME): test bonus invalid_fd invalid_fd_bonus

clean:
	rm -f *.txt

fclean : clean
	rm -f *.out

re: fclean all

test: $(FSRCS) $(MAIN)
	$(CC) $(TESTFLAGS) $^ -o $(NAME)
	./$(NAME) | cat -e

bonus: $(FBSRCS) $(BONUS)
	$(CC) $(BTESTFLAGS) $^ -o $(NAME)
	./$(NAME) | cat -e

invalid_fd: $(FSRCS) $(INVFD)
	$(CC) $(TESTFLAGS) $^ -o $(NAME)
	./$(NAME) | cat -e

invalid_fd_bonus: $(FBSRCS) $(BINVFD)
	$(CC) $(BTESTFLAGS) $^ -o $(NAME)
	./$(NAME) | cat -e

stdin: $(FSRCS) $(STDIN)
	$(CC) $(TESTFLAGS) $^ -o $(NAME)
	./$(NAME) | cat -e

stdin_bonus: $(FBSRCS) $(BSTDIN)
	$(CC) $(BTESTFLAGS) $^ -o $(NAME)
	./$(NAME) | cat -e

dracula: $(COPY)
	@if diff $< $(ORIGINAL); then \
		echo "\n\"$<\" and \"$(ORIGINAL)\" are identical\n"; \
	else \
		echo "\n\"$<\" and \"$(ORIGINAL)\" are different\n"; \
	fi

dracula_bonus: $(BCOPY)
	@if diff $< $(ORIGINAL); then \
		echo "\n\"$<\" and \"$(ORIGINAL)\" are identical\n"; \
	else \
		echo "\n\"$<\" and \"$(ORIGINAL)\" are different\n"; \
	fi

$(COPY): $(FSRCS) $(DRACULA)
	$(CC) $(TESTFLAGS) $^ -o $(NAME)
	./$(NAME)

$(BCOPY): $(FBSRCS) $(BDRACULA)
	$(CC) $(BTESTFLAGS) $^ -o $(NAME)
	./$(NAME)

.PHONY: all clean fclean re test bonus invalid_fd invalid_fd_bonus stdin stdin_bonus dracula bonus_dracula
