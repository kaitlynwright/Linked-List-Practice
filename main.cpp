#include "LLL.cpp"

void LLL_rand(void) {
	int instr, pos, input;

	printf("Enter number of elements in lll:\n");
	scanf("%d", &instr);
	printf("Enter maximum value that elements can be:\n");
	scanf("%d", &input);

	LLL *lll = new LLL(instr, input);
	
	do {
		printf("\nLLL Explorer\n0)quit\n1)insert\n2)remove\n"\
		"3)insert in given position\n4)remove node from given position\n"\
		"5)print\n");
		scanf("%d", &instr);

		switch(instr) {
			case 1:
				scanf("%d", &input);
				lll->insert(input);
				break;
			case 2:
				scanf("%d", &input);
				lll->remove(input);
				break;
			case 3:
				scanf("%d", &input);
				scanf("%d", &pos);
				lll->insert_at(input,pos);
				break;
			case 4:
				scanf("%d", &pos);
				lll->remove_at(pos);
			case 5:
				lll->print();
				break;
			default:
				break;
		}
	}while(instr != 0);
	delete lll;
	return;
}



int main() {

	LLL lll;
	int instr, data, pos;

	do { 
		printf("\nLLL Explorer\n0)quit\n1)insert\n2)remove\n"\
		"3)insert in given position\n4)remove from given position\n"\
		"5)print\n");
		scanf("%d", &instr);
	
		switch(instr) {
	
			case 1:
				printf("Enter data to insert to lll: ");
				scanf("%d", &data);
				lll.insert(data);
				break;
			case 2:
				printf("Enter data to remove from lll: ");
				scanf("%d", &data);
				lll.remove(data);
				break;
			case 3:
				printf("Enter data to insert: ");
				scanf("%d", &data);
				printf("Enter position in lll to insert: ");
				scanf("%d", &pos);
				lll.insert_at(data,pos);
				break;
			case 4:
				printf("Enter position of node to remove: ");
				scanf("%d", &pos);
				lll.remove_at(pos);
				break;
			case 5:
				lll.print();
				break;
			default:
				break;
		}
	}while(instr!=0);

	return 0;
}
