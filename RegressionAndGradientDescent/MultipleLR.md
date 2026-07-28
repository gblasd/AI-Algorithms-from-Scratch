# Multiple Linear Regression - The Concept

**Multiple Linear Regression** builds upon the concept of Simple Linear Regression, accounting for more than once independent variable.

The Simple Linear Regression queation:

$$y = \beta_0 + \beta_1x$$

For Multiple Linear Regression, we add multiple independent variables $x_1, x_2, \dots x_m$ :

## Linear Algebra Bahind: Dataset Representation

Suppose we had $n$ data points (equations), each with $m$ features ($x$ values). Then $X$ would like:

$$
X = \begin{bmatrix}
1 & x_{1,1} & x_{1,2} & \dots & x_{1,m} \\
1 & x_{2,1} & x_{2,2} & \dots & x_{2,m} \\
\vdots & \vdots & \vdots & \ddots & \vdots \\
1 & x_{n,1} & x_{n,2} & \dots & x_{n,m}
\end{bmatrix}
$$

Each row represents the $m$ features for a single data point. Notice how we include a column of 1's the intercept (also called bias) of each equation.

For each row (equation), there is a corresponding $y$ value. So looks like:

$$
y = \begin{bmatrix}
y_1 \\
y_2 \\
\vdots \\
y_n
\end{bmatrix}
$$

The normal equation results in a vector:

$$
\begin{bmatrix}
\beta_1 \\
\beta_2 \\
\vdots \\
\beta_n
\end{bmatrix}
$$

## Linear Algebra Behind: Making a Prediction


Now, for any set of features $x_1$ though $x_m$, we can predict the $\hat{y}$ value as:

$$ \hat{y} = (1 \cdot \beta_0) + (\beta_1 \cdot x_1) + (\beta_2 \cdot x_2) + \dots + (\beta_m \dots x_m)$$

To calculate all the predictions at once, we take the dot product of $X$ and $\beta$

$$
y = \begin{bmatrix}
y_1 \\
y_2 \\
\vdots \\
y_n
\end{bmatrix} = 
\begin{bmatrix}
1 & x_{1,1} & x_{1,2} & \dots & x_{1,m} \\
1 & x_{2,1} & x_{2,2} & \dots & x_{2,m} \\
\vdots & \vdots & \vdots & \ddots & \vdots \\
1 & x_{n,1} & x_{n,2} & \dots & x_{n,m}
\end{bmatrix}
\begin{bmatrix}
\beta_0 \\
\beta_1 \\
\vdots \\
\beta_m
\end{bmatrix} = X \cdot \beta
$$


## Linear Algebra Behind: Math Solution

To implement Multiple Linear Regression, we'll leverage some Linear Algebra concepts. Using the Normal equation, we can calculate the coefficients for our regression equation:

$$ \beta = (X^TX)^{-1}X^{T}y $$

Where $X$ is matrix of features and $y$ is a vector of the target variable values. Like Simple Linear Regression, residuals (the difference between actual and predicted values) play a significant role. The smaller these residuals, the better the model fits.

## Implementing Multiple Regression from Scratch

We'll primarily rely on `Eigen` to handle numerical operations and matrices.

First, we set up our dataset:

```cpp
#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main() {
    MatrixXf X(5, 3);
    X << 73, 67, 43,
         91, 88, 64,
         87, 134, 58,
         102, 43, 37,
         69, 96, 70;

    VectorXf y(5);
    y << 56, 81, 119, 22, 103;
```

Next we calculate our matrix of coefficients, $\beta$, using the Normal Equation:

- Enhance our frame matrix, $X$, with an extra column of ones to account for the intercept:

```cpp
    MatrixXf X_b(X.rows(), X.cols() + 1);
    X_b << VectorXf::Ones(X.rows()), X;
```

Compute the coefficients $\beta$ using the Normal Equation:

```cpp
    VectorXf beta = (X_b.transpose() * X_b).inverse() * X_b.transpose() * y;
```

## Model's Performance Evaluation

After completing our model, we need to evaluate its performance. We use the coefficient of determination ($R^2$ score) for this purpose. It indicates how well our model fits the data. The formula is:

$$ R^2 = 1 - \frac{SS_{residuals}}{SS_{total}} $$

Here, $SS_{residuals}$ is the residual sum of squares, and $SS_{total}$ is the total sum of squares:

$$ R^2 = \sum_{i=1}^{n} (y_i - \hat{y_i})^2 $$

where $y_i$ are the observed values and $\hat{y_i}$ are the predicted values from the regression model.

$$ SS_{total} = \sum_{i=1}^{n} (y_i - \hat{y_i})^2 $$

where $y_i$ are the observed values and $\bar{y}$ is the mean of the observed data.

A higher $R^2$ value (closer to 1) indicates a better model fit.

```cpp
    VectorXf predictions = X_b * beta;
    float ss_residuals = (y - predictions).squaredNorm();
    float ss_total = (y.array() - y.mean()).square().sum();
    float r2_score = 1 - (ss_residuals / ss_total);

    cout << "R^2 Score: " << r2_score << endl;
    return 0;
}
```