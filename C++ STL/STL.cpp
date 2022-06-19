#include<bits/stdc++.h>
using namespace std;




//Containers in C++ STL

void explainPair() {

	pair<int, int> p = {1, 3}; //pair

	cout << p.fist << " " << p.second;

	pair<int, pair<int, int>> p = {1, {3, 4}}; //pair of int and pairs

	cout << p.fist << " " << p.second << " " << p.second.fist << " " << p.second.second << endl

	pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}}; //array of pair type

	cout << arr[1].second << endl;
}


void explainVector() { //dinamic array

	vector<int> v; //empty vector decleration

	v.push_back(1);
	v.emplace_back(2); //same but faster than push_back

	vector<pair<int, int>> vec;

	vec.push_back({1, 2});
	vec.emplace_back(1, 2); //will automatically understand its a pair type no need to use ( {1,2} ) simply (1,2)

	vector<int> v1{5, 100}; //vector of size 5 with 100 as default value --> {100,100,100,100,100}

	vector<int> v2(5); //vector of size 5 with 0 as default value --> {0,0,0,0,0}

	vector<int> v3(v1); //copies content of vector v1 into vector v3



	//iterator

	vector<int>::iterator it = v.begin(); //points to the memory address of first element of the vector

	it++;
	cout << *(it) << " "; //prints the value at address of it //without the '*' before it will only print the memory address of the current value of the iterator


	vector<int>::iterator it = v.end(); //points to the memory address of last element of the vector

	/*
	Hardly Used functions

	vector<int>::iterator it=v.rbegin(); //reverse begin
	vector<int>::iterator it=v.rend(); //reverse end

	*/

	cout << v[0] << " " << v.at(0);

	cout << v.back() << " ";


	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *(it) << " ";
	}

	//auto --> automatically adjusts the data type according to the given data

	for (auto it = v.begin(); it != v.end(); i++) {
		cout << *(it) << " ";
	}

	for (auto it : v) { // for each loop with auto
		cout << it << " ";
	}

	// {10,20,12,23}
	v.erase(v.begin() + 1); //erase(address) //ie 20 //10,12,23

	// {10,20,12,23,35}
	v.erase(v.begin() + 2, v.begin() + 4); //erase(start address ,end address after the element)  // start --> inclusive and end --> excluded //{ 10, 20}



	//Insert Funciton

	vector<int> v(2, 100); //{100,100}

	v.insert(v.begin(), 300); //{300,100,100}
	v.insert(v.begin() + 1, 2, 10); //{300,10,10,100,100}


	vector<int> copy(2, 50); //{50,50}
	v.insert(v.begin(), copy.begin() , copy.end()); //{50,50,300,10,10,100,100}


	//{10,20}
	cout << v.size(); // 2

	//{10,20}
	v.pop_back(); //{10} // pops last element of the vector



	//v1={10,20,30} v2={40,50,60}
	v1.swap(v2); //swaps value of two vectors  //v1 --> {40,50,60}  v2 --> {10,20,30}


	cout << v.empty(); // returns True/False

}



void explainList() {
	//list operations are much faster than vector operations as they implement doubly linked list internally overall time complexity of list is much faster

	list<int> ls;

	ls.push_back(2); //{2}
	ls.emplace_back(4); //{2,4}


	ls.push_front(5); //{5,2,4};
	ls.emplace_front(6); //{6,5,2,4};


	//rest functions same as vector
	//begin,end,rbegin,rend,clear,insert,size,swap
}


void explainQueue() {
	//FIFO - FastInFastOut DataStructure

	queue<int> q;
	q.push(1);//{1}
	q.push(2);//{1,2}
	q.emplace(3);//{1,2,3}

	q.back() += 5; //3+5=8
	cout << q.front(); //prints 1
	cout << q.back(); //prints 8

	q.pop(); //{2,8}

	cout << q.front(); //prints 2

	//size swap empty same as stack
}


