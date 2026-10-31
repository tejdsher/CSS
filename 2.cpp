#include <iostream>
using namespace std;

struct Order {
    int orderID;
    int deliveryTime;
};

void merge(Order a[], int low, int mid, int high) {
    Order temp[100];
    int i = low, j = mid + 1, k = 0;

    while (i <= mid && j <= high) {
        if (a[i].deliveryTime <= a[j].deliveryTime)
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= high)
        temp[k++] = a[j++];

    for (i = low, k = 0; i <= high; i++, k++)
        a[i] = temp[k];
}

void mergeSort(Order a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);

        merge(a, low, mid, high);
    }
}

int main() {
    Order a[100];
    int n;

    cout << "Enter number of orders: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter Order ID and Delivery Time: ";
        cin >> a[i].orderID >> a[i].deliveryTime;
    }

    mergeSort(a, 0, n - 1);

    cout << "\nOrders sorted by delivery time:\n";

    for (int i = 0; i < n; i++) {
        cout << "Order ID: " << a[i].orderID
             << " Delivery Time: " << a[i].deliveryTime
             << " minutes\n";
    }

    return 0;
}