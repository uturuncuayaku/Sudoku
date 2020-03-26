#include <gtk/gtk.h>
#include <gmodule.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
struct board{

	char s[9][9];
	int difficulty;
};
struct board initBoard()
{
	
}
void readBoard(struct board *s)
{
	FILE *f = fopen("puzzle.in", "r");
	char *su = malloc(81*sizeof(char)+1);
	fscanf(f, "%s", su);
//	printf("%s\n",su);

	int i,j, ct = 0;
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			s->s[i][j] = su[ct++];
//      printf("%c", s->s[i][j]);
		}
//		putchar('\n');
	}
	fclose(f);
	free(su);
}

int main(int argc, char *argv[])
{
	
	struct board *s;
	s = malloc(sizeof(struct board));
	readBoard(s);
	
	GtkWidget *window;
	GtkWidget *table;
	GtkWidget *button;
	
	char values[9][9];
	int i,j;
	for(i = 0; i < 9; i++)
	{	for(j = 0; j < 9; j++)
		{
			values[i][j] = s->s[i][j];
		}
	}
	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_container_set_border_width(GTK_CONTAINER(window), 100);
	gtk_window_set_default_size(GTK_WINDOW(window), 400,400);
	gtk_window_set_title(GTK_WINDOW(window), "Sudoku");

 
	table = gtk_table_new(9,9,TRUE);
	gtk_table_set_row_spacings(GTK_TABLE(table), 2);
	gtk_table_set_col_spacings(GTK_TABLE(table), 2);

	i = 0;
	j = 0;
	  for (i=0; i < 9; i++) {
		for (j=0; j < 9; j++) {
			gchar label[] = {values[i][j], '\0'};
			button = gtk_button_new_with_label(label);
			gtk_table_attach_defaults(GTK_TABLE(table), button, j, j+1, i, i+1);
		}
	  }

  gtk_container_add(GTK_CONTAINER(window), table);

  g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

  gtk_widget_show_all(window);
  gtk_main();


return(0);
}
