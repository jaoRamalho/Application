# Diretório de destino para os arquivos .o
OBJ_DIR = obj

# Lista de todos os arquivos .cpp no diretório src
CPP_FILES := $(wildcard src/*.cpp)

# Lista de arquivos .o gerados a partir dos arquivos .cpp
OBJ_FILES := $(patsubst src/%.cpp,$(OBJ_DIR)/%.o,$(CPP_FILES))


# Compilação dos arquivos .cpp para arquivos .o
$(OBJ_DIR)/%.o: src/%.cpp
	g++ -c $< -o $@ -Iinclude \
	-Iinclude/nlohmann \
	-IQt/include \
	-IQt/include/QtCore \
	-IQt/include/QtGui \
	-IQt/include/QtWidgets \
	-IQt/include/QtNetwork \
	-IQt/include/QtSql \
	-IQt/include/QtXml \
	-IQt/include/QtMultimedia

# Regra padrão para construir o executável
all: compile link

compile: $(OBJ_FILES)

link:
	g++ $(OBJ_FILES) -o bin/main -LQt/lib -lQt6Core -lQt6Gui -lQt6Widgets -lQt6Network -lQt6Sql -lQt6Xml

# Limpar os arquivos .o e o executável
clean:
	rm -rf $(OBJ_DIR)/*.o bin/main