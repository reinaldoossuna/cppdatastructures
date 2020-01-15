APP         = hash

CC          = g++
SRC         = main.cpp
OUT         = main.out

CFLAGS      = -I.

HEADERS     = $(wildcard *.h)
LFLAGS      = -whitespace/braces,-legal/copyright
LINELENGTH  = 120

.PHONY: all run clean lint debug
all: lint $(APP) run

debug:
	$(CC) -o debug_$(OUT) -g main.cpp $(CFLAGS)

$(APP): $(OBJS)
	$(CC) -o $(OUT) main.cpp $(CFLAGS)

run:
	./$(OUT)

lint:
	cpplint --linelength=$(LINELENGTH) --filter=$(LFLAGS) $(SRC) $(HEADERS)
	cppcheck --language=c++ $(SRC) $(HEADERS)

clean:
	rm $(OUT)
