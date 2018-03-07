#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node  *right;
}tree;
tree *createtree()
{
    int i,j,n,k1,k2,m;   /*  k1 is most smmall  */
    tree **narr, *q;
    printf("please input leaves of number:\n");
    scanf("%d",&n);
    printf("please input number:\n");
    narr=(tree **)malloc(n*sizeof(tree *));
    for (i = 0; i < n; i++)
    {
	scanf("%d",&m);
	narr[i]=(tree *)malloc(sizeof(tree));
	narr[i]->data=m;
	narr[i]->left = NULL;
	narr[i]->right = NULL;
    }
    for (i = 1; i < n; i++)
    {

	k1=-2;
        for (j = 0; j < n; j++)
        {
	    if(narr[j]!=NULL && k1==-2)
            {
                k1 = j;
                continue;
            }
            if (narr[j] != NULL)
            {
                k2 = j;
                break;
            }
        }
        for (j = k2; j < n; j++)
        {
            if (narr[j] != NULL)
            {
                if (narr[j]->data < narr[k1]->data)
                {
                    k2 = k1;
                    k1 = j;
                }
                else if (narr[j]->data <narr[k2]->data)
                    k2 = j;
            }
        }
	q =(tree *)malloc(sizeof(tree));
        q->data = narr[k1]->data + narr[k2]->data;
        q->left =narr[k1];
        q->right = narr[k2];
	narr[k1] = q;
	narr[k2] = NULL;
    }
    free(narr);
    return q;
}
void huffman(tree* FBT, int r) /* outtput huff coding  */
{
    int i;
    static int a[10];
    if (FBT != NULL)
    {
        if (FBT->left == NULL && FBT->right == NULL)
        {
	    printf("the weight:%d\n", FBT->data);
	    for (i = 0; i <r;i++)    
                printf("%d", a[i]);
            printf("\n");
        }
        else
        {
	    a[r] = 1;
	    huffman(FBT->left,r+1);      /* left is 1 */
	    a[r] = 0;
	    huffman(FBT->right,r+1);     /*  right is 0 */
        }
    }
}
void outputtree(tree* bg) /* input   */
{
     if(bg!=NULL)
     {
	if (bg->left== NULL && bg->right == NULL)
        {
	    printf("%d ",bg->data);
	}
	    outputtree(bg->left);
	    outputtree(bg->right);
     }
}


int main(void)
{
    tree *t;
    
    t=createtree();
    printf(" each leaf node in the leaves of harvard slow coding\n");
    huffman(t,0);
    printf("huffman tree\n");
    outputtree(t);
    return 0;

}
