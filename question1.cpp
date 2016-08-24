#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

typedef long Algorithm;
class StringNode{
	public:
	    Algorithm kadane;
	    Algorithm divCon;
	    Algorithm brute;


		StringNode* next;

		friend class SLinkedList;
};

class SLinkedList{
	public:
		SLinkedList();
		~SLinkedList();
		bool isEmpty()const;
		const int num();		//prints front element
		void addFront(const int& a, const int& b, const int& c);
		void removeFront();
		friend ostream& operator<<(ostream& out, const SLinkedList& obj);

	private:
		StringNode* head;
};

SLinkedList::SLinkedList() :head(NULL){}
SLinkedList::~SLinkedList(){
	while(!isEmpty()) removeFront();
}
bool SLinkedList::isEmpty()const{
	 return head == NULL;
}
/*
const int& SLinkedList::front()const{

}
*/
void SLinkedList::addFront(const int& a, const int& b, const int& c){
	StringNode* v = new StringNode;
	v ->brute=a;
	v ->divCon=b;
	v ->kadane=c;
	v ->next=head;
	head =v;
}
void SLinkedList::removeFront(){
	StringNode* old =head;
	head = old->next;
	delete old;
}

ostream& operator<<(ostream& out, const SLinkedList& obj){
	StringNode* temp = obj.head;
	while(temp !=NULL){
		out << temp->brute<<'   '<<temp->divCon<<'  '<<temp->kadane<<endl;
		temp = temp->next;
	}
	return out;
}

int main (void){
	SLinkedList* data= new SLinkedList();
    ifstream input;

    input.open("output.txt");
    if(!input){
        cerr<<"File Not Found"<<endl;
        return -1;
    }

    long inputSize,alg1,alg2,alg3;
    string firstLine;

    getline(input,firstLine); //skips first line
    input>>inputSize>>alg1>>alg2>>alg3;

    while(input){
        data ->addFront(alg1,alg2,alg3);
        //cout<<alg1<<' '<<alg2<<' '<<alg3<<endl;
        input>>inputSize>>alg1>>alg2>>alg3;
    }
  cout<< *data <<endl;



return 0;
}
