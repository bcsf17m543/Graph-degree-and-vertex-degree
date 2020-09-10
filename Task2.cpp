#include<vector>
#include<queue>
#include<iterator>
#include<iostream>

using namespace std;
enum color { white, grey, black };
class Node
{
public:
	color clr;
	int elem;
	int dist;
	int Incoming;
	Node* pred;
	vector<Node>adj;
	Node()
	{
		clr = white;
		elem = 0;
		dist = -1;
		pred = NULL;
	}
	Node(int k)
	{
		clr = white;
		elem = k;
		dist = -1;
		pred = NULL;
		Incoming = 0;

	}
	friend ostream& operator<<(ostream &out, Node &c);

	void show()
	{
		for (int it = 0; it != adj.size(); ++it)
		{
			cout << adj[it].elem << " ";

		}
		cout << endl;

	}
	bool operator==(Node& n)
	{
		if (n.elem == this->elem && n.clr == this->clr&&n.dist == this->dist&&n.pred == this->pred)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void AddIncoming()
	{
		Incoming++;
		cout << Incoming << endl;
	}
	void setc(color k)
	{
		clr = k;
	}
};
ostream& operator<<(ostream &out, Node &c)
{
	out << "Element" << c.elem << " \n";
	out << "Predecessor" << c.pred << " \n";
	out << "Color" << c.clr << " \n";


	return out;
}
class Graph
{
private:
	Node* list;
	int size;
	int count;
	int *incoming;

public:
	int getsize()
	{
		return size;
	}
	Node getind(int i)
	{
		return list[i];
	}
	Graph(int k)
	{
		size = k;
		list = new Node[size];
		initialize();
		incoming = new int[size];
		IniIn();
	}
	void IniIn()
	{
		for (int i = 0; i < size; i++)
		{
			incoming[i] = 0;
		}
	}
	void initialize()
	{
		for (int i = 0; i < size; i++)
		{
			list[i].elem = i;
		}
	}
	
	void Addvertex(int src, int dest)
	{
		Node k(dest);
		Node j(src);
		list[src].adj.push_back(k);
		list[dest].adj.push_back(j);

	}
	void Display()
	{
		for (int i = 0; i < size; i++)
		{
			cout << list[i].elem << " ";
			list[i].show();
		}
	}
	Node getNode(Node &n)
	{
		if (Search(n))
		{
			for (int i = 0; i < size; i++)
			{

				if (list[i] == n)
				{
					return list[i];
				}
			}
		}
	}
	bool Search(Node &n)
	{
		bool k = false;
		for (int i = 0; i < size; i++)
		{
			if (list[i] == n)
			{
				k = true;
			}
		}
		return k;
	}
	int count_connection()
	{
		int count = 0;
		for (int i = 0; i < size; i++)
		{
			count += list[i].adj.size();
		}
		return count / 2;
	}
	//try
	void ADDVER(int dest, int src)
	{
		Node k(src);
		list[dest].adj.push_back(k);
		incoming[src]++;
	}
	void Reverse()
	{
		Node* temp = new Node[size];
		int j = 0;
		for (int i = size; i > 0; i++)
		{
			temp[i] = list[j];
			j++;
		}
	}
	bool AllBlack()
	{
		bool k = false;
		for (int i = 0; i < size; i++)
		{
			if (list[i].clr == black)
			{
				k = true;
			}
			else
			{
				k = false;
			}
		}
		return k;
	}
	void setNode(Node k, int i)
	{
		list[i] = k;
	}
	void DisplayArrows()
	{
		cout << "Vertex     In       Out" << endl;
		for (int i = 0;i < size; i++)
		{
			cout << i<<"          "<<list[i].adj.size() << "      " << incoming[i] << endl;
		}
	}
	
};
int main()
{
	Graph mojo(7);
	mojo.ADDVER(0, 1);
	mojo.ADDVER(1, 3);
	mojo.ADDVER(3, 1);
	mojo.ADDVER(2, 0);

	mojo.ADDVER(0, 2);
	mojo.ADDVER(2, 6);
	mojo.ADDVER(2, 5);
	mojo.ADDVER(6, 5);
	mojo.ADDVER(5, 6);
	mojo.ADDVER(5, 4);
	mojo.ADDVER(3, 4);
	mojo.ADDVER(4, 3);
	mojo.DisplayArrows();
	//mojo.Display();


	return 0;
}