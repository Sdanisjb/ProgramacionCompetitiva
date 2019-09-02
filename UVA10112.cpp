#include <iostream>

using namespace std;

struct P {
	char c;
	int x, y;
} p[20];

inline double area(P & a, P & b, P & c) {
	double size = 0.5 * ((c.y - a.y) * (b.x - a.x) - (b.y - a.y) * (c.x - a.x));
	return size < 0 ? -size : size;
}

int main() {
	int n;
	while (cin>>n && n) {
		for (int i = 0; i < n; i++) {
			char c;
			int x, y;
			cin>>c>>x>>y;
			p[i].x = x;
			p[i].y = y;
			p[i].c = c;
		}
		char a, b, c;
		double max = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int k = j + 1; k < n; k++) {
					double size = area(p[i], p[j], p[k]);
					if (size > max) {
						bool in = false;
						for (int l = 0; l < n && !in; l++) {
							if (l == i || l == j || l == k) {
								continue;
							}
							in = (area(p[i], p[j], p[l]) + area(p[i], p[k], p[l]) + area(p[j], p[k], p[l]) == size);
						}
						if (!in) {
							max = size;
							a = p[i].c;
							b = p[j].c;
							c = p[k].c;
						}
					}
				}
			}
		}
		cout<<a<<b<<c<<endl;
	}
	return 0;
}

