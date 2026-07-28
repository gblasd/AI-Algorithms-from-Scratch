#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main() {
    MatrixXd housing_data(4, 2);
    housing_data << 1800, 3,
                    2400, 4,
                    1416, 2,
                    3000, 5;

    VectorXd prices(4);
    prices << 350000, 475000, 230000, 640000;

    MatrixXd ones = MatrixXd::Ones(housing_data.rows(), 1);
    MatrixXd X(housing_data.rows(), housing_data.cols() + 1);
    X << ones, housing_data;

    VectorXd coefficients = (X.transpose() * X).inverse() * X.transpose() * prices;

    VectorXd predicted_prices = X * coefficients;

    VectorXd residuals = prices - predicted_prices;

    ArrayXd centered = prices.array() - prices.mean();
    double sst = centered.square().sum();

    double ssr = residuals.squaredNorm();
    
    double r2 = 1 - (ssr / sst);

    cout << "Coefficients:\n" << coefficients.transpose() << endl;
    cout << "Predicted prices:\n" << predicted_prices.transpose() << endl;
    cout << "R^2: " << r2 << endl;

    return 0;
}

/*
How to run this code:
$clang++ -std=c++17 -I /opt/homebrew/include/eigen3 MLR.cpp -o MLR
$./main
*/