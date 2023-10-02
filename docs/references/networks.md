## Network

### `ALG_Network`

**Type** : Structure

**Description** : The Network structure represent the entire neural network.

<<<<<<< HEAD
| Variable  | Type          | Accessibility | Description                         |
|-----------|---------------|---------------|-------------------------------------|
| _layers   | `ALG_Layer**` | Read Only     | An array the network layers         |
| _nbLayers | `int`         | Read Only     | The number of layers in the network |

---

### `ALG_CreateNetwork()`

**Type** : Function

**Prototype** : `Network *ALG_CreateNetwork(int inputSize)`
=======
| Variable     | Type     | Accessibility | Description |
|--------------|----------|---------------|-------------|

---

### `ALG_NetworkCreate()`

**Type** : Function

**Prototype** : `Network *ALG_NetworkCreate(int inputSize)`
>>>>>>> 06bc75c7962d99ddb5e24d1d73cc969058868712

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

<<<<<<< HEAD
### `ALG_AddLayerToNetwork()`

**Type** : Function

**Prototype** : `void ALG_AddLayerToNetwork(ALG_Network *n, size_t size)`
=======
### `ALG_NetworkAddLayer()`

**Type** : Function

**Prototype** : `void ALG_NetworkAddLayer(ALG_Network *n, size_t size)`
>>>>>>> 06bc75c7962d99ddb5e24d1d73cc969058868712

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

<<<<<<< HEAD
### `ALG_DestroyNetwork()`
=======
### `ALG_NetworkDestroy()`
>>>>>>> 06bc75c7962d99ddb5e24d1d73cc969058868712

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
<<<<<<< HEAD
| _nbUnits | `size_t`     | Read Only     | The number of units.              |

---

### `ALG_CreateLayer()`

**Type** : Function

**Prototype** : `ALG_Layer *ALG_CreateLayer(size_t size, ALG_Layer *previousLayer)`
=======
| _size    | `size_t`     | Read Only     | The number of units               |

---

### `ALG_LayerCreate()`

**Type** : Function

**Prototype** : `ALG_Layer *ALG_LayerCreate(size_t size, ALG_Layer *previousLayer)`
>>>>>>> 06bc75c7962d99ddb5e24d1d73cc969058868712

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

<<<<<<< HEAD
### `ALG_DestroyLayer()`

**Type** : Function

**Prototype** : `void ALG_DestroyLayer(ALG_Layer* l)`
=======
### `ALG_LayerDestroy()`

**Type** : Function

**Prototype** : `void ALG_LayerDestroy(ALG_Layer* l)`
>>>>>>> 06bc75c7962d99ddb5e24d1d73cc969058868712

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

<<<<<<< HEAD
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
=======
| Variable | Type      | Accessibility | Description                                  |
|----------|-----------|---------------|----------------------------------------------|
| output   | `double`  | Read/Write    | The computed output of the artificial neuron |
| _weights | `*double` | Read Only     | The weights values                           |
| _size    | `size_t`  | Read Only     | The number of weights                        |
| _bias    | `double`  | Read Only     | The computed bias                            |

---

### `ALG_UnitCreate()`

**Type** : Function

**Prototype** : `ALG_Unit *ALG_UnitCreate(size_t size)`
>>>>>>> 06bc75c7962d99ddb5e24d1d73cc969058868712

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

<<<<<<< HEAD
### `ALG_DestroyUnit()`

**Type** : Function

**Prototype** : `void ALG_DestroyUnit(ALG_Unit *u)`
=======
### `ALG_UnitDestroy()`

**Type** : Function

**Prototype** : `void ALG_UnitDestroy(ALG_Unit *u)`
>>>>>>> 06bc75c7962d99ddb5e24d1d73cc969058868712

**Description** : Free memory of a unit.

**Parameters**

| Parameter | Type        | Description          |
|-----------|-------------|----------------------|
| u         | `*ALG_Unit` | The unit to destroy. |

**Mutations and return**

Free the `u` pointer.