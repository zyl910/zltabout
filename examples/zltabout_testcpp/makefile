.PHONY : all clean

# flags
CC = g++
CFLAGS += -Wall -I../../src
#LDFLAGS += -L../../lib
#LIBS += -lglib

# args
RELEASE =0
UNICODE =0
BITS =
EXFLAGS =
#EXFLAGS = -std=c++98

# [args] 生成模式. 0代表debug模式, 1代表release模式. make RELEASE=1.
ifeq ($(RELEASE),0)
	# debug
	CFLAGS += -g
else
	# release
	CFLAGS += -O3 -DNDEBUG
	//CFLAGS += -O3 -g -DNDEBUG
endif

# [args] UNICODE模式. 0代表ansi模式, 1代表unicode模式. make UNICODE=1.
ifeq ($(UNICODE),0)
	# ansi
	CFLAGS +=
else
	# unicode
	CFLAGS += -D_UNICODE -DUNICODE
endif

# [args] 程序位数. 32代表32位程序, 64代表64位程序, 其他默认. make BITS=32.
ifeq ($(BITS),32)
	CFLAGS += -m32
else
	ifeq ($(BITS),64)
		CFLAGS += -m64
	else
	endif
endif

# [args] 扩展参数. make EXFLAGS="-mavx".
CFLAGS += $(EXFLAGS)


# makefile path.
vpath %.h ../../src
vpath %.c ../../src
vpath %.hpp ../../src
vpath %.cpp ../../src

# files
TARGETS = zltabout_testcpp
OBJS = zltabout_testcpp.o zltabout_c.o zltabout_cpp.o

all : $(TARGETS)

zltabout_testcpp : $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) $(LIBS)


zltabout_c.o : zltabout_c.c zltabout_c.h
	$(CC) -c $< $(CFLAGS)

zltabout_cpp.o : zltabout_cpp.cpp zltabout_cpp.hpp
	$(CC) -c $< $(CFLAGS)

zltabout_testcpp.o : zltabout_testcpp.cpp zltabout.h zltabout_c.h zltabout_cpp.hpp
	$(CC) -c $< $(CFLAGS)


clean :
	$(RM) $(OBJS) $(TARGETS) $(addsuffix .exe,$(TARGETS))

 
 