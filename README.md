# Shape Detection Application

The ShapeDetection application is a C ++ app made with OpenCV. It has been built and tested on Linux (Ubuntu 18.04) with OpenCV as build dependancy in cmake (library). The enclosed documentation shows how the system is built using the GRASP patterns, and made modular using runtime configuration.

---

## Pre-conditions / Downloads

The following artifacts / tools are used by and included in the extension as-is:

- OpenCV: [http://docs.opencv.org/2.4/doc/tutorials/introduction/linux_install/linux_install.html](http://docs.opencv.org/2.4/doc/tutorials/introduction/linux_install/linux_install.html)

---

## Build

- cd Code/
- mkdir build
- cmake -S . -B build/
- cd build
- make
- ShapeDetection [Input img] (If kept empty, the webcam will be triggered)

---

## Author

- Tim Beeren: [https://github.com/TBeeren](https://github.com/TBeeren)




