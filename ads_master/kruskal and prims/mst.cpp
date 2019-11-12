#include <iostream>
#define inf 99999;
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

class graph{
	int **g;
	int n;
	char city[100];
	edge ed[100];
	int edno;

public:
	graph()
	{
		cout<<"Enter the no of cities. ";
		cin>>n;
		edno=0;

		g=new int*[n];

		for(int i=0;i<n;i++)
		{
			g[i]=new int[n];
			cout<<"Enter the "<<i+1<<" city name : ";
			cin>>city[i];
		}

		for(int i=0;i<n;i++)
		{

			for(int j=i;j<n;j++)
			{
				if(i==j)
				{
					g[i][j]=inf;
				}

				else{
					cout<<"Enter the wt between "<<city[i]<<" and "<<city[j]<<" or -1 for no edge : ";
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
				if(ed[i].wt>ed[j].wt)
				{
					edge e;
					e=ed[i];
					ed[i]=ed[j];
					ed[j]=e;
				}
			}
		}
	}


	void show(edge* an,int x)
	{
		for(int i=0;i<x;i++)
		{
			cout<<city[an[i].start]<<" -> "<<city[an[i].end]<<" = "<<an[i].wt<<endl;
		}
	}

	void kruskal()
	{
		sort();
		edge *ans=new edge[n-1];
		int *component=new int[n];

		for(int i=0;i<n;i++)
		{
			component[i]=i;
		}

		int comp1,comp2;
		int i=0;
		int j=0;

		while(i<(n-1))
		{
			comp1=component[ed[i].start];
			comp2=component[ed[i].end];

			if(comp1!=comp2)
			{
				ans[j].start=ed[i].start;
				ans[j].end=ed[i].end;
				ans[j].wt=ed[i].wt;

				for(int k=0;k<n;k++)
				{
					if(component[k]==comp1)
					{
						component[k]=comp2;
					}
				}
				j++;
			}
			i++;
		}
		show(ans,n-1);
	}

	void prims()
	{
		edge* ans=new edge[n-1];
		int *dist=new int[n];
		int *visit=new int[n];
		int *from=new int[n];

		for(int k=0;k<n;k++)
		{
			dist[k]=g[0][k];
			visit[k]=0;
			from[k]=0;
		}
		visit[0]=1;
		int min,i,j,ind;
		i=0;
		j=0;
		ind=0;

		while(i<(n-1))
		{
			min=inf;

			for(int k=0;k<n;k++)
			{
				if(min>dist[k] && visit[k]==0)
				{
					min=dist[k];
					j=k;
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

int main(int argc, char const *argv[])
{
	graph G;
	//G.kruskal();
	G.prims();
	return 0;
}