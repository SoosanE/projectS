//과제 #7, 12221487, 엄수산
//main.cpp
#include<iostream>
#include<iomanip> //quoted랑 setw사용위해서	
#include<string>
#include<fstream>
#include"Friend.h" //Friend라는 class 사용위해
#include"BestFriend.h"//BestFriend라는 class 사용위해
using namespace std;
const int MAXNOS = 100;//친구 정보를 저장할 수 있는 배열의 최대 크기 MAXNO를 100으로 지정하기위해서

int readFile(ifstream&, Friend[]); //function prototype
void sorting(Friend[], int);
void outputArray(Friend[], int);

int main() {
	cout << "# of Friends before defining Friend Array= " << Friend::getCount() << endl; //객체 개수 카운팅 :0
	Friend myFriends[MAXNOS];
	int noFriends;
	cout << "# of Friends after defining Friend Array= " << Friend::getCount() << endl; //객체 개수 카운팅: 100
	cout << "Size of myFriends[] = " << sizeof(myFriends) << endl;
	//파일을 통해서 데이터 입력	
	ifstream inFile("testMydude.txt", ios::in);
	if (!inFile) {
		cout << "입력 파일 없음";
		exit(1);
	}

	noFriends = readFile(inFile, myFriends);
	sorting(myFriends, noFriends);
	//cout << endl << "<< 정렬 이후의 데이터 출력 >>" << endl;
	//outputArray(myFriends, noFriends);

	//Friend firstF, secondF, thirdF;
	//firstF = myFriends[0];
	//Friend lastF(myFriends[noFriends - 1]);

	/*cout << "\n공란으로 항목 구분하여 한 라인에 2명의 친구 정보를 입력하세요!" << endl;
	cin >> secondF >> thirdF;
	cout << "\n\n 방금전에 입력한 2명의 친구 정보 \n\n" << secondF << thirdF << endl;
	cout << "정렬된 배열의 첫 친구와 마지막 친구 정보 \n\n" << firstF << lastF << endl;
	cout << "# of Friends at the end of main()= " << lastF.getCount() << endl;*/

	BestFriend bF1, bF2;
	cout << "\n공란으로 항목 구분하여 2명의 BestFriend 정보를 입력하세요! " << endl;
	cin >> bF1 >> bF2;
	cout << "\n\n방금 전에 입력한 2명의 BestFriend 정보\n\n" << bF1<<bF2<<endl;

	bF1 = bF2;
	cout << "\n\n변경한 두명의 BestFriend 정보 \n\n" << bF1 << bF2 << endl;
	cout << "# of Best Friends at the end of main() = " << BestFriend::getBestFriendCount() << endl;
	return 0;
}


int readFile(ifstream& inFile, Friend myFriends[]) {
	int count = 0;
	string name; //이름 변수
	int age; //나이 변수
	float gpa; //gpa 변수
	string pnumber; //휴대폰 번호 변수
	while (inFile >> name >> age >> gpa >> pnumber) { //파일로부터 정보를 입력받는다.
		myFriends[count].setName(name); //배열[index]에 이름 변환
		myFriends[count].setAge(age);
		myFriends[count].setGPA(gpa);
		myFriends[count].setPnumber(pnumber);
		cout << left << name << ", " << age << ", " << gpa << ", " << pnumber << endl; //유저에게 각 정보들이 보이도록 출력
		count++; //각 array에 있는 정보 개수만큼 파일에서 정보를 읽는다.
	}
	return count;
}
//배열에 있는 정보들 출력, count와 totalFriends의 관계
void outputArray(Friend myFriends[], int totalFriends) {
	for (int i = 0; i < totalFriends; i++) {
		cout << myFriends[i].getName() << "  ";
		cout << myFriends[i].getAge() << "  ";
		cout << myFriends[i].getGPA() << "  ";
		cout << myFriends[i].getPnumber() << endl;
	}
}
void sorting(Friend myFriends[], int totalFriends) { //나이 정렬 함수
	Friend curFriend;
	int moveIndex;

	for (int i = 1; i < totalFriends; i++) {
		curFriend = myFriends[i];
		moveIndex = i;
		while ((moveIndex > 0) && (myFriends[moveIndex - 1].getAge() > curFriend.getAge())) {
			myFriends[moveIndex] = myFriends[moveIndex - 1];
			moveIndex--;
		}
		myFriends[moveIndex] = curFriend;
	}
}



