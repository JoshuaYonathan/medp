FROM ubuntu:24.04

# Install required packages
RUN apt-get update && apt-get install -y
RUN apt-get install clang-tools -y
RUN apt-get install clang-tidy -y
RUN apt-get install clang-format -y
RUN apt-get install cmake -y
RUN apt-get install curl -y
RUN apt-get install gcc-arm-none-eabi -y
RUN apt-get install gdb-multiarch -y
RUN apt-get install make -y
RUN apt-get install ninja-build -y
RUN apt-get install picolibc-arm-none-eabi -y
RUN apt-get install tar -y
RUN apt-get install xz-utils -y

# Manually install LLVM toolchain for arm
WORKDIR /tmp
ARG llvm_name="arm-llvm-toolchain"
ARG llvm_ver="19.1.1"
RUN mkdir -p /usr/local/${llvm_name}/${llvm_ver}
RUN curl -fSL --progress-bar -o ${llvm_name}.tar.xz \
https://github.com/ARM-software/LLVM-embedded-toolchain-for-Arm/releases/download/release-${llvm_ver}/LLVM-ET-Arm-${llvm_ver}-Linux-x86_64.tar.xz 
RUN tar -xf ${llvm_name}.tar.xz --strip-components=1 -C /usr/local/${llvm_name}/${llvm_ver}
ENV PATH="$PATH:/usr/local/${llvm_name}/${llvm_ver}/bin"

WORKDIR /home/app
