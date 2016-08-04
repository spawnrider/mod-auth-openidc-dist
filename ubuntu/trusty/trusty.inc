FROM ubuntu:14.04.1
MAINTAINER hzandbelt@pingidentity.com

# Ubuntu 14.04.1 LTS

RUN apt-get clean && apt-get update
RUN apt-get install -y apt-utils curl
