struct Mask {
	int inv(int mask, int n) {
		return (((1 << n) - 1)&(~mask));
	}
	bool cur(int pos, int mask) {
		return mask&(1 << pos);
	}
	int set1(int pos, int mask) {
		return mask | (1 << pos);
	}
	int set0(int pos, int mask) {
		return mask & (~(1 << pos));
	}
	int cntBits(int mask) {
		int cnt = 0;
		for (; mask != 0; mask >>= 1) {
			if (mask & 1) cnt++;
		}
		return cnt;
	}
} maskop;