NAME = cub3d

NAME_B = cub3d_bonus

FLAGS = -Wall -Werror -Wextra -O3 -fsanitize=address -fsanitize=undefined  

SRCS = 	src/main.c					\


HEADER = ./Include/cube.h

FRAMEWORK = -framework Cocoa -framework OpenGL -framework IOKit

LIBS =  ./utils/libft/libft.a

.c.o:
	@gcc  ${FLAGS}  -c $< -o ${<:.c=.o}

OBJS = ${SRCS:.c=.o}

OBJS_B = ${SRCS_B:.c=.o}

MAP = ./map/valid_map1.cub

CC = gcc

OS := $(shell uname -s)

all: ${NAME}
${NAME}:${OBJS}
		@$(MAKE) -C ./utils/libft

ifeq ($(OS),Darwin)
		@${CC} ${FLAGS} ${OBJS} ${LIBS} ${FRAMEWORK} -o ${NAME}
endif

ifeq ($(OS),Linux)
		@${CC} ${FLAGS} ${OBJS}  ./utils/libft/libft.a  -o ${NAME}
endif

clean:
		@${RM} ${OBJS}
		@${RM} ${OBJS_B}

fclean: clean
	make -C ./utils/libft clean
	rm -rf cub3d
	rm -rf cub3d_bonus

git:
	@git add ${SRCS} ${HEADER} Makefile

val:
	valgrind --track-origins=yes --leak-check=full ./$(NAME) ./map/valid_map1.cub

run: all
	./${NAME} 

norm:
	norminette ${SRCS}

bun: all

leak: all
	@echo "\033[92mTEST 1 \n \033[0m"
	@leaks --atExit --  ./${NAME} ./map/valid_map1.cub

bonus: ${OBJS_B}
	@$(MAKE) -C ./utils/libft
	@$(MAKE) -s -C ./utils/MLX

ifeq ($(OS),Darwin)
		@${CC} ${FLAGS} ${OBJS_B} ${LIBS} ${FRAMEWORK} -o ${NAME_B}
endif

ifeq ($(OS),Linux)
		@${CC} ${FLAGS} ${OBJS} ./utils/MLX/libmlx42.a ./utils/libft/libft.a -lglfw -lm -o ${NAME_B}
endif

re: fclean all

.PHONY: clean fclean re all
