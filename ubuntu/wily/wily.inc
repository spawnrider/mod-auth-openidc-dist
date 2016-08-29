FROM ubuntu:wily
MAINTAINER hzandbelt@pingidentity.com

# Ubuntu 15.10

RUN apt-get clean && apt-get update
RUN apt-get install -y apt-utils curl
