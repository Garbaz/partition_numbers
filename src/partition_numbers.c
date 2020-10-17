#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gmp.h>

int main(int argc, char **argv) {
    if(argc <= 1) exit(-1);
    unsigned long max_n = strtoul(argv[1],NULL,10)+1;
    printf("§ Generating sign list...\n");
    char sign[max_n];
    memset(sign,0,sizeof(sign));
    unsigned long k = 0;
    unsigned long s = 0;
    while(k < max_n) {
        sign[k] = (s % 4 <= 1 ? +1 : -1);
        k += (s % 2 == 0 ? s/2 + 1 : s+2);
        s++;
    }
    printf("§ Creating mpz_t list...\n");
    mpz_t* part = (mpz_t*)malloc(sizeof(mpz_t)*max_n);
    printf("§ Generating partition numbers...\n");
    mpz_init_set_ui(part[0],1);
    gmp_printf("0 : %Zd\n",part[0]);
    for(unsigned long i = 1; i < max_n; i++) {
        mpz_init(part[i]);
        for(unsigned long j = 0; j < i; j++) {
            if(sign[j] == 1) {
                mpz_add(part[i],part[i],part[i-j-1]);
            } else if(sign[j] == -1) {
                mpz_sub(part[i],part[i],part[i-j-1]);
            }
        }
        gmp_printf("%lu : %Zd\n",i,part[i]);
    }
}
