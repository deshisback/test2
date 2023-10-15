#include <iostream>
#include <ctime>

using namespace std;
int main() {
	srand(time(NULL));

	const short COUNTER = 10;
	double arr[COUNTER];
	unsigned int SumOfPoints = 0;

	for (int i = 0; i < COUNTER; i++) {
		
		cin >> arr[i]; // потом исправить на ввод пользователем
		arr[i] += ((double)rand()/RAND_MAX * 10) - 5;
	}

	for (int i = 0; i < COUNTER; i++) {
		
		cout << arr[i] << " ";

		if ((int)arr[i] & (1 << 31) || arr[i] < 0 && arr[i] > -1) {
			arr[i] += arr[i]* -2;
		}

		if (i % 2 == 1 && i != 0) {

			cout << endl;

			double val = sqrt(arr[i] * arr[i] + arr[i - 1] * arr[i - 1]);

			if (val >= 0 && val < 1) {
				SumOfPoints += 5;
			}

			else if (val >= 1 && val < 2) {
				SumOfPoints += 4;
			}

			else if (val >= 2 && val < 3) {
				SumOfPoints += 3;
			}

			else if (val >= 3 && val < 4) {
				SumOfPoints += 2;
			}

			else if (val >= 4 && val < 5) {
				SumOfPoints += 1;
			}
		}
	}
	cout << endl;

	for (int i = 0; i < COUNTER; i++) {

		cout << arr[i] << " ";

		if (i % 2 == 1 && i != 0) cout << endl;
	}
	cout << endl;

	cout << SumOfPoints << " ";
	if (SumOfPoints < 10) cout << "looser!";
}