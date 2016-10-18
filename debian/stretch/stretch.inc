FROM debian:stretch
MAINTAINER hzandbelt@pingidentity.com

RUN echo \
    'deb http://ftp.us.debian.org/debian/ stretch main\n \
     deb http://ftp.us.debian.org/debian/ stretch-updates main\n \
     deb http://security.debian.org stretch/updates main\n' \
    > /etc/apt/sources.list

RUN apt-get clean && apt-get --fix-missing update
RUN apt-get install -y apt-utils curl
