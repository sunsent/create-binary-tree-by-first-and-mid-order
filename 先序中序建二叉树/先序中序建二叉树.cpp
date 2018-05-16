#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct Node
{
	int id;
	int value;
	Node * lkid, *rkid;
};

void creatTreeByFiMi(Node *& root,vector<int> id_first, vector<int> id_middle, int first_start=-1, int first_end=-1, int mid_start=-1, int mid_end=-1 ) {
	if (first_start == -1) {
		
		first_start = 0;//��������ͷ
		mid_start = 0;//��������β
		first_end = id_first.size()-1; //��������ͷ
		mid_end = id_middle.size()-1; //��������β
	}
	if (id_first.size() != id_middle.size() || id_first.size() == 0){
		return ;
	}
	root = new Node;
	root->id = id_first[first_start];
	root->lkid = NULL;//Ĭ�ϲ�һ��ΪNULL
	root->rkid = NULL;
	if (id_first.size() == 1) return ;
	int rootLocInMid = 0;//�����������е�λ��
	int ltreeSize = 0;
	//ȷ��������
	if (id_middle[mid_start] == root->id) {}//û��������
	else {
		
		for (int i = mid_start; i <= mid_end; i++) {
			if (id_middle[i] == root->id) {
				rootLocInMid = i;
				break;
			}
			ltreeSize++;
		}
		int lfirst_start = first_start + 1;
		int lfirst_end = first_start + ltreeSize;
		int lmid_start = mid_start;
		int lmid_end = mid_start + ltreeSize - 1;
		creatTreeByFiMi(root->lkid, id_first, id_middle, lfirst_start, lfirst_end, lmid_start, lmid_end);
	}
	//ȷ��������
	if (id_middle[mid_end]== root->id) {}//û��������
	else {

		int rfirst_start = first_start + ltreeSize + 1;
		int rfirst_end =first_end ;
		int rmid_start = rootLocInMid + 1;
		int rmid_end = mid_end;
		creatTreeByFiMi(root->rkid, id_first, id_middle, rfirst_start, rfirst_end, rmid_start, rmid_end);
	}
}
void visitTreeByFirst( Node * & root) {
	if (root == NULL) return;
	queue<Node*> levelRoot;
	levelRoot.push(root);
	while (levelRoot.size() != 0) {
		int levelRoot_size = levelRoot.size();
		for (int i = 0; i <levelRoot_size; i++) {
			Node* curRoot = levelRoot.front();
			levelRoot.pop();
			if (curRoot->lkid != NULL) {
				levelRoot.push(curRoot->lkid);
			}
			if (curRoot->rkid != NULL) {
				levelRoot.push(curRoot->rkid);
			}
			cout << curRoot->id << "   ";
		}
		cout << endl;
	}
}
int main() {
	Node * node;
	vector<int> id_first;
	for (int i = 0; i < 10;i++) {
		id_first.push_back(i+1);
	}
	int id_mid_arry[10] = {3,4,2,6,5,1,9,8,7,10};
	vector<int> id_mid;
	for (int i = 0; i < 10; i++) {
		id_mid.push_back(id_mid_arry[i]);
	}
	creatTreeByFiMi(node, id_first, id_mid);
	visitTreeByFirst(node);
	int end;
	cin >> end;
}
