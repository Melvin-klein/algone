## Structures

### `ALG_Network`

**Description** : The Network structure represent the entire neural network.

| Variable     | Type     | Accessibility | Description |
|--------------|----------|---------------|-------------|

### `ALG_Unit`

**Description** : A Unit represent a network simple computational unit.

| Variable | Type      | Accessibility | Description                                  |
|----------|-----------|---------------|----------------------------------------------|
| output   | `double`  | Read/Write    | The computed output of the artificial neuron |
| _weights | `*double` | Read Only     | The weights values                           |
| _size    | `size_t`  | Read Only     | The number of weights                        |
| _bias    | `double`  | Read Only     | The computed bias                            |

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

---

### `ALG_UnitCreate`

**Prototype** : `ALG_Unit *ALG_UnitCreate(size_t size)`

**Description** : Create a new Unit.

**Parameters**

| Parameter | Type     | Description            |
|-----------|----------|------------------------|
| size      | `size_t` | The number of weights. |

**Modifications and returns**

| Parameter | Type    | Description   |
|-----------|---------|---------------|
|           | `Unit*` | The new unit. |

---

### `ALG_UnitDestroy`

**Prototype** : `void ALG_UnitDestroy(ALG_Unit *u)`

**Description** : Free memory of a unit.

**Parameters**

| Parameter | Type        | Description          |
|-----------|-------------|----------------------|
| u         | `*ALG_Unit` | The unit to destroy. |

**Modifications and returns**

No modifications or return.