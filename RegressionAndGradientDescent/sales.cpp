#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <iomanip>

// using namespace std;

int main() {
    // Asume we have this data: hours of adviersement vs weekly sales
    std::vector<double> ad_hours = {10, 20, 30, 40, 50};            // independent variable : x
    std::vector<double> weekly_sales = {200, 420, 650, 800, 950};   // dependent variable   : y
    int n = ad_hours.size();

    // Using the formulas to calculate the slope (m) anf y-intercept (c)
    double mean_x = std::accumulate(ad_hours.begin(), ad_hours.end(), 0.0) / n;
    double mean_y = std::accumulate(weekly_sales.begin(), weekly_sales.end(), 0.0) / n;

    // Step 3: Calculate the coefficients
    double num = 0.0, den = 0.0;

    for (int i = 0; i < n; ++i) {
        num += (ad_hours[i] - mean_x) * (weekly_sales[i] - mean_y);
        den += (ad_hours[i] - mean_x) * (ad_hours[i] - mean_x); // ^2
    }

    double m = num / den; // slop of the line
    double c = mean_y - m * mean_x; // intercept

    // The model
    std::cout << "Model: Sales = " << std::fixed << std::setprecision(2) << c
              << " + " << m << "*Advertising_Hours" << std::endl;

    std::vector<double> y_pred(n);
    for (int i = 0; i < n; ++i) {
        y_pred[i] = c + m * ad_hours[i];
    } 

    return 0;
}