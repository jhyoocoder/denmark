#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

const int MAX_NODE = 1000;
// C++ How to construct Graph

using namespace std;

typedef struct _Node {
	string name;
	int answer;
	vector<string> children;
} Node;

vector<Node*> g; // graph

void init() {
	for (int i = 0; i < g.size(); i++) {
		g[i]->children.clear();
		delete g[i];
	}
	g.clear();
}

void printTree() {
	for (int i = 0; i < g.size(); i++) {
		cout << g[i]->name << " ";
		for (int j = 0; j < g[i]->children.size(); j++) {
			cout << g[i]->children[j] << " ";
		}	
		cout << endl;
	}
}

int searchDepth(int node, int d, int &a) {
	if (d == 1) {
		a = a + g[node]->children.size();
	} else {
		for (int i = 0; i < g[node]->children.size(); i++) {
			for (int j = 0; j < g.size(); j++) {
				if ( g[node]->children[i] == g[j]->name )
					searchDepth(j, d - 1, a);
			}
		}
	}
}

bool comp(const Node* a, const Node* b) {
	if (a->answer > b->answer) return true;
	else if (a->answer == b->answer) {
		return a->name < b->name;
	}
	return false;
}

int main() {

	int tcase, n, d;
	string parent, child;
	cin >> tcase;

	init();
	for (int t = 0; t < tcase; t++) {
		cin >> n >> d;
		cout << "Tree " << t+1 <<":" << endl;
		for (int i =0 ; i  < n; i++) {
			int k;
			cin >> parent >> k;
			Node *newNode = new Node;
			newNode->name = parent;
			for (int j = 0; j < k; j++) { 
				cin >> child;
				newNode->children.push_back(child);
			}
			g.push_back(newNode);
		}
		// printTree(); -- for debug
		for (int i =0 ; i < n; i++) {
			int ans = 0;
			searchDepth(i, d, ans);
			g[i]->answer = ans;
		}
		//sorting by names [alphabetical order]
		sort(g.begin(), g.end(), comp);
		int cnt = 0;
		for (int i =0 ; i < n; i++) {
			if (g[i]->answer > 0 && cnt < 3) {
				cnt ++;
				cout << g[i]->name << " " << g[i]->answer << endl;
				if (g[i]->answer == g[i+1]->answer) cnt--;
			}
		}
		init();
		cout << endl;
	}

	return 0;
}