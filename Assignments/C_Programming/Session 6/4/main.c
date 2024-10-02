#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

void sort_by_area(triangle* tr, int n)
{
 float* area = malloc(n * sizeof(float)); 
 float p;
    for(int i = 0; i < n; i++){
        p = (tr[i].a + tr[i].b + tr[i].c ) / 2.0;
        area[i] = sqrt(p * (p - tr[i].a) * (p - tr[i].b) * (p - tr[i].c));
    }

    double tempArea;
     triangle temp;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n ; j++){
            if(area[i] > area[j ]){
                temp = tr[j];
                tr[j] = tr[i];
                tr[i] = temp;

                tempArea = area[j];
                area[j] = area[i];
                area[i] = tempArea;
            }
        }
    }
}
int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}