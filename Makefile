SOURCE_FOLDER := src
OBJECT_FOLDER := obj
INCLUDE_FOLDER := include
LIBRARY_FOLER := lib

C := .cpp
O := .o
H := .hpp

GCC := g++ -std=c++20

RAYLIB_LINK_FLAGS := -lraylib -lopengl32 -lgdi32 -lwinmm

SOURCE := $(wildcard $(SOURCE_FOLDER)/*$(C))
SOURCE += $(wildcard $(SOURCE_FOLDER)/*/*$(C))

OBJECT := $(patsubst $(SOURCE_FOLDER)/%$(C),$(OBJECT_FOLDER)/%$(O),$(SOURCE))

# Put const.o at the back, because it contains global variables
OBJECT := $(filter-out $(OBJECT_FOLDER)/const$(O), $(OBJECT)) $(OBJECT_FOLDER)/const$(O)

HEADER := $(wildcard $(INCLUDE_FOLDER)/*$(H))
HEADER += $(wildcard $(INCLUDE_FOLDER)/*/*$(H))

ONLY_HEADER := $(filter-out $(patsubst $(SOURCE_FOLDER)/%$(C),$(INCLUDE_FOLDER)/%$(H),$(SOURCE)),$(HEADER))

INCLUDE_FOLDERS := $(patsubst %/,%,$(sort $(wildcard $(dir $(HEADER)))))
OBJECT_FOLDERS := $(patsubst $(INCLUDE_FOLDER)%,$(OBJECT_FOLDER)%,$(INCLUDE_FOLDERS))

INCLUDE_FLAGS := $(addprefix -I,$(INCLUDE_FOLDERS))

LINK := -L$(LIBRARY_FOLER) $(RAYLIB_LINK_FLAGS)
EXE := main

all: $(OBJECT) $(HEADER)
	$(GCC) $(OBJECT) -o $(EXE) $(LINK)

force: clean all

$(OBJECT_FOLDER)/%$(O): $(SOURCE_FOLDER)/%$(C) $(INCLUDE_FOLDER)/%$(H) $(ONLY_HEADER) | $(OBJECT_FOLDERS)
	$(GCC) $(INCLUDE_FLAGS) -c $< -o $@

$(OBJECT_FOLDERS):
	$(foreach dir,$(OBJECT_FOLDERS),mkdir -p "$(dir)" &&) echo

.PHONY: clean
clean:
	$(RM) -r $(OBJECT_FOLDER)
	$(RM) *.exe

.PHONY: info
info:
	$(info $(OBJECT_FOLDERS))