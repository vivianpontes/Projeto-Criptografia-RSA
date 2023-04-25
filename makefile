MAIN = main.c
UTILS = lib/utils.c lib/utils.h

copile_main:
	gcc $(UTILS) $(MAIN) -o main