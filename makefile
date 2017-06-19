INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj

CXX = clang++
CXXFLAGS = -I$(INC_DIR)
CXXVER = -std=c++11

DEPS = $(wildcard $(INC_DIR)/*.h)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(wildcard $(SRC_DIR)/*.cpp))

all : nqueens

nqueens : $(OBJS)
	@echo $(DEPS)
	@echo $(OBJS)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(CXXVER)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp $(DEPS)
	mkdir -p $(OBJ_DIR)
	$(CXX) -c -o $@ $< $(CXXFLAGS) $(CXXVER)
