//#include<iostream>
//using namespace std;
//class AdjMat
//{
//private:
//	int **arr;
//	int size;
//public:
//	AdjMat(int siz)
//	{
//		size = siz;
//		arr = new int*[size];
//		for(int i=0;i<size;i++)
//		{
//			arr[i] = new int[size];
//		}
//		for (int i = 0; i < size; i++)
//		{
//			for (int j = 0; j < size; j++)
//			{
//				arr[i][j] = 0;
//			}
//		}
//	}
//	void AddVertex(int src, int dest)
//	{
//		arr[src][dest] = 1;
//	}
//	void Display()
//	{
//		for (int i = 0; i < size; i++)
//		{
//			for (int j = 0; j < size; j++)
//			{
//				cout << arr[i][j] << " ";
//			}
//			cout << endl;
//		}
//	}
//	void CountDegree(int ver)
//	{
//		int Deg = 0;
//		for (int i = 0; i < size; i++)
//		{
//			if (arr[ver][i] == 1)
//			{
//				Deg++;
//			}
//		}
//		cout << "Degree of vertex " << ver << " is " << Deg;
//	}
//};
//int main()
//{
//	AdjMat hi(5);
//	hi.AddVertex(0, 1);
//	hi.AddVertex(0, 2);
//	hi.AddVertex(0, 3);
//	
//
//
//	hi.Display();
//	hi.CountDegree(0);
//
//	return 0;
//}