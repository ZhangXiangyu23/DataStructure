### Chapter Four

#### 1.二叉搜索树

树是一种重要的数据结构，它可以有多个后继。

二叉搜索树首先是一棵二叉树，就是一个节点最多有两个分支。另外，二叉搜索树还具有一个特性：对于每一个节点都是，左子树上的值均小于该节点的值，右子树上的值均大于该节点上的值。

##### （1）数据结构的定义

```c
typedef int ElementType;
struct TreeNode{
	ElementType Element;
	struct Node* Left;
	struct Node* Right;
};

typedef struct TreeNode* Position;//指的是普通节点
typedef struct TreeNode* SearchTree;//指的是二叉搜索树 
```

##### （2）清空一棵二叉搜索树

```c
SearchTree MakeEmpty(SearchTree T)
{
	if(T!=NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);	
	}
	return NULL;
}
```

##### （3）查找某个值在二叉树的哪个位置

原理就是：借助二叉搜索树的特性，比节点值大的话，递归去搜索右子树；比节点值小的话，递归去搜索左子树。递归结束条件是找到对应节点，或者是直接指空了。

```c
Position Find(ElementType X,SearchTree T)
{
	if(T==NULL)
	{
		return NULL;	
	}
	else
	{
		if(X<T->Element)
		{
			return Find(X,T->Left);
		}
		if(X>T->Element)
		{
			return Find(X,T->Right);
		}
		if(X==T->Element)
		{
			return T;	
		}	
	}		
} 
```

##### （4）寻找二叉搜索树中的最小值（递归的思路）

同样利用二叉搜索树的特性，往左一直递归查找，最左侧的叶子节点便是这棵二叉搜索树的最小值。

```c
//递归找最小值
Position FindMin(SearchTree T)
{
	if(T==NULL)
	{
		return NULL;
	}
	else if(T->Left==NULL)
	{
		return T;
	}
	else
	{
		return FindMin(T->Left);
	}
} 
```

##### （5）寻找二叉搜索树中的最大值（循环的思路）

```c
Position FindMax(SearchTree T)
{
	if(T!=NULL)
	{
		while(T->Right!=NULL)
		{
			T=T->Right;
		}
	}
	return T;
} 
```

##### （6）关键操作之插入

具体思路：

如果这棵树一开始就是空的，那就建立树根节点，然后左子树为NULL，右子树为NULL；现将这棵树建立起来。

如果一开始树不为空，那必有节点，那节点里面也必有值啊！为满足二叉搜索树的特性。插入的值比节点值小，那么就左侧递归插入。如果插入的值比节点值大，那么就右侧递归插入。如果正好等于节点的值，什么也不做！

```c
//向二叉搜索树中插入一个值X
SearchTree Insert(ElementType X,SearchTree T)
{
	if(T==NULL)
	{
		T=(Position)malloc(sizeof(struct TreeNode));
		T->Element=X;
		T->Left=NULL;
		T->Right=NULL;	
	}
	else
	{
		if(X<T->Element)
		{
//			return Insert(X,T->Left);
//			我知道为什么要这么写了！因为这样才能连成一棵树啊！！！！
			T->Left=Insert(X,T->Left);	 
		}
		else
		{
			T->Right=Insert(X,T->Right);	
		}	
	}
	//如果这个值已经在树中了，那就啥也操作，直接返回T 
	return T;	
} 
```

##### （7）关键操作之删除一个值

思路：首先是递归地去查找，先找到这个值再进行删除的操作。

如果找不见，那就是树里面没有节点是这个值。

如果找到了，那就考虑这个节点的左右子树是否都有？这个节点只有左子树？这个节点只有右子树？

这个节点本身就是叶子节点？

因为情况不同，那么操作也肯定不相同！

1）==有左右子树==：在这种情况下，我们删除这个节点的话，应该考虑删除了它之后的树，是否还是满足二叉搜索树的特性。

**小妙招来了：**寻找被删除节点的右子树中的最小值。让这个值去替换被删除节点中的值，这样能够保持二叉搜索树的特性。然后再递归地删除右子树中最小值节点。做到“偷天换日”，删除了另一个值的真实指针，让其值替换了真正被删除的节点！

2）==只有一棵子树==:

只有左子树：一个节点如果只有左子树，那么它的右子树肯定是指向为NULL，删除它之后还要保持它的子树在啊！所以，先将T保存在临时变量中，T=T->Left,让被删除节点的父节点指向它的右子树，从而保证删除了被删除节点，而且保持不变。

只有右子树，也是同样的理解。将T先保存在临时变量中，然后T=T->Right;

最后将将保存在临时变量中的指针，free掉。

3）==一棵子树也没有，是个叶子节点==。直接free掉。

```c
//在二叉搜索树中删除一个值
SearchTree Delete(ElementType X,SearchTree T)
{
	Position temp;
	if(T==NULL)
	{
		printf("没有找到!\n");
	}
	else if(X<T->Element)
	{
		T->Left=Delete(X,T->Left);
	}
	else if(X>T->Element)
	{
		T->Right=Delete(X,T->Right);
	}
	else if(T->Left&&T->Right)
	{
		temp=FindMin(T->Right);
		T->Element=temp->Element;
		T->Right=Delete(T->Element,T->Right);
	}
	else
	{
		temp=T;
		if(T->Left==NULL)
		{
			T=T->Right;
		}
		else if(T->Right==NULL)
		{
			T=T->Left;
		}
		free(temp);
	}
	return T;
	
	
}
```



##### （8）获取一个节点的值

```c
//取一个节点中的值
ElementType Retrieve(Position P)
{
	return P->Element;	
}
```

