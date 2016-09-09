#include<iostream>
using namespace std;
class QuickFind
{
private:
	int *id, size;
public:
	QuickFind(int N)
	{
		id = new int[N];	
		size = N;
		for (int i = 0; i < N; i++)
			id[i] = i;
	}

	bool find(int p, int q)
	{	return id[p] == id[q];	}

	void unite(int p, int q)
	{
		int pid = id[p];
		for (int i = 0; i < size; i++)
			if (id[i] == pid) 
				id[i] = id[q];
		/*
			
		*/
			
	}
	/*
	3-4   0 1 2 4 4 5 6 7 8 9
	4-9   0 1 2 9 9 5 6 7 8 9
	8-0   0 1 2 9 9 5 6 7 0 9
	2-3   0 1 9 9 9 5 6 7 0 9
	5-6   0 1 9 9 9 6 6 7 0 9
	5-9   0 1 9 9 9 9 9 7 0 9
	7-3   0 1 9 9 9 9 9 9 0 9
	4-8   0 1 0 0 0 0 0 0 0 0
	6-1   1 1 1 1 1 1 1 1 1 1

		Problem: many value can change

	
	*/
};
class  QuickUnion
{
	private:
	int *id, size;

	int root(int i)    /*QuickUnion add  fuction  root 
						 ============diffence==============*/
	{
		while (i != id[i])
			i = id[i];
		return i;
	}

	public:
	QuickUnion (int N)
	{
		id = new int[N];	
		size = N;
		for (int i = 0; i < N; i++)
			id[i] = i;
	}

	bool find(int p, int q)
	{
		return root(p) == root(q);
	}

	void unite(int p, int q)
	{
		id[root(q)] = root(p);
	}
	/*
		3-4   0 1 2 4 4 5 6 7 8 9
		4-9   0 1 2 9 9 5 6 7 8 9
		8-0   0 1 2 9 9 5 6 7 0 9
		2-3   0 1 9 9 9 5 6 7 0 9
		5-6   0 1 9 9 9 6 6 7 0 9
		5-9   0 1 9 9 9 9 9 7 0 9
		7-3   0 1 9 9 9 9 9 9 0 9
		4-8   0 1 0 0 0 0 0 0 0 0
		6-1   1 1 1 1 1 1 1 1 1 1
	*/
};
class WeightedQuickUnion
{
	private:
			int *id,*sz,size;
			int root(int i)
			{
				while(i!=id[i])
					i=id[i];
				return i;
			}
	public:
		WeightedQuickUnion(int N)
			{
				id=new int [N];	
				sz=new int [N];
				size=N;
				for(int i=0;i<N;i++)			
				{
					id[i]=i;
					sz[i]=i;
				}
					
			}
			bool find(int p,int q)
			{
				return root(p)==root(q);	
			}
			void uinte(int p,int q) // cheak connected
			{
				/* WeightedQuickUnion add Weighted
				============diffence==============*/
			 	int x = root(p); 
        		int y = root(q);
        		if(sz[x] < sz[y])
        		{
            		id[x] = y;
            		sz[y] += sz[x];
       			}
       			else
        		{
            		id[y] = x;
            		sz[x] += sz[y];
       			}
			}			
};
class PathCompression
{
	private:
			int *id,size;
			int root(int i)
			{
				while(i!=id[i])
				{
					id[i] = id[id[i]];
					i=id[i]; /*============diffence==============*/	
				}
					
				return i;
			}
	public:
			PathCompression(int N)
			{
				id=new int [N];
				size=N;
				for(int i=0;i<N;i++)
					id[i]=i;
			}
			bool find(int p,int q)
			{
				return root(p)==root(q);	
			}
			void uinte(int p,int q) // cheak connected
			{
				id[root(q)]=root(p);
			}				
};
class WQUPC
{
	private:
			int *id,*sz;
			int root(int i)
			{
				while(i!=id[i])
				{
					id[i] = id[id[i]];
					i=id[i]; 
				}
					
				return i;
			}
	public:
		WQUPC(int N)
		{
			id=new int [N];	
			sz=new int [N];
	
			for(int i=0;i<N;i++)			
			{
				id[i]=i;
				sz[i]=i;
			}
		}
			bool find(int p,int q)
			{
				return root(p)==root(q);	
			}
			void unite(int p,int q) // cheak connected
			{
				int i = root(p);
    			int j = root(q);



    			if(sz[i] < sz[j])
				{          

        			id[i] = j;
        			sz[j] += sz[i];

    			}
				else
				{
					id[j] = i;
        			sz[i] += sz[j];
    			}
			}				
};
void inputWQUPC()
{
	int N;
	cin >>N;
	WQUPC uf(N+1);
	char op;
	while(cin>>op)
	{
		int p,q;
		cin >>p>>q;
		if(op=='c')
			uf.unite(p,q);
		else if(op=='q')
		{
			if(uf.find(p,q))
				cout << p << " and " << q <<" are connected.\n";
			else
				cout << p << " and " << q <<" are isolated.\n";
		}
		else break;
	}
	/*
		10
		c 3 4
		c 4 9
		q 5 3
			5 and 3 are connected
		c 8 0
		q 9 3
			5 and 3 are connected
		c 2 3
		c 5 6
		c 5 9
		q 3 5
			5 and 3 are connected
		q 5 2
			5 and 3 are connected
		c 7 3
		c 4 8	
		q 1 7
			5 and 3 are connected
		q 8 2
			5 and 3 are connected
		c 6 1
		q 1 3
			5 and 3 are connected
		x 0 0
		time 3.42
	*/
}
int main()
{
	inputWQUPC();
}
