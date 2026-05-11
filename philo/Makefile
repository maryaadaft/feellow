CC = cc
CFLAGs = -Wall -Wextra -Werror
SRCs = philo_main.c utils.c to_num.c
OBJs = ${SRCs:.c=.o}
Name = philo

all: $(Name)

$(Name) : $(OBJs)
		$(CC) $(CFLAGs) -o $(Name) $(OBJs)

clean:
	rm -rf $(OBJs)

fclean: clean
	rm -rf $(Name)

re: fclean all

.PHONY: all clean fclean re