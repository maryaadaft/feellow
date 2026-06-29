CC = cc
CFLAGs = -Wall -Wextra -Werror -pthread
SRCs = philo_main.c utils.c to_num.c clean_error.c calc_time.c init.c routine.c monitor.c
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
