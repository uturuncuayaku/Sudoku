#include <gtk/gtk.h>

static void callback( GtkWidget *widget, gpointer data)
{
	g_print("callback - %s was pressed\n", (gchar *)data);
}
static gboolean delete_event(GtkWidget *widget, GdkEvent *event, gpointer data)
{
	gtk_main_quit();
	return FALSE;
}
int main(int argc, char **argv)
{

	GtkWidget *window;
	GtkWidget *button;
	GtkWidget *box1;

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Sudoku");

	g_signal_connect(window, "delete-event", G_CALLBACK(delete_event), NULL);

	/* Decor  window */
	gtk_container_set_border_width(GTK_CONTAINER(window), 100);

	/* Box */
	/* Add */
	box1 = gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(window),box1);

	/* Button */
	button = gtk_button_new_with_label("Hint");
	g_signal_connect(button, "clicked", G_CALLBACK(callback),(gpointer) "button 1");

	gtk_box_pack_start(GTK_BOX(box1), button, TRUE, TRUE, 0);

	gtk_widget_show(button);
	gtk_widget_show(box1);
	gtk_widget_show(window);	
	gtk_main();

	return(0);
}
