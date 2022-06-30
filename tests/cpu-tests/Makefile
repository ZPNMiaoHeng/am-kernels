.PHONY: all run gdb clean latest $(ALL)

RESULT = .result
$(shell > $(RESULT))

COLOR_RED   = \033[1;31m
COLOR_GREEN = \033[1;32m
COLOR_NONE  = \033[0m
# all c filename
ALL = $(basename $(notdir $(shell find tests/. -name "*.c")))
# Makefile.filename
all: $(addprefix Makefile., $(ALL))
	@echo "" $(ALL)
# all取值为 ：所有以“：”结尾的 以及Makefile.所有文件
$(ALL): %: Makefile.%
# ARCH
Makefile.%: tests/%.c latest 
#	@echo MAKE=$(MAKECMDGOALS)
	@/bin/echo -e "NAME = $*\nSRCS = $<\nLIBS += klib\ninclude $${AM_HOME}/Makefile" > $@
	@if make -s -f $@ ARCH=$(ARCH) $(MAKECMDGOALS); then \
		printf "[%14s] $(COLOR_GREEN)PASS!$(COLOR_NONE)\n" $* >> $(RESULT); \
	else \
		printf "[%14s] $(COLOR_RED)FAIL!$(COLOR_NONE)\n" $* >> $(RESULT); \
	fi
#	-@rm -f Makefile.$*

run: all
	@cat $(RESULT)
	@rm $(RESULT)

gdb: all

clean:
	rm -rf Makefile.* build/

latest:
