SOURCE_FOLDER := src
OBJECT_FOLDER := obj
INCLUDE_FOLDER := include
LIBRARY_FOLER := lib

C := .cpp
O := .o
H := .h

RAYLIB_LINK_FLAGS := -lraylib -lopengl32 -lgdi32 -lwinmm

SOURCE := $(wildcard $(SOURCE_FOLDER)/*$(C))
SOURCE += $(wildcard $(SOURCE_FOLDER)/*/*$(C))

OBJECT := $(patsubst $(SOURCE_FOLDER)/%$(C),$(OBJECT_FOLDER)/%$(O),$(SOURCE))
#OBJECT := $(addprefix $(OBJECT_FOLDER)/,$(notdir $(OBJECT)))

HEADER := $(wildcard $(INCLUDE_FOLDER)/*$(H))
HEADER += $(wildcard $(INCLUDE_FOLDER)/*/*$(H))

INCLUDE_FOLDERS := $(patsubst %/,%,$(sort $(wildcard $(dir $(HEADER)))))
OBJECT_FOLDERS := $(patsubst $(INCLUDE_FOLDER)%,$(OBJECT_FOLDER)%,$(INCLUDE_FOLDERS))

INCLUDE_FLAGS := $(addprefix -I,$(INCLUDE_FOLDERS))

LINK := -L$(LIBRARY_FOLER) $(RAYLIB_LINK_FLAGS)
EXE := main

all: $(OBJECT) $(HEADER)
	g++ $(OBJECT) -o $(EXE) $(LINK)

force: clean all

$(OBJECT_FOLDER)/%$(O): $(SOURCE_FOLDER)/%$(C) $(INCLUDE_FOLDER)/%$(H) | $(OBJECT_FOLDERS)
	g++ $(INCLUDE_FLAGS) -c $< -o $@

$(OBJECT_FOLDERS):
	$(foreach dir,$(OBJECT_FOLDERS),if not exist "$(dir)" mkdir "$(dir)" &&) echo

.PHONY: clean
clean:
	@if exist $(OBJECT_FOLDER) (rmdir /s /q $(OBJECT_FOLDER))
	@del /Q *.exe 2>NUL
	$(info Removed "obj" folder)
	$(info Removed "exe" files)

.PHONY: info
info:
	$(info $(OBJECT_FOLDERS))