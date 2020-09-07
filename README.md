# Macroroni and Keys 
![macroroni](https://raw.githubusercontent.com/hlfstr/macroroni/master/art/macroroni_128.png)

This is a cross-platform text expansion program written in C++ for modern systems.  

### Tested platforms
Linux - GNOME
MacOS - Catalina

## Building

Be sure to download the full source when attempting to build the application.  Inlcuded in the source tree is wxWidgets as a submodule, and thus it needs to be downloaded as well:

```sh
$ git clone --recursive https://github.com/hlfstr/macroroni
```

If you **did not** specify the `--recursive` line when you first cloned, then run this to download the full source:
```sh
$ git submodule update --init --recursive
```

From the top-level source directory of `macroroni`, create a build directory and run CMake:
```sh
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build
```

Then grab a cup of coffee!  wxWidgets can take a while to complete and build times will vary based on your machine.

On completion, you will have a file named `mak` in your build directory, this is your application!