#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <graphics.h>

struct node 							// tao mot cau truc cay
{
	char data[11];
	int dem;
	node* left;
	node* right;
};
typedef struct node Node;
typedef Node* Tree;

Tree Taonode(char x[11]){   			// Tao Node	
		Node *p= new Node();
		strcpy(p->data, x);
		p -> dem = 1;
		p -> left = NULL;
		p -> right = NULL;
		return p;
	}
	
void Themnode(Tree &t,Node* p){			// Them node vao cay t
	
	if(t!= NULL){
	
	if (strcmp(t->data, p->data) == 0){
		t->dem++; 
		}
	else if (strcmp(t->data, p ->data ) < 0 ){
		Themnode(t->right, p);
	}
	else if ( strcmp(t->data, p->data) > 0){
		Themnode(t -> left, p);
	}
		
}
	else
	{
		t=p;
 	}
}

void Hienthicay(Tree &t)				// Duyet cay LNR ghi vao file
{	
	if (t!= NULL)
	{
		Hienthicay(t->left);
		FILE *file;
		file = fopen("huy.out", "a");	
		fprintf (file, "%-15s : %d\n", t->data, t->dem);
		Hienthicay(t->right);
	}
}
void Hienthicaybanphim(Tree &t)
{
	if (t!= NULL)
	{
		Hienthicaybanphim(t->left);
		printf ("%-15s : %d\n", t->data, t->dem);
		Hienthicaybanphim(t->right);
	}
}

int dem(Tree t)							// dem so Node trong cay
{
	if (t== NULL) return 0;
	else return (dem (t->right) + dem (t->left)) + 1;
}

bool Daucau(char x)						// cac dau can xoa
{
	return x == ',' || x== '.' || x == '(' || x== ')'
	|| x == ';' || x == ':' || x == '!' || x == '?';
}

void Xoadau(char *s)					// xoa dau cuoi tu
{
	int n=strlen(s);
	int i= n-1;
	while (Daucau(s[i]))
	{
		s[i] = '\0';
		i--;
	}
}

void Docfile(Tree &t)					// Doc file va xu li cay
{					
	FILE *file;
	file = fopen("huy.in","r");
	while (!feof(file) && dem(t) < 100){
	char word[11];
	fscanf(file, "%s", &word);
	Xoadau(word);
	Node* p= Taonode(word);
	Themnode(t, p);
	}
	fclose(file);	
}

void tachtu(Tree &t, char *s)			// Tach tu trong van ban 
{
	char *b;
	const char *delim = " \n";
	for (b = strtok(s, delim); b!= NULL; b = strtok(NULL, delim))
	{
		char word[11];
		strcpy(word, b);
		Xoadau(word);
	Node* p= Taonode(word);
	Themnode(t, p);
	}
}

void DoHoa()
{
	char a[] = "TRUONG DAI HOC BACH KHOA";
	char b[] = "KHOA CONG NGHE THONG TIN";
	char c[] = "DO AN CO SO";
	char d1[] = "TEN DE TAI: CHUONG TRINH DEM VA";
	char d2[] = "IN RA TAN SUAT XUAT HIEN CUA CAC TU";
	char d3[] = "TRONG MOT VAN BAN.";
	char e1[] = "Nguoi huong dan: NGUYEN VAN NGUYEN";
	char e2 [] = "Sinh vien thuc hien:";
	char e3 [] = "Le Quoc Huy - Lop 19TCLCDT2 - Nhom 19.10B";
	char f [] = "Nhan phim bat ki de chay chuong trinh.";
	
	initwindow (1200,800);
	setfillstyle (1,15);
	floodfill (200, 300 ,15);
	
	setcolor (3);
	setlinestyle (0, 0, 3);
	line (10, 10, 1190, 10);
	line (10, 10, 10, 790);
	line (10, 790, 1190, 790);
	line (1190, 790, 1190, 10);
	
	setcolor(3);
	setlinestyle (0, 0, 1);
	line (14, 14, 1186, 14);
	line (14, 14, 14, 786);
	line (14, 786, 1186, 786);
	line (1186, 786, 1186, 14);
	
	setbkcolor(15);
	setcolor (1);
	settextstyle (1, 0, 2);
	settextjustify (1,1);
	outtextxy (600, 50, a);
	settextstyle (1, 0, 3);
	outtextxy (600, 75, b);
	line (400, 90, 800, 90);
	
	setcolor (0);
	settextstyle (0, 0, 4);
	settextjustify (1,1);
	outtextxy (600, 300, c);
	
	setcolor (2);
	settextstyle (1, 0, 3);
	settextjustify (1,0);
	outtextxy (600, 400, d1);
	outtextxy (600, 440, d2);
	outtextxy (600, 480, d3);
	
	setcolor (0);
	settextstyle (9, 0, 1);
	settextjustify (1,1);
	outtextxy (600, 600, e1);
	settextjustify (0,1);
	outtextxy (340, 625, e2);
	outtextxy (340, 650, e3);
	
	setcolor (0);
	settextstyle (10, 0, 3);
	settextjustify (1,1);
	outtextxy (600, 770, f);
	
	getch();
	closegraph();
}

main()
{
	int cv;
	char a[1000];
	Tree t = NULL;
	
	DoHoa();
	
	while (true)
	{
		printf ("\n\n\t\t ------------- Bang lua chon -------------\n\n");
		printf ("1. Nhap van ban tu ban phim.\n");
		printf ("2. Doc van ban tu file.\n");
		printf ("0. Ket thuc.");
		printf ("\n\n\t\t -----------------------------------------\n");
		printf ("Nhap lua chon: ");
		scanf ("%d", &cv);
	if (cv < 0 || cv >2)
	{
		printf ("Lua chon khong hop le!");
	}
	
	else if (cv == 1)
	{
		printf ("Nhap van ban:\n");
		fflush (stdin);
		gets (a);
		tachtu(t, a);
		printf ("\n");	
		Hienthicaybanphim(t);
	}
	
	else if (cv == 2)
	{
		Docfile(t);
		Hienthicay(t);
	}
	else 
	{
		break;
	}
}
		
	return 0;
}

