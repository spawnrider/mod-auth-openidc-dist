FROM debian:wheezy
MAINTAINER hzandbelt@pingidentity.com

RUN apt-get clean && apt-get update
RUN apt-get install -y apt-utils curl
