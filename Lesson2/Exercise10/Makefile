APP         = stream.out

CC          = g++
SRCS        = $(wildcard *.cpp)
HEADERS     = $(wildcard *.h)
OBJS        = $(patsubst %.cpp, %.o, $(SRCS))

CFLAGS      = -Wall -Wextra -Werror -I.
LFLAGS      = -whitespace/braces,-legal/copyright
LINELENGTH  = 120

.PHONY: all clean lint
all: lint run clean

debug: CFLAGS += -g
debug: $(APP)

%.o: %.cpp $(HEADERS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(APP): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

run: $(APP)
	./$(APP)

lint:
	cpplint --linelength=$(LINELENGTH) --filter=$(LFLAGS) $(SRCS) $(HEADERS)
	cppcheck --language=c++ $(SRCS) $(HEADERS)

clean:
	rm $(OBJS)
	rm $(APP)
