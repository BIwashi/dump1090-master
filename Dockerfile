FROM ubuntu:20.04
ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get upgrade -y

# ubuntu 18.0.4で発生する問題回避 timezone 選択
RUN apt-get install -y tzdata
ENV TZ=Asia/Tokyo

WORKDIR /home/user

RUN apt-get install -y build-essential 
RUN apt-get install -y git
RUN apt-get install -y cmake
RUN apt-get install -y make
RUN apt-get install -y vim
RUN apt-get install -y clang
RUN apt-get install -y libssl-dev
RUN apt-get install -y wget
RUN apt-get install -y pkg-config
RUN apt-get install -y librtlsdr-dev
RUN apt-get install -y rtl-sdr
RUN apt-get install -y iproute2
# RUN apt-get install -y
# RUN apt-get install -y


RUN apt-get autoremove -y
