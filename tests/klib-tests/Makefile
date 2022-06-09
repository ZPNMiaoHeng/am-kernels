.PHONY: all run clean latest $(ALL)

RESULT = .result
$(shell > $(RESULT))

COLOR_RED   = \033[1;31m
COLOR_GREEN = \033[1;32m
COLOR_NONE  = \033[0m
# all c filename
ALL = $(basename $(notdir $(shell find src/. -name "*.c")))
# Makefile.filename
all: $(addprefix Makefile., $(ALL))
	@echo "" $(ALL)
$(ALL): %: Makefile.%

Makefile.%: src/%.c latest
	@/bin/echo -e "NAME = $*\nSRCS = $<\ninclude $${AM_HOME}/Makefile" > $@
	@if make -s -f $@ ARCH=$(ARCH) $(MAKECMDGOALS); then \
		printf "[%14s] $(COLOR_GREEN)PASS!$(COLOR_NONE)\n" $* >> $(RESULT); \
	else \
		printf "[%14s] $(COLOR_RED)FAIL!$(COLOR_NONE)\n" $* >> $(RESULT); \
	fi
	-@rm -f Makefile.$*

run: all
	@cat $(RESULT)
	@rm $(RESULT)

clean:
	rm -rf Makefile.* build/

latest:

#NAME = klibtest
#SRCS = src/memset.c

#include $(AM_HOME)/Makefile
