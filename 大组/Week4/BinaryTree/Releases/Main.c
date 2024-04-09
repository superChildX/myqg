#include"BinaryTree.h"
#include"BinaryTree.c"
#include<windows.h>
int main(){
    SetConsoleOutputCP(65001);
    int x = 0;
    char choice;
    BinaryTree tree = NULL;
    ElemType e;
    Node *node;
    do{
        system("cls");
        if(x == 1){
            printf("现有二叉树前序遍历:");
            preorder(tree);
            printf("\n============================================================================\n");
        }
        printf("1.创建二叉树（直接插入批量数字）\n");
        printf("2.插入元素\n");
        printf("3.删除元素\n");
        printf("4.前序遍历\n");
        printf("5.中序遍历\n");
        printf("6.后序遍历\n");
        printf("7.层次遍历\n");
        printf("0.退出(非递归遍历就不用了，毕竟结果都一样,代码有)\n");
        printf("输入操作数:");
        scanf("%c",&choice);
        getchar();
        if((choice != '1' && choice != '0') && x == 0){
            printf("还没创建树呢~~\n");
            system("pause");
            continue;
        }
        switch (choice){
            case '0':
                break;
            case '1':
                if(x == 1){
                    printf("已经创建了树咯~不能再创建了\n");
                    break;
                }
                tree = init(tree);
                printf("创建成功!\n");
                x = 1;
                break;
            case '2':
                printf("输入插入数据:");
                e = Scan();
                if(e == -999){
                    printf("输入错误\n");
                    break;
                }
                insert(tree,e);
                if(num1 == 0)
                    printf("插入成功!\n");
                break;
            case '3':
                printf("输入删除的数据:");
                scanf("%d",&e);
                getchar();
                node = deleteNode(tree,e);
                if(node == NULL)
                    printf("没有该数据呀~\n");
                else
                    printf("删除成功,数据是%d\n",node->value);
                break;
            case '4':
                printf("前序遍历:");
                preorder(tree);
                break;
            case '5':
                printf("中序遍历:");
                inorder(tree);
                break;
            case '6':
                printf("后序遍历:");
                postorder(tree);
                break;
            case '7':
                printf("层次遍历:");
                levelorder(tree);
                break;
            default :
                printf("输入错误啦，重新输入一下吧~\n");
        }
        system("pause");
    }while(choice != '0');
    return 0;
}