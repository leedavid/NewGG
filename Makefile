CXX := clang++
CC := clang
LD := ld

SRC_DIR := I_GGX64
ARCH ?= x86_64

INCLUDE_PATHS += -I$(PWD)/I_GGX64 -I$(PWD)/endgame
COMMON_DEFS += $(INCLUDE_PATHS) -std=c++11 -O3
CCFLAGS-x86_64 = -msse -msse2 -msse3 -msse4.1 -msse4.2 
CCFLAGS-arm64 = -arch arm64
CCFLAGS += -stdlib=libc++ -Wno-shift-negative-value -Wno-c++11-extensions -Wno-switch $(CCFLAGS-$(ARCH)) $(COMMON_DEFS)
LDFLAGS += -lc++ -lpthread

objs :=

include $(SRC_DIR)/rules.mk

all: newgg

newgg: $(objs)
	$(CXX) $^ -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CCFLAGS) -o $@ -c $<

%.o: %.c
	$(CC) $(CCFLAGS) -o $@ -c $<

.PHONY: clean
clean:
	find . -name "*.o" -exec rm \{} \;
	 
