SRCDIR := src
INCDIR := include
BUILDDIR := build
ASSETSDIR := assets

all: $(BUILDDIR)/main.out

# Build the final executable
$(BUILDDIR)/main.out: $(BUILDDIR)/main.o $(BUILDDIR)/Carte.o $(BUILDDIR)/ZAU.o $(BUILDDIR)/ZU.o
	g++ -o $@ $^

# Build main.o
$(BUILDDIR)/main.o: $(SRCDIR)/main.cpp $(INCDIR)/Point2D.hpp $(INCDIR)/Polygone.hpp $(SRCDIR)/Carte.cpp $(INCDIR)/Carte.hpp $(SRCDIR)/Parcelle.cpp $(INCDIR)/Parcelle.hpp $(SRCDIR)/ZAU.cpp $(INCDIR)/ZAU.hpp $(SRCDIR)/ZU.cpp $(INCDIR)/ZU.hpp $(INCDIR)/Constructible.hpp | $(BUILDDIR)
	g++ -I$(INCDIR) -c $(SRCDIR)/main.cpp -o $(BUILDDIR)/main.o

# Build Carte.o
$(BUILDDIR)/Carte.o: $(SRCDIR)/Carte.cpp $(INCDIR)/Carte.hpp | $(BUILDDIR)
	g++ -I$(INCDIR) -c $(SRCDIR)/Carte.cpp -o $(BUILDDIR)/Carte.o

# Build ZAU.o
$(BUILDDIR)/ZAU.o: $(SRCDIR)/ZAU.cpp $(INCDIR)/ZAU.hpp | $(BUILDDIR)
	g++ -I$(INCDIR) -c $(SRCDIR)/ZAU.cpp -o $(BUILDDIR)/ZAU.o

# Build ZU.o
$(BUILDDIR)/ZU.o: $(SRCDIR)/ZU.cpp $(INCDIR)/ZU.hpp | $(BUILDDIR)
	g++ -I$(INCDIR) -c $(SRCDIR)/ZU.cpp -o $(BUILDDIR)/ZU.o

# Create build directory
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

clean:
	rm -rfv $(BUILDDIR) && rm -rfv $(ASSETSDIR)/lexique*