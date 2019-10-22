# Cc-Collections
Provides tools to store data.

## Objects
- Array : Stores data linearly. The size can be changed by reallocation only (semi dynamic array). 

## Project Structure
- include : Header files
- src : Source files
- bin : Created after compilation
- tmp : Created in compilation

## Build
### Depedencies
- make
- g++
- ld (with gcc)
### Make
To build :
```shell
$ make
```
To build and run :
```shell
$ make run
```
To clean the project (removes temporary and executable files) :
```shell
$ make clean
```
To flush the project (removes only temporary files) :
```shell
$ make flush
```
