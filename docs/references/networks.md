## Structures

### `Network`

**Description** : The Network structure represent the entire neural network.

| Variable     | Type          | Description
| ------------ | ------------- | ------------
| learningRate | `double` | Control the speed of learning

---

## Functions

### `ALG_NetworkCreate`

**Prototype** : `Network *ALG_NetworkCreate(int inputSize, double learningRate)`

**Description** : Create an artificial neural network with the first input layer.

**Parameters**

| Parameter    | Type          | Description
| ------------ | ------------- | ------------
| inputSize | `int` | The number of artificial neurons (units) in the input layer.
| learningRate | `double` | Control the speed of learning.

**Return**

| Parameter    | Type          | Description
| ------------ | ------------- | ------------
|  | `Network*` | A pointer to the network structure that have been created.
