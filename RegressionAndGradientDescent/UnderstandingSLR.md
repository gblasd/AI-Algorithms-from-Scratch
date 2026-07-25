# Understanding and Implementing Simple Linear Regression from Scratch

**Regression Analysis** is a powerful tool for modeling relationships between variables.

## Understading Regression

`Regression` is a superstar in the world of statistics, finance, investing, and Machine Learning, is our guide to predicting future outcomes. In the world of regression, there are two central provinces: Simple Linear Regression and Multiple Linear Regression.

## Basics of Simple Linear Regression

Within the kingdom of Simple Linear Regression, there's a strong belief that the two main characters (variables $x$ and $y$) share a linear relationship. It's as though they're tied with a together with a magical linear thread. Here's a look at their relationship script $y=c+m \cdot x$.

in this script, $c$ represents the Y-intercept, $m$ depicts the slop of the line, $y$ is our dependent variable (what we want to predict), and $x$ is an independent variable (the cause of the prediction).

## Mathematical Basis of Simple Linear Regression

The formula governing Simple Linear Regression revolves around minimizing residuals. Imagine residuals as the distance between the actual and predicted values of the dependent variable.

Let's uncover these magic spells:

$$m = \sum _{i=1}^N \frac{(x_i -\bar{x})(y_i - \bar{y})}{\sum _{i=1}^N (x_i - \bar{x})^2}$$

$$c = \bar{y} - m \cdot \bar{x}$$

In these formulas, $N$ represents the number of data points: $x$ refers to the x-coordinate of the points, and $y$ corresponds to the y-coordinates; $\bar{x}$ and $\bar{y}$ refer to the means of $x$ and $y$ values, respectively.