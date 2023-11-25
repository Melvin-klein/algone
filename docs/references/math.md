## Matrix

### `ALG_Matrix`

**Type** : Structure

**Description** : A matrix.

| Variable | Type     | Accessibility | Description                                                                                                      |
|----------|----------|---------------|------------------------------------------------------------------------------------------------------------------|
| values   | `double` | Read/Write    | A 1D array that contains all the matrix's values.                                                                |
| _size    | `size_t` | Read Only     | An array that describe matrix size. First value is the number of rows. The second value is the number of columns |

---

### `ALG_CreateMatrix()`

**Type** : Function

**Prototype** : `ALG_Matrix *ALG_CreateMatrix(size_t rows, size_t columns, double v)`

**Description** : Create a matrix.

**Parameters**

| Parameter | Type     | Description                       |
|-----------|----------|-----------------------------------|
| rows      | `int`    | The number of rows.               |
| columns   | `int`    | The number of columns.            |
| v         | `double` | The value to init all the matrix. |

**Mutations and return**

| Case   | Name | Type          | Description                                              |
|--------|------|---------------|----------------------------------------------------------|
| Return |      | `ALG_Matrix*` | A pointer to the matrix structure that has been created. |

---

### `ALG_FillMatrix()`

**Type** : Function

**Prototype** : `void ALG_FillMatrix(ALG_Matrix *m, double v)`

**Description** : Fill all the matrix `m` with the value `v`.

**Parameters**

| Parameter | Type          | Description                              |
|-----------|---------------|------------------------------------------|
| m         | `ALG_Matrix*` | The matrix to fill.                      |
| v         | `double`      | The value to use for filling the matrix. |

**Mutations and return**

| Case     | Name | Type          | Description                                  |
|----------|------|---------------|----------------------------------------------|
| Mutation | m    | `ALG_Matrix*` | All the values of the matrix are set to `v`. |

---

### `ALG_DebugMatrix()`

**Type** : Function

**Prototype** : `void ALG_DebugMatrix(ALG_Matrix *m)`

**Description** : Print information about the matrix in the console.

**Parameters**

| Parameter | Type          | Description          |
|-----------|---------------|----------------------|
| m         | `ALG_Matrix*` | The matrix to debug. |

**Mutations and return**

No mutations or return.

---

### `ALG_DestroyMatrix()`

**Type** : Function

**Prototype** : `void ALG_DestroyMatrix(ALG_Matrix *m)`

**Description** : Free memory of the matrix `m`.

**Parameters**

| Parameter | Type          | Description         |
|-----------|---------------|---------------------|
| m         | `ALG_Matrix*` | The matrix to free. |

**Mutations and return**

| Case     | Name | Type          | Description       |
|----------|------|---------------|-------------------|
| Mutation | m    | `ALG_Matrix*` | Free the pointer. |

---

## Activation

---

### `ALG_Sigmoid()`

**Type** : Function

**Prototype** : `double ALG_Sigmoid(double x, double lambda)`

**Description** : Compute the sigmoid function with param `lambda`. The function is computed with the formula :

$$
f_{\lambda}(x) = \frac{1}{1 + e^{- \lambda x}}
$$

**Parameters**

| Parameter | Type     | Description                                |
|-----------|----------|--------------------------------------------|
| x         | `double` | The point where sigmoid must be evaluated. |
| lambda    | `double` | The sigmoid parameter.                     |

**Mutations and return**

| Case   | Name | Type     | Description        |
|--------|------|----------|--------------------|
| Return |      | `double` | The computed value |

---

## Cost functions

---

### `ALG_MeanSquaredError()`

**Type** : Function

**Prototype** : `double ALG_MeanSquaredError(double predictions[], double targets[], size_t batchSize)`

**Description** : Compute the mean squared function. It is computed with the formula :

$$
MSE(x) = \frac{1}{n} \sum_{i = 1}^{n}(Y_i - \hat{Y}_i)^2
$$

where $n$ is the number of predictions, $Y_i$ is the target prediction et $\hat{Y}_i$ is the predicted value.

**Parameters**

| Parameter   | Type       | Description                                                          |
|-------------|------------|----------------------------------------------------------------------|
| predictions | `double[]` | An array of predicted values. Must have the same size as `targets`   |
| targets     | `double[]` | An array of targets values. Must have the same size as `predictions` |
| batchSize   | `size_t[]` | The number of predictions.                                           |

**Mutations and return**

| Case   | Name | Type     | Description        |
|--------|------|----------|--------------------|
| Return |      | `double` | The computed value |