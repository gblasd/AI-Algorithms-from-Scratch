#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

int main() {
    // Step 1: get the dataset
    vector<double> x = {1, 2, 3, 4, 5};
    vector<double> y = {2, 4, 5, 4, 5};
    int n = static_cast<int>(x.size());

    // Step 2: Compute the mean of x and y
    double mean_x = accumulate(x.begin(), x.end(), 0.0) / n;
    double mean_y = accumulate(y.begin(), y.end(), 0.0) / n;

    // Step 3: Calculate the coefficients
    double num = 0.0, den = 0.0;
    for (int i = 0; i < n; ++i) {
        num += (x[i] - mean_x) * (y[i] - mean_y);
        den += (x[i] - mean_x) * (x[i] - mean_x);
    }

    double m = num / den;
    double c = mean_y - m * mean_x;

    // Our models is now ready to predict new values. Let's test it with a new input value.
    cout << "Mean x: " << mean_x << endl;
    cout << "Mean y: " << mean_y << endl;
    cout << "Model: y = " << c << " + " << m << "*x" << endl;
    return 0;
}