all: rpm-upload-i386

rpm-upload-i386: build
	docker run --rm -v $$PWD:/shared:rw -it $(BUILD_TAG) /bin/bash -c "cp /opt/rpmbuild/rpm/RPMS/i686/*.rpm /shared"
	scp *.rpm zandbelt@mod-auth-openidc.org:/var/www/mod-auth-openidc.org/download

clean: rpm-clean
	rm -f Dockerfile *.spec

include ../../../Makefile.inc
