#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <iomanip>

// using namespace std;

int main() {
    // Step 1: get the dataset
    std::vector<double> advertising_costs = {100, 200, 300, 400, 500};  // independent variable
    std::vector<double> sales = {300, 500, 600, 700, 800};              // dependet variable
    int n = advertising_costs.size();

    // Step 2: Compute the mean of x and y
    double mean_adv = std::accumulate(advertising_costs.begin(), advertising_costs.end(), 0.0) / n;
    double mean_sales = std::accumulate(sales.begin(), sales.end(), 0.0) / n;

    /*
    auto adv_begin = advertising_costs.end();
    std::cout << *adv_begin << std::endl;
    */

    // Step 3: Calculate the coefficients
    double num = 0.0, den = 0.0;

    for (int i = 0; i < n; ++i) {
        num += (advertising_costs[i] - mean_adv) * (sales[i] - mean_sales);
        den += (advertising_costs[i] - mean_adv) * (advertising_costs[i] - mean_adv);
    }

    double m = num / den;
    double c = mean_sales - m * mean_adv;

    // The model
    std::cout << "Model: Sales = " << std::fixed << std::setprecision(2) << c
              << " + " << m << "*Advertising_Costs" << std::endl;

    std::vector<double> y_pred(n);
    for (int i = 0; i < n; ++i) {
        y_pred[i] = c + m * advertising_costs[i];
    } 

    return 0;
}