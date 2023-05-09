PROG=program.exe
SOURCES=main.c calculator.c game.c shapes.c  
DEPS=calculator.h game.h shapes.h
CC=gcc
CFLAGS=
DEBUG?=1
GTESTINCLUDE = gtest
LIBGTEST = C:\msys64\mingw64\lib\libgtest_main.a C:\msys64\mingw64\lib\libgtest.a

ifeq ($(DEBUG), 1)
	CFLAGS += -g
	OUTPUTDIR=bin/debug
	PROG=YL-debug.exe
else
	CFLAGS += -g0 -O3
	OUTPUTDIR=bin/release
endif

 
OBJS =  $(addprefix $(OUTPUTDIR)/,$(SOURCES:.c=.o))

$(PROG): $(OUTPUTDIR) $(OBJS) 
	$(CC) $(CFLAGS) -o $(PROG) $(OBJS)




$(OUTPUTDIR)/%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -o $@ -c $< 

$(OUTPUTDIR)/%.o: %.cpp $(DEPS)
	g++ -o $@ -c $< -I $(GTESTINCLUDE)


clean:
	@del /q "$(OUTPUTDIR)" 
	@del /q $(PROG)

$(OUTPUTDIR):
	@mkdir "$(OUTPUTDIR)"

check.exe: $(OUTPUTDIR)/parallelogramTest.o $(OUTPUTDIR)/calculator.o $(OUTPUTDIR)/game.o $(OUTPUTDIR)/shapes.o  
	g++ -o $@ $^ $(CFLAGS) -I $(GTESTINCLUDE)  $(LIBGTEST)

test: check.exe
	./check.exe

.PHONY: clean

