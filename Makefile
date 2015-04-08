CXX = g++
GTEST_DIR = /usr/src/gtest
GTEST_LIB_DIR = /usr/lib
CPPFLAGS += -isystem $(INCLUDE_DIR) $(GTEST_DIR)/include
CXXFLAGS += -g -Wall -Wextra -pthread -std=c++11
TESTS = test
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h $(GTEST_DIR)/include/gtest/internal/*.h
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h
TEST_DIR = ./tests/src
SANDBOX_ROOT = ~/ClionProjects/Sandbox
INCLUDE_DIR = $(SANDBOX_ROOT)/include
SOURCE_DIR = $(SANDBOX_ROOT)/src


sandbox_include = $(INCLUDE_DIR)/CollectibleTile.h \
	$(INCLUDE_DIR)/Event.h \
	$(INCLUDE_DIR)/Game.h \
	$(INCLUDE_DIR)/GameLoop.h \
	$(INCLUDE_DIR)/Map.h \
	$(INCLUDE_DIR)/Tile.h \
	$(INCLUDE_DIR)/Tileset.h \
	$(INCLUDE_DIR)/Video.h 

sandbox_source = $(SOURCE_DIR)/CollectibleTile.cpp \
	$(SOURCE_DIR)/Event.cpp \
	$(SOURCE_DIR)/Game.cpp \
	$(SOURCE_DIR)/GameLoop.cpp \
	$(SOURCE_DIR)/Map.cpp \
	$(SOURCE_DIR)/Tile.cpp \
	$(SOURCE_DIR)/Tileset.cpp \
	$(SOURCE_DIR)/Video.cpp \
	$(SOURCE_DIR)/main.cpp 

all: $(TESTS)

clean:
	rm -f $(TESTS) *.o *.a; rm -rf build

gtest-all.o: $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o: $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c $(GTEST_DIR)/src/gtest_main.cc

gtest.a: gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a: gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

first_test.o: $(TEST_DIR)/first_test.cpp 
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(TEST_DIR)/first_test.cpp

sandbox.o: $(sandbox_source) $(sandbox_include)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(sandbox_source)

test: sandbox.o first_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@; ./test
