
SFML_PATH = C:/Libraries/SFML

INCLUDES = -I$(SFML_PATH)/include
LIBDIR = -L$(SFML_PATH)/lib
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

CXX = g++
CXXFLAGS = -std=c++17 $(INCLUDES)
LDFLAGS = $(LIBDIR) $(LIBS)

SRC = src/main.cpp
TARGET = libs/app

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	del $(TARGET).exe
