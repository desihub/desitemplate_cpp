================
desitemplate_cpp
================

.. image:: https://travis-ci.org/desihub/desitemplate_cpp.png
    :target: https://travis-ci.org/desihub/desitemplate_cpp
    :alt: Test Status

.. image:: https://coveralls.io/repos/github/desihub/desitemplate_cpp/badge.svg?branch=master
    :target: https://coveralls.io/github/desihub/desitemplate_cpp?branch=master
    :alt: Coverage Status

Introduction
============

This repository is intended to be a template for other C/C++ repositories.

Product Name
============

The name of a software product should be short but descriptive.  You may be
stuck with it for a long time.

There is one important guideline when creating a new product.
**Don't choose a name that contains a hyphen!**  Automation will be
converting the product name into an environment variable, and shells don't
like environment variable names that contain hyphens.

Installing a Product
====================

DESI products should be installed with desiInstall.  desiInstall decides how
to perform an installation based on the files it finds in the top level of
the product directory (see below).

There may be situations where a product contains no code by design.  In this
case it should still contain a stripped-down top-level Makefile that
contains enough functionality to install the product, but otherwise
does nothing.

Versioning a Product
====================

DESI products should be able to report their versions through a standard
method.  For Python packages, the standard is to set the ``__version__``
variable in the top-level module, *e.g.* ``desiutil.__version__``.
For DESI products that are based on desiutil_, the ``__version__`` string
can be manipulated with ``python setup.py version``.

.. _desiutil: http://desiutil.readthedocs.io

This package demonstrates an equivalent technique for setting a version string.

* ``make version`` will update src/version.hpp, which is a one-line file
  that can be included in other header files.  It will contain something like::

      #define VERSION_STRING "0.0.1.dev8"

* ``make TAG=1.0.0 version`` will set the src/version.hpp file to a
  specific tag name.
* This package defines a function, ``desitemplate::version()`` that
  returns this version string.

You can copy this technique, or provide your own method for setting and
getting the version.

Testing a Product
=================

This package demonstrates how to integrate a C/C++ package with Travis_ and
Coveralls_.  The ``main.cpp`` file compiles to an executable that runs
simple unit tests, using the standard C-library ``assert()`` function.
Test coverage analysis requires ``gcov``, which is usually included by
default in the ``gcc`` compiler collection.

.. _Travis: https://travis-ci.org
.. _Coveralls: https://coveralls.io

Product Contents
================

Directory Structure
-------------------

A DESI product may contain these top-level directories.  It may contain
additional directories, but the directories listed here have special
meaning for desiInstall.

bin/
    This directory is only needed if the product contains executable code.
    If you do not have any scripts, and you are not planning to compile any
    C/C++ code to create an executable, you can omit this directory from your
    svn product.  This is more likely to be the case for Python-based products
    than for C/C++-based products.  If this directory is present, but empty,
    this is a signal to desiInstall that you intend to compile C/C++ code
    to create an executable binary.
doc/
    Contains high-level documentation of the software.  Typically, the code
    itself will contain its own documentation.  This area is for
    documentation that discusses the product as a whole.  Doxygen_ can and
    will process files placed in this directory.
    Doxygen_ documents should be .dox files.
etc/
    Contains small data and configuration files used by the code.  This does not
    mean you should be checking in large data files!  This directory also
    contains the template module file for the product.  If additional files
    are found in this directory, they will be installed automatically,
    independent of any Makefile.
lib/
    If this directory is present, even if it is empty, it is a signal to
    desiInstall that you intend to compile C/C++ code to produce a library
    (static or shared). *At this time we have not set a policy on include
    files (.h/.hpp) that may be required to use such libraries.*
pro/
    If this directory is present, support for IDL code will be added to the
    Module file.
src/
    Contains C/C++ code.

You should only create the directories you actually need.  For example,
if you are writing a pure C++ library, you don't need the bin directory.

.. _Doxygen: http://www.stack.nl/~dimitri/doxygen/

Top-level Files
---------------

README.rst Files
~~~~~~~~~~~~~~~~

Of course your product should have a README(.rst) file!  The preferred name and
format is ``README.rst``.  If your product lives on GitHub, it will automatically
be rendered!

If your product is in svn, be sure that the svn:mime-type property is set::

    svn propset svn:mime-type text/x-rst README.rst

This will allow Trac to render your README.rst file in HTML.  In fact, you should
set this mime-type for any and all .rst files that you have (in svn).

Makefile
~~~~~~~~

If your product is C/C++-based, at minimum you will need a top-level Makefile,
which should point to a Makefile in the ``src/`` directory.  This may suffice
for relatively simple C/C++-based products.  More complicated compiles will
require a configure file or the autotools files needed to generate a
configure file.

The Makefile will be called with ``make install``.  Helpful environment
variables such as ``WORKING_DIR`` and ``INSTALL_DIR`` will be supplied by
desiInstall.  In the example Makfile included with the template product,
``make install`` performs a ``make all`` automatically.

The Makefile should be prepared to handle the installation of
files and directories in ``INSTALL_DIR``.  That is, desiInstall won't try
to second-guess what files and directories you want to install.

Other Files
-----------

.module file
~~~~~~~~~~~~

In the etc/ directory is a file called ``desitemplate_cpp.module``.  This file is used to
create a module file for the product at install time.  It should be renamed
to the name of the product plus ``.module``.  It should be customized for
the needs of the product.  In particular, any packages that your product
depends on should be added to the module file.

src/Makefile
~~~~~~~~~~~~

It is assumed that most of the heavy-duty work of compiling a C/C++-based
product will take place in the src directory, and that the src/Makefile
will handle that compiling.  It should be set up (or created in a configure
stage) accordingly.  Libraries (shared or static) should be written to the
``lib/`` directory, and executables should be written to the ``bin/`` directory.

License
=======

desitemplate_cpp is free software licensed under a 3-clause BSD-style license. For details see
the ``LICENSE.rst`` file.
