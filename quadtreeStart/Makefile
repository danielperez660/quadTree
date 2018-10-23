
# code details

EXE_DIR = .
EXE = $(EXE_DIR)/main


SRC= main.c writeTree.c buildTree.c destroyTree.c growTree.c tests.c valueTree.c

# generic build details

CC=      cc
COPT=    -g
CFLAGS= -lm

# compile to  object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(COPT) -c -o $@ $<

# build executable

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(EXE)

# clean up compilation

clean:
	rm -f $(OBJ) $(EXE)

# dependencies

main.o: main.c treeStructure.h buildTree.h writeTree.h destroyTree.h growTree.h tests.h valueTree.h
tests.o: tests.c tests.h
buildTree.o: buildTree.c buildTree.h
writeTree.o: writeTree.c writeTree.h
destroyTree.o: destroyTree.c destroyTree.h
growTree.o: growTree.c growTree.h
valueTree.o: valueTree.c valueTree.h
