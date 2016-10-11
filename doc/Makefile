all : html/index.html
#
html/index.html : Doxyfile
	doxygen

instal :
	@ if test -d html; then \
		if ! test -d $(INSTALL_DIR)/doc/html; then \
			/bin/mkdir -p $(INSTALL_DIR)/doc/html; fi; \
		/bin/cp -Rvf $(WORKING_DIR)/doc/html $(INSTALL_DIR)/doc/html/doxygen; fi

clean :
	- $(RM) -r html latex
