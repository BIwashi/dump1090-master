FROM ubuntu:20.04
ENV DEBIAN_FRONTEND=noninteractive

# ubuntu 18.0.4で発生する問題回避 timezone 選択
RUN apt-get install -y tzdata
ENV TZ=Asia/Tokyo

WORKDIR /home/user

RUN apt-get update
RUN apt-get install -y build-essential 
RUN apt-get install -y git
RUN apt-get install -y cmake
RUN apt-get install -y make
RUN apt-get install -y vim
RUN apt-get install -y clang
RUN apt-get install -y libssl-dev
RUN apt-get install -y wget
RUN apt-get install -y
RUN apt-get install -y
RUN apt-get install -y
RUN apt-get install -y
RUN apt-get install -y
RUN apt-get install -y


RUN apt-get autoremove -y
