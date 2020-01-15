DIRECTORIES = $(sort $(dir $(wildcard */)))

.PHONY: lint

lint:
	for d in $(DIRECTORIES); \
	do						\
		$(MAKE) --directory=$$d lint;		\
	done
