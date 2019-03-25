#define MAX 10

int a[MAX];
int rand_seed=10;
int rand();
int bubble_sort_b(int, int*);

int bubble_sort();
////
int bubble_sort()
{
    int i;

    /* fill array */
    for (i=0; i < MAX; i++)
    {
        a[i]=rand();
        printf("%d\n",a[i]);
    }

    bubble_sort_b(MAX, a);

    /* print sorted array */
    printf("--------------------\n");
    for (i=0; i < MAX; i++)
        printf("%d\n",a[i]);
}

////
int rand()
/* from K&R
   - produces a random number between 0 and 32767.*/
{
    rand_seed = rand_seed * 1103515245 +12345;
    return (unsigned int)(rand_seed / 65536) % 32768;
}

int bubble_sort_b(int m, int a[]){
	int t, x, y;
	/* bubble sort the array */
    for (x=0; x < m-1; x++)
        for (y=0; y < m-x-1; y++)
            if (a[y] > a[y+1])
            {
                t=a[y];
                a[y]=a[y+1];
                a[y+1]=t;
            }
}
