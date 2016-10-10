FROM debian:jessie
MAINTAINER hzandbelt@pingidentity.com

RUN echo \
    'deb http://ftp.nl.debian.org/debian/ jessie main\n \
     deb http://ftp.nl.debian.org/debian/ jessie-updates main\n \
     deb http://security.debian.org jessie/updates main\n' \
    > /etc/apt/sources.list

RUN apt-get clean && apt-get update
RUN apt-get install -y apt-utils curl
