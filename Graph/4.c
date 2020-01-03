#ifndef QUEUE
#define QUEUE

#define maxsize 50

typedef struct {
	int data[maxsize];
	int front;
	int rear;
}*Queue, Node;

#endif


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int qqq[2000];

void initQueue(Queue queue)
{
	queue->front = 0;
	queue->rear = 0;
}

bool isEmpty(Queue queue)
{
	if (queue->front == queue->rear) {
		return true;
	}
	return false;
}

bool isFull(Queue queue)
{
	if ((queue->rear + 1) % maxsize == queue->front) {
		return true;
	}
	return false;
}

bool Enqueue(Queue queue, int num)
{
	if (isFull(queue)) {
		return false;
	}
	queue->data[queue->rear] = num;
	queue->rear = (queue->rear + 1) % maxsize;
	return true;
}

bool Dequeue(Queue queue, int *x)
{
	if (isEmpty(queue)) {
		return false;
	}
	*x = queue->data[queue->front];
	queue->front = (queue->front + 1) % maxsize;
	return true;
}



#define MAXVEX 100

bool visited[100];

typedef struct {
	char vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVert, numEdge;
	int out[MAXVEX];
	int in[MAXVEX];
}Graph;

void createGraph(Graph * G)
{
	int i, j, k, w;
	int ii, jj;
	char a, b;
	scanf("%d%d", &G->numVert, &G->numEdge);
	getchar();
	for (i = 0; i < G->numVert; i++) {
		scanf("%c", &G->vexs[i]);
	}
	getchar();
	for (i = 0; i < G->numVert; i++) {
		for (j = 0; j < G->numVert; j++) {
			G->arc[i][j] = 0;
		}
		G->in[i] = G->out[i] = 0;
	}


	for (k = 0; k < G->numEdge; k++) {

		scanf("%c%c", &a, &b);
		getchar();
		for (i = 0; i < G->numVert; i++) {
			if (G->vexs[i] == a) {
				ii = i;
				G->in[ii]++;
				break;
			}
		}
		for (i = 0; i < G->numVert; i++) {
			if (G->vexs[i] == b) {
				jj = i;
				G->out[jj]++;
				break;
			}
		}
		G->arc[ii][jj] = 1;
		G->arc[jj][ii] = 1;
	}
}

int all = 0;

void BFSTraverse(Graph G)
{
	int i, j;
	Queue q = (Queue)malloc(sizeof(Node));
	initQueue(q);
	for (i = 0; i < G.numVert; i++) {
		visited[i] = false;
	}
	for (i = 0; i < G.numVert; i++) {
		if (!visited[i]) {
			all++;
			visited[i] = true;
			//printf("%c", G.vexs[i]);
			Enqueue(q, i);
			while (!isEmpty(q)) {
				Dequeue(q, &i);
				for (j = 0; j < G.numVert; j++) {
					if (G.arc[i][j] == 1 && !visited[j]) {
						visited[j] = true;
						//printf("%c", G.vexs[j]);
						Enqueue(q, j);
					}
				}
			}
		}
	}
}

int main(void)
{
	Graph G;
	createGraph(&G);

	
	BFSTraverse(G);
	

	printf("%d\n", all);

}

