
struct Elem {
	int num;
	Elem *prev;
};

void _push(int num, Elem **top);
int _pop(Elem **top);
