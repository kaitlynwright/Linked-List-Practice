struct Node {
	int data;
	Node *next;
};

class LLL {
public:
	int length;
	Node *head, *tail;

	LLL();
	LLL(int);
	LLL(int,int);
	~LLL();

	void insert(int);
	int insert_at(int,int);
	void remove(int);
	int remove_at(int);
	void print();
};
