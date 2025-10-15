CXX = clang++ #compiler  
CXXFLAGS = -I includes #compiler flags
SOURCES = components/main.cpp language_processing/commands.cpp functionalities/checklist.cpp
TARGET = build/program #output dir 

$(TARGET): $(SOURCES) # build rule
	$(CXX) $(SOURCES) $(CXXFLAGS) -o $(TARGET)

clean: 
	rm -f $(TARGET) 

#run the program 
run: $(TARGET)
	./$(TARGET)