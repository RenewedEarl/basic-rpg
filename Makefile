# Makefile

CC = gcc
CFLAGS = -Wall -g
# Declare the final exectutable
TARGET = bin/main
# Object files (marked as intermediate)
OBJ = main.o src/mainmenu.o src/adventurearea.o src/textfuncs.o src/characters.o src/battle.o

# Final build rule
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)
	rm -f $(OBJ)

main.o: main.c include/mainmenu.h
src/mainmenu.o: src/mainmenu.c include/characters.h include/textfuncs.h include/adventurearea.h include/mainmenu.h
src/textfuncs.o: src/textfuncs.c include/characters.h
src/adventurearea.o: src/adventurearea.c include/textfuncs.h include/mainmenu.h include/characters.h include/battle.h
src/characters.o: src/characters.c include/characters.h
src/battle.o: src/battle.c include/characters.h include/textfuncs.h

clean:
	rm -f *.o main
