# to execute the makefile on unix-y systems, type 'make'.
# if that doesn't work, 'make -f makefile' might be useful.

# replace 'your_file' below with your actual source file names.
# add more if needed.

CXX = Creature.cpp
CXX += Goblin.cpp
CXX += Barbarian.cpp
CXX += Reptile.cpp
CXX += Bluemen.cpp
CXX += Shadow.cpp
CXX += game.cpp 

PROG1 = game

default:
	g++ ${CXX} -o ${PROG1}

clean:
	rm -f a.out *.o *~ ${PROG1}
