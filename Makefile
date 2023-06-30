CC = g++
BUILD_DIR = build
SRC_DIR = src
INCLUDE_DIR = include
CFLAGS = -std=c++11 -I$(INCLUDE_DIR)
LINK_FLAGS = 

EXECUTABLE_FILE1 = renosimulation.out
EXECUTABLE_FILE2 = newrenosimulation.out
EXECUTABLE_FILE3 = bbrsimulation.out 

OBJECTS1 = \
	$(BUILD_DIR)/RenoSimulation.o \
	$(BUILD_DIR)/TCPConnection.o \
	$(BUILD_DIR)/Reno.o \

OBJECTS2 = \
	$(BUILD_DIR)/NewRenoSimulation.o \
	$(BUILD_DIR)/TCPConnection.o \
	$(BUILD_DIR)/NewReno.o \

OBJECTS3 = \
	$(BUILD_DIR)/BBRSimulation.o \
	$(BUILD_DIR)/TCPConnection.o \
	$(BUILD_DIR)/BBR.o


TCPConnectionSensitivityList = \
	$(SRC_DIR)/TCPConnection.cpp \
	$(INCLUDE_DIR)/TCPConnection.hpp \


RenoSensitivityList = \
	$(SRC_DIR)/RenoSimulation.cpp \
	$(SRC_DIR)/Reno.cpp \
	$(INCLUDE_DIR)/TCPConnection.hpp \
	$(INCLUDE_DIR)/Reno.hpp

NewRenoSensitivityList = \
	$(SRC_DIR)/NewRenoSimulation.cpp \
	$(SRC_DIR)/NewReno.cpp \
	$(INCLUDE_DIR)/TCPConnection.hpp \
	$(INCLUDE_DIR)/NewReno.hpp

BBRSensitivityList = \
	$(SRC_DIR)/BBRSimulation.cpp \
	$(SRC_DIR)/BBR.cpp \
	$(INCLUDE_DIR)/TCPConnection.hpp \
	$(INCLUDE_DIR)/BBR.hpp




all: $(BUILD_DIR) $(EXECUTABLE_FILE1) $(EXECUTABLE_FILE2) $(EXECUTABLE_FILE3)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/RenoSimulation.o: $(RenoSensitivityList)
	$(CC) $(CFLAGS) $(LINK_FLAGS) -c $(SRC_DIR)/RenoSimulation.cpp -o $(BUILD_DIR)/RenoSimulation.o

$(BUILD_DIR)/NewRenoSimulation.o: $(NewRenoSensitivityList)
	$(CC) $(CFLAGS) $(LINK_FLAGS) -c $(SRC_DIR)/NewRenoSimulation.cpp -o $(BUILD_DIR)/NewRenoSimulation.o

$(BUILD_DIR)/BBRSimulation.o: $(BBRSensitivityList)
	$(CC) $(CFLAGS) $(LINK_FLAGS) -c $(SRC_DIR)/BBRSimulation.cpp -o $(BUILD_DIR)/BBRSimulation.o


$(BUILD_DIR)/TCPConnection.o: $(TCPConnectionSensitivityList)
	$(CC) $(CFLAGS) $(LINK_FLAGS) -c $(SRC_DIR)/TCPConnection.cpp -o $(BUILD_DIR)/TCPConnection.o

$(BUILD_DIR)/Reno.o: $(RenoSensitivityList)
	$(CC) $(CFLAGS) $(LINK_FLAGS) -c $(SRC_DIR)/Reno.cpp -o $(BUILD_DIR)/Reno.o

$(BUILD_DIR)/NewReno.o: $(NewRenoSensitivityList)
	$(CC) $(CFLAGS) $(LINK_FLAGS) -c $(SRC_DIR)/NewReno.cpp -o $(BUILD_DIR)/NewReno.o

$(BUILD_DIR)/BBR.o: $(BBRSensitivityList)
	$(CC) $(CFLAGS) $(LINK_FLAGS) -c $(SRC_DIR)/BBR.cpp -o $(BUILD_DIR)/BBR.o

$(EXECUTABLE_FILE1): $(OBJECTS1)
	$(CC) $(CFLAGS) $(LINK_FLAGS) $(OBJECTS1) -o $(EXECUTABLE_FILE1)

$(EXECUTABLE_FILE2): $(OBJECTS2)
	$(CC) $(CFLAGS) $(LINK_FLAGS) $(OBJECTS2) -o $(EXECUTABLE_FILE2)

$(EXECUTABLE_FILE3): $(OBJECTS3)
	$(CC) $(CFLAGS) $(LINK_FLAGS) $(OBJECTS3) -o $(EXECUTABLE_FILE3)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) *.o *.out