FROM debian:wheezy
MAINTAINER hzandbelt@pingidentity.com

RUN echo \
    'deb http://ftp.nl.debian.org/debian/ wheezy main\n \
     deb http://ftp.nl.debian.org/debian/ wheezy-updates main\n \
     deb http://security.debian.org wheezy/updates main\n' \
    > /etc/apt/sources.list

RUN apt-get clean && apt-get --fix-missing update
RUN apt-get install -y apt-utils curl
