FROM debian:jessie
MAINTAINER hans.zandbelt@zmartzone.eu

RUN apt-get update && apt-get install -y apt-utils curl
