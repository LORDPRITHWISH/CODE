#include <iostream>
#include <gmp.h>

void calculatePi(mpf_t pi, int n)
{
    mpf_t term;
    mpf_init(term);

    mpf_set_d(pi, 0.0);
    mpf_set_d(term, 1.0);

    for (int i = 0; i < n; ++i)
    {
        mpf_div_ui(term, term, 3);
        mpf_neg(term, term);
        mpf_add_ui(term, term, 1);
        mpf_div_ui(term, term, 2 * i + 1);
        mpf_add(pi, pi, term);
    }

    mpf_mul_ui(pi, pi, 4);

    mpf_clear(term);
}

int main()
{
    int precision = 800; // Set precision to 800 iterations
    mpf_t pi;
    mpf_init2(pi, 1000); // Set precision to 1000 bits

    calculatePi(pi, precision);
    gmp_printf("Approximation of Pi with %d iterations: %.800Ff\n", precision, pi);

    mpf_clear(pi);

    return 0;
}
