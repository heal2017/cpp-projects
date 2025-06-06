OUTPUT = a.out
LIBNAME = incam

TOPDIR := $(PWD)
BINDIR := $(TOPDIR)/bin
INCDIR := $(TOPDIR)/inc
SRCDIR := $(TOPDIR)/src
OBJDIR := $(TOPDIR)/obj
LIBDIR := $(TOPDIR)/lib

SHARELIBNAME = $(LIBDIR)/lib$(LIBNAME).so
VPATH := $(INCDIR):$(SRCDIR):$(OBJDIR)

STDFLAG = -std=c++11
DEBUGFLAG = -g
IFLAG = -I $(INCDIR)

CC = g++ -fPIC
AR = ar -rcs

TARGET=$(BINDIR)/$(OUTPUT)

SRC=$(wildcard $(SRCDIR)/*.cpp)
OBJ=$(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRC))

$(TARGET):$(OBJ)
	$(CC) $(STDFLAG) $(IFLAG) $(DEBUGFLAG) -o $(TARGET) $(OBJ)

$(OBJDIR)/%.o:$(SRCDIR)/%.cpp
	$(CC) $(STDFLAG) $(IFLAG) $(DEBUGFLAG) -c $< -o $@

share:
	make -f Share
	@echo "===================="
	@echo "共享库环境变量:"
	@echo "export LD_LIBRARY_PATH=$(LD_LIBRARY_PATH):$(LIBDIR)"
	@echo "===================="

init:
	mkdir -p $(BINDIR)
	mkdir -p $(INCDIR)
	mkdir -p $(SRCDIR)
	mkdir -p $(OBJDIR)
	mkdir -p $(LIBDIR)

run:
	$(TARGET)

clean:
	rm $(BINDIR)/* -f
	rm $(OBJDIR)/* -f
	rm $(LIBDIR)/* -f
	
cleanall:
	make clean
	rm $(INCDIR)/* -f
	rm $(SRCDIR)/* -f

