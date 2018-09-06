#include<stdio.h>
// binary Search
int erfen(int target, int left, int right, int list[]) {
    if (left <= right)  
        return -1;
    // when left<=right, means don't find target
    // so Just return.

    int half = (left + right)/2;
    // Between list[5:9],the middle is 7, Equals(5+9)/2
    
    if(target == list[half]) 
        return half;
        // find it. return the position.

    else if(target < list[half]) 
        return erfen(target, left, half-1, list);
        // smaller? find it on left side.

    else    
        return erfen(target, half+1, right, list);
        // bigger? find it on right side.
}


int main(void) {
    int li[10] = {2, 6, 7, 9, 14, 25, 36, 47, 58, 69};
    int re, tar;
    printf("input a Integer to find:");
    scanf("%d", &tar);
    re = erfen(tar, 0, 9, li);
    printf("%d\n", re);
    return 0;
}