void explainDeque() {
	deque<int> dq;

	dq.push_back(1); //{1}
	dq.emplace_black(2); //{1,2}
	dq.push_front(3); //{3,1,2}
	dq.emplace_front(4); //{4.3,1,2}



	dq.pop_back(); //{3,4,1}
	dq.pop_front(); //{4.1}


	dq.back(); //1    //reference of the last element of the deque container
	dq.front(); //4   //reference of the first element of the deque container



	//rest functions same as vector
	//begin,end,rbegin,rend,clear,insert,size,swap
}



void explainStack() { //every operation is in O(1)
	//LIFO - LastInFirstOut DataStructure

	stack<int> st;
	st.push(1); //{1}
	st.push(2); //{2,1}
	st.push(3); //{3,2,1}
	st.push(4); //{4,3,2,1}
	st.push(5); //{5,4,3,2,1}

	st.emplace(6);//{6,1,2,3,4,5} //same as push



	cout << st.top(); //prints 6

	//size swap empty same as other DS

}

void explainPriorityQueue() { //push pop --> O(log N) ,top -->O(1)

	//Max heap
	priority_queue<int> pq;
	pq.push(5); //{5}
	pq.push(2); //{5,2}
	pq.push(8); //{8,5,2}
	pq.emplace(10); //{10,8,5,2}

	cout << pq.top(); //prints 10

	pq.pop(); //{8,5,2}  //O(1)

	cout << pq.top(); //prints 8

	//size swap empty same as stack

	//Minimum Heap  //Min Priority queue
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(5); //{5}
	pq.push(2); //{2,5}
	pq.push(8); //{2,5,8}
	pq.emplace(10); //{2,5,8,10}

	cout << pq.top(); //prints 2  //O(log n)
}



void explainSet() {
	//all operations are ~ O(log N)
	//sorted and unique
	set<int> st;
	st.insert(1); //{1}
	st.emplace(2); //{1,2} //doesn't allow duplicate items
	st.insert(2); //{1,2}
	st.insert(4); //{1,2,4}
	st.insert(3); //{1,2,3,4}



	//Functionality of insert in vector can be used also, that only increases efficiency


	//begin , end , rbegin , rend , size , empty are same like other DS


	//{1,2,3,4,5}
	auto it = st.find(3); //returns itretor pointing to address of 3

	//{1,2,3,4,5}
	auto it = st.find(6); // if the element is not presnt then it returns st.end()


	//{1,2,5}
	st.erase(5); // erase 5  //{1,2}

	int cnt = st.count(5); //returns 1 if present else 0

	cout << cnt << endl; //prints 0 //5 is erased


	auto it = st.find(3); // passing the iterator containing the address of the elelement to be erased
	st.erase(it);  // O(1)

	//{!,2,3,4,5}
	auto it1 = st.find(2);
	auto it2 = st.find(4);

	st.erase(it1, it2); //st.erase(first,last) //{1,4,5}


	//lower_bound() and upper_bound() function works in the same way as in vector


	//syntax
	auto it = st.lower_bound(2);
	auto it = st.upper_bound(3);


}

void explainMultiSet() {
	//Unlike set MultiSet stores duplicate items too

	multiset<int>ms;

	ms.insert(1); //{1}
	ms.insert(1); //{1,1}
	ms.insert(1); //{1,1,1}

	ms.erase(1); //all 1's get erased

	int cnt = ms.count(1); // 0 as all 1's got earased in above step
	ms.erase(ms.find(1)); //only a single occurance of 1 will be erased ie first occurance
	ms.erase(ms.find(1), ms.find(1) + 2); // ms.erase(starting occurance, till 2nd occurance)


	//rest functions are same
}

void explainUnorderedSet() {
	//Sotres Unqiue but in Unsorted Manner(Random manner) ; Has almost all operation complextities as O(1) in best case (Worst case (very reare)--> O(N)) unlike set and multiset(assuming there are no collisions)
	unordered_set<int> st;

	//upper_bound() and lower_bound() do not work rest all fucitna are same

}

