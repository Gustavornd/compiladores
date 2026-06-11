CXX ?= g++
CXXFLAGS ?= -std=c++11 -Wall -Wextra -Wno-sign-compare
GRAM ?= 9

TARGET := compilador
BUILD_DIR := build
GRAM_DIR := src/src-gram$(GRAM)

# ---------------------------------------------------------
# AJUSTE NOS CAMINHOS DOS ARQUIVOS
# Apontando diretamente para os arquivos do diretório atual
# ---------------------------------------------------------
GRAM_FILE ?= gramatica-9/gramatica-9.site
TABELA_FILE ?= gramatica-9/tabela_lr1.conf
TOKENS ?= ins/in.tokens
PARAMS ?= ins/in.params
SAIDA ?= ins/saida.txt

CORE_SRCS := \
    src/sol.cpp \
    src/Arvore.cpp \
    src/Gramatica.cpp \
    src/Parser.cpp \
    src/TabelaLR1.cpp \
    src/debug-util.cpp \
    src/matriz-util.cpp

GRAM_SRCS := $(wildcard $(GRAM_DIR)/*.cpp)
SRCS := $(CORE_SRCS) $(GRAM_SRCS)
OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

.PHONY: all clean run run-salvar

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -I$(GRAM_DIR) -Isrc -MMD -MP -c $< -o $@

# ---------------------------------------------------------
# COMANDOS DE EXECUÇÃO
# ---------------------------------------------------------
run: $(TARGET)
	./$(TARGET) $(GRAM_FILE) $(TABELA_FILE) $(PARAMS) < $(TOKENS)

run-salvar: $(TARGET)
	./$(TARGET) $(GRAM_FILE) $(TABELA_FILE) $(PARAMS) < $(TOKENS) > $(SAIDA)

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

-include $(DEPS)