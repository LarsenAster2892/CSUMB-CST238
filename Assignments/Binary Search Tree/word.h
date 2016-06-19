class word
{
public:
	char name[30];
	bool isEmpty();

	bool operator<(word & rhs);
	bool operator>(word & rhs);
};

