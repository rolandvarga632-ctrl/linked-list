all:
	gcc -Wall -Wextra -g llist.c test.c -o test
	@valgrind --leak-check=full --track-origins=yes ./test
