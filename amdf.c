#include <stdio.h>

#define NMAX 80000 //Número máximo de amostras
#define Ts 0.000125 //Tempo de amostragem
#define FMAX 70 //Frequência mínima a ser detectada
#define MMAX 500 //Máximo valor de atraso do sinal
//(int)(1/(FMAX*Ts))+1
#define abs(a) ((a) < 0 ? (a)*(-1) : (a))
#define min(a, b) ((a) < (b) ? (a) : (b))

typedef struct{
  int x;
  double y;
} Point;

int k;

void merge(Point *arr, int left, int mid, int right)
{
  int n1 = mid - left + 1;
  int n2 = right - mid;

  Point L[80000], R[80000];

  for(int i = 0; i < n1; i++)
    L[i] = arr[left + i];
  for(int j = 0; j < n2; j++)
    R[j] = arr[mid + 1 + j];

  int i = 0, j = 0;
  int k = left;

  while(i < n1 && j < n2) {
    if(L[i].y <= R[j].y) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while(i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while(j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergesort(Point *arr, int left, int right)
{
  if(left >= right) return;

  int mid = (right + left) / 2;
  mergesort(arr, left, mid);
  mergesort(arr, mid + 1, right);
  merge(arr, left, mid, right);
}

void vales_detectados(double *arr, int size, int window, Point *vales)
{
  k = 0;

  for(int i = window; i < size-window; i++) {
    __uint8_t flag = 1;

    for(int j = i-window; j <= i+window; j++) {
      if(j == i) continue;
      if(j < i) {
        if(arr[j] <= arr[i]) {
          flag = 0;
          break;
        }
      } else {
        if(arr[j] < arr[i]) {
          flag = 0;
          break;
        }
      }
    }

    if(flag) {
      vales[k].x = i;
      vales[k].y = arr[i];
      k++;
    }
  }
}

int main(void)
{
  double data[NMAX], AMDF[MMAX];

  int i = 0;
  while(scanf("%lf", &data[i]) != EOF) i++;

  int N = i+1;
  for(int m = 0; m < MMAX; m++) {
    AMDF[m] = 0;
    for(int i = m; i < N; i++)
      AMDF[m] += abs(data[i] - data[i-m]);

    AMDF[m] /= (N - m);
  }

  Point vales[MMAX];

  vales_detectados(AMDF, MMAX, 5, vales);

  mergesort(vales, 0, k-1); //ordena

  int minx = vales[0].x, count = 10;
  //printf("%lf %lf\n", vale.x*Ts, vale.y);
  for(int m = 0; m < k && m < count; m++) {
    //printf("%d %lf", AMDF[m].x, AMDF[m].y);
    minx = min(minx, vales[m].x);
  } 

  printf("%lf\n", 1/(minx*Ts));

  return 0;
}