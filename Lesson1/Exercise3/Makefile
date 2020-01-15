APP         = remove_if

CC          = g++
SRCS        = main.cpp
OUT         = main.out

CFLAGS      = -I.

HEADERS     = $(wildcard *.h)
LFLAGS      = -legal/copyright
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
