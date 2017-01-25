FROM ubuntu:wily
MAINTAINER hans.zandbelt@zmartzone.eu

# Ubuntu 15.10

RUN apt-get clean && apt-get --fix-missing update
RUN apt-get update && apt-get install -y apt-utils curl
