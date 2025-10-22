#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define N	300
#define M	((N << 9) + 1)

void srand_() {
	struct timeval tv;

	gettimeofday(&tv, NULL);
	srand(tv.tv_sec ^ tv.tv_usec);
}

int rand_(int n) {
	return (rand() * 76543LL + rand()) % n;
}

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

struct V {
	int l, c;
} uu[M], vv[M * 2];

int compare(const void *a, const void *b) {
	struct V *u = (struct V *) a;
	struct V *v = (struct V *) b;

	return u->l != v->l ? u->l - v->l : u->c - v->c;
}

void sort(int m) {
	int i, j;
	struct V tmp;

	for (i = 0; i < m; i++) {
		j = rand_(i + 1);
		tmp = vv[i], vv[i] = vv[j], vv[j] = tmp;
	}
	qsort(vv, m, sizeof *vv, compare);
}

int main() {
	static int ll[N], cc[N];
	int n, m, m_, i, j, l, l_, a;
	struct V *u, *v;

	srand_();
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &l);
		l_ = 1;
		for (a = 2; a <= l / a; a++)
			if (l % a == 0) {
				l_ *= a;
				while (l % a == 0)
					l /= a;
			}
		l_ *= l;
		ll[i] = l_;
	}
	for (i = 0; i < n; i++)
		scanf("%d", &cc[i]);
	m = 0;
	u = &uu[m++];
	u->l = u->c = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			u = &uu[j];
			vv[j] = *u;
			v = &vv[m + j];
			v->l = gcd(u->l, ll[i]);
			v->c = u->c + cc[i];
		}
		m_ = m * 2;
		sort(m_);
		m = 0;
		for (j = 0; j < m_; j++)
			if (j == 0 || vv[j].l != vv[j - 1].l)
				uu[m++] = vv[j];
	}
	printf("%d\n", m >= 2 && uu[1].l == 1 ? uu[1].c : -1);
	return 0;
}
