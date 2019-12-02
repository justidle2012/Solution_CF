//1145A Thanos Sort 灭霸排序
//http://codeforces.com/problemset/problem/1145/A
#include <cstdio>
#include <algorithm>

const int MAXN = 20;
int data[MAXN] = {};

bool mycmp(int x, int y) {
    return x<y;
}

//灭霸排序，返回
int thanos_sort(int left, int right) {
    if (true == std::is_sorted(data+left, data+right, mycmp)) {
        return right-left;
    } else {
        int l = (right-left)/2;
        return std::max(thanos_sort(left, right-l), thanos_sort(left+l, right));
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int i;
    for (i=0; i<n; i++) {
        scanf("%d", &data[i]);
    }

    int ans = thanos_sort(0, n);

    printf("%d\n", ans);

    return 0;
}