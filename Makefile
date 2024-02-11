SOURCE_FOLDER := src
OBJECT_FOLDER := obj
INCLUDE_FOLDER := include
LIBRARY_FOLER := lib

SOURCE := $(wildcard $(SOURCE_FOLDER)/*.cpp)
OBJECT := $(patsubst $(SOURCE_FOLDER)/%.cpp,$(OBJECT_FOLDER)/%.o,$(SOURCE))
HEADER := $(wildcard $(INCLUDE_FOLDER)/game/*.hpp)

SFML_LINK_FLAGS := -lraylib -lopengl32 -lgdi32 -lwinmm
INCLUDE_FLAGS := -I$(INCLUDE_FOLDER) -I$(INCLUDE_FOLDER)/game -I$(INCLUDE_FOLDER)/SFML

LINK := -L$(LIBRARY_FOLER) $(SFML_LINK_FLAGS)
EXE := main

all: $(OBJECT) $(HEADER)
	g++ $(OBJECT) -o $(EXE) $(LINK)

$(OBJECT_FOLDER)/%.o: $(SOURCE_FOLDER)/%.cpp $(INCLUDE_FOLDER)/%.h | $(OBJECT_FOLDER)
	g++ $(INCLUDE_FLAGS) -c $< -o $@

$(OBJECT_FOLDER):
	mkdir $(OBJECT_FOLDER)

.PHONY: clean
clean:
	@if exist $(OBJECT_FOLDER) (rmdir /s /q $(OBJECT_FOLDER))
	@del /Q *.exe 2>NUL
	$(info Removed "obj" folder)
	$(info Removed "exe" files)

.PHONY: info
info:
	$(info $(CXX))