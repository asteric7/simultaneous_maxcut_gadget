CXXFLAGS=-O3 -Wall
LDFLAGS=-lmpfr

MAIN=prover_smc
OBJECTS=alpha.o bvnl.o rectangles.o gaussian.o search_smc.o
HEADERS=intervals.h

all: $(MAIN)

%.o: %.cc %.h $(HEADERS) Makefile
	$(CXX) $(CXXFLAGS) -c -o $@ $<


$(MAIN): $(MAIN).cc $(OBJECTS) $(HEADERS) Makefile
	$(CXX) $(CXXFLAGS) -o $@ $(MAIN).cc $(OBJECTS) $(LDFLAGS)


clean: 
	rm -f $(OBJECTS) $(MAIN) 

