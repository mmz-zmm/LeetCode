mclass
Solution{public : int hIndex(vector<int> & citations){int n = citations.size();
int left = 0;
int right = n - 1;
int mid = 0;
while (left < right) {
    mid = left + (right - left) / 2;
    if (citations[mid] >= n - mid) {
        right = mid;
    } else {
        left = mid + 1;
    }
}

return citations[left] >= n - left ? n - left : 0;
}
}
;