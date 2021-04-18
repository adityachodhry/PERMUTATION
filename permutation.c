// Display all the possible permutation of given string.

#include <stdio.h>
#include <string.h>

void perm(char *s, int a, int n);
void swap(char *c1, char *c2);

void main()
{
    char str[10];
    int n;
    printf("Enter the string:\n");
    scanf("%s", str);
    n = strlen(str);
    printf("All possible permutations:\n");
    perm(str, 0, n - 1);
}
void perm(char *s, int a, int n) // a = xyz , a = 0 , n = 2
{
    int j;
    if (a == n)
        printf("%s\n", s); // print xyz, yxz, zyx = xyz, xzy, yxz, yxz, yzx, zyx, zxy
    else
    {
        for (j = a; j <= n; j++)
        {
            swap((s + a), (s + j)); // s - base address
            perm(s, a + 1, n);
            swap((s + a), (s + j)); // backtracking
        }
    }
}
void swap(char *c1, char *c2)
{
    char temp;  // swaping x and y
    temp = *c1; // x
    *c1 = *c2;  // y
    *c2 = temp; // x
}