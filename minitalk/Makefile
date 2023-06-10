# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 12:57:39 by thibnguy          #+#    #+#              #
#    Updated: 2023/06/10 17:21:46 by thibnguy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES		:=	./src
OBJECTS		:=	./bin
INCLUDES	:=	./includes

SRCS		:=	ft_atoi.c \
				ft_check_pid.c \
				ft_intlen.c \
				ft_printf.c \
				ft_strdup.c \
				ft_strlen.c

OBJS		:=	$(addprefix ${OBJECTS}/, $(SRCS:.c=.o))

CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror
CINCLUDES	:=	-I ${INCLUDES}

BLACK		:=	"\033[1;30m"
RED			:=	"\033[1;31m"
GREEN		:=	"\033[1;32m"
CYAN		:=	"\033[1;35m"
BLUE		:=	"\033[1;36m"
WHITE		:=	"\033[1;37m"
EOC			:=	"\033[0;0m"

${OBJECTS}/%.o: ${SOURCES}/%.c
	@mkdir -p $(dir $@)
	@echo "● Compilation de "$(BLUE)"${notdir $<}"$(EOC)"."
	@${CC} ${CFLAGS} -o $@ -c $< ${CINCLUDES}

all: server client

server: ${OBJS} ${OBJECTS}/server.o
	@echo $(GREEN)"● Compilation du server..."$(EOC)
	@${CC} ${CFLAGS} -fsanitize=address -g ${CINCLUDES} -o server ${OBJS} ${OBJECTS}/server.o

client: ${OBJS} ${OBJECTS}/client.o
	@echo $(GREEN)"● Compilation du client..."$(EOC)
	@${CC} ${CFLAGS} -fsanitize=address -g ${CINCLUDES} -o client ${OBJS} ${OBJECTS}/client.o

clean:
	@echo ${RED}"● Supression des fichiers binaires (.o)..."$(EOC)
	@rm -rf ${OBJECTS}

fclean: clean
	@echo ${RED}"● Supression des executables et librairies..."$(EOC)
	@rm -rf server client

re: fclean all

.PHONY: all clean fclean re