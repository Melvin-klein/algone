# Goal
.DEFAULT_GOAL := libdebug

# Phony targets
.PHONY: libdebug librelease test utest build clean

# Compilation
CC = gcc
CCFLAGS = -Wall

# Directories and files
# Dossiers contenant les fichiers source
SRCDIR = src
TESTDIR = tests
BUILDDIR = build
BINDIR = bin

# Récupérer tous les fichiers source dans les dossiers spécifiés
SRCS = $(subst $(SRCDIR)/, , $(shell find $(SRCDIR) -name "*.c"))
OBJS = $(SRCS:%.c=%.o)
# Fichiers de tests
SRCS_T = $(subst $(TESTDIR)/, , $(shell find $(TESTDIR) -name "*.c"))
OBJS_T = $(SRCS_T:%.c=%.o)

# Commande pour créer les dossiers de sortie s'ils n'existent pas
MKDIR_P = mkdir -p

libdebug: build

build: $(patsubst %, $(BUILDDIR)/lib/%, $(OBJS))
	$(MKDIR_P) $(BINDIR)
	ar -crs $(BINDIR)/libalgone.a $^

$(BUILDDIR)/lib/%.o: $(SRCDIR)/%.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CCFLAGS) -c $< -o $@

$(BUILDDIR)/tests/%.o: $(TESTDIR)/%.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CCFLAGS) -c $< -o $@

tests_mac: clean build build_test_mac
	./$(BINDIR)/tests_algone

build_test_mac: $(patsubst %, $(BUILDDIR)/tests/%, $(OBJS_T))
	$(CC) -o $(BINDIR)/tests_algone $^ -L./bin -lalgone -lcheck -lm -lpthread

tests_ubuntu: build build_test_ubuntu
	./$(BINDIR)/tests_algone

build_test_ubuntu: $(patsubst %, $(BUILDDIR)/tests/%, $(OBJS_T))
	$(CC) -o $(BINDIR)/tests_algone $^ -L./bin -lalgone -lcheck -lm -lpthread -lsubunit

utests: build
	$(MKDIR_P) $(BUILDDIR)/utests
	$(CC) -c utests/main.c -o $(BUILDDIR)/utests/main.o
	$(CC) -o $(BINDIR)/utests_algone $(BUILDDIR)/utests/main.o -L./bin -lalgone
	./$(BINDIR)/utests_algone

wasm: build
	emcc -s FORCE_FILESYSTEM -s EXIT_RUNTIME=1 -s WASM=1 ./wasm/wrapper.c -o ./wasm/build/algone.js

clean:
	$(RM) -r $(BUILDDIR) $(BINDIR)
