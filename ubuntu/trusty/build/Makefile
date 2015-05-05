all: upload

clean: deb-clean

upload: deb-copy
	scp *.deb zandbelt@mod-auth-openidc.org:/var/www/mod-auth-openidc.org/download

include ../../../Makefile.inc
