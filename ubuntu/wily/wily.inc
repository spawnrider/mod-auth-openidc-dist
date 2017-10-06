FROM ubuntu:wily
MAINTAINER hans.zandbelt@zmartzone.eu

# Ubuntu 15.10

RUN sed -i -e 's/archive.ubuntu.com/old-releases.ubuntu.com/g' /etc/apt/sources.list
RUN apt-get update && apt-get install -y apt-utils curl
