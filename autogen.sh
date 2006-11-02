#! /bin/sh

PKG_NAME=gtksourceviewmm

srcdir=`dirname $0`
test "x$srcdir" = x && srcdir=.

origdir=`pwd`

if test -f "$srcdir/configure.ac" && \
   test -d "$srcdir/gtksourceview/src" && \
   test -d "$srcdir/gtksourceview/gtksourceviewmm"
then :; else
    echo "** Error **: Directory \`${srcdir}\' does not look like"
    echo "the top-level ${PKG_NAME} directory."
    exit 1
fi

(automake-1.9 --version) < /dev/null > /dev/null 2>&1 || {
	echo
	DIE=1
	echo "You must have automake installed to compile gtksourceviewmm."
	echo "Download the appropriate package for your distribution,"
	echo "or see http://www.gnu.org/software/automake"
}

MAKE=`which gnumake`
test -x "$MAKE" || MAKE=`which gmake`
test -x "$MAKE" || MAKE=`which make`

if "$MAKE" --version 2>/dev/null | grep "Free Software Foundation" >/dev/null 2>&1
then :; else
    echo "** Error **: You need GNU make to build gtksourceviewmm from CVS."
    echo "${MAKE} is not GNU make."
    exit 1
fi

echo "Found GNU make at ${MAKE}... good."

cd "$srcdir"

echo "Adding libtools."
libtoolize --automake || exit 1

echo "Building macros."
aclocal -I "$srcdir/scripts" $ACLOCAL_FLAGS || exit 1

#echo "Building config header."
#autoheader

echo "Building makefiles."
automake-1.9 --add-missing || exit 1

echo "Building configure."

autoconf || exit 1


enable_warnings=

case "$*" in
    *--enable-warnings*|*--disable-warnings*)
        ;;
    *)  # enable -Werror by default when building with gcc3
        ${CXX:-"g++"} --version 2>/dev/null | grep '(GCC) 3\.[0-9]\+\.[0-9]' >/dev/null 2>&1 \
            && enable_warnings='--enable-warnings=hardcore'
        ;;
esac

cd "$origdir"
rm -f config.cache

if test -z "$AUTOGEN_SUBDIR_MODE"
then
    echo "Running $srcdir/configure --enable-maintainer-mode" $enable_warnings "$@"
    "$srcdir/configure" --enable-maintainer-mode $enable_warnings "$@" || exit 1
    echo
    echo 'run "make"'
    echo
else
    echo
    echo 'run "./configure ; make"'
    echo
fi

exit 0

