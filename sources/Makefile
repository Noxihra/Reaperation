##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile of the entire project
##

ARGV			:=

MAKEFLAGS		+=	--silent --no-print-directory

COMPILATION		:=

LINKAGE			:=

WNO				:=	switch
#WARNING			:= #Uncomment this line to disable warnings

# -l
LDLIBS			:=	sfml-graphics sfml-window sfml-system sfml-audio

SRCNOINC		:=	API sources/Flow

# -L (ls inside the LIBDIR var)
#MKLIBS			:=

# (MYLIBS is undefined, find *.a in MKLIBS)
#MYLIBS			:=


################################################################################

NAME			:=	Game
ISXX			:=	true

ifdef NAME

RM				:=	rm -rf
ECHO			:=	@echo -e
MKDIR			:=	mkdir -p

NORMAL			:=	\e[0m
BLACK			:=	\e[0;30m
DARKGRAY		:=	\e[1;30m
RED				:=	\e[0;31m
LRED			:=	\e[1;31m
GREEN			:=	\e[0;32m
LGREEN			:=	\e[1;32m
BROWN			:=	\e[0;33m
YELLOW			:=	\e[1;33m
BLUE			:=	\e[0;34m
LBLUE			:=	\e[1;34m
PURPLE			:=	\e[0;35m
LPURPLE			:=	\e[1;35m
CYAN			:=	\e[0;36m
LCYAN			:=	\e[1;36m
LIGHT			:=	\e[0;37m
WHITE			:=	\e[1;37m

BACK			:=	\e[H
ENDRASE			:=	\e[K
ERASE			:=	\e[1K\r
FERASE			:=	\e[2K\r
SPOS			:=	\e[2s
SPOS			:=	\e[2s
RPOS			:=	\e[1u
HIDECURS		:=	\e[?25l
SHOWCURS		:=	\e[?25h

################################################################################

OBJDIR			?=	.object
DEPDIR			?=	.dependecy

SRCEXT			?=	$(if $(ISXX),.cpp,.c)
INCEXT			?=	$(if $(ISXX),.hpp,.h)
OBJEXT			?=	.o
DEPEXT			?=	.d

TNAME			?=	unit_tests
TARGET			?=	$(NAME)
TTARGET			?=	$(TNAME)

################################################################################

ifneq ($(shell if [[ '$(MAKECMDGOALS)' == clean || '$(MAKECMDGOALS)' == fclean ]]; then echo true; fi), true)

## LIBDIR
ifndef LIBDIR
	ifeq (, $(shell if ! [ -d "lib" ]; then echo -n false; fi))
		LIBDIR	:=	lib
	else ifeq (, $(shell if ! [ -d "libs" ]; then echo -n false; fi))
		LIBDIR	:=	libs
	else ifeq (, $(shell if ! [ -d "library" ]; then echo -n false; fi))
		LIBDIR	:=	library
	else ifeq (, $(shell if ! [ -d "libraries" ]; then echo -n false; fi))
		LIBDIR	:=	libraries
	endif
endif

## INCDIR
ifndef INCDIR
	SRCNOINC	:=	$(patsubst %,! -path './%/*',$(SRCNOINC))
	INCDIR		!=	echo "$(patsubst ./%,%,$(dir $(shell find . -type f -name \*$(INCEXT) ! -path './.git/*' ! -path '$(LIBDIR)/*' $(SRCNOINC) )))" | tr ' ' '\n' | awk '!a[$$0]++'
	INCDIR		+=	.
	INCDIR		+=	sources
endif

## CC
ifdef ISXX
	ifneq ($(shell if [[ '$(CC)' == 'g++' || '$(CC)' == 'clang++' ]]; then echo true; fi), true)
		CC		:=	g++
	endif
else ifneq ($(shell if [[ '$(CC)' == gcc || '$(CC)' == clang ]]; then echo true; fi), true)
	CC			:=	gcc
endif

DEPFLAGS		=	-MT $@ -MMD -MP -MF $(DEPDIR)/$*$(DEPEXT)

## MODE FLAGS
RELFLAGS		+=	-Ofast
RELXXFLAGS		+=	-Ofast
LIBFLAGS		+=	-Ofast
LIBXXFLAGS		+=	-Ofast
DEBFLAGS		+=	-Og -g3
DEBXXFLAGS		+=	-Og -g3
UNIFLAGS		+=	--coverage
UNIXXFLAGS		+=	--coverage

## DEBUG
DEBUG			!=	file $(TARGET) | grep -o debug
ifeq ($(shell if [[ -n '$(DEBUG)' || '$(MAKECMDGOALS)' == debug || '$(MAKECMDGOALS)' == with_gdb ]]; then echo true; fi),true)
	DEBUG		=	debug
	CFLAGS		+=	$(DEBFLAGS)
	CXXFLAGS	+=	$(DEBXXFLAGS)
else
	CFLAGS		+=	$(RELFLAGS)
	CXXFLAGS	+=	$(RELXXFLAGS)
endif

MAIN			?=	$(patsubst ./%,%,$(shell find . -type f -name \*main$(SRCEXT) -o -name \*Main$(SRCEXT)))
TMAIN			?=	$(TSTDIR)/tests$(SRCEXT)

## UNITARY TESTS
ifeq ($(MAKECMDGOALS), tests_run)
	UNITARY		:=	unitary
	TMPTARGET	:=	$(TARGET)
	TARGET		:=	$(TTARGET)
	TTARGET		:=	$(TMPTARGET)
	CFLAGS		+=	$(UNIFLAGS)
	CXXFLAGS	+=	$(UNIXXFLAGS)
	OBJDIR		:=	$(addsuffix /tests, $(OBJDIR))
	DEPDIR		:=	$(addsuffix /tests, $(DEPDIR))
	LDLIBS		+=	criterion
	SRCFILES	?=	$(patsubst ./%,%,$(shell find . -type f -name \*$(SRCEXT) ! -path './$(MAIN)' ! -path './$(LIBDIR)/*'))
else
	OBJDIR		:=	$(addsuffix /sources, $(OBJDIR))
	DEPDIR		:=	$(addsuffix /sources, $(DEPDIR))
	SRCFILES	?=	$(patsubst ./%,%,$(shell find . -type f -name \*$(SRCEXT) ! -path './$(TSTDIR)/*' ! -path './$(TMAIN)' ! -path './$(LIBDIR)/*'))
endif

## FILES
OBJFILES		:=	$(SRCFILES:%$(SRCEXT)=$(OBJDIR)/%$(OBJEXT))
SRC_NBR			!=	echo "$$(($(words $(SRCFILES))))"

## COLOR
DEBUG_COLOR		:=	$(if $(DEBUG),$(if $(UNITARY),$(LPURPLE),$(LRED)),$(if $(UNITARY),$(LGREEN),$(LCYAN)))
DEBUG_MODE_MSG	:=	$(DEBUG_COLOR)$(if $(DEBUG),[Debug,[Normal)$(if $(UNITARY),:Unitary],])$(NORMAL)

## COMPILATIONS FLAGS
CPPFLAGS		:=	$(addprefix -I, $(INCDIR))
ifdef LIBDIR
	MKLIBS		?=	$(foreach libs, $(shell ls $(LIBDIR)),$(libs))
endif
MYLIBS			?=	$(foreach libs, $(MKLIBS), $(patsubst lib%,%,$(patsubst $(LIBDIR)/$(libs)/%.a,%,$(shell find $(LIBDIR)/$(libs) -type f -name \*.a))))
LDFLAGS			+=	$(addprefix -L, $(addprefix $(addsuffix /, $(LIBDIR)), $(MKLIBS)))
$(patsubst $(OBJDIR)%,$(DEPDIR)%,$(@D))
LDLIBS			:=	$(addprefix -l, $(LDLIBS)) $(addprefix -l, $(MYLIBS))

## NoWarning
WNO				:=	$(addprefix -Wno-, $(WNO))
## Warning
WARNING			?=	pedantic all extra double-promotion format init-self unused
#WARNING			?=	pedantic all extra double-promotion format init-self unused fatal-errors
WARNING			:=	$(addprefix -W, $(WARNING))

################################################################################

all : $(TARGET)
	if [[ ! '$(FILE_TODO)' == '' ]]; then echo -e '$(DEBUG_COLOR)[Linkage]$(NORMAL) - Done'; fi
	$(ECHO) '$(DEBUG_MODE_MSG) : $(if $(ISXX),$(CXXFLAGS),$(CFLAGS))'

$(TARGET) : $(OBJFILES)
	if [[ ! '$(FILE_TODO)' == '' ]]; then echo -e '$(RPOS)$(ENDRASE)Done\n'; fi
	$(eval CURPOS = $(shell cat .curs_pos.tmp))
	$(ECHO) -n "\033[$(CURPOS)H"
	rm -f .curs_pos.tmp
ifdef COMPILE_LIB
	$(MAKE) compile_lib
endif
	$(CC) $(OUTPUT_OPTION) $(LINKAGE) $(if $(UNITARY),--coverage,) $^ $(LDFLAGS) $(LDLIBS)

count : $(OBJFILES)
	$(ECHO) $(COUNTING)

display :
ifneq ($(MAKECMDGOALS), count)
	$(eval FILE_TODO := $(shell $(MAKE) count))
	if [[ ! '$(FILE_TODO)' == '' ]]; then echo -e '$(DEBUG_COLOR)[Compilation]$(NORMAL) - $(SPOS)'; fi
	echo -en "\033[6n" ; read -sdR CURPOS ; echo $${CURPOS#*[} > .curs_pos.tmp
endif

CURPOS			=	$(shell cat .curs_pos.tmp)

$(OBJDIR)/%$(OBJEXT) : %$(SRCEXT) | display
ifneq ($(MAKECMDGOALS), count)
	$(eval I := $(shell echo -n "$$(($(I)+1))"))
	$(eval PERCENT := $(shell printf %.2f "$$((10000*($(I)-1)/($(FILE_TODO))))e-2"))
	$(ECHO) -n '$(HIDECURS)$(RPOS)$(ENDRASE)$(PERCENT)% ($<)'
	$(eval CURPOS = $(shell cat .curs_pos.tmp))
	$(ECHO) -n "\033[$(CURPOS)H$(SHOWCURS)"
	$(MKDIR) $(@D) $(patsubst $(OBJDIR)%,$(DEPDIR)%,$(@D))
	$(CC) -c $(OUTPUT_OPTION) $(DEPFLAGS) $(if $(ISXX),$(CXXFLAGS),$(CFLAGS)) $(CPPFLAGS) $(WARNING) $(WNO) $(COMPILATION) $< || (rm .curs_pos.tmp && exit 1)
	echo -en "\033[6n" ; read -sdR CURPOS ; echo $${CURPOS#*[} > .curs_pos.tmp
else
	$(eval COUNTING = $(shell echo -n "$$(($(COUNTING)+1))"))
endif

include $(wildcard $(OBJFILES:$(OBJDIR)%$(OBJEXT)=$(DEPDIR)%$(DEPEXT)))

.NOTPARALLEL: re
re : fclean all

debug : $(if $(shell file $(TARGET) | grep -o debug), all, re)
	valgrind ./$(TARGET) $(ARGV)

with_gdb : $(if $(shell file $(TARGET) | grep -o debug), all, re)
	gdb $(TARGET)

tests_run : $(if $(shell ls | grep $(TARGET)), all, re)
	valgrind ./$(TARGET)
	gcovr -be $(TSTDIR)/

auto : all ; ./$(TARGET) $(ARGV)
auto_valless : all ; valgrind ./$(TARGET)

library : $(OBJFILES)
	if [[ ! '$(FILE_TODO)' == '' ]]; then echo -e '$(RPOS)$(ENDRASE)Done\n'; fi
	$(eval CURPOS = $(shell cat .curs_pos.tmp))
	$(ECHO) -n "\033[$(CURPOS)H"
	rm -f .curs_pos.tmp
	$(AR) lib$(TARGET).a $^
	$(ECHO) '$(LCYAN)[Library]$(NORMAL) - Created'

endif
################################################################################

clean :
	$(RM) $(OBJDIR) $(DEPDIR) vgcore.* .curs_pos.tmp
	$(ECHO) '$(DARKGRAY)[Clean]$(NORMAL) - Done'

fclean : clean
	$(RM) $(TARGET) $(TTARGET)
	$(ECHO) '$(DARKGRAY)[Fclean]$(NORMAL) - Done'

show:; cat Makefile | less

else
re :			; $(error No binary name set on the Makefile)
debug :			; $(error No binary name set on the Makefile)
tests_run :		; $(error No binary name set on the Makefile)
auto :			; $(error No binary name set on the Makefile)
auto_valless :	; $(error No binary name set on the Makefile)
clean :			; $(error No binary name set on the Makefile)
fclean :		; $(error No binary name set on the Makefile)
endif

.PHONY: clean, fclean, re, auto, show, auto, auto_valless, tests_run, debug, all