void explainMap() { //O(Log N)
	//stores element sorted on basis of key

	map<int, int> mp;

	map<int, pair<int, int>> mp;

	map<pair<int, int>, int> mp


	mp[1] = 2;
	mp.emplace({3, 1});
	mp.insert({2, 4});

	mp[ {2, 3}] = 10;


	for (auto it : mp) {
		cout << it.first << " " << it.second << endl;
	}

	cout << mp[1];
	cout << mp[5];


	auto it = mp.find(3);
	cout << *(it).second;

	auto it = mp.find(5); //since 5 is not present so it points to after the end index (not at the end its after the end) of the map ( ie mp.end())

	//syntax for upper_bound and lower_bound
	auto it = mp.lower_bound(2);

	auto it = mp.upper_bound(3);

	//erase,swap,size,empty are same as above containers

}

void explainMultimap() {
	//Unlike map it stores duplicate(multiple) keys as well
	//mp[key] can't be used here
}

void explainUnorderedMap() {
	//Unsorted(Randomised , Unsorted , Unique ) but effecient (difference is same as that of set and unordered_set)

	//AVG -O(1) , //WORST - O(Log N)
}


//comp function for pairs
bool comp(pair<int, int>p1 , pair<int, int>p2) {  //bool comp (pair1 ,pair2){}
//check order
	if (p1.second < p2.second) return true;
	if (p1.second > p2.second) return false;
	//if  they are equal its okay no need for swaping
	if (p1.fist > p2.first)return true;
	return false;
}


void explainExtra() {

	int a[] = {1, 4, 5, 8, 9};
	int n = sizeof(a) / sizeof(a[0]); //size of array a

	//sort(start,end)
	sort(a, a + n);
	sort(v.begin(), v.end()); //for vector

	sort(a + 2, a + 4);
	sort(a, a + n, greater<int>);


	pair<int, int> a[] = {{1, 2}, {2, 1}, {4, 1}};

	//**sort it according to the second element if the second element is same then sort it according to the first element but in decending

	sort(a, a + n, comp); //using the custom boolean comperator as defined above //{4,1},{2,1},{1,2}

	int num = 7;
	int cnt = __builtin_popcount();  //number of 1's in binary of n in __builtin_popcount(n) (ie number of set bits)

	long long num = 165786578687;
	int cnt = __builtin_popcountll();



	//STL for generating permutations till null is reached
	string s = "123";
	sort(s.begin(), s.end()); //sorting is utterly imp here else not all permutations will get printed
	do {
		cout << s << endl;
	} while (next_permutation(s.begin(), s.end()));


	//to directly find the max element in a array/vector
	//max_element(a, a + n) --> returns address to the element
	int maxi = *max_element(a, a + n); //prints 9

	//for minimum element
	int mini = *min_element(a, a + n); //prints 1

}


