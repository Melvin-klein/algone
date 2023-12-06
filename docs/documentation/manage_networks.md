# Manage networks

A network is an [`ALG_Network`](/references/networks#alg_network) struct that refers to several layers.
It can be seen as a container for the entire network entity.

## Create networks

There are many ways of creating networks. How you do it depends on the situation you're in.

### Create network

If you already know the number of layer your network will have,
you can use the [`ALG_CreateNetwork()`](/references/networks#alg_createnetwork) method as follows :

```C
ALG_Network* n = ALG_CreateNetwork(100, 4)
```

The first parameter is the number of inputs (or features) and the second parameter is the number of layers in addition to the input layer.

### Create bare network

If you don't already know in advance the number of layers, you can create a bare network.
This is a network only filled with an input layer. You can add layer later with the [`ALG_CreateLayerInNetwork()`](/references/networks#alg_createlayerinnetwork) function.

```C
// Creates a network with 10 inputs 
ALG_Network* n = ALG_CreateBareNetwork(10);

// You can add layer later
// It creates a new layer of 100 units (neurons) at the end of the network.
ALG_CreateLayerInNetwork(n, 100);
```

### Create network from file

You can create networks from files with the `.model.alg` extension. To learn more about this file format, you should read the [file format documentation page](/documentation/file_formats).
To load a network from a file, use the [`ALG_CreateNetworkFromFile()`](/references/alg_createnetworkfromfile) function.

```C
FILE *file = fopen("path/to/basic_network.model.alg", "r");
ALG_Network* n = ALG_CreateNetworkFromFile(file);
```

## Train networks

!!! note ""
    
    This section is empty. Work in progress.

## Monitor networks

!!! note ""

    This section is empty. Work in progress.