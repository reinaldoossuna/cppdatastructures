APP         = iterators

CC          = g++
SRCS        = main.cpp
OUT         = main.out

CFLAGS      = -I.

HEADERS     = $(wildcard *.h)
LFLAGS      = -legal/copyright
LINELENGTH  = 120

.PHONY: all run clean
all: $(APP) run

$(APP): $(OBJS)
	$(CC) -o $(OUT) main.cpp $(CFLAGS)

run:
	./$(OUT)

lint:
	cpplint --linelength=$(LINELENGTH) --filter=$(LFLAGS) $(SRC) $(HEADERS)
	cppcheck --language=c++ $(SRC) $(HEADERS)

.PHONY: clean
clean:
	rm $(OUT)
