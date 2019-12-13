#include "header.h"

int   ia[2];
int G[16384][256];
int G2[16384+2][256];

__attribute__((noinline))
void example14(int in[][256], int coeff[][256], int *result) {
  int k,j,i=0;
  for (k = 0; k < 2; k++) {
    int sum = 0;
    for (i = 0; i < 16384; i++)
        for (j = 0; j < 256; j++)
          sum += in[i+k][j] * coeff[i][j];

    result[k] = sum;
  }
}

int main(int argc,char* argv[]){
  init_memory(&ia[0], &ia[2]);
  init_memory(&G[0][0], &G[0][256]);
  init_memory(&G2[0][0],&G2[0][256]);
  BENCH("Example14",  example14(G2,G,ia), 256, digest_memory(&ia[0], &ia[2]));
  return 0;
}