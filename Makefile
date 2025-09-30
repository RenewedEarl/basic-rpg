# Makefile

CC = gcc
CFLAGS = -Wall -g
# Declare the final exectutable
TARGET = main
# Object files (marked as intermediate)
OBJ = main.o src/mainmenu.o src/adventurearea.o src/textfuncs.o

# Final build rule
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)
	rm -f $(OBJ)

main.o: main.c include/mainmenu.h
src/mainmenu.o: src/mainmenu.c include/characters.h include/textfuncs.h include/adventurearea.h include/mainmenu.h
src/textfuncs.o: src/textfuncs.c
src/adventurearea.o: src/adventurearea.c include/textfuncs.h include/mainmenu.h

clean:
	rm -f *.o main
