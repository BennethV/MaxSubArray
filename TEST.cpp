#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;
///should be copied to .h file
struct Node{
    int kadane;
    int divCon;
    int brute;
    Node* next;
    Node* prev;
};


class QueueLinkList{
public:
    QueueLinkList();
    bool isEmpty() const;
    const Node& front() const;                  //return front element
    const Node& rear() const;                   // return back element
    int getQueueSize() const;                   // return number of elements
    void add(Node* inputNode,const int& a, const int& b, const int& c);
    void enqueue(const int& a, const int& b, const int& c);
    void remove(Node* input);
    void dequeueFront();
    void dequeue();
    friend std::ostream& operator<<(std::ostream& out, const QueueLinkList& obj);
    ~QueueLinkList();

private:
    Node* head;
    Node* tail;
    int queueSize;
};

//should be copied to implementation file .cpp
QueueLinkList::QueueLinkList(){
    head = new Node();
    tail = new Node();
    head ->next = tail;
    tail ->prev = head;
    queueSize = 0;
}
QueueLinkList::~QueueLinkList(){
    while(!isEmpty()) dequeueFront();
    delete head;
    delete tail;
}
bool QueueLinkList::isEmpty() const{
    return (head ->next == tail);
}

const Node& QueueLinkList::front() const{
    return *head;
}

const Node& QueueLinkList::rear() const{
    return *tail;
}

int QueueLinkList::getQueueSize() const{
    return queueSize;
}

void QueueLinkList::add(Node* inputNode,const int& a, const int& b, const int& c){
    Node* newNode = new Node();
    newNode->brute = a;
    newNode->divCon = b;
    newNode->kadane = c;

    newNode->next = inputNode;
    newNode ->prev = inputNode ->prev;
    inputNode ->prev -> next = inputNode ->prev = newNode;
}
void QueueLinkList::enqueue(const int& a, const int& b, const int& c){

    add(head->next,a, b,c);
     queueSize ++;

}


void QueueLinkList::remove(Node* input){
    Node* prevNode = input -> prev;
    Node* newNode = input ->next;
    prevNode ->next = newNode;
    newNode ->prev = prevNode;
}
void QueueLinkList::dequeue(){

    remove(tail -> prev);
    queueSize --;
}
void QueueLinkList::dequeueFront(){
    remove(head -> next);
    queueSize --;
}
std::ostream& operator<<(std::ostream& out, const QueueLinkList& obj){
    Node* temp = obj.tail;
    int n =1;
    temp = temp->prev;
    while( n < obj.getQueueSize()){
        temp = temp->prev;
        out << temp->brute << ' ' << temp->divCon << ' ' << temp->kadane << std::endl;

        n++;
    }
    return out;
}

int main (void){
	QueueLinkList* data= new QueueLinkList();
    ifstream input;

    input.open("output.txt");
    if(!input){
        cerr<<"File Not Found"<<endl;
        return -1;
    }

    int inputSize,alg1,alg2,alg3;
    string firstLine;

    getline(input,firstLine); //skips first line
    input>>inputSize>>alg1>>alg2>>alg3;

    while(input){
        data ->enqueue(alg1,alg2,alg3);
        //cout<<alg1<<' '<<alg2<<' '<<alg3<<endl;
        input>>inputSize>>alg1>>alg2>>alg3;
    }
    data->dequeue(); //deletes from da back
  cout<< *data <<endl;
  cout<<endl;
  cout<< data->getQueueSize();



return 0;
}

