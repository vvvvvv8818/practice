/* 14889 스타트와 링크 / 백트래킹 */

#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

void split();

int N;
int member[20][20];
vector < int > S;
vector < int > L;
int DIFF = 9999;
int S_score, L_score;

int main(void)
{
 int i, j ;
 scanf("%d", &N);
 
 for (i = 0; i < N; i++) {
  for (j = 0; j < N; j++) {
   scanf("%d", &member[i][j]);
  }
 }
 
 split();

 printf("%d", DIFF);
 return 0;
}

void split() {
 int start = 1;
 int end = 1;
 int i, j;
 // make start, end (N/2)
 for (i = 0; i < N / 2 - 1; i++) {
  start = start << 1;
  start += 1;
  end = end << 1;
  end += 1;
 }
 for (i = 0; i < N / 2; i++) {
  start = start << 1;
 }
 //printf("start:%d / end:%d\n", start, end);

 // for start~end
 for (; start >= end; start--) {
  S.clear();
  L.clear();

  for (i = 0; i < N; i++) {
   if (start & (1 << i)) {
    S.push_back(i);
    if (S.size() > N / 2) break;
   }
   else {
    L.push_back(i);
    if (L.size() > N / 2) break;
   }
  }
  


  if (S.size() == L.size()) {
   // print vector
   /*printf("[S]  [L]\n");
   for (i = 0; i < N / 2; i++)
    printf("%d  %d\n", S[i], L[i]);
    */
   // get score
   S_score = L_score = 0;
   for (i = 0; i < N / 2 - 1 ; i++) {
    for (j = i+1; j < N / 2; j++) {
     S_score += member[S[i]][S[j]] + member[S[j]][S[i]];
     L_score += member[L[i]][L[j]] + member[L[j]][L[i]];
    }
   }
  }

  abs(S_score - L_score) < DIFF ? DIFF = abs(S_score - L_score) : DIFF ;
  //printf("DIFF : %d\n", DIFF);
 }
 
} 

 

 
