# Development Environment for CSc 305

## Compilers and Build Environments

In order to successfully compile the source code that will be presented in the
labs and lectures, you will require the following tools installed in your
system:

* A C++ compiler. For Windows, use [Visual Studio Community
  2019](https://visualstudio.microsoft.com/vs/community/). For Linux, please
  make sure you have the GNU C++ compiler version 7.4 or above. Please note that
  LLVM Clang is **not** currently supported.
* [CMake](https://cmake.org/download/) version 3.12 or above,
* [Python](https://www.python.org/downloads/) 2.7+ or 3.x,
* [Git](https://git-scm.com/downloads).

The environment in the labs is currently setup to work correctly with your
assignments, and may be easier than manually setting things up in your own
machine.

Once you have everything setup, please refer to the instructions provided in lab
1 to compile and run the sample code provided in the labs. Lecture code will be
provided without the CMake scripts, but it can be easily added to an existing
project by just copying the code.

If you have any questions about setting up your computers, please come see me
after class, email me, or schedule an appointment.

## OpenGL Development

The course uses OpenGL core version 4.5 or 4.6. The support for OpenGL is
determined by your graphics card and your driver. If your card is not recent
enough, or if you do not have the latest driver version, you will be unable to
run the course code in your machine. This directory contains a simple tester
program to check if your computer supports the required version of OpenGL. If
the program runs without any errors, then your computer supports the required
OpenGL versions. If it does not, here are a few things you can try:

* Ensure you have the *latest* version of the driver for your graphics card
  installed.
* Check the website of the company who made your graphics card and check the
  highest OpenGL version that your card supports. If the maker says your card
  supports OpenGL 4.5+, then you are good to go.

If your card is unable to run OpenGL 4.5+, then you will have to work on the lab
computers. These have already been setup and support the version of OpenGL
required for this course.

If you have any questions about setting up your computers, please come see me
after class, email me, or schedule an appointment.
