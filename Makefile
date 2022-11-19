NAME = so_long

SRCS = split.c utils.c \
	   itoa.c get_next_line_solong.c \
	   get_next_line_utils_so_long.c \
	   printfsolong.c printfsolong2.c \
	   count.c main.c \
	   testmap.c argcheck.c \
	   solvency.c solvencybis.c \
	   texture.c preparescreen.c \
	   texture2.c selecttexture.c \
	   loop.c keypad.c \
	   playermouvement.c playerseek.c \

BONUSSRCS = split.c utils.c \
			itoa.c get_next_line_solong.c \
			get_next_line_utils_so_long.c \
			printfsolong.c printfsolong2.c \
			countbonus.c argcheckbonus.c \
			testmap.c solvency.c \
			solvencybis.c texture2.c \
			texture.c selecttexture.c \
			selecttexturebonus.c loop.c \
			keypadbonus.c playermouvement.c \
			playerseek.c preparescreenbonus.c \
			main.c mouvementenemy.c \


ifdef BONUS
	OBJECTS = ${BONUSSRCS:.c=.o}
else
	OBJECTS = ${SRCS:.c=.o}
endif

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLXINCLUDE = -I /usr/local/include/ -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(OBJECTS) $(MLXINCLUDE) $(CFLAGS) -o $(NAME)

bonus :
		make BONUS=1 all

clean :
	rm -rf $(OBJECTS)

fclean : clean


re : fclean $(NAME)
	rm -rf $(OBJECTS)
