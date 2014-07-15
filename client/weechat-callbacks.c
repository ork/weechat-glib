/* See COPYING file for license and copyright information */

#include "../lib/weechat-commands.h"
#include "weechat-callbacks.h"

void cb_focusentry(GtkWidget* widget,
                   G_GNUC_UNUSED gpointer data)
{
    if (GTK_IS_ENTRY(widget)) {
        gtk_widget_grab_default(widget);
        gtk_widget_grab_focus(widget);
    }
}

void cb_tabswitch(G_GNUC_UNUSED GtkNotebook* notebook,
                  GtkWidget* page,
                  G_GNUC_UNUSED guint page_num,
                  G_GNUC_UNUSED gpointer user_data)
{
    gtk_container_foreach(GTK_CONTAINER(page), cb_focusentry, NULL);
}

void cb_input(GtkWidget* widget, gpointer data)
{
    weechat_t* weechat = data;

    if (gtk_entry_get_text_length(GTK_ENTRY(widget)) > 0) {
        weechat_cmd_input(weechat,
                          gtk_widget_get_name(widget),
                          gtk_entry_get_text(GTK_ENTRY(widget)));
    }
    gtk_entry_set_text(GTK_ENTRY(widget), "");
}