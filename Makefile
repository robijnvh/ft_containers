# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rvan-hou <rvan-hou@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2021/03/15 15:36:52 by robijnvanho   #+#    #+#                  #
#    Updated: 2021/05/05 15:15:28 by robijnvanho   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	ft_containers

SOURCES			= 	CATCH2/main.cpp \
					CATCH2/catch.cpp \
					CATCH2/map_test.cpp \
					CATCH2/list_test.cpp \
					CATCH2/vector_test.cpp \
					CATCH2/iterator_test.cpp \
					CATCH2/stack_test.cpp \
					CATCH2/queue_test.cpp \
					# CATCH2/vector_test_roy.cpp \
					CATCH2/vector_test_tim.cpp \

OBJECTS 		=	${SOURCES:%.c=%.o}

FLAGS 			=	-Wall -Wextra -Werror -g3
INCLUDES 		=	-Iincludes/
UTILS			=	-Iincludes/utils/
CATCH2			=	-ICATCH2/
COMPILE_TEST	=	clang++ -std=c++14
COMPILE_LIB		=	clang++ -std=c++98

WHITE 			= 	\033[38;5;15m
RED 			= 	\033[38;5;160m

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(COMPILE_TEST) $(INCLUDES) $(UTILS) $(FLAGS) -o $(NAME) $(OBJECTS)
	@echo "$(WHITE)Executable -> ./ft_containers"

%.o: %.c
	@$(COMPILE_TEST) $(INCLUDES) $(UTILS) $(FLAGS) -c -o $@ $<

clean:
	@echo "$(RED)rm ./ft_containers"
	@/bin/rm -f $(NAME)

re: clean all
