# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rvan-hou <rvan-hou@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2021/03/15 15:36:52 by robijnvanho   #+#    #+#                  #
#    Updated: 2021/03/16 14:33:22 by rvan-hou      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	ft_containers

SOURCES			= 	UNIT_TEST/0_main.cpp \
					UNIT_TEST/1_vector_test.cpp \
					UNIT_TEST/catch.cpp \

OBJECTS 		=	${SOURCES:%.c=%.o}

FLAGS 			=	-Wall -Wextra -Werror
INCLUDES 		=	-Iincludes/
UTILS			=	-Iincludes/utils/
UNIT_TEST		=	-IUNIT_TEST/
COMPILE			=	clang++ -std=c++14

GREEN 			= 	\033[38;5;46m
WHITE 			= 	\033[38;5;15m
GREY 			= 	\033[38;5;8m
ORANGE 			= 	\033[38;5;202m
RED 			= 	\033[38;5;160m

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "$(GREEN)----------------------------------------------------"
	@$(COMPILE) $(INCLUDES) $(UTILS) $(UNIT_TEST) $(FLAGS) -o $(NAME) $(OBJECTS)
	@echo "Executable				./ft_containers"
	@echo "$(GREEN)----------------------------------------------------"

%.o: %.c
	@echo "$(GREY)Compiling...				$(WHITE)$<"
	@$(COMPILE) $(INCLUDES) $(UTILS) $(UNIT_TEST) $(FLAGS) -c -o $@ $<

clean:
	@echo "$(RED)----------------------------------------------------"
	@echo "$(WHITE)DELETE ./ft_containers"
	@echo "$(RED)----------------------------------------------------"
	@/bin/rm -f $(NAME)

re: clean all