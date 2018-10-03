#include<gtk-3.0/gtk/gtk.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#include<limits.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<math.h>
#define atoa(x) #x
#define E 2.71828
#define SUM 0
#define SUB 1
#define MULT 2
#define DIV 3
#define MOD 4
#define POW 5	
#define EMPTY -1
#define NONE 100
#define NUMBER 1000
#define SYMBOL -1000
unsigned int myfact(int n)
{
    int i;
    unsigned int f = 1;
    
    if (n < 0) {
     g_print("Syntax error"); // gtk_entry_set_text(GTK_ENTRY(entry), "sytax error");
	return INT_MIN;
	}
    else {
        for(i=1; i<=n; ++i) {
            f = f*i;              
        }
       
    }

    return f;
}

char* itoa(int n) {
	int flag = 0;
    char* str = NULL;
    int numChars = 0; 
    if (n < 0) {
        n = -n;
        flag = -1;
        numChars++;
    }
    
    int temp = n;
    do {
        numChars++;
        temp = temp/10;
    } while ( temp );
    
    str = (char*)malloc(sizeof(char)*(numChars + 1));
    str[numChars] = 0;
    
    if (flag == -1) str[0] = '-';
    
    int i = numChars - 1;
    do {
        str[i--] = n%10 + '0';
        n = n/10;
    } while (n);
    return str;
}
int main(int argc, char *argv[]) {
	gtk_init(&argc, &argv);

	GtkWidget *window;
	
	GtkWidget *grid;
	GtkWidget *b9;
	GtkWidget *b8;
	GtkWidget *b7;
	GtkWidget *b6;
	GtkWidget *b5;
	GtkWidget *b4;
	GtkWidget *b3;
	GtkWidget *b2;
	GtkWidget *b1;
	GtkWidget *b0;
	GtkWidget *x;
	GtkWidget *c;
	GtkWidget *e;
	
	GtkWidget *plus;
	GtkWidget *minus;
	GtkWidget *mult;
	GtkWidget *div;
	GtkWidget *mod;
	
	GtkWidget *dot;
	
	GtkWidget *sine;
	GtkWidget *cosine;
	GtkWidget *mytan;
	GtkWidget *inv;
	GtkWidget *mylog;
	GtkWidget *ln;
	GtkWidget *mysqrt;
	GtkWidget *square;
	GtkWidget *lb;
	GtkWidget *rb;
	GtkWidget *mypow;
	GtkWidget *entry;
	
	GtkWidget *ten;
	GtkWidget *fact;	
	GtkWidget *pi;	
	GtkWidget *exp;
	
	GtkToolItem *sep;
	GtkWidget *status;
	GtkWidget *frame;
	grid = gtk_grid_new();
	frame = gtk_frame_new("");
	
	gtk_grid_set_row_spacing (GTK_GRID(grid), 5);
	gtk_grid_set_column_spacing (GTK_GRID(grid), 5);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_container_set_border_width(GTK_CONTAINER(window), 20);
	gtk_window_set_default_size(GTK_WINDOW(window), 300, 300);
	gtk_window_set_title(GTK_WINDOW(window), "CALCULATOR");
// adding grid to frame n frame to window	
	gtk_container_add(GTK_CONTAINER(frame), grid);
	gtk_container_set_border_width(GTK_CONTAINER(grid), 15);
	gtk_container_add(GTK_CONTAINER(window), frame);
	entry = gtk_entry_new();
	
//	gtk_editable_set_editable (GTK_EDITABLE(entry), TRUE);
	status = gtk_statusbar_new();
//	gtk_toolbar_insert(GTK_TOOLBAR(entry), sep, -1);
	gtk_entry_grab_focus_without_selecting(GTK_ENTRY(entry));
//	gtk_entry_set_width_chars(GTK_ENTRY(entry), 30); 
	//gtk_container_add(GTK_CONTAINER(window), entry);
	if(entry != NULL) {
	//	gtk_container_add(GTK_CONTAINER(grid), entry);
	//	printf("entry NULL");
	}
	
	
	gtk_grid_attach(GTK_GRID(grid), entry, 0, 0, 6, 2);
	
	b0 = gtk_button_new_with_label("0");
	gtk_grid_attach(GTK_GRID(grid), b0, 2, 8, 1, 1);
	
	void b0press(GtkWidget *widget, gpointer data) {
	gtk_frame_set_label(GTK_FRAME(frame), "");
	char p[512];
	 strcpy(p, gtk_entry_get_text(GTK_ENTRY(entry)));
	
	strcat(p, "0");
	gtk_entry_set_text(GTK_ENTRY(entry), p);
	}
	g_signal_connect(G_OBJECT(b0), "clicked", G_CALLBACK(b0press), NULL);
	
	b1 = gtk_button_new_with_label("  1  ");
	gtk_grid_attach(GTK_GRID(grid), b1, 3, 7, 1, 1);
	void b1press(GtkWidget *widget, gpointer data) {
	gtk_frame_set_label(GTK_FRAME(frame), "");
	char p[512];
	 strcpy(p, gtk_entry_get_text(GTK_ENTRY(entry)));
	
	strcat(p, "1");
	gtk_entry_set_text(GTK_ENTRY(entry), p);
	}
	g_signal_connect(G_OBJECT(b1), "clicked", G_CALLBACK(b1press), NULL);
	
	b2 = gtk_button_new_with_label("  2  ");
	
	gtk_grid_attach(GTK_GRID(grid), b2, 2, 7, 1, 1);
	void b2press(GtkWidget *widget, gpointer data) {
	gtk_frame_set_label(GTK_FRAME(frame), "");
	char p[512];
	 strcpy(p, gtk_entry_get_text(GTK_ENTRY(entry)));
	
	strcat(p, "2");
	gtk_entry_set_text(GTK_ENTRY(entry), p);
//	gtk_editable_insert_text(GTK_EDITABLE(entry), "2", 10, 0);
	}
	g_signal_connect(G_OBJECT(b2), "clicked", G_CALLBACK(b2press), NULL);
	
	b3 = gtk_button_new_with_label("  3  ");
	gtk_grid_attach(GTK_GRID(grid), b3, 1, 7, 1, 1);
	
	void b3press(GtkWidget *widget, gpointer data) {
	gtk_frame_set_label(GTK_FRAME(frame), "");
	char p[512];
	 strcpy(p, gtk_entry_get_text(GTK_ENTRY(entry)));
	
	strcat(p, "3");
	gtk_entry_set_text(GTK_ENTRY(entry), p);
	}
	g_signal_connect(G_OBJECT(b3), "clicked", G_CALLBACK(b3press), NULL);
	
	b4 = gtk_button_new_with_label("  4  ");
	gtk_grid_attach(GTK_GRID(grid), b4, 3, 6, 1, 1);
	
	void b4press(GtkWidget *widget, gpointer data) {
	gtk_frame_set_label(GTK_FRAME(frame), "");
	char p[512];
	 strcpy(p, gtk_entry_get_text(GTK_ENTRY(entry)));
	
	strcat(p, "4");
	gtk_entry_set_text(GTK_ENTRY(entry), p);
	}
	g_signal_connect(G_OBJECT(b4), "clicked", G_CALLBACK(b4press), NULL);
	
	b5 = gtk_button_new_with_label("  5  ");
	gtk_grid_attach(GTK_GRID(grid), b5, 2, 6, 1, 1);
	
	void b5press(GtkWidget *widget, gpointer data) {
	gtk_frame_set_label(GTK_FRAME(frame), "");
	char p[512];
	 strcpy(p, gtk_entry_get_text(GTK_ENTRY(entry)));
	
	strcat(p, "5");
	gtk_entry_set_text(GTK_ENTRY(entry), p);
	}
	g_signal_connect(G_OBJECT(b5), "clicked", G_CALLBACK(b5press), NULL);
	
	b6 = gtk_button_new_with_label("  6  ");
	gtk_grid_attach(GTK_GRID(grid), b6, 1, 6, 1, 1);
	
	void b6press(GtkWidget *widget, gpointer data) {
	gtk_frame_set_label(GTK_FRAME(frame), "");
	char p[512];
	 strcpy(p, gtk_entry_get_text(GTK_ENTRY(entry)));
	
	strcat(p, "6");
	gtk_entry_set_text(GTK_ENTRY(entry), p);
	}
	g_signal_connect(G_OBJECT(b6), "clicked", G_CALLBACK(b6press), NULL);
	
	b7 = gtk_button_new_with_label("  7  ");
	gtk_grid_attach(GTK_GRID(grid), b7, 3, 5, 1, 1);
	
	void b7press(GtkWidget *widget, gpointer data) {
	gtk_frame_set_label(GTK_FRAME(frame), "");
	char p[512];
	 strcpy(p, gtk_entry_get_text(GTK_ENTRY(entry)));
	
	strcat(p, "7");
	gtk_entry_set_text(GTK_ENTRY(entry), p);
	}
	g_signal_connect(G_OBJECT(b7), "clicked", G_CALLBACK(b7press), NULL);
	
	b8 = gtk_button_new_with_label("  8  ");
	gtk_grid_attach(GTK_GRID(grid), b8, 2, 5, 1, 1);
	
	void b8press(GtkWidget *widget, gpointer data) {
	gtk_frame_set_label(GTK_FRAME(frame), "");
	char p[512];
	 strcpy(p, gtk_entry_get_text(GTK_ENTRY(entry)));
	
	strcat(p, "8");
	gtk_entry_set_text(GTK_ENTRY(entry), p);
	}
	g_signal_connect(G_OBJECT(b8), "clicked", G_CALLBACK(b8press), NULL);
	
	b9 = gtk_button_new_with_label("  9  ");
	gtk_grid_attach(GTK_GRID(grid), b9, 1, 5, 1, 1);
	
	void b9press(GtkWidget *widget, gpointer data) {
	gtk_frame_set_label(GTK_FRAME(frame), "");
	char p[512];
	strcpy(p, gtk_entry_get_text(GTK_ENTRY(entry)));
	
	strcat(p, "9");
	gtk_entry_set_text(GTK_ENTRY(entry), p);
	}
	g_signal_connect(G_OBJECT(b9), "clicked", G_CALLBACK(b9press), NULL);
	
	e = gtk_button_new_with_label("    =    ");
	gtk_grid_attach(GTK_GRID(grid), e, 4, 6, 1, 2);
// working with ints and floats
	void xmain() {
		gtk_frame_set_label(GTK_FRAME(frame), "");
		int flag = 0;
		float ans;
		float power;
		char str[128] = "56 % 7";
   		char a[2] = "+";
   		char b[2] = "-";
   		char c[2] = "*";
   		char d[2] = "/";
   		char e[2] = "%";
  		char f[2] = "^";
   		char x;
   		int state = INT_MIN, i = 0, isno = NUMBER;
		char *token;
   		
   		strcpy(str, gtk_entry_get_text(GTK_ENTRY(entry)));
   		if(strcmp(str, "") == 0){
   			flag = EMPTY;
   			puts("null entry");
   		}
   		while(str[i] != '\0') {
			if(str[i] == '+' || str[i] =='-' || str[i] == '/' || str[i] == '*' || str[i] == '%' || str[i] == '^')
				isno = SYMBOL;
				i++;
			}	
		i = 0;	
   		if(flag == -1) {
   			gtk_entry_grab_focus_without_selecting(GTK_ENTRY(entry));
   		}	
   		if(isno == NUMBER) {
   			puts("only number");
   			gtk_entry_set_text(GTK_ENTRY(entry), str);
   			
   			return;
   			}
   		if(flag != -1) {
   			while(str[i] != '\0') {
   				x = str[i++];
   			switch(x) {
   				case '0': case '1': case '2':
				case '4': case '5': case '6':
				case '7': case '8': case '9':
				case '3': case '.':
//					state = NONE;
					break;
   				case '+' :
   					state = SUM;
   					puts("state sum");
   					break;
   				case '-' :
   					state = SUB;
   					puts("state sub");
   					break;
   				case '*' :
   					state = MULT;
   					puts("state mult");
   					break;
   				case '/' :
   					state = DIV;
   					puts("state div");
   					break;
   				case '%' :
   					state = MOD;
   					puts("state mod");
   					break;
   				case '^' :
   					state = POW;
   					puts("state power");
   					break;	
   				case ' ':	
   					break;	
   				default:
// try this    		 change none to sum		
   					state = NONE;
   					puts("state NONE");
   					break;	
  	 	}
   	}
   	}
   	float sum = 0, prod = 1, div, diff;
   	int mod;
  	 	switch(state) {
   			case SUM :
 				token = strtok(str, a);
 //				if(token == NULL)
 //				sum = sum + atof(str);
  				while( token != NULL ) {
      				sum = sum + atof(token);
      				token = strtok(NULL, a);
   					}
   				
 	 			printf("\nsum : %f", sum);
 	 			ans = sum;
  			break;
  			case SUB :
 				token = strtok(str, b);
 				if(token != NULL) {
 					diff = atof(token);
 				}
  				while( token != NULL ) {
  					token = strtok(NULL, b);
  					if(token != NULL)
      					diff = diff - atof(token);
   				}
  				printf("\nDiff : %f", diff);
  				ans = diff;
  				break;
  		
  			case MULT :
 				token = strtok(str, c);
 			
  				while( token != NULL ) {
  					prod = prod * atof(token);
  					token = strtok(NULL, c);
   					}
  				printf("\n prod : %f", prod);
  				ans = prod;
  				break;
  		
  			case DIV :
 				token = strtok(str, d);
 				if(token != NULL) {
 					div = atof(token);
 					}
  				while( token != NULL ) {
  					token = strtok(NULL, d);
  					if(token != NULL)
      					div = div / atof(token);
   					}
  				printf("\n Div : %f", div);
  				ans = div;
  				break;
  		
  			case MOD :
 				token = strtok(str, e);
 				if(token != NULL) {
 					mod = atoi(token);
 					}
  				while( token != NULL ) {
  					token = strtok(NULL, e);
  					if(token != NULL)
      					mod = mod % atoi(token);
   					}
  				printf("\n mod : %d", mod);
  				ans = mod;
  				break;
  			case POW :
 				token = strtok(str, f);
 				if(token != NULL) {
 					power = atof(token);
 					}
  				while( token != NULL ) {
  					token = strtok(NULL, f);
  				if(token != NULL)
      				power =  pow(power, atof(token));
   				}
  				printf("\n power : %f", power);
  				ans = power;
  				break;
  			case NONE :
				flag = EMPTY;	
				printf(" executing none on %s", str);
				gtk_entry_set_text(GTK_ENTRY(entry), str);
//	  			ans = atof(str);
  				break;	
   		}
   		if(flag != EMPTY) {
   			char p[100];
			if((ans - (int)ans) == 0 ) {
				strcpy(p, itoa(ans));
				puts(p);
				gtk_entry_set_text(GTK_ENTRY(entry), p);
			}
			else {
				sprintf(p, "%f", ans);
				puts(p);
				gtk_entry_set_text(GTK_ENTRY(entry), p);
			}
		}
	}
	
	
/*	void str(GtkWidget *widget, gpointer data) {
		char *p = gtk_entry_get_text(GTK_ENTRY(entry));
		printf("%s", p);
		g_print("equal pushed");
	}
*/	g_signal_connect(G_OBJECT(e), "clicked", G_CALLBACK(xmain), NULL);
	
	c = gtk_button_new_with_label("    C    ");
	gtk_grid_attach(GTK_GRID(grid), c,  4, 8, 1, 2);
	
	void cpress(GtkWidget *widget, gpointer data) {
		gtk_frame_set_label(GTK_FRAME(frame), "");
		gtk_entry_set_text(GTK_ENTRY(entry), "");
		gtk_entry_grab_focus_without_selecting(GTK_ENTRY(entry));
	}
	
	g_signal_connect(G_OBJECT(c), "clicked", G_CALLBACK(cpress), NULL);
	
	
	x = gtk_button_new_with_label("    X    ");
	gtk_grid_attach(GTK_GRID(grid), x, 4, 5, 1, 1);
	
//	g_signal_connect(G_OBJECT(x), "clicked", G_CALLBACK(backspace(*entry)), NULL);
	void xpress(GtkWidget *widget, gpointer data) {
		gtk_frame_set_label(GTK_FRAME(frame), "");
		int flag = 0;
		char *p =(char *) gtk_entry_get_text(GTK_ENTRY(entry));
		int l = strlen(p);
		if(p == "") {
			flag = -1;
			puts("nothing to erase");
		}
		char t[100];
		if(flag == 0){
			snprintf(t, l, "%s", p);
			gtk_entry_set_text(GTK_ENTRY(entry), t);
//			strncpy(t, p, l-1);
//			p[l-1] = '\0';
//			sprintf(t, "%s", p);
		
//			gtk_entry_grab_focus_without_selecting(GTK_ENTRY(entry));
		}
//		else {
//			gtk_entry_grab_focus_without_selecting(GTK_ENTRY(entry));
//		}
	}
	g_signal_connect(G_OBJECT(x), "clicked", G_CALLBACK(xpress), NULL);

	plus = gtk_button_new_with_label("  +  ");
	gtk_grid_attach(GTK_GRID(grid), plus, 1, 4, 1, 1);
	
	void xplus(GtkWidget *widget, gpointer data) {
	gtk_frame_set_label(GTK_FRAME(frame), "");
	char p[512];
	strcpy(p, gtk_entry_get_text(GTK_ENTRY(entry)));
	
	strcat(p, "+");
	gtk_entry_set_text(GTK_ENTRY(entry), p);
	}
	g_signal_connect(G_OBJECT(plus), "clicked", G_CALLBACK(xplus), NULL);
	
	minus = gtk_button_new_with_label("  -  ");
	gtk_grid_attach(GTK_GRID(grid), minus, 2, 4, 1, 1);
	
	void xminus(GtkWidget *widget, gpointer data) {
	gtk_frame_set_label(GTK_FRAME(frame), "");
	char p[512];
	 strcpy(p, gtk_entry_get_text(GTK_ENTRY(entry)));
	
	strcat(p, "-");
	gtk_entry_set_text(GTK_ENTRY(entry), p);
	}
	g_signal_connect(G_OBJECT(minus), "clicked", G_CALLBACK(xminus), NULL);
	
	mult = gtk_button_new_with_label("  *  ");
	gtk_grid_attach(GTK_GRID(grid), mult, 3, 4, 1, 1);
	
	void xmult(GtkWidget *widget, gpointer data) {
	gtk_frame_set_label(GTK_FRAME(frame), "");
	char p[512];
	 strcpy(p, gtk_entry_get_text(GTK_ENTRY(entry)));
	
	strcat(p, "*");
	gtk_entry_set_text(GTK_ENTRY(entry), p);
	}
	g_signal_connect(G_OBJECT(mult), "clicked", G_CALLBACK(xmult), NULL);
	
	div = gtk_button_new_with_label("  /  ");
	gtk_grid_attach(GTK_GRID(grid), div, 4, 4, 1, 1);
	
	void xdiv(GtkWidget *widget, gpointer data) {
	gtk_frame_set_label(GTK_FRAME(frame), "");
	char p[512];
	 strcpy(p, gtk_entry_get_text(GTK_ENTRY(entry)));
	
	strcat(p, "/");
	gtk_entry_set_text(GTK_ENTRY(entry), p);
	}
	g_signal_connect(G_OBJECT(div), "clicked", G_CALLBACK(xdiv), NULL);
	
	mod = gtk_button_new_with_label("\t%\t");
	gtk_grid_attach(GTK_GRID(grid), mod, 3, 8, 1, 1);
	
	void xmod(GtkWidget *widget, gpointer data) {
	gtk_frame_set_label(GTK_FRAME(frame), "");
	char p[512];
	 strcpy(p, gtk_entry_get_text(GTK_ENTRY(entry)));
	
	strcat(p, "%");
	gtk_entry_set_text(GTK_ENTRY(entry), p);
	}
	g_signal_connect(G_OBJECT(mod), "clicked", G_CALLBACK(xmod), NULL);
	
	dot = gtk_button_new_with_label("  \t. \t ");
	gtk_grid_attach(GTK_GRID(grid), dot, 1, 8, 1, 1);
	
	void dotpress(GtkWidget *widget, gpointer data) {
	gtk_frame_set_label(GTK_FRAME(frame), "");
	char p[512];
	 strcpy(p, gtk_entry_get_text(GTK_ENTRY(entry)));
	
	strcat(p, ".");
	gtk_entry_set_text(GTK_ENTRY(entry), p);
	}
	g_signal_connect(G_OBJECT(dot), "clicked", G_CALLBACK(dotpress), NULL);
	
	sine = gtk_button_new_with_label("    sin    ");
	gtk_grid_attach(GTK_GRID(grid), sine, 1, 2, 1, 1);
	
	void xsine(GtkWidget *widget, gpointer data) {
		char ptr[100];
		strcpy(ptr, gtk_entry_get_text(GTK_ENTRY(entry)));
		char str[128] = "sin(";
		strcat(str, ptr);
		strcat(str, ")");
		gtk_frame_set_label(GTK_FRAME(frame), str);
		float x = atof(gtk_entry_get_text(GTK_ENTRY(entry)));
		x = x*3.14159/180;
		x = sin(x);
		
		char p[100];
		if((x - (int)x) == 0 ) {
//			p = itoa(x);
			strcpy(p, itoa(x));
			puts(p);
			gtk_entry_set_text(GTK_ENTRY(entry), p);
		}
		else {
			sprintf(p, "%f", x);
			puts(p);
			gtk_entry_set_text(GTK_ENTRY(entry), p);
		}
	}
	g_signal_connect(G_OBJECT(sine), "clicked", G_CALLBACK(xsine), NULL);
	
	cosine = gtk_button_new_with_label("    cos    ");
	gtk_grid_attach(GTK_GRID(grid), cosine, 2, 2, 1, 1);
	
	void xcos(GtkWidget *widget, gpointer data) {
		char ptr[100];
		strcpy(ptr, gtk_entry_get_text(GTK_ENTRY(entry)));
		char str[128] = "cos(";
		strcat(str, ptr);
		strcat(str, ")");
		gtk_frame_set_label(GTK_FRAME(frame), str);
		float x = atof(gtk_entry_get_text(GTK_ENTRY(entry)));
		x = x*3.14159/180;
		x = cos(x);
		
		char p[100];
		if((x - (int)x) == 0 ) {
//			p = itoa(x);
			strcpy(p, itoa(x));
			puts(p);
			gtk_entry_set_text(GTK_ENTRY(entry), p);
		}
		else {
			sprintf(p, "%f", x);
			puts(p);
			gtk_entry_set_text(GTK_ENTRY(entry), p);
		}
	}
	g_signal_connect(G_OBJECT(cosine), "clicked", G_CALLBACK(xcos), NULL);
	
	mytan = gtk_button_new_with_label("    tan    ");
	gtk_grid_attach(GTK_GRID(grid), mytan, 3, 2, 1, 1);
	
	void xtan(GtkWidget *widget, gpointer data) {
		char ptr[100];
		strcpy(ptr, gtk_entry_get_text(GTK_ENTRY(entry)));
		char str[128] = "tan(";
		strcat(str, ptr);
		strcat(str, ")");
		gtk_frame_set_label(GTK_FRAME(frame), str);
		float x = atof(gtk_entry_get_text(GTK_ENTRY(entry)));
		x = x*3.14159/180;
		x = tan(x);
		
		char p[100];
		if((x - (int)x) == 0 ) {
//			p = itoa(x);
			strcpy(p, itoa(x));
			puts(p);
			gtk_entry_set_text(GTK_ENTRY(entry), p);
		}
		else {
			sprintf(p, "%f", x);
			puts(p);
			gtk_entry_set_text(GTK_ENTRY(entry), p);
		}
	}
	g_signal_connect(G_OBJECT(mytan), "clicked", G_CALLBACK(xtan), NULL);
	
	inv = gtk_button_new_with_label("    1/x    ");
	gtk_grid_attach(GTK_GRID(grid), inv, 4, 2, 1, 1);
//it is working	
	void inverse(GtkWidget *widget, gpointer data) {
		char ptr[100];
		strcpy(ptr, gtk_entry_get_text(GTK_ENTRY(entry)));
		char str[128] = "(";
		strcat(str, ptr);
		strcat(str, ")^-1");
		gtk_frame_set_label(GTK_FRAME(frame), str);
		float x = atof(gtk_entry_get_text(GTK_ENTRY(entry)));
		x = 1/x;
		
		char p[100];
		if((x - (int)x) == 0 ) {
//			p = itoa(x);
			strcpy(p, itoa(x));
			puts(p);
			gtk_entry_set_text(GTK_ENTRY(entry), p);
		}
		else {
			sprintf(p, "%f", x);
			puts(p);
			gtk_entry_set_text(GTK_ENTRY(entry), p);
		}
	}
	g_signal_connect(G_OBJECT(inv), "clicked", G_CALLBACK(inverse), NULL);
	
	mysqrt = gtk_button_new_with_label("    sqrt    ");
	gtk_grid_attach(GTK_GRID(grid), mysqrt, 1, 3, 1, 1);
// int working 	float working
	void root(GtkWidget *widget, gpointer data) {
		char ptr[100];
		strcpy(ptr, gtk_entry_get_text(GTK_ENTRY(entry)));
		char str[128] = "sqrt(";
		strcat(str, ptr);
		strcat(str, ")");
		gtk_frame_set_label(GTK_FRAME(frame), str);
		float x = atof(gtk_entry_get_text(GTK_ENTRY(entry)));
		x = sqrt(x);
		
		char p[100];
		if((x - (int)x) == 0 ) {
//			p = itoa(x);
			strcpy(p, itoa(x));
			puts(p);
			gtk_entry_set_text(GTK_ENTRY(entry), p);
		}
		else {
			sprintf(p, "%f", x);
			puts(p);
			gtk_entry_set_text(GTK_ENTRY(entry), p);
		}
	}
	g_signal_connect(G_OBJECT(mysqrt), "clicked", G_CALLBACK(root), NULL);
	
	mypow = gtk_button_new_with_label("    x^y    ");
	gtk_grid_attach(GTK_GRID(grid), mypow, 0, 6, 1, 1);
	
	void xpow(GtkWidget *widget, gpointer data) {
	char ptr[100];
		strcpy(ptr, gtk_entry_get_text(GTK_ENTRY(entry)));
		char str[128] = "(";
		strcat(str, ptr);
		strcat(str, ")");
		gtk_frame_set_label(GTK_FRAME(frame), str);
	char p[512];
	strcpy(p, gtk_entry_get_text(GTK_ENTRY(entry)));
	strcat(p, "^");
	gtk_entry_set_text(GTK_ENTRY(entry), p);
	}
	g_signal_connect(G_OBJECT(mypow), "clicked", G_CALLBACK(xpow), NULL);
	
	exp = gtk_button_new_with_label("    e^    ");
	gtk_grid_attach(GTK_GRID(grid), exp, 0, 7, 1, 1);
// working with ints	and float
	void epow(GtkWidget *widget, gpointer data) {
		char ptr[100];
		strcpy(ptr, gtk_entry_get_text(GTK_ENTRY(entry)));
		char str[128] = "exp(";
		strcat(str, ptr);
		strcat(str, ")");
		gtk_frame_set_label(GTK_FRAME(frame), str);
		float x = atof(gtk_entry_get_text(GTK_ENTRY(entry)));
		x = pow(E, x);
		
		char p[100];
		if((x - (int)x) == 0 ) {
//			p = itoa(x);
			strcpy(p, itoa(x));
			puts(p);
			gtk_entry_set_text(GTK_ENTRY(entry), p);
		}
		else {
			sprintf(p, "%f", x);
			puts(p);
			gtk_entry_set_text(GTK_ENTRY(entry), p);
		}
	}
	g_signal_connect(G_OBJECT(exp), "clicked", G_CALLBACK(epow), NULL);
	
	ten = gtk_button_new_with_label("    10^x    ");
	gtk_grid_attach(GTK_GRID(grid), ten, 0, 8, 1, 1);
//works with ins... and float
	void tenpow(GtkWidget *widget, gpointer data) {
		char ptr[100];
		strcpy(ptr, gtk_entry_get_text(GTK_ENTRY(entry)));
		char str[128] = "(10 ^ ";
		strcat(str, ptr);
		strcat(str, ")");
		gtk_frame_set_label(GTK_FRAME(frame), str);
		float x = atof(gtk_entry_get_text(GTK_ENTRY(entry)));
		x = pow(10, x);
		
		char p[100];
		if((x - (int)x) == 0 ) {
//			p = itoa(x);
			strcpy(p, itoa(x));
			puts(p);
			gtk_entry_set_text(GTK_ENTRY(entry), p);
		}
		else {
			sprintf(p, "%f", x);
			puts(p);
			gtk_entry_set_text(GTK_ENTRY(entry), p);
		}
	}
	g_signal_connect(G_OBJECT(ten), "clicked", G_CALLBACK(tenpow), NULL);
	
	square = gtk_button_new_with_label("    x^2    ");
	gtk_grid_attach(GTK_GRID(grid), square, 2, 3, 1, 1);
//square  working here with ints....
	void xsquare(GtkWidget *widget, gpointer data) {
		char ptr[100];
		strcpy(ptr, gtk_entry_get_text(GTK_ENTRY(entry)));
		char str[128] = "(";
		strcat(str, ptr);
		strcat(str, ")^2");
		gtk_frame_set_label(GTK_FRAME(frame), str);
		float x = atof(gtk_entry_get_text(GTK_ENTRY(entry)));
		x = x*x;
		
		char p[100];
		if((x - (int)x) == 0 ) {
//			p = itoa(x);
			strcpy(p, itoa(x));
			puts(p);
			gtk_entry_set_text(GTK_ENTRY(entry), p);
		}
		else {
			sprintf(p, "%f", x);
			puts(p);
			gtk_entry_set_text(GTK_ENTRY(entry), p);
		}
	}
	g_signal_connect(G_OBJECT(square), "clicked", G_CALLBACK(xsquare), NULL);
	
	lb = gtk_button_new_with_label("    (    ");
	gtk_grid_attach(GTK_GRID(grid), lb, 3, 3, 1, 1);
	
	void xlb(GtkWidget *widget, gpointer data) {
	gtk_frame_set_label(GTK_FRAME(frame), "");
	char p[512];
	 strcpy(p, gtk_entry_get_text(GTK_ENTRY(entry)));
	
	strcat(p, "(");
	gtk_entry_set_text(GTK_ENTRY(entry), p);
	}
	g_signal_connect(G_OBJECT(lb), "clicked", G_CALLBACK(xlb), NULL);
	
	rb = gtk_button_new_with_label("    )    ");
	gtk_grid_attach(GTK_GRID(grid), rb, 4, 3, 1, 1);
	
	void xrb(GtkWidget *widget, gpointer data) {
	gtk_frame_set_label(GTK_FRAME(frame), "");
	char p[512];
	 strcpy(p, gtk_entry_get_text(GTK_ENTRY(entry)));
	
	strcat(p, ")");
	gtk_entry_set_text(GTK_ENTRY(entry), p);
	}
	g_signal_connect(G_OBJECT(rb), "clicked", G_CALLBACK(xrb), NULL);
	
	mylog = gtk_button_new_with_label("    log    ");
	gtk_grid_attach(GTK_GRID(grid), mylog, 0, 2, 1, 1);
	
	void tenlog(GtkWidget *widget, gpointer data) {
		char ptr[100];
		strcpy(ptr, gtk_entry_get_text(GTK_ENTRY(entry)));
		char str[128] = "log(";
		strcat(str, ptr);
		strcat(str, ")");
		gtk_frame_set_label(GTK_FRAME(frame), str);
		float x = atof(gtk_entry_get_text(GTK_ENTRY(entry)));
		float t = x;
		x = log(x)/2.303;
		if(t == 10 || 100 || 1000 || 10000 || 100000 || 1000000 || 10000000 || 100000000 || 1000000000) {
		//	x = x + 1;
		//	x = (int)x;
		}
		char p[100];
		if((x - (int)x) == 0 ) {
//			p = itoa(x);
			strcpy(p, itoa(x));
			puts(p);
			gtk_entry_set_text(GTK_ENTRY(entry), p);
		}
		else {
			sprintf(p, "%f", x);
			puts(p);
			gtk_entry_set_text(GTK_ENTRY(entry), p);
		}
	}
	g_signal_connect(G_OBJECT(mylog), "clicked", G_CALLBACK(tenlog), NULL);
	
	ln = gtk_button_new_with_label("    ln    ");
	gtk_grid_attach(GTK_GRID(grid), ln, 0, 3, 1, 1);
	
	void elog(GtkWidget *widget, gpointer data) {
		char ptr[100];
		strcpy(ptr, gtk_entry_get_text(GTK_ENTRY(entry)));
		char str[128] = "ln(";
		strcat(str, ptr);
		strcat(str, ")");
		gtk_frame_set_label(GTK_FRAME(frame), str);
		float x = atof(gtk_entry_get_text(GTK_ENTRY(entry)));
		x = log(x);
		
		char p[100];
		if((x - (int)x) == 0 ) {
//			p = itoa(x);
			strcpy(p, itoa(x));
			puts(p);
			gtk_entry_set_text(GTK_ENTRY(entry), p);
		}
		else {
			sprintf(p, "%f", x);
			puts(p);
			gtk_entry_set_text(GTK_ENTRY(entry), p);
		}
	}
	g_signal_connect(G_OBJECT(ln), "clicked", G_CALLBACK(elog), NULL);
	
	fact = gtk_button_new_with_label("    n!    ");
	gtk_grid_attach(GTK_GRID(grid), fact, 0, 4, 1, 1);
//works successfully	
		void facto(GtkWidget *widget, gpointer data) {
		char ptr[100];
		strcpy(ptr, gtk_entry_get_text(GTK_ENTRY(entry)));
		char str[128] = "factorial(";
		strcat(str, ptr);
		strcat(str, ")");
		gtk_frame_set_label(GTK_FRAME(frame), str);
		float x = atoi(gtk_entry_get_text(GTK_ENTRY(entry)));
		x = myfact(x);
		
		char p[100];
	//	p = itoa(x);
		strcpy(p, itoa(x));
		puts(p);
		gtk_entry_set_text(GTK_ENTRY(entry), p);
	}
	g_signal_connect(G_OBJECT(fact), "clicked", G_CALLBACK(facto), NULL);
	
	pi = gtk_button_new_with_label("    pi    ");
	gtk_grid_attach(GTK_GRID(grid), pi, 0, 5, 1, 1);
	
	void pipress(GtkWidget *widget, gpointer data) {
	gtk_frame_set_label(GTK_FRAME(frame), "");
	char p[512];
	strcpy(p, gtk_entry_get_text(GTK_ENTRY(entry)));
	
	strcat(p, "3.14159");
	gtk_entry_set_text(GTK_ENTRY(entry), p);
	}
	g_signal_connect(G_OBJECT(pi), "clicked", G_CALLBACK(pipress), NULL);
	
	
	exp = gtk_button_new_with_label("    e    ");
	gtk_grid_attach(GTK_GRID(grid), exp, 0, 9, 1, 1);
	void epress(GtkWidget *widget, gpointer data) {
	char p[512];
	strcpy(p, gtk_entry_get_text(GTK_ENTRY(entry)));
	
	strcat(p, "2.71828");
	gtk_entry_set_text(GTK_ENTRY(entry), p);
	}
	g_signal_connect(G_OBJECT(exp), "clicked", G_CALLBACK(epress), NULL);
	
	gtk_widget_show_all(window);
	gtk_main();
	return 0;
}
