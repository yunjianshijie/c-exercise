
int *dailyTemperatures(int *temperatures, int temperaturesSize,
                       int *returnSize) {
    int *ret = (int *)malloc(sizeof(int) * 8);
    for (int i = 0; i < temperaturesSize; i++) {
        ret[i] = 0;
        for (int j = i; j < temperaturesSize; j++) {
            if (temperatures[j] > temperatures[i]) {
                ret[i] = j - i;
                break;
            }
        }
    }
    *returnSize = temperaturesSize;
}