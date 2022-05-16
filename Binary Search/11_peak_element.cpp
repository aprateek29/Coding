// this array is called biotonic array which has only 1(one) peak

#include <iostream>
using namespace std;

int main()
{

    int arr[] = {5, 10, 20, 46, 34, 30, 25, 20, 15};
    int s = sizeof(arr) / sizeof(arr[0]);

    int l = 1;
    int h = s - 2;
    int mid;

    // size > 2
    // check separately for first and last element

    while (l <= h)
    {
        mid = l + (h - l) / 2;
        if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
        {
            break;
        }
        else if (arr[mid] > arr[mid - 1])
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    cout << arr[mid] << " " << mid << endl;

    return 0;
}