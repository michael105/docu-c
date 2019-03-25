 
/*
source: http://www.rohitab.com/discuss/topic/42593-c-linked-list/

 Anasazi
Posted 20 July 2016 - 06:12 PM 


Hi all, 

I've been having vacation for a couple of weeks now, during this time I've been working on an automated game bot. 

 

Now within the cavebot module of this thing, I had to store the position of each corpse from each creature slayed. Because it would be more efficient to loot the corpses when no more creatures to kill is available.

 

Pondering the ideas of what to do, I settled upon the use of a linked list.

I figured that I might as well post an example here for those who's not familiar with such.

*/
	
#include <stdio.h>
#include <stdlib.h>
 
struct _NODE {
    int nId;
    struct _NODE *pPrev;
    struct _NODE *pNext;
};
 
struct _NODE *CreateNode(struct _NODE *pPrev, int nId)
{
    struct _NODE *pNode = malloc(sizeof(struct _NODE));
    if(pNode)
    {
        pNode->nId = nId;
        pNode->pPrev = (pPrev == NULL) ? NULL : pPrev;
        pNode->pNext = NULL;
    }
    return pNode;
}
 
void AppendNewNode(struct _NODE *pRoot, int nId)
{
    struct _NODE *pNode = pRoot;
    if(!pNode) return;
    while(pNode->pNext) pNode = pNode->pNext;
    pNode->pNext = CreateNode(pNode, nId);
}
 
void RemoveNode(struct _NODE **pRoot, int nId)
{
    struct _NODE *pNode = *pRoot;
    while(pNode)
    {
        if(pNode->nId == nId)
        {
            if(pNode->pPrev) pNode->pPrev->pNext = pNode->pNext;
            if(pNode->pNext) pNode->pNext->pPrev = pNode->pPrev;
 
            if(pNode == *pRoot)
            {
                *pRoot = pNode->pNext;
            }
            free(pNode);
            return;
        }
        pNode = pNode->pNext;
    };
}
 
void DumpNodeData(struct _NODE *pRoot)
{
    struct _NODE *pNode = pRoot;
    while(pNode)
    {
        printf("ID\t%d (p:%d\tn:%d)\n", 
            pNode->nId,
            pNode->pPrev?pNode->pPrev->nId:-1,
            pNode->pNext?pNode->pNext->nId:-1);
        pNode = pNode->pNext;
    }
}
 
int main()
{
    struct _NODE *pRoot = CreateNode(NULL, 0);
    AppendNewNode(pRoot, 1);
    AppendNewNode(pRoot, 2);
    DumpNodeData(pRoot);
 
    printf("---\n");
 
    RemoveNode(&pRoot, 0);
    DumpNodeData(pRoot);
 
    printf("---\n");
 
    RemoveNode(&pRoot, 2);
    DumpNodeData(pRoot);
 
    printf("---\n");
 
    RemoveNode(&pRoot, 1);
    DumpNodeData(pRoot);
 
    return 0;
}
