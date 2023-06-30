CC = g++
BUILD_DIR = build
SRC_DIR = src
INCLUDE_DIR = include
CFLAGS = -std=c++11 -I$(INCLUDE_DIR)
LINK_FLAGS = 

EXECUTABLE_FILE = simulation.out

OBJECTS = \
	$(BUILD_DIR)/Simulation.o \
	$(BUILD_DIR)/TCPConnection.o \
	$(BUILD_DIR)/Reno.o \
	$(BUILD_DIR)/NewReno.o \
	$(BUILD_DIR)/BBR.o
	

MainSensitivityList = \
	$(SRC_DIR)/Simulation.cpp \
	$(INCLUDE_DIR)/TCPConnection.hpp \
	$(INCLUDE_DIR)/Reno.hpp \
	$(INCLUDE_DIR)/NewReno.hpp \
	$(INCLUDE_DIR)/BBR.hpp


all: $(BUILD_DIR) $(EXECUTABLE_FILE)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/Simulation.o: $(MainSensitivityList)
	$(CC) $(CFLAGS) $(LINK_FLAGS) -c $(SRC_DIR)/Simulation.cpp -o $(BUILD_DIR)/Simulation.o

$(BUILD_DIR)/TCPConnection.o: $(NetworkSensitivityList)
	$(CC) $(CFLAGS) $(LINK_FLAGS) -c $(SRC_DIR)/TCPConnection.cpp -o $(BUILD_DIR)/TCPConnection.o

$(BUILD_DIR)/Reno.o: $(GraphSensitivityList)
	$(CC) $(CFLAGS) $(LINK_FLAGS) -c $(SRC_DIR)/Reno.cpp -o $(BUILD_DIR)/Reno.o

$(BUILD_DIR)/NewReno.o: $(GraphSensitivityList)
	$(CC) $(CFLAGS) $(LINK_FLAGS) -c $(SRC_DIR)/NewReno.cpp -o $(BUILD_DIR)/NewReno.o

$(BUILD_DIR)/BBR.o: $(GraphSensitivityList)
	$(CC) $(CFLAGS) $(LINK_FLAGS) -c $(SRC_DIR)/BBR.cpp -o $(BUILD_DIR)/BBR.o

$(EXECUTABLE_FILE): $(OBJECTS)
	$(CC) $(CFLAGS) $(LINK_FLAGS) $(OBJECTS) -o $(EXECUTABLE_FILE)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) *.o *.out