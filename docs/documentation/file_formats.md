# File formats

## Network file

The files containing a description of a model have the `*.net.alg` extension.
It is a basic text file with a specific format. The first line is filled with metadata.

### Metadata

Metadata are a sequence of data at the beginning of the file.
They are separated by one space and can be retrieved with the [`ALG_ReadMetadataFromFile()`](/references/alg_readmetadatafromfile) function.

For networks, metadata are (in this order) :

1. The input size (i.e. the number of inputs)
2. The number of layers

For instance, if the file describes a network with 10 inputs and 5 layers, the first line of the file should be like :

```
10 5
```

### Layers

After metadata, each line of the file represent a layer.
Each layer own units, and, units own weights and bias.

It means that a units is represented by a sequence of numbers describing the weights and end by number that represent the bias.
For instance, if you want to describe a unit with 3 weights of `0.234`, `1.456`, `-2.748` and a bias of `0` you should write :

```
0.234 1.456 -2.748 0
```

To add more than one unit to the layer, write a sequence of units like :

```
0.234 1.456 -2.748 0 0.234 1.456 -2.748 0
```

In the example above, you have a layer with two units with the same weights and the same bias but feel free to change them.

!!! danger "Bias"

    The bias must be at the end of the units weights sequence.