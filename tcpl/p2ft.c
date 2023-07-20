/* Pointers to Functions and Types */

typedef struct _t1 {
	int a1;
	int a2;
	int (*tfp)(int x1, int x2);
} t1;

int f1(int x1, int x2) {
	return x1 + x2;
}
int f2(int x1, int x2) {
	return x1 - x2;
}

int main(void) {
	extern int printf(const char * x1, ...);

	t1 v1 = {
		.a1 = 5,
		.a2 = 7,
		.tfp = f1,
	}
	int (*fptr)(int x1, int x2) = f2;

	int v2 = v1.tfp(v1.a2, 9);
	int v3 = (*fptr)(8, v1.a1);
	// wrong: int var = v1.(*tfp)(1, 2);

	t1 * v4 = &v1;
	// wrong: t1 * v4 = v1, because:
	printf("%d\n", v1);
	printf("%p\n", &v1);

	return 0;
}
