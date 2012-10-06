include Macros

SHELL = /bin/bash

RM          := rm -rf

EXEDIR      ?= .
EXENAME     ?= solve_euler

ifeq ($(DEVEL),1)
	CSHRFLAGS := $(CSHRFLAGS) $(DEVELFLAGS)
endif

ifeq ($(DEBUG),1)
	CSHRFLAGS := $(CSHRFLAGS) $(DEBUGFLAGS)
else
	CPPFLAGS  += -DNDEBUG
	CSHRFLAGS := $(CSHRFLAGS) -flto
	LDFLAGS   += -fuse-linker-plugin
endif

srcdir ?= ./src
blddir ?= ./bld

VPATH = .:$(blddir):$(srcdir):$(srcdir)/base:$(srcdir)/problems

INCDIRS = -I$(srcdir)/base -I$(srcdir)/include

CPPFLAGS += $(INCDIRS)

OBJS := main.o Problems.o prime.o Euler1.o Euler2.o Euler3.o Euler6.o

OBJS := $(addprefix $(blddir)/,$(OBJS))

DEPS := $(OBJS:.o=.d)

.PHONY: mkblddir clean all

.SUFFIXES:

$(blddir)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -MMD -MF $(patsubst %.o,%.d,$@) -c $< -o $@

$(blddir)/%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -MMD -MF $(patsubst %.o,%.d,$@) -c $< -o $@

all: mkblddir $(EXEDIR)/$(EXENAME)

mkblddir:
	@mkdir -p $(blddir)

$(EXEDIR)/$(EXENAME): $(OBJS)
	$(LINKER) $(LDFLAGS) $(CPPFLAGS) $(OBJS) -o $@

clean:
	$(RM) $(OBJS) $(DEPS) $(EXEDIR)/$(EXENAME)

-include $(DEPS)
