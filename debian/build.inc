RUN echo "Acquire::http::Timeout \"90\";" > /etc/apt/apt.conf.d/99timeout

RUN apt-get install -y build-essential devscripts dh-make pkg-config util-linux
RUN apt-get install -y gcc tar autoconf automake libtool
RUN apt-get install -y libssl-dev libcurl4-openssl-dev libjansson-dev libhiredis-dev libpcre3-dev apache2-dev check
