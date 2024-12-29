# Modern Embedded Development Platform
This project serves as a starting platform for modern embedded development, based on a cortex-m7 processor. This project includes:

1. CMake + Ninja debug and release build configurations
2. ARM GNU toolchain support with Picolibc
3. ARM LLVM toolchain support with Picolibc
4. Dockerfile for cross-platform builds

## Building with Docker
To build the docker image, run the following:

    docker build -t medp:latest -f Dockerfile .

To run the container in a bash shell daemon, run the following:

    docker run -d -it --rm --name=medp --mount type=bind,source=.,target=/home/app medp:latest bash

To build the project, run the following:

    docker exec medp cmake . --preset ["Arm LLVM","Arm GNU"]
    docker exec medp cmake --build --preset ["Debug <configure_preset>", "Release <configure_preset>"]

