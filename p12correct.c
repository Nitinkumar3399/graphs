#define INT_MAX  1000
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// number of vertices 
int n=0;
int e=0;

// adjacency matrix 
int g[60][60]; 

void create_Graph() 
{ 
	printf("Enter no. of vertices: ");
    scanf("%d",&n); 
// initializing each element of the adjacency matrix to zero 
	for (int i = 0; i < n; ++i) 
    { 
	   for (int j = 0; j < n; ++j) 
       { 
	      	g[i][j] = 0; 
       } 
    } 

  printf("\nGraph is successfully created !! Now U are ready to Add Edges .");

} 

void Display_AdjacencyMatrix() 
{ 
    if (n==0)
    {
        printf("Graph  is not created yet !!");
        printf("\nSo, there is nothing to display .");
        return ;
    }
    
	printf("\n\nAdjacency Matrix:"); 
 
	for (int i = 0; i < n; ++i) 
   {
      printf("\n");  
      for (int j = 0; j < n; ++j) 
      { 
	    printf("%d ",g[i][j]); 
	  }
   }

   printf("\n"); 
} 


struct Node
{
     int data;
     struct Node *next;

}*front=NULL,*rear=NULL;

void enqueue(int x)
{
      struct Node *t;
      t=(struct Node*)malloc(sizeof(struct Node));
 if(t==NULL)
      printf("Queue is FUll\n");
 else
 {
       t->data=x;
       t->next=NULL;
 if(front==NULL)
       front=rear=t;
 else
 {
       rear->next=t;
       rear=t;
 }

 }

}

int dequeue()
{
      int x=-1;
      struct Node* t;

 if(front==NULL)
      printf("Queue is Empty\n");
 else
  {
       x=front->data;      
       t=front;
       front=front->next;
       free(t);
  }
   return x;
}

int isEmpty()
{
    return front==NULL;
}

int Modified_BFS_1(int start,int END)
{
     int i=start,j,k;
    int visited[n];
    int MinDistance[n];
  
  // initialize to zero
  for ( k = 0; k < n; k++)
  {
      visited[k]=0;
      MinDistance[k]=0;
  }
  

 // printf("%d ",i);
   visited[i]=1;
   enqueue(i);

 while(!isEmpty())
  {
     i=dequeue();
     for(j=0;j<n;j++)
    {
        if(g[i][j]==1 && visited[j]==0)
          {
              //printf("%d ",j);
              visited[j]=1;
              MinDistance[j]=MinDistance[i]+1;
              enqueue(j);
          }
    }
  }
return MinDistance[END];

}


void shortest_path_all_vertex()
{
  int i,j;
  if (n==0)
    {
        printf("Graph  is not created yet !!");
        printf("\nSo, there is nothing to Calculate shortest path .");
        return ;
    }
 else
  {
    for ( i = 0; i < n; i++)

    // printing only upper triangular matrix
    //printing of all distinct pair of vertices

    for (j = i; j < n; j++)
    { 
        if (i!=j)
        {
             printf("Distance between vertices ( %d,%d ) is: %d\n",i,j,Modified_BFS_1(i,j));
        }
        
    }
    
  }


}

void path_length()
{ 
     int x,y;
    if (n==0)
    {
        printf("Graph  is not created yet !!");
        printf("\nSo, there is nothing to Calculate .");
        return ;
    }
    else
   {   
        printf("Enter first vertex : ");
        scanf("%d",&x);
        printf("\nEnter second vertex : ");
        scanf("%d",&y);
        printf("\nshortest path between %d and %d is of %d Edges",x,y,Modified_BFS_1(x,y));
   }

}


void print_shortest_Distance()
{


  if (n==0)
    {
        printf("Graph  is not created yet !!");
        printf("\nSo, there is nothing to calculate .");
        return ;
    }
  else
    {
       int SRC,DEST,array[20],j=0,i,v,k;
    
       int visited[n],Distance[n],pred[n];

       printf("Enter SOURCE vertex : ");
       scanf("%d",&SRC);
       printf("\nEnter DESTINATION vertex : ");
       scanf("%d",&DEST);
       i=SRC;
   
  
       // initialize to zero
       for ( k = 0; k < n; k++)
      {
            visited[k]=0;
            Distance[k]=INT_MAX;
            pred[k] = -1;
      }
  

       // printf("%d ",i);
      visited[i]=1;
      Distance[i]=0;
      enqueue(i);

       while(!isEmpty())
       {
              i=dequeue();
              for(v=0;v<n;v++)
              {
                    if(g[i][v]==1 && visited[v]==0)
                     {
                         //printf("%d ",v);
                           visited[v]=1;
                           Distance[v]=Distance[i]+1;
                           pred[v]=i;
                           enqueue(v);
          

                           // We stop BFS when we find  destination. 
                           if (v == DEST) 
                           { 
                                  i=DEST;
                                  array[j]=i; 
                               while (pred[i]!= -1)
                               { 
                                    j++;
                                    array[j]=pred[i]; 
                                    i = pred[i]; 
                                } 
    
                              // distance from source is in distance array 
                              printf("Shortest path length is : %d",Distance[DEST]); 
  
                              // printing path from source to destination 
                              printf("\nPath is::\n"); 
                          
                              for(k=j;k>=0 ;k--)
                              {
                                 printf("%d -> ",array[k]);
                              }
                              printf("STOP");

                              //   here queue is not empty so in second call of 
                              //the function it will create problem
                              if (!isEmpty())
                             {
                                 dequeue();
                                 dequeue();
                                 dequeue();
                             }
                      
                              return ;
                           } 

                      }
 

              }

        }
    }

   printf("\n[Given source and destination are not connected ]");

}


//detection of cycle
// A utility function to find the subset of an element i 
int find(int parent[], int i) 
{ 
    if (parent[i] == -1) 
        return i; // return itself .
    return find(parent, parent[i]); 
} 
  
// A utility function to do union of two subsets  
void Union(int parent[], int x, int y) 
{ 
    int parent_of_x = find(parent, x); 
    int parent_of_y = find(parent, y); 

    if(parent_of_x!=parent_of_y)
    { 
       parent[parent_of_x] = parent_of_y; 
    } 
} 
  
// The main function to check whether a given graph contains  
// cycle or not 
int isCyclicGraph() 
{ 
  int i,j;
    // Allocate memory for creating V subsets 
    int *parent = (int*) malloc( n * sizeof(int) ); 
  
    // Initialize all subsets as single element sets 
    memset(parent, -1, sizeof(int) * n); 
  
    // Iterate through all edges of graph, find subset of both 
    // vertices of every edge, if both subsets are same, then  
    // there is cycle in graph. 
    for ( i = 0; i <n; i++)
    {   // In case of undirected graph  we only consider  either upper or lower triangular part
        // because we only consider here no. of edges . 
        for ( j = i; j < n; j++)
        {
             if(g[i][j]==1)
             {
                 int x = find(parent, i); 
                 int y = find(parent, j); 
  
                  if (x == y) 
                       return 1; 
  
                Union(parent, x, y);

             }
        }
        
    }

    return 0; 
} 
  






void Add_Edge() 
{
  if (n==0)
    {
        printf("Graph  is not created yet !!");
        printf("\nSo, U are not able to Add Edges right now .");
        return ;
    }

  else
  {   int x,y;
      printf("Enter two vertices between them you want to insert an Edge\n");
      printf("Enter first vertex : ");
      scanf("%d",&x);
      printf("\nEnter second vertex : ");
      scanf("%d",&y);
     // checks if the vertex exists in the graph
 
	  if ((x >= n) || (y > n)) 
      { 
          printf("Vertex does not exists!"); 
    	} 

    // checks if the vertex is connecting to itself 
	  if (x == y) 
    { 
	       printf("Same Vertex!"); 
         printf("\nself loop is not allowed");
         printf("\nbecause we are not generally shown self loop");
    } 
   	else 
     { 
 	      // connecting the vertices 
	      g[y][x] = 1; // In case of directed graph we conside only g[x][y]=1 .that's sit.
	      g[x][y] = 1; 
        e++;
     }
 
  }

} 

