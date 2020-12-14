#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef struct coupon {
    int value;
    int distanceToPureValue;
};

coupon coupons[1000];

int main()
{
     int min = INT_MAX;
    int couponMin = INT_MAX;
    int n = 0, pureValue = 0;
    scanf("%d %d", &n, &pureValue);
    for (int i = 0; i < n; i++) {
        scanf("%d", &coupons[i].value);
        coupons[i].distanceToPureValue = (int)abs(pureValue - coupons[i].value);

        if (coupons[i].distanceToPureValue < min) {
            min = coupons[i].distanceToPureValue;
            couponMin = coupons[i].value;
        }

        else if (min == coupons[i].distanceToPureValue) {
            if (coupons[i].value < couponMin)
                couponMin = coupons[i].value;
        }
    }

    cout << couponMin << endl;

   // cout << "Hello world!" << endl;
    return 0;
}