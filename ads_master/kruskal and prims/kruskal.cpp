#include <iostream>
#define inf 999999
using namespace std;

class edge{
	int start,end,wt;

public:

	edge()
	{
		start=-1;
		end=-1;
		wt=-1;
	}

	friend class graph;
};

class graph
{
	int **g;
	int edno;
	int n;
	edge ed[100];
	char city[100];


public:
	
	graph()
	{
		edno=0;
		cout<<"Enter the no of cities. ";
		cin>>n;
		g=new int*[n];
		for (int i = 0; i < n; ++i)
		{
			g[i]=new int[n];
			cout<<"\nEnter the "<<i+1<<" city= ";
			cin>>city[i]; 
		}

		for(int i=0;i<n;i++)
		{
			for(int j=i;j<n;j++)
			{
				if(i==j)
				{
					g[i][i]=inf;
				}

				else{
					cout<<"Enter the money between "<<city[i]<<" and "<<city[j]<<" or -1 for no edge ";
					cin>>g[i][j];
					g[j][i]=g[i][j];

					if(g[i][j]==-1)
					{
						g[i][j]=inf;
						g[j][i]=inf;
					}
					else{
						ed[edno].start=i;
						ed[edno].end=j;
						ed[edno].wt=g[i][j];
						edno++;
					}
				}
			}
		}

	}


	void sort()
	{
		for(int i=0;i<edno;i++)
		{
			for(int j=i+1;j<edno;j++)
			{
				edge e;
				if(ed[i].wt>ed[j].wt)
				{
					e=ed[i];
					ed[i]=ed[j];
					ed[j]=e;
				}
			}
		}
	}

	void kruskal()
	{
		edge *ans=new edge[n-1];
		int *comp=new int[n];
		sort();

		for(int i=0;i<n;i++ )
		{
			comp[i]=i;
		}

		int i=0,j=0;
		int comp1,comp2;

		while(i<(n-1))
		{
			comp1=comp[ed[i].start];
			comp2=comp[ed[i].end];

			if(comp2!=comp1)
			{
				ans[j].start=ed[i].start;
				ans[j].end=ed[i].end;
				ans[j].wt=ed[i].wt;

				for(int k=0;k<n;k++)
				{
					if(comp[k]==comp1)
						comp[k]=comp2;
				}
				j++;
			}
			i++;
		}

		show(ans,n-1);
	}

	void show(edge* an,int x)
	{
		for(int i=0;i<x;i++)
		{
			cout<<city[an[i].start]<<" -> "<<city[an[i].end]<<" = "<<an[i].wt<<endl;
		}
	}


	void prims()
	{
		int *visit=new int[n];
		int *dist=new int[n];
		int *from=new int[n];
		edge* ans=new edge[n-1];

		for(int i=0;i<n;i++)
		{
			visit[i]=0;

			if(g[0][i]!=0)
			{
				dist[i]=g[0][i];
			}
			from[i]=0;
		}

		visit[0]=1;
		int min,j,ind;
		ind=0;
		int i=0;
		while(i<(n-1))
		{
			min=inf;
			for(int k=0;k<n;k++)
			{
				if(min>dist[k] && visit[k]==0)
				{
					j=k;
					min=dist[k];
				}
			}
			visit[j]=1;
			ans[ind].start=from[j];
			ans[ind].end=j;
			ans[ind].wt=min;
			ind++;

			for(int k=0;k<n;k++)
			{
				if(g[j][k]<dist[k] && visit[k]==0)
				{
					dist[k]=g[j][k];
					from[k]=j;
				}
			}
			i++;
		}

		show(ans,n-1);

	}
};

int main()
{
	graph G;
	//G.kruskal();
	G.prims();
	return 0;
}