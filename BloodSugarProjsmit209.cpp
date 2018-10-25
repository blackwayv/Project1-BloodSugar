/*
Joshua Smith
Project 1: Blood Sugar
COSC 2030
10-24-2018
*/
#include <iostream>
#include <string>
using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::stof;
float total(float array[]);

int main() {
	float maxw1 = 0.0,
		minw1 = LONG_MAX,
		maxw2 = 0.0,
		minw2 = LONG_MAX;
	int countw1 = 0,
		countw2 = 0;
	float week1[255] = { 0 },
		week2[255] = { 0 };
	cout << "Two Week Blood Sugar Tracker\nEnter a blood sugar reading, 'N' or 'Next' for 'Next day', 'D' or 'Day' for 'Daily summary', or 'W' or 'Week' for 'Weekly summary'" << endl;
	for (int i = 0; i < 7; i++) {
		float inputf = -1;
		string inputs = "";
		float day[255] = { 0 };
		bool next = false;
		float daymax = 0.0,
			daymin = LONG_MAX;
		int countd = 0;
		while (!next) {
			cout << ">";
			while (inputf <= 0) {
				cin >> inputs;
				if (inputs == "D" || inputs == "Day") {
					float sum = 0.0;
					for (int in = 0; in < countd; in++) {
						sum += day[in];
					}
					if (daymin == LONG_MAX) {
						cout << "Today, " << countd << " readings have been entered, " << daymax << " is the highest reading, 0 is the lowest reading, and " << total(day) << " is the total." << endl;
					}
					else {
						cout << "Today, " << countd << " readings have been entered, " << daymax << " is the highest reading, " << daymin << " is the lowest reading, and " << total(day) << " is the total." << endl;
					}
				}
				else if (inputs == "W" || inputs == "Week") {
					if (minw1 == LONG_MAX) {
						cout << "This week, " << countw1 << " readings have been entered, " << maxw1 << " is the highest reading, 0 is the lowest reading, and " << total(week1) << " is the total." << endl;
					}
					else {
						cout << "This week, " << countw1 << " readings have been entered, " << maxw1 << " is the highest reading, " << minw1 << " is the lowest reading, and " << total(week1) << " is the total." << endl;
					}
				}
				try {
					inputf = stof(inputs);
				}
				catch (...) {}
				if (inputf > 0) {
					day[countd] = inputf;
					if (inputf > daymax) {
						daymax = inputf;
					}
					if (inputf < daymin) {
						daymin = inputf;
					}
					if (inputf > maxw1) {
						maxw1 = inputf;
					}
					if (inputf < minw1) {
						minw1 = inputf;
					}

					week1[countw1] = inputf;
					countd++;
					countw1++;
				}
				if (inputs == "N" || inputs == "Next") {
					inputf = 1;
					next = true;
				}
			}
			inputf = -1;
			inputs = "";
		}
		if (daymin == LONG_MAX) {
			cout << "Yesterday, " << countd << " readings were entered, " << daymax << " was the highest reading, 0 was the lowest reading, and " << total(day) << " was the total." << endl;
		}
		else {
			cout << "Yesterday, " << countd << " readings were entered, " << daymax << " was the highest reading, " << daymin << " was the lowest reading, and " << total(day) << " was the total." << endl;
		}
	}
	cout << "Last week, " << countw1 << " readings were entered, " << maxw1 << " was the highest reading, " << minw1 << " was the lowest reading, and " << total(week1) << " was the total." << endl;
	for (int i = 0; i < 7; i++) {
		float inputf = -1;
		string inputs = "";
		float day[255] = { 0 };
		float daytotal = 0.0;
		bool next = false;
		float daymax = 0.0,
			daymin = LONG_MAX;
		int countd = 0;
		while (!next) {
			cout << ">";
			while (inputf <= 0) {
				cin >> inputs;
				if (inputs == "D" || inputs == "Day") {
					float sum = 0.0;
					for (int in = 0; in < countd; in++) {
						sum += day[in];
					}
					if (daymin == LONG_MAX) {
						cout << "Today, " << countd << " readings have been entered, " << daymax << " is the highest reading, 0 is the lowest reading, and " << total(day) << " is the total." << endl;
					}
					else {
						cout << "Today, " << countd << " readings have been entered, " << daymax << " is the highest reading, " << daymin << " is the lowest reading, and " << total(day) << " is the total." << endl;
					}
				}
				else if (inputs == "W" || inputs == "Week") {
					if (minw1 == LONG_MAX) {
						cout << "This week, " << countw2 << " readings have been entered, " << maxw2 << " is the highest reading, 0 is the lowest reading, and " << total(week2) << " is the total." << endl;
					}
					else {
						cout << "This week, " << countw2 << " readings have been entered, " << maxw2 << " is the highest reading, " << minw2 << " is the lowest reading, and " << total(week2) << " is the total." << endl;
					}
				}
				try {
					inputf = stof(inputs);
				}
				catch (...) {}
				if (inputf > 0) {
					day[countd] = inputf;
					if (inputf > daymax) {
						daymax = inputf;
					}
					if (inputf < daymin) {
						daymin = inputf;
					}
					if (inputf > maxw2) {
						maxw2 = inputf;
					}
					if (inputf < minw2) {
						minw2 = inputf;
					}
					week2[countw2] = inputf;
					countd++;
					countw2++;
				}
				if (inputs == "N" || inputs == "Next") {
					inputf = 1;
					next = true;
				}
			}
			inputf = -1;
			inputs = "";
		}
		if (daymin == LONG_MAX) {
			cout << "Yesterday, " << countd << " readings were entered, " << daymax << " was the highest reading, 0 was the lowest reading, and " << total(day) << " was the total." << endl;
		}
		else {
			cout << "Yesterday, " << countd << " readings were entered, " << daymax << " was the highest reading, " << daymin << " was the lowest reading, and " << total(day) << " was the total." << endl;
		}
	}
	cout << "Last week, " << countw2 << " readings were entered, " << maxw2 << " was the highest reading, " << minw2 << " was the lowest reading, and " << total(week2) << " was the total." << endl;
	system("pause");
	return 0;
}

float total(float array[]) {
	float total = 0.0;
	for (int i = 0; i < 255; i++) {
		total += array[i];
	}
	return total;
}