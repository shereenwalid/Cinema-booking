#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int tnow = 870;
int t1[4];
int t2[4];
void reservation(int, int, char);
void display();
void system(int, char);
int x, y;
char f;
char ch;

const int SIZE = 4;
struct description
{
int h1;
int m1;
int h2;
int m2;
int cap1;
int cap2;
}movies[SIZE];
int main() {
fstream xy;
xy.open("task1.txt", ios::in);
if (xy.is_open()) {
for (int i = 0; i < SIZE; i++)
{
xy >> movies[i].h1 >> movies[i].m1 >> movies[i].h2 >> movies[i].m2 >> movies[i].cap1 >> movies[i].cap2;
}
xy.close();

}
else
cout << "can't be opened";

for (int i = 0; i < 4; i++) {
t1[i] = (movies[i].h1 * 60) + movies[i].m1;
}
for (int i = 0; i < 4; i++) {
t2[i] = (movies[i].h2 * 60) + movies[i].m2;
}
int num, x, y;
char ch{}, f;
cout << '\t' << '\t' << '\t' << '\t' << '\t' << "cinema booking" << endl;
cout << '\t' << '\t' << '\t' << '\t' << '\t' << "**************" << endl << endl;

display();
cin >> num;
while (num == 1 || num == 2) {

system(num, ch);
cin >> num;

}
if (num == 3)
{
exit(0);
}


return 0;

}
void reservation(int x, int y, char f) {
cout << " 1/ Knives Out " << endl << " 2/ The Lost City Of D " << endl << " 3/ Avengers: Endgame " << endl << " 4/ Uncharted " << endl;
cout << "please enter movie number :";
cin >> x;
cout << " number of tickets reserved : ";
cin >> y;
if (t1[x - 1] > tnow) {
int k = y;
if (movies[x - 1].cap1 >= k) {
cout << "Tickets successfully reserved thank you for booking with us ";
exit(0);
}
else if (movies[x - 1].cap1 > 0) {
cout << "the capacity available is : " << movies[x - 1].cap1 << endl << " do you wish to reserve ? enter k if you want to reserve or m if not ";
}
}
cin >> f;
if (f == 'k' || f == 'K') {
cout << "reserved ";
exit(0);
}
else if ((f == 'm' || 'M') && (t2[x - 1] > tnow)) {

cout << "First screening time can't be booked " << movies[x - 1].h2 << ":" << movies[x - 1].m2 << " available" << endl;
cout << " do you wish to reserve hall 2 ? enter k if you want to reserve or m if not " << endl;
cin >> f;
if (f == 'k' || f == 'K') {
if (movies[x - 1].cap2 >= y) {

cout << "reserved ";
exit(0);
}
else if (movies[x - 1].cap2 > 0) {
cout << "the capacity available at " << movies[x - 1].h2 << ":" << movies[x - 1].m2 << "is : " << movies[x - 1].cap2 << endl << " enter k if you want to reserve or m if not " << endl;
cin >> f;
}


if (f == 'k' || f == 'K') {
cout << "reserved ";
exit(0);
}
else if (f == 'm' || f == 'M') {
do {
cout << " please Press 'y' to go back to main menu "; cin >> ch;
} while (ch != 'y' && ch != 'Y');
cout << endl;
display();
}
}

}

else {
do {
cout << " there is no screening time available please Press 'y' to go back to main menu "; cin >> ch;
} while (ch != 'y' && ch != 'Y');
cout << endl; display();
}

}
void display() {

cout << "Main menu: " << endl << "**********" << endl << endl;
cout << "To display movies , type 1..." << endl << "To book your ticket, type 2..." << endl << "To exit , type 3..." << endl;
cout << "Type the number here: ";

}
void system(int num, char ch) {
if (num == 1) {
fstream file;
file.open("task2.txt");

if (file.fail()) {
cout << "unable to open file " << endl;
}
else
{
string s;
while (getline(file, s))
{
cout << s << endl;
}
file.close();
}

do {
cout << "please Press 'y' to go back to main menu "; cin >> ch;
} while (ch != 'y' && ch != 'Y');
cout << endl; display();



}
if (num == 2) {
reservation(x, y, f);

do {
cout << "please Press 'y' to go back to main menu "; cin >> ch;
} while (ch != 'y' && ch != 'Y');
cout << endl; display();

}

}
