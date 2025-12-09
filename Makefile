# SRCDIR := src
# INCDIR := include
# BUILDDIR := build
# ASSETSDIR := assets

# all: $(BUILDDIR)/main.out

# # Build the final executable
# $(BUILDDIR)/main.out: $(BUILDDIR)/main.o $(BUILDDIR)/Carte.o $(BUILDDIR)/Parcelle.o $(BUILDDIR)/ZAU.o $(BUILDDIR)/ZU.o $(BUILDDIR)/ZA.o 
# 	g++ -o $@ $^

# # Build main.o
# $(BUILDDIR)/main.o: $(SRCDIR)/main.cpp $(INCDIR)/Point2D.hpp $(INCDIR)/Polygone.hpp $(SRCDIR)/Carte.cpp $(INCDIR)/Carte.hpp $(SRCDIR)/Parcelle.cpp $(INCDIR)/Parcelle.hpp $(SRCDIR)/ZAU.cpp $(INCDIR)/ZAU.hpp $(SRCDIR)/ZU.cpp $(INCDIR)/ZU.hpp $(SRCDIR)/ZA.cpp $(INCDIR)/ZA.hpp $(INCDIR)/ZN.hpp $(INCDIR)/Constructible.hpp | $(BUILDDIR)
# 	g++ -I$(INCDIR) -c $(SRCDIR)/main.cpp -o $(BUILDDIR)/main.o

# # Build Carte.o
# $(BUILDDIR)/Carte.o: $(SRCDIR)/Carte.cpp $(INCDIR)/Carte.hpp | $(BUILDDIR)
# 	g++ -I$(INCDIR) -c $(SRCDIR)/Carte.cpp -o $(BUILDDIR)/Carte.o

# # Build Parcelle.o
# $(BUILDDIR)/Parcelle.o: $(SRCDIR)/Parcelle.cpp $(INCDIR)/Parcelle.hpp | $(BUILDDIR)
# 	g++ -I$(INCDIR) -c $(SRCDIR)/Parcelle.cpp -o $(BUILDDIR)/Parcelle.o

# # Build ZAU.o
# $(BUILDDIR)/ZAU.o: $(SRCDIR)/ZAU.cpp $(INCDIR)/ZAU.hpp | $(BUILDDIR)
# 	g++ -I$(INCDIR) -c $(SRCDIR)/ZAU.cpp -o $(BUILDDIR)/ZAU.o

# # Build ZU.o
# $(BUILDDIR)/ZU.o: $(SRCDIR)/ZU.cpp $(INCDIR)/ZU.hpp | $(BUILDDIR)
# 	g++ -I$(INCDIR) -c $(SRCDIR)/ZU.cpp -o $(BUILDDIR)/ZU.o

# # Build ZA.o
# $(BUILDDIR)/ZA.o: $(SRCDIR)/ZA.cpp $(INCDIR)/ZA.hpp | $(BUILDDIR)
# 	g++ -I$(INCDIR) -c $(SRCDIR)/ZA.cpp -o $(BUILDDIR)/ZA.o

# # Create build directory
# $(BUILDDIR):
# 	mkdir -p $(BUILDDIR)

# clean:
# 	rm -rfv $(BUILDDIR)


SRCDIR   := src
INCDIR   := include
BUILDDIR := build

CXX      := g++
CXXFLAGS := -I$(INCDIR) -Wall -Wextra
LDFLAGS  :=

SRCS := $(wildcard $(SRCDIR)/*.cpp)
OBJS := $(SRCS:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)

.PHONY: all clean

all: $(BUILDDIR)/main.out

$(BUILDDIR)/main.out: $(OBJS)
	$(CXX) $^ -o $@ $(LDFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILDDIR):
	mkdir -p $@

clean:
	rm -rf $(BUILDDIR)

# ----------------------------
# Tests
# ----------------------------
TEST_SRCS := $(wildcard tests/*.cpp)
TEST_BIN  := $(patsubst tests/%.cpp,$(BUILDDIR)/%_test,$(TEST_SRCS))

# Implementation sources to link with tests (exclude main.cpp to avoid multiple mains)
TEST_IMPL := $(filter-out $(SRCDIR)/main.cpp,$(SRCS))

.PHONY: test
test: $(TEST_BIN)

$(BUILDDIR)/%_test: tests/%.cpp | $(BUILDDIR)
	# Compile the test and link against the implementation sources (excluding main.cpp)
	$(CXX) $(CXXFLAGS) $< $(TEST_IMPL) -o $@

