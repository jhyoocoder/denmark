#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

typedef struct _Node {
	string name;
	bool visited;
	int answer; // generation[d]
	int *generation; // generation[1] = # of children
				// generation[d] = what we want to know
	struct _Node* parent;
	vector<struct _Node*> children;
} Node;

vector<Node*> graph;

void init() {
	for (int i = 0; i < graph.size(); i++) {
		if (graph[i] != NULL) {
			delete graph[i]->generation;
			for (int j = 0; j < graph[i]->children.size(); j++) {
				if (!graph[i]->children[j])
					delete graph[i]->children[j];
			}
			graph[i]->children.clear();
			delete graph[i];
		}
	}
	graph.clear();
}

void printTree() {
	for (int i = 0; i < graph.size(); i++) {
		cout << graph[i]->name << " ";
		for (int j = 0; j < graph[i]->children.size(); j++) {
			cout << graph[i]->children[j]->name << " ";
		}
		cout << endl;
	}
}

Node* findNode (string name) {
	Node *res = NULL;
	for (int j = 0 ; j < graph.size(); j++)
		if (graph[j]->name == name) {
			res = graph[j];
		}
	return res;
}

Node *makeNode(string name, int d) {
	Node *parentNode = new Node;			
	parentNode->name = name;
	parentNode->generation = new int[d+1];
        for (int i = 0; i <= d; i++) parentNode->generation[i] = 0;
	parentNode->visited = false;
	parentNode->parent = NULL;
//	parentNode->answer = &(parentNode->generation[d]);
	parentNode->answer = 0;
	graph.push_back(parentNode);
	return parentNode;
}

inline int jhmin(const int &a, const int &b) { return (a<b)?(a):(b); }

bool compareAnswer(const Node* a, const Node *b) {
	if (a->answer > b->answer) {
		return true;
	} else if (a->answer == b->answer) {
		return a->name < b->name;
	}
	return false;
}
void process(int d) {
	//Algorithm : BFS from leaves to root
	//counting generation[] of each node. by using "depth"
	//leaves = depth 0, parents of leaves = depth 1 = end of generation[]

	if (d > 1) {  // nothing to do

		//[1] initialization
		//find leaves and add them in queue
		queue<Node*> level;

		for (int j = 0 ; j < graph.size(); j++)
			if (graph[j]->generation[1] == 0) { // leaf node
				level.push(graph[j]);
			}

		//[2] Travel to Root
		while (!level.empty()) {
			Node *thisNode = level.front();
			int thisDepth = 0;
			while (thisNode != NULL) {
				if (thisDepth == d) {
					thisNode->generation[d] ++;
					thisNode = level.front();
					if (thisNode->parent && !thisNode->parent->visited) {
						level.push(thisNode->parent);
						thisNode->parent->visited = true;
					}
					break;
				}
				thisNode = thisNode->parent;
				thisDepth++;
			}

			level.pop();
		}

	}

	for (int j = 0 ; j < graph.size(); j++) {
		graph[j]->answer = graph[j]->generation[d];
	}
		
	sort(graph.begin(), graph.end(), compareAnswer);
}


int main() {
	int tcase;
	int n, d;
	string parent, child;
	cin >> tcase;

	for (int t = 0; t < tcase; t++) {
		cin >> n >> d;
		init();
		
		for (int i = 0; i < n; i++) {
			Node *parentNode;
			int m;
			
			cin >> parent >> m;

			parentNode = findNode(parent);

			if (parentNode == NULL) {
				parentNode = makeNode(parent, d);
			}

			parentNode->generation[1] = m;

			for (int j = 0; j < m; j++) {
				Node *childNode;

				cin >> child;
					
				childNode = findNode(child);
			
				if (childNode == NULL) {
					childNode = makeNode(child, d);
				}
				childNode->parent = parentNode;
				
				
				parentNode->children.push_back(childNode);
			}
		}
		
		process(d);
		
		//printTree(); //-- for debug
		cout << "Tree " << t+1 << ":" << endl;
		int cnt = 0; 
		for (int i = 0; i < graph.size(); i++) {
			if (graph[i]->answer > 0) {
				cnt++;
				cout << graph[i]->name << " " << graph[i]->answer <<endl;
				if (cnt >= 3) {
					if (i != graph.size() - 1)
						if (graph[i]->answer != graph[i+1]->answer) break;	
				} 
			}
		}
		if (t + 1 != tcase) cout << endl;
	}
	return 0;
}