## Structures

### `ALG_Network`

**Description** : The Network structure represent the entire neural network.

| Variable     | Type     | Description                   |
|--------------|----------|-------------------------------|

---

## Functions

### `ALG_NetworkCreate`

**Prototype** : `Network *ALG_NetworkCreate(int inputSize)`

**Description** : Create an artificial neural network with the first input layer.

**Parameters**

| Parameter    | Type     | Description                                                  |
|--------------|----------|--------------------------------------------------------------|
| inputSize    | `int`    | The number of artificial neurons (units) in the input layer. |

**Modifications and returns**

| Parameter | Type       | Description                                                |
|-----------|------------|------------------------------------------------------------|
|           | `Network*` | A pointer to the network structure that have been created. |

---

### `ALG_NetworkAddLayer`

**Prototype** : `void ALG_NetworkAddLayer(ALG_Network *n, size_t size)`

**Description** : Create and append a new layer to a network.

**Parameters**

| Parameter | Type           | Description                                          |
|-----------|----------------|------------------------------------------------------|
| n         | `*ALG_Network` | The network which is going to receive the new layer. |
| size      | `size_t`       | The number of units inside the layer                 |

**Modifications and returns**

| Parameter | Type       | Description                                                                  |
|-----------|------------|------------------------------------------------------------------------------|
| n         | `Network*` | The network has received a new layer and its size has been incremented by 1. |