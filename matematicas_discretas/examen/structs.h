struct treeTokens{
	char type;
	int pos;//position
	int L,R;//left, right
	char Lchar;
	char Rchar;
	int priority;
	int size;
};

struct token_2{
	char type;
	int pos;
	int L,R;
	int Lchar, Rchar;
	int priority;
	int size;
	struct token_2 *id;
};

typedef struct treeTokens TOKENS;
typedef struct token_2 NEWTOKENS;