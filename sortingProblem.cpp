#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void almostSorted(vector<int> arr)
{
    if (is_sorted(arr.begin(), arr.end()))
    {
        cout << "yes" << endl;
        return;
    }
    //  vector<int> arr = {4, 2};
    //  arr = {1,5,4,3,2,6};
    //  arr = {3,1,2};
    // for finding first wrong term
    int i = 0;
    while (arr[i] <= arr[i + 1])
    {
        i++;
    }
    // for second trying to iterate from last
    int j = arr.size() - 1;

    while (arr[j] > arr[j - 1])
    {
        j--;
    }
    // cout << "at this situation the value of i and j are " << i << " " << j << endl;
    // checking it can be done in one swap or not
    // if (i == (j - 1))
    // {
    //     swap(arr[i], arr[j]);
    //     cout << "yes" << endl;
    //     cout << "swap " << i << " " << j << endl;
    // }
    if (i < j)
    {
        swap(arr[i], arr[j]);

        if (is_sorted(arr.begin(), arr.end()))
        {
            cout << "yes34" << endl;
            cout << "swap " << i + 1 << " " << j + 1 << endl;
            return;
        }
        else
        {
            swap(arr[i], arr[j]);
            int a = i, b = j;
            if (is_sorted(arr.rbegin() + (arr.size() - j), arr.rbegin() + (arr.size() - i)))
            {
                // cout << "inside inner if" << endl;
                while (i < j)
                {
                    // cout << "in while" << endl;
                    swap(arr[i], arr[j]);
                    i++;
                    j--;
                }
                // for (int i = 0; i < arr.size(); i++)
                // {
                //     cout << arr[i] << endl;
                // }
                if (is_sorted(arr.begin(), arr.end()))
                {
                    cout << "yes" << endl;
                    cout << "reverse " << a + 1 << " " << b + 1 << endl;
                    return;
                }
                else{
                    cout << "no" << endl;
                }
            }
        }
    }
}
int main()
{
    vector<int> arr = {4, 2};
    // arr = {1, 5, 4, 3, 2, 6};
    arr = {3, 1, 2};
    almostSorted(arr);
    // almostSorted(arr);

    

    // cout<<arr[1];
    return 0;
}
