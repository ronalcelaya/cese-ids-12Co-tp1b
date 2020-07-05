SRC_DIR = ./src
INC_DIR = ./inc
OBJ_DIR = ./build/obj
BIN_DIR = ./build
DOC_DIR = ./build/docs

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC_FILES))

all: build_folders $(OBJ_FILES)
	@echo Building aplication
	@gcc $(OBJ_FILES) -o $(BIN_DIR)/app.out

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo Compiling source file $(notdir $(basename $<))
	@gcc -c $< -I$(INC_DIR) -o $@

doc: $(BIN_DIR) $(DOC_DIR)
	@echo Building documentation in $(DOC_DIR)
	@doxygen

clean:
	@echo Cleaning .o files
	@-rm $(OBJ_DIR)/*.o

clean-all:
	@echo Cleaning all generated files
	@-rm -rf $(BIN_DIR)

###############################################################################
# Creation of output folders
build_folders: $(BIN_DIR) $(LIB_DIR) $(OBJ_DIR) $(DOC_DIR)$(DPN_DIR) $(RST_DIR)\
 $(DOC_DIR)

$(OUT_DIR):
	@echo Creating output root folder
	@mkdir $(OUT_DIR)

$(BIN_DIR): $(OUT_DIR)
	@echo Creating output binaries folder
	@mkdir $(BIN_DIR)

$(OBJ_DIR): $(OUT_DIR)
	@echo Creating output objects folder
	@mkdir $(OBJ_DIR)

$(DOC_DIR): $(BIN_DIR)
	@echo Creating output documentation folder
	@mkdir $(DOC_DIR)
