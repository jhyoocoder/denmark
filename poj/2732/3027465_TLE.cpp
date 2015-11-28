#include <iostream>
#include <string>
using namespace std;

const int MAXSIZE = 1000;

struct treenode {
	string name;
	int nchild;
	treenode *firstc, *nexts;
	bool root;
	int ans;
} nodes[MAXSIZE];
int nNodes, sort[MAXSIZE];

treenode *findNode(string name)
{
	int i;
	for(i=0; i<nNodes; i++) {
		if (nodes[i].name == name)
			return nodes+i;
	}
	nodes[nNodes].name = name;
	nodes[nNodes].nchild = 0;
	nodes[nNodes].firstc = nodes[nNodes].nexts = 0;
	nodes[nNodes].root = true;		// may be root;
	nNodes++;
	return nodes+(nNodes-1);
}

void input(int n)
{
	nNodes = 0;
	for(int i=0; i<n; i++) {
		string name;
		cin >> name;
		treenode *node = findNode(name);
		cin >> node->nchild;
		cin >> name;
		node->firstc = findNode(name);
		node->firstc->root = false;
		treenode *temp = node->firstc;
		for(int j=1; j<node->nchild; j++) {
			cin >> name;
			temp->nexts = findNode(name);
			temp->nexts->root = false;
			temp = temp->nexts;
		}
	}
}

int *processTree(treenode *node, int d)
{
//cout << "start node " << node->name << endl;
	int i;
	int *desc = new int[d], *temp;
	for(i=0; i<d; i++)
		desc[i] = 0;
	desc[0] = 1;
	node->ans = 0;
	treenode *c = node->firstc;
	for(i=0; i<node->nchild; i++) {
		temp = processTree(c, d);
//cout << "  node " << node->name << ", return from child " << c->name;
//for(int ii=0; ii<d; ii++) cout << ' ' << temp[ii]; cout << endl;
		for(int j=1; j<d; j++) {
			desc[j] += temp[j-1];
		}
		node->ans += temp[d-1];
		delete temp;
		c = c->nexts;
	}
	return desc;
}

treenode *findRoot()
{
	for(int i=0; i<nNodes; i++) {
		if (nodes[i].root) {
			return nodes+i;
		}
	}
	cout << "Couldn't find root" << endl;	// should never happen
	exit(-1);
	return 0;
}

void output(int icase)
{
	int i, j;

	cout << "Tree " << icase << ":" << endl;
	for(i=0; i<nNodes-1; i++) {
		for(j=0; j<nNodes-1; j++) {
			if (nodes[j].ans < nodes[j+1].ans || (nodes[j].ans == nodes[j+1].ans && nodes[j].name > nodes[j+1].name)) {
				treenode temp = nodes[j];
				nodes[j] = nodes[j+1];
				nodes[j+1] = temp;
			}
		}
	}
	int count = 1;
	for(i=0; i<nNodes; i++) {
		if (nodes[i].ans == 0 || (count > 3 && nodes[i].ans != nodes[i-1].ans))
			break;
		cout << nodes[i].name << ' ' << nodes[i].ans << endl;
		count++;
	}
}

void main()
{
	int ncases, n, d;
	cin >> ncases;
	for(int icase = 1; icase <= ncases; icase++) {
		cin >> n >> d;
		input(n);
		treenode *root = findRoot();
		processTree(root, d);
		output(icase);
		if (icase < ncases)
			cout << endl;
	}
}