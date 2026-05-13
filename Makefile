# Nombre del ejecutable
TARGET = app

# Compilador
CXX = g++

# Flags
CXXFLAGS = -std=c++11 -Wall

# Archivos fuente (.cc)
SRC = main.cc app.cc archivo.cc class_user.cc garaje.cc garaje_service.cc pago.cc

# Regla principal
all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Ejecutar
run: all
	./$(TARGET)

# Limpiar
clean:
	rm -f $(TARGET)