#
# Directories where binary code will live.  Be sure any environment
# variables are properly exported.
#
BIN := $(WORKING_DIR)/bin
LIB := $(WORKING_DIR)/lib
#
# Pass these flags to the C compiler
#
CPPFLAGS := -Wall -fPIC -fprofile-arcs -ftest-coverage
#
# Objects to compile
#
OBJECTS := most_recent_svn_tag.o get_svn_devstr.o svn_version.o \
	compare_version.o parse_version.o version.o
#
# By default, make uses this rule to compile individual objects. Override
# if necessary
#
# COMPILE.cc = $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c
# COMPILE.cpp = $(COMPILE.cc)
# OUTPUT_OPTION = -o $@
# %.o: %.cpp
#	$(COMPILE.cpp) $(OUTPUT_OPTION) $<
#
# Flags for the link stage.
#
LDLIBS := -L $(LIB) -l template
SOFLAGS := -shared -fPIC
#
# Set the shared library extension.  This is a simple way to get
# the appropriate extension on Mac OS.
#
SO := so
UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
	SO = dylib
	SOFLAGS = -dynamiclib
endif
#
# This is a message to make that these targets are 'actions' not files.
#
.PHONY : all clean install version
#
# Makefiles should always define this target.
#
all : $(BIN)/test_desitemplate_cpp
#
# This creates the executable.
#
$(BIN)/test_desitemplate_cpp: $(LIB)/libtemplate.$(SO) main.o
	@ if test ! -d $(BIN); then /bin/mkdir -p $(BIN); fi
	$(LINK.cc) main.o $(LOADLIBES) $(LDLIBS) -o $@
#
# This creates the library.
#
$(LIB)/libtemplate.$(SO): $(OBJECTS)
	@ if test ! -d  $(LIB); then /bin/mkdir -p $(LIB); fi
	$(LINK.cc) $(SOFLAGS) $^ $(LOADLIBES) -o $@
#
# Copy built executables and libraries to their final locations.
#
install : all
	/bin/mkdir -p $(INSTALL_DIR)/bin
	/bin/cp -vf $(BIN)/test_desitemplate_cpp $(INSTALL_DIR)/bin
	/bin/mkdir -p $(INSTALL_DIR)/lib
	/bin/cp -vf $(LIB)/libtemplate.$(SO) $(INSTALL_DIR)/lib
#
# GNU make pre-defines $(RM).  The - in front of $(RM) causes make to
# ignore any errors produced by $(RM).
#
clean :
	- $(RM) $(LIB)/libtemplate.$(SO) $(BIN)/test_desitemplate_cpp *.o *.gcno *.gcda *~ core
	- /bin/rmdir $(BIN) $(LIB)
#
# Enable 'make version' to update the version string.
# Do make TAG=0.1.2 version to set the tag explicity.
# LASTTAG and COUNT are defined inside the recipe so they
# only get defined when make version is invoked.
#
version :
	$(eval LASTTAG := $$(shell git describe --tags --dirty --always | cut -d- -f1))
	$(eval COUNT := $(shell git rev-list --count HEAD))
	- $(RM) version.hpp
	@ if test -n "$(TAG)"; then v=$(TAG); else v=$(LASTTAG).dev$(COUNT); fi; \
		echo "#define VERSION_STRING \"$$v\"" > version.hpp
