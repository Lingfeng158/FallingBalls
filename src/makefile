IDIR =../include
CXX=g++
CXXFLAGS=-I$(IDIR)

ODIR=obj

LIBS=-lm

_DEPS = filewriting.h globalInfo.h pawn.h action.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o filewriting.o pawn.o action.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

FBallStage: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~