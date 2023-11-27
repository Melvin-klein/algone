# Welcome to Algone Library

Algone is a **machine learning** and **data science** library written in C.

Contributions are open and welcome for every one 😁

## Organisation of the documentation

* [Get started](#get-started) - Get an overview of how the library works.
* [Documentation](documentation/manage_data.md) - Discover all things Algone made possible.
* [Tutorials](tutorials/mnist.md) - Learn step by step how to solve toy machine learning problems.
* [References](references/networks.md) - Get the description of all available elements in Algone library.
* [Download](https://github.com/Melvin-klein/algone/releases) - Download the library.

## Get started

### Installation

!!! warning ""

    **Please, don't use Algone in production**. The library comes with any guarantee that it will work properly.

1. Follow the [Download](https://github.com/Melvin-klein/algone/releases) link and extract the archive.
2. Put header files in a folder and the `libalgone.a` in another one.
3. Include the `algone.h` header by writting `#include "algone.h"`
4. Specify folders where headers and lib are installed in your compilation command.

### Load Data

First, we must have data to train our neural network. You can load data from a CSV using the function `ALG_ReadCSV`.

```C
#include "algone.h"

ALG_DataFrame = ALG_ReadCSV("path/to/your/file.csv");
```

### Create the network

Algone have a multiple ways to create a neural network. In this example we start with a bare neural network.

```C
ALG_Network* n = ALG_CreateBareNetwork(10);
```