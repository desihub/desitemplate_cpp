#
# Template Makefile for use with desiInstall.  You can assume that
# desiInstall will set these environment variables:
#
# WORKING_DIR   : The directory containing the svn export
# INSTALL_DIR   : The directory the installed product will live in.
# (PRODUCT)     : Where (PRODUCT) is replaced with the name of the
#                 product in upper case, e.g. DESITEMPLATE.  This should
#                 be the same as WORKING_DIR for typical installs.
#
# Use this shell to interpret shell commands, & pass its value to sub-make
#
export SHELL = /bin/sh
#
# This is like doing 'make -w' on the command line.  This tells make to
# print the directory it is in.
#
MAKEFLAGS = w
#
# This is a list of subdirectories that make should descend into.  Makefiles
# in these subdirectories should also understand 'make all' & 'make clean'.
# This list can be empty, but should still be defined.
#
SUBDIRS = src doc
#
# This section tests for the definition of WORKING_DIR and INSTAL_DIR.
#
ifndef WORKING_DIR
WORKING_DIR_CHECK = $(error WORKING_DIR is undefined!)
endif
ifndef INSTALL_DIR
INSTALL_DIR_CHECK = $(error INSTALL_DIR is undefined!)
endif
#
# This is a message to make that these targets are 'actions' not files.
#
.PHONY : doc all install clean version
#
# This should compile all code prior to it being installed.
#
all :
	$(WORKING_DIR_CHECK)
	@ for f in $(SUBDIRS); do if test -f $$f/Makefile; then $(MAKE) -C $$f all; fi; done
#
# This will compile Doxygen docs.
#
doc :
	@ if test -f doc/Makefile; then $(MAKE) -C doc all; fi
#
# This should handle the installation of files in $INSTALL_DIR.  Note that
# 'all' is a dependency of 'install'.
#
install : all
	$(INSTALL_DIR_CHECK)
	@ for f in $(SUBDIRS); do if test -f $$f/Makefile; then $(MAKE) -C $$f install; fi; done
#
# GNU make pre-defines $(RM).  The - in front of $(RM) causes make to
# ignore any errors produced by $(RM).
#
clean :
	- $(RM) *~ core
	@ for f in $(SUBDIRS); do $(MAKE) -C $$f clean ; done
#
# Enable 'make version' to update the version string.
# Do make TAG=0.1.2 version to set the tag explicity.
#
version :
	$(MAKE) -C src version
