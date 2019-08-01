IDIR =../include
CXX=g++
CXXFLAGS=-I$(IDIR)

ODIR=obj

LIBS=-lm

_DEPS = filewriting.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o filewriting.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

FBalls: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~