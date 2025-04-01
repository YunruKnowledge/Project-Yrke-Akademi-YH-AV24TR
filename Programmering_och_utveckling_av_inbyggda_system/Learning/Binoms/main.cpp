#include <iostream>
#include <string>

std::string formula(int n);

long long factorial(int n);

long long binomialVal(int n, int k);

int main(void) {
    std::cout << formula(3) << std::endl;
    return 0;
}

std::string formula(const int n) {
    std::string formula;

    if (n == 0) {
        formula = "1";
    } else {
        int temp_n = n;
        if (n < 0) {
            temp_n = -temp_n;
        }

        for (int k = 0; k <= temp_n; ++k) {
            const long long val{binomialVal(temp_n, k)};
            std::string term;

            if (val != 1) {
                term += std::to_string(val);
            }

            if (temp_n - k > 0) {
                term += "a";
                if (temp_n - k > 1) {
                    term += "^" + std::to_string(temp_n - k);
                }
            }

            if (k > 0) {
                if (temp_n - k > 0) term += " * ";
                term += "b";
                if (k > 1) {
                    term += "^" + std::to_string(k);
                }
            }

            if (!formula.empty()) {
                formula += " + ";
            }
            formula += term;
        }
    }

    return (n < 0) ? "1/(" + formula + ")" : formula;
}

long long factorial(const int n) {
    long long fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

long long binomialVal(const int n, const int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}