void Add_Vertex() 
{ 
   if (n==0)
    {
        printf("Graph  is not created yet !!");
        printf("\nSo, U are not able to Add vertex right now .");
        return ;
    }

    else
    {
     // increasing the number of vertices 
	   n++; 
	   int i; 

    // initializing the new elements to 0 
   	for (i = 0; i < n; ++i) 
      { 
           g[i][n - 1] = 0; 
	         g[n - 1][i] = 0; 
    	} 
     printf("\n successfully !! Next vertex is Added but now it is not connected with graph ");
     printf("\nFor connection U should have an Edge");

   }

} 


void Remove_Vertex() 
{

  if (n==0)
    {
        printf("Graph  is not created yet !!");
        printf("\nSo, U are not able to Remove any vertex right now .");
        return ;
    } 

    else
    {
       int x;
       printf("Enter vertex you want to Delete: ");
       scanf("%d",&x);
       // checking if the vertex is present 
      if (x > n) 
       { 
           printf("\nVertex not present!"); 
	         return; 
	     } 
      else 
      { 
	       int i; 
 
	      // removing the vertex 
         while (x < n) 
        { 
	         // shifting the rows to left side 
	         for (i = 0; i < n; ++i)
           {
              g[i][x] = g[i][x + 1]; 
           }

           // shifting the columns upwards   
	         for (i = 0; i < n; ++i) 
           { 
	            g[x][i] = g[x + 1][i]; 
           } 

	       x++; 

        } 

        printf(" vertex is  deleted ");
        // decreasing the number of vertices 
	       n--; 

      } 
   }


} 


int main() 
{
  
  int ch,x;
    
    while(1)
    {
      printf("\n\n\n\t********** -:INPUT MENU:- **********\n");
      printf("\n\t 1 - CREATE GRAPH");
      printf("\n\t 2 - DISPLAY GRAPH");
      printf("\n\t 3 - ADD VERTEX IN A GRAPH");
      printf("\n\t 4 - ADD EDGES IN A GRAPH");
      printf("\n\t 5 - DELETE VERTEX IN A GRAPH");
      printf("\n\t 6 - FIND SHORTEST PATH BETWEEN TWO NODES");
      printf("\n\t 7 - DETECT CYCLE IN A GRAPH");
      printf("\n\t 8 - FIND SHORTEST PATH LENGTH IN ANY 2 VERTEX");
      printf("\n\t 9 - FIND SHORTEST DISTANCE BETWEEN ALL UNIQUE PAIR OF VERTICES");
      printf("\n\t 10 - Exit");
        printf("\n Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
           case 1:
                create_Graph();
                break;
           case 2:
                Display_AdjacencyMatrix();
                break;
           case 3:
                Add_Vertex();
                break;
           case 4:
                Add_Edge();
                break;
           case 5:
                Remove_Vertex();
                break;
           case 6:
                print_shortest_Distance();
                break;
           case 7:
                x=isCyclicGraph();
                if(x==1)
                   printf("\n\tGraph contains cycle !!");
                else if(x==0)
                   printf("\n\tGraph does not contain cycle !!");
                else
                {
                   printf("Graph  is not created yet !!");
                   printf("\nSo,first of all create graph then check cycle.");
                }
                break;
           case 8:
                path_length();
                break;
           case 9:
                shortest_path_all_vertex();
                break;
           case 10:
                exit(0);
            default:
                printf("\n Wrong choice menu\n");
        }
    } 
   return 0;
}
 
