FROM ubuntu:trusty
MAINTAINER hzandbelt@pingidentity.com

# Ubuntu 14.04 LTS

RUN apt-get clean && apt-get --fix-missing update
RUN apt-get update && apt-get install -y apt-utils curl
