OUTPUT = a.out

TOPDIR := $(PWD)
BINDIR := $(TOPDIR)/bin
INCDIR := $(TOPDIR)/inc
SRCDIR := $(TOPDIR)/src
OBJDIR := $(TOPDIR)/obj

VPATH := $(INCDIR):$(SRCDIR):$(OBJDIR)

STDFLAG = -std=c++11
DEBUGFLAG = -g
IFLAG = -I $(INCDIR)

CC = g++
AR = ar -rcs

TARGET=$(BINDIR)/$(OUTPUT)

SRC=$(wildcard $(SRCDIR)/*.cpp)
OBJ=$(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRC))

$(TARGET):$(OBJ)
	$(CC) $(STDFLAG) $(IFLAG) $(DEBUGFLAG) -o $(TARGET) $(OBJ)

$(OBJDIR)/%.o:$(SRCDIR)/%.cpp
	$(CC) $(STDFLAG) $(IFLAG) $(DEBUGFLAG) -c $< -o $@

init:
	mkdir -p $(BINDIR)
	mkdir -p $(INCDIR)
	mkdir -p $(SRCDIR)
	mkdir -p $(OBJDIR)

run:
	$(TARGET)

clean:
	rm $(BINDIR)/* -f
	rm $(OBJDIR)/* -f
	
cleanall:
	make clean
	rm $(INCDIR)/* -f
	rm $(SRCDIR)/* -f