void otherSTLBuiltInFunctions() {

	//STL GCD or HCF
	//__gcd(x,y)
	cout << __gcd(6, 20) << endl; //prints 2


	//STL pow(base,exponent)
	cout << pow(2, 4) << endl; //prints 16


	//STL sqrt(N)
	cout << sqrt(4) << endl; //prints 2

	//STL min(value1,value2)
	cout << min(5, 7) << endl; //prints 5

	//STL max(value1,value2)
	cout << max(5, 7) << endl; //prints 7


	//STL swap(value1, value2)
	int a = 10;
	int b = 20;
	swap(a, b);
	cout << a << " " << b << endl; //a=20 ,b=10


	//STL toupper('ch')
	int j = 0;
	char str[] = "abc";
	char ch;

	while (str[j]) {
		ch = str[j];
		putchar(toupper(ch)); //prints ABC
		j++;
	}

	//STL tolower('ch')
	int j = 0;
	char str[] = "ABC";
	char ch;

	while (str[j]) {
		ch = str[j];
		putchar(toupper(ch)); //prints abc
		j++;
	}

	//STL floor(value)
	cout << floor(2.3) << "\n"; //prints 2


	//STL ceil(value)
	cout << ceil(2.3) << "\n";  //prints  3
	cout << ceil(-2.3) << "\n"; //prints -2


	//STL round()
	double x = 12.5, y = 13.3, z = 14.8;

	// Displaying the nearest values
	// of x, y and z
	cout <<  round(x) << "\n";  //prints 13
	cout <<  round(y) << "\n";  //prints 13
	cout <<  round(z) << "\n";  //prints 15

	// For lround
	cout <<  lround(-0.0) << "\n";  //prints 0
	cout <<  lround(2.3) << "\n";   //prints 2
	cout <<  lround(2.5) << "\n";   //prints 3
	cout <<  lround(2.7) << "\n";   //prints 3
	cout <<  lround(-2.3) << "\n";  //prints -2
	cout <<  lround(-2.5) << "\n";  //prints -3
	cout <<  lround(-2.7) << "\n";  //prints -3

	// For llround
	cout << llround(-0.01234) << "\n";   //prints 0
	cout << llround(2.3563) << "\n";     //prints 2
	cout << llround(2.555) << "\n";      //prints 3
	cout << llround(2.7896) << "\n";     //prints 3
	cout << llround(-2.323) << "\n";     //prints -2
	cout << llround(-2.5258) << "\n";    //prints -3
	cout << llround(-2.71236) << "\n";   //prints -3



	//Important Time Saving Functions of STL

	int a[] = {1, 4, 5, 8, 9};
	int n = sizeof(a) / sizeof(a[0]); //size of array a


	//STL Binary Search
	//binary_search(start,end,elementToBeSearched);

	bool res = binary_search(a, a + n, 3);
	cout << res << endl;

	bool res = binary_search(a, a + n, 4);
	cout << res << endl;



	//STL lower_bound   //O(log n)
	//lower_bound(start,end,element) - start ;


	// a[]={1,4,5,6,9,9}
	//returns the first occurance if elementToBeSearched is presnet
	//if the elementToBeSearched is not there it points to the imediate next greater element for eg- if elementToBeSearched is 3 which is not present it will return a iterator pointing to immediate greater ie 4
	//if the elementToBeSearched is 10 which is not presnent and also 9 is the greatest element in the present array so it return a iterator pointing to immediate greater ie it will point to the end of the array.

	int index = lower_bound(a, a + n, 4) - a; //returns 1 (returns itreator pointing to index of 4)

	int index = lower_bound(a, a + n, 7) - a;  // returns 4 (returns itreator pointing to sindex of next greater ie 9)

	int index = lower_bound(a, a + n, 10) - a; // returns 6 (returns itreator pointing to end of array)


	int index = lower_bound(v.begin(), v.end(), 4) - v.begin();




	//STL upper_bound  //O(log n)
	//upper_bound(start,end,element) - start ;


	// a[]={1,4,5,6,9,9}
	//always returns the next greater element of the elementToBeSearched
	//if the elementToBeSearched is not there it points to the imediate next greater element ( eg- if elementToBeSearched is 3 which is not present it will return a iterator pointing to immediate greater ie 4)
	//if the elementToBeSearched is 10 which is not presnent and also 9 is the greatest element in the present array so it return a iterator pointing to immediate greater ie it will point to the end of the array.

	int index = upper_bound(a, a + n, 4) - a; //returns 1 (returns itreator pointing to index of 4)

	int index = upper_bound(a, a + n, 7) - a;  // returns 4 (returns itreator pointing to sindex of next greater ie 9)

	int index = upper_bound(a, a + n, 10) - a; // returns 6 (returns itreator pointing to end of array)


	int index = upper_bound(v.begin(), v.end(), 4) - v.begin();
}




int main() {

	return 0;
}