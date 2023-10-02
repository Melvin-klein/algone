## Matrix

### `ALG_Matrix`

**Type** : Structure

**Description** : A matrix.

| Variable | Type     | Accessibility | Description                                                                                                      |
|----------|----------|---------------|------------------------------------------------------------------------------------------------------------------|
| values   | `double` | Read/Write    | A 1D array that contains all the matrix's values.                                                                |
| _size    | `size_t` | Read Only     | An array that describe matrix size. First value is the number of rows. The second value is the number of columns |

---

<<<<<<< HEAD
### `ALG_CreateMatrix()`

**Type** : Function

**Prototype** : `ALG_Matrix *ALG_CreateMatrix(size_t rows, size_t columns, double v)`
=======
### `ALG_MatrixCreate()`

**Type** : Function

**Prototype** : `ALG_Matrix *ALG_MatrixCreate(size_t rows, size_t columns, double v)`
>>>>>>> 06bc75c7962d99ddb5e24d1d73cc969058868712

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

<<<<<<< HEAD
### `ALG_FillMatrix()`

**Type** : Function

**Prototype** : `void ALG_FillMatrix(ALG_Matrix *m, double v)`
=======
### `ALG_MatrixFill()`

**Type** : Function

**Prototype** : `void ALG_MatrixFill(ALG_Matrix *m, double v)`
>>>>>>> 06bc75c7962d99ddb5e24d1d73cc969058868712

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

<<<<<<< HEAD
### `ALG_DebugMatrix()`

**Type** : Function

**Prototype** : `void ALG_DebugMatrix(ALG_Matrix *m)`
=======
### `ALG_MatrixDebug()`

**Type** : Function

**Prototype** : `void ALG_MatrixDebug(ALG_Matrix *m)`
>>>>>>> 06bc75c7962d99ddb5e24d1d73cc969058868712

**Description** : Print information about the matrix in the console.

**Parameters**

| Parameter | Type          | Description          |
|-----------|---------------|----------------------|
| m         | `ALG_Matrix*` | The matrix to debug. |

**Mutations and return**

No mutations or return.

---

<<<<<<< HEAD
### `ALG_DestroyMatrix()`

**Type** : Function

**Prototype** : `void ALG_DestroyMatrix(ALG_Matrix *m)`
=======
### `ALG_MatrixDestroy()`

**Type** : Function

**Prototype** : `void ALG_MatrixDestroy(ALG_Matrix *m)`
>>>>>>> 06bc75c7962d99ddb5e24d1d73cc969058868712

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