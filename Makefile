CC = g++
CCFLAG = -g -w

exec: main.o Grassland.o
    $(CC) $(CCFLAG) -o Project7 main.o Grassland.o

main.o: main.C World.h Grassland.h
    $(CC) $(CCFLAG) -c main.C

Grassland.o: Animal.h Wolf.h Rabbit.h Cells.h Grassland.h Grassland.C
    $(CC) $(CCFLAG) -c Grassland.C
