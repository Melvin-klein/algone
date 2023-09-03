## Network

### `ALG_Network`

**Type** : Structure

**Description** : The Network structure represent the entire neural network.

| Variable  | Type          | Accessibility | Description                         |
|-----------|---------------|---------------|-------------------------------------|
| _layers   | `ALG_Layer**` | Read Only     | An array the network layers         |
| _nbLayers | `int`         | Read Only     | The number of layers in the network |

---

### `ALG_CreateNetwork()`

**Type** : Function

**Prototype** : `Network *ALG_CreateNetwork(int inputSize)`

**Description** : Create an artificial neural network with the first input layer.

**Parameters**

| Parameter    | Type     | Description                                                  |
|--------------|----------|--------------------------------------------------------------|
| inputSize    | `int`    | The number of artificial neurons (units) in the input layer. |

**Mutations and return**

| Case   | Name | Type       | Description                                                |
|--------|------|------------|------------------------------------------------------------|
| Return |      | `Network*` | A pointer to the network structure that have been created. |

---

### `ALG_AddLayerToNetwork()`

**Type** : Function

**Prototype** : `void ALG_AddLayerToNetwork(ALG_Network *n, size_t size)`

**Description** : Create and append a new layer to a network.

**Parameters**

| Parameter | Type           | Description                                          |
|-----------|----------------|------------------------------------------------------|
| n         | `*ALG_Network` | The network which is going to receive the new layer. |
| size      | `size_t`       | The number of units inside the layer                 |

**Mutations and return**

| Case     | Name | Type       | Description                                                                  |
|----------|------|------------|------------------------------------------------------------------------------|
| Mutation | n    | `Network*` | The network has received a new layer and its size has been incremented by 1. |

---

### `ALG_DestroyNetwork()`

**Type** : Function

**Prototype** : `void ALG_NetworkDestroy(ALG_Network* n)`

**Description** : Free memory of a network.

**Parameters**

| Parameter | Type           | Description          |
|-----------|----------------|----------------------|
| n         | `ALG_Network*` | The pointer to free. |

**Mutations and return**

| Case     | Name | Type           | Description       |
|----------|------|----------------|-------------------|
| Mutation | n    | `ALG_Network*` | Free the pointer. |

---

## Layer

---

### `ALG_Layer`

**Type** : Structure

**Description** : A Layer is a struct that contains units that are on the same depth in the network.

| Variable | Type         | Accessibility | Description                       |
|----------|--------------|---------------|-----------------------------------|
| _units   | `ALG_Unit**` | Read Only     | The units contained in the layer. |
| _nbUnits | `size_t`     | Read Only     | The number of units.              |

---

### `ALG_CreateLayer()`

**Type** : Function

**Prototype** : `ALG_Layer *ALG_CreateLayer(size_t size, ALG_Layer *previousLayer)`

**Description** : Create a new Layer.

**Parameters**

| Parameter     | Type         | Description                                                                |
|---------------|--------------|----------------------------------------------------------------------------|
| size          | `size_t`     | The number of units.                                                       |
| previousLayer | `ALG_Layer*` | The layer that will forward it's computed units values inside the network. |

**Mutations and return**

| Case   | Name | Type         | Description    |
|--------|------|--------------|----------------|
| Return |      | `ALG_Layer*` | The new layer. |

---

### `ALG_DestroyLayer()`

**Type** : Function

**Prototype** : `void ALG_DestroyLayer(ALG_Layer* l)`

**Description** : Free memory of a layer.

**Parameters**

| Parameter | Type         | Description          |
|-----------|--------------|----------------------|
| l         | `ALG_Layer*` | The pointer to free. |

**Mutations and return**

| Case     | Name | Type         | Description       |
|----------|------|--------------|-------------------|
| Mutation | l    | `ALG_Layer*` | Free the pointer. |

---

## Unit

---

### `ALG_Unit`

**Type** : Structure

**Description** : A Unit represent a network simple computational unit.

| Variable   | Type      | Accessibility | Description                                  |
|------------|-----------|---------------|----------------------------------------------|
| output     | `double`  | Read/Write    | The computed output of the artificial neuron |
| _weights   | `*double` | Read Only     | The weights values                           |
| _nbWeights | `size_t`  | Read Only     | The number of weights                        |
| _bias      | `double`  | Read Only     | The computed bias                            |

---

### `ALG_CreateUnit()`

**Type** : Function

**Prototype** : `ALG_Unit *ALG_CreateUnit(size_t size)`

**Description** : Create a new Unit.

**Parameters**

| Parameter | Type     | Description            |
|-----------|----------|------------------------|
| size      | `size_t` | The number of weights. |

**Mutations and return**

| Case   | Name | Type    | Description   |
|--------|------|---------|---------------|
| Return |      | `Unit*` | The new unit. |

---

### `ALG_DestroyUnit()`

**Type** : Function

**Prototype** : `void ALG_DestroyUnit(ALG_Unit *u)`

**Description** : Free memory of a unit.

**Parameters**

| Parameter | Type        | Description          |
|-----------|-------------|----------------------|
| u         | `*ALG_Unit` | The unit to destroy. |

**Mutations and return**

Free the `u` pointer.