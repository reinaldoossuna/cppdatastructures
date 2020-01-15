APP         = playlist

CC          = g++
SRCS        = main.cpp
OUT         = main.out

CFLAGS      = -I.

HEADERS     = $(wildcard *.h)
LFLAGS      = -whitespace/braces
LINELENGTH  = 120

.PHONY: all run clean
all: lint $(APP) run

$(APP): $(OBJS)
	$(CC) -o $(OUT) main.cpp $(CFLAGS)

run:
	./$(OUT)

lint:
	cpplint --linelength=$(LINELENGTH) --filter=$(LFLAGS) $(SRC) $(HEADERS)
	cppcheck --language=c++ $(SRC) $(HEADERS)

clean:
	rm $(OUT)
