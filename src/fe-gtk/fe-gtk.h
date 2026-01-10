/* ZoiteChat
 * Copyright (C) 1998-2010 Peter Zelezny.
 * Copyright (C) 2009-2013 Berke Viktor.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#ifndef HEXCHAT_FE_GTK_H
#define HEXCHAT_FE_GTK_H

#include "config.h"

#define DISPLAY_NAME "ZoiteChat"

#ifndef WIN32
#include <sys/types.h>
#endif

#include <glib/gi18n.h>
#include <gtk/gtk.h>

#ifdef HAVE_GTK_MAC
#include <gtkosxapplication.h>
#endif

#include "banlist.h"

#define flag_c flag_wid[0]
#define flag_n flag_wid[1]
#define flag_t flag_wid[2]
#define flag_i flag_wid[3]
#define flag_m flag_wid[4]
#define flag_l flag_wid[5]
#define flag_k flag_wid[6]
#define flag_b flag_wid[7]
#define NUM_FLAG_WIDS 8

#if GTK_CHECK_VERSION(4, 0, 0)
typedef int GtkIconSize;
#define GTK_ICON_SIZE_MENU 0
#define GTK_ICON_SIZE_LARGE_TOOLBAR 1
#define GTK_ICON_SIZE_DIALOG 2

#ifndef GTK_STOCK_ABOUT
#define GTK_STOCK_ABOUT "help-about"
#endif
#ifndef GTK_STOCK_ADD
#define GTK_STOCK_ADD "list-add"
#endif
#ifndef GTK_STOCK_APPLY
#define GTK_STOCK_APPLY "dialog-apply"
#endif
#ifndef GTK_STOCK_CANCEL
#define GTK_STOCK_CANCEL "process-stop"
#endif
#ifndef GTK_STOCK_CLEAR
#define GTK_STOCK_CLEAR "edit-clear"
#endif
#ifndef GTK_STOCK_CLOSE
#define GTK_STOCK_CLOSE "window-close"
#endif
#ifndef GTK_STOCK_CONNECT
#define GTK_STOCK_CONNECT "network-connect"
#endif
#ifndef GTK_STOCK_COPY
#define GTK_STOCK_COPY "edit-copy"
#endif
#ifndef GTK_STOCK_DELETE
#define GTK_STOCK_DELETE "edit-delete"
#endif
#ifndef GTK_STOCK_DIALOG_ERROR
#define GTK_STOCK_DIALOG_ERROR "dialog-error"
#endif
#ifndef GTK_STOCK_DISCONNECT
#define GTK_STOCK_DISCONNECT "network-disconnect"
#endif
#ifndef GTK_STOCK_FIND
#define GTK_STOCK_FIND "edit-find"
#endif
#ifndef GTK_STOCK_GO_BACK
#define GTK_STOCK_GO_BACK "go-previous"
#endif
#ifndef GTK_STOCK_GO_FORWARD
#define GTK_STOCK_GO_FORWARD "go-next"
#endif
#ifndef GTK_STOCK_HELP
#define GTK_STOCK_HELP "help-browser"
#endif
#ifndef GTK_STOCK_INDEX
#define GTK_STOCK_INDEX "view-list"
#endif
#ifndef GTK_STOCK_JUMP_TO
#define GTK_STOCK_JUMP_TO "go-jump"
#endif
#ifndef GTK_STOCK_JUSTIFY_LEFT
#define GTK_STOCK_JUSTIFY_LEFT "format-justify-left"
#endif
#ifndef GTK_STOCK_MEDIA_PLAY
#define GTK_STOCK_MEDIA_PLAY "media-playback-start"
#endif
#ifndef GTK_STOCK_NETWORK
#define GTK_STOCK_NETWORK "network-workgroup"
#endif
#ifndef GTK_STOCK_NEW
#define GTK_STOCK_NEW "document-new"
#endif
#ifndef GTK_STOCK_NO
#define GTK_STOCK_NO "process-stop"
#endif
#ifndef GTK_STOCK_OK
#define GTK_STOCK_OK "emblem-ok"
#endif
#ifndef GTK_STOCK_OPEN
#define GTK_STOCK_OPEN "document-open"
#endif
#ifndef GTK_STOCK_PREFERENCES
#define GTK_STOCK_PREFERENCES "preferences-system"
#endif
#ifndef GTK_STOCK_QUIT
#define GTK_STOCK_QUIT "application-exit"
#endif
#ifndef GTK_STOCK_REFRESH
#define GTK_STOCK_REFRESH "view-refresh"
#endif
#ifndef GTK_STOCK_REDO
#define GTK_STOCK_REDO "edit-redo"
#endif
#ifndef GTK_STOCK_REMOVE
#define GTK_STOCK_REMOVE "list-remove"
#endif
#ifndef GTK_STOCK_REVERT_TO_SAVED
#define GTK_STOCK_REVERT_TO_SAVED "document-revert"
#endif
#ifndef GTK_STOCK_SAVE
#define GTK_STOCK_SAVE "document-save"
#endif
#ifndef GTK_STOCK_SAVE_AS
#define GTK_STOCK_SAVE_AS "document-save-as"
#endif
#ifndef GTK_STOCK_SPELL_CHECK
#define GTK_STOCK_SPELL_CHECK "tools-check-spelling"
#endif
#ifndef GTK_STOCK_YES
#define GTK_STOCK_YES "emblem-ok"
#endif

typedef enum
{
	GTK_RELIEF_NONE
} GtkReliefStyle;

static inline void
gtk_button_set_relief (GtkButton *button, GtkReliefStyle relief)
{
	gtk_button_set_has_frame (button, relief != GTK_RELIEF_NONE);
}

static inline void
gtk_button_set_image (GtkButton *button, GtkWidget *image)
{
	gtk_button_set_child (button, image);
}

static inline const char *
gtkutil_stock_label (const char *stock_id)
{
	if (g_strcmp0 (stock_id, GTK_STOCK_APPLY) == 0)
		return _("_Apply");
	if (g_strcmp0 (stock_id, GTK_STOCK_CANCEL) == 0)
		return _("_Cancel");
	if (g_strcmp0 (stock_id, GTK_STOCK_MEDIA_PLAY) == 0)
		return _("_Play");
	if (g_strcmp0 (stock_id, GTK_STOCK_NO) == 0)
		return _("_No");
	if (g_strcmp0 (stock_id, GTK_STOCK_OK) == 0)
		return _("_OK");
	if (g_strcmp0 (stock_id, GTK_STOCK_YES) == 0)
		return _("_Yes");

	return NULL;
}

static inline GtkWidget *
gtk_button_new_from_stock (const gchar *stock_id)
{
	GtkWidget *button = gtk_button_new ();
	const char *label = gtkutil_stock_label (stock_id);

	if (label != NULL)
	{
		gtk_button_set_label (GTK_BUTTON (button), label);
		gtk_button_set_use_underline (GTK_BUTTON (button), TRUE);
	}

	if (stock_id != NULL)
		gtk_button_set_icon_name (GTK_BUTTON (button), stock_id);

	return button;
}

static inline GtkWidget *
gtk_image_new_from_stock (const gchar *stock_id, GtkIconSize size)
{
	(void)size;
	return gtk_image_new_from_icon_name (stock_id);
}

static inline void
gtk_entry_set_icon_from_stock (GtkEntry *entry, GtkEntryIconPosition icon_pos,
                               const gchar *stock_id)
{
	gtk_entry_set_icon_from_icon_name (entry, icon_pos, stock_id);
}

static inline GtkWidget *
gtkutil_box_new (GtkOrientation orientation, gboolean homogeneous, gint spacing)
{
	GtkWidget *box = gtk_box_new (orientation, spacing);

	gtk_box_set_homogeneous (GTK_BOX (box), homogeneous);
	return box;
}

static inline GtkAlign
gtkutil_align_from_float (gfloat align)
{
	if (align <= 0.0f)
	{
		return GTK_ALIGN_START;
	}
	if (align >= 1.0f)
	{
		return GTK_ALIGN_END;
	}
	return GTK_ALIGN_CENTER;
}

static inline void
gtkutil_set_alignment (GtkWidget *widget, gfloat xalign, gfloat yalign)
{
	gtk_widget_set_halign (widget, gtkutil_align_from_float (xalign));
	gtk_widget_set_valign (widget, gtkutil_align_from_float (yalign));
}

static inline void
gtkutil_set_margins (GtkWidget *widget, gint xpad, gint ypad)
{
	gtk_widget_set_margin_start (widget, xpad);
	gtk_widget_set_margin_end (widget, xpad);
	gtk_widget_set_margin_top (widget, ypad);
	gtk_widget_set_margin_bottom (widget, ypad);
}

static inline void
gtkutil_set_padding (GtkWidget *widget, gint xpad, gint ypad)
{
	gtkutil_set_margins (widget, xpad, ypad);
}

static inline void
gtkutil_container_add_child (GtkWidget *container, GtkWidget *child)
{
	if (GTK_IS_WINDOW (container))
	{
		gtk_window_set_child (GTK_WINDOW (container), child);
		return;
	}
	if (GTK_IS_BUTTON (container))
	{
		gtk_button_set_child (GTK_BUTTON (container), child);
		return;
	}
	if (GTK_IS_SCROLLED_WINDOW (container))
	{
		gtk_scrolled_window_set_child (GTK_SCROLLED_WINDOW (container), child);
		return;
	}
	if (GTK_IS_FRAME (container))
	{
		gtk_frame_set_child (GTK_FRAME (container), child);
		return;
	}
	if (GTK_IS_BOX (container))
	{
		gtk_box_append (GTK_BOX (container), child);
		return;
	}

	gtk_widget_set_parent (child, container);
}

static inline void
gtkutil_box_pack_start (GtkWidget *box, GtkWidget *child, gboolean expand,
                        gboolean fill, guint padding)
{
	if (expand || fill)
	{
		gtk_widget_set_hexpand (child, TRUE);
		gtk_widget_set_vexpand (child, TRUE);
	}
	if (padding > 0)
	{
		gtkutil_set_margins (child, padding, padding);
	}
	gtk_box_append (GTK_BOX (box), child);
}

static inline void
gtkutil_box_pack_end (GtkWidget *box, GtkWidget *child, gboolean expand,
                      gboolean fill, guint padding)
{
	gtkutil_box_pack_start (box, child, expand, fill, padding);
}
#else
static inline GtkWidget *
gtkutil_box_new (GtkOrientation orientation, gboolean homogeneous, gint spacing)
{
	if (orientation == GTK_ORIENTATION_HORIZONTAL)
	{
		return gtk_hbox_new (homogeneous, spacing);
	}

	return gtk_vbox_new (homogeneous, spacing);
}

static inline void
gtkutil_set_alignment (GtkWidget *widget, gfloat xalign, gfloat yalign)
{
	gtk_misc_set_alignment (GTK_MISC (widget), xalign, yalign);
}

static inline void
gtkutil_set_padding (GtkWidget *widget, gint xpad, gint ypad)
{
	gtk_misc_set_padding (GTK_MISC (widget), xpad, ypad);
}

static inline void
gtkutil_container_add_child (GtkWidget *container, GtkWidget *child)
{
	gtk_container_add (GTK_CONTAINER (container), child);
}

static inline void
gtkutil_box_pack_start (GtkWidget *box, GtkWidget *child, gboolean expand,
                        gboolean fill, guint padding)
{
	gtk_box_pack_start (GTK_BOX (box), child, expand, fill, padding);
}

static inline void
gtkutil_box_pack_end (GtkWidget *box, GtkWidget *child, gboolean expand,
                      gboolean fill, guint padding)
{
	gtk_box_pack_end (GTK_BOX (box), child, expand, fill, padding);
}
#endif

#ifdef HAVE_GTK_MAC
extern GtkosxApplication *osx_app;
#endif

struct server_gui
{
	GtkWidget *rawlog_window;
	GtkWidget *rawlog_textlist;

	/* join dialog */
	GtkWidget *joind_win;
	GtkWidget *joind_entry;
	GtkWidget *joind_radio1;
	GtkWidget *joind_radio2;
	GtkWidget *joind_check;

	/* chanlist variables */
	GtkWidget *chanlist_wild;		/* GtkEntry */
	GtkWidget *chanlist_window;
	GtkWidget *chanlist_list;
	GtkWidget *chanlist_label;
	GtkWidget *chanlist_min_spin;	/* minusers GtkSpinButton */
	GtkWidget *chanlist_refresh;	/* buttons */
	GtkWidget *chanlist_join;
	GtkWidget *chanlist_savelist;
	GtkWidget *chanlist_search;

	GSList *chanlist_data_stored_rows;	/* stored list so it can be resorted  */
	GSList *chanlist_pending_rows;
	gint chanlist_tag;
	gint chanlist_flash_tag;

	gboolean chanlist_match_wants_channel;	/* match in channel name */
	gboolean chanlist_match_wants_topic;	/* match in topic */

	GRegex *chanlist_match_regex;	/* compiled regular expression here */
	unsigned int have_regex;

	guint chanlist_users_found_count;	/* users total for all channels */
	guint chanlist_users_shown_count;	/* users total for displayed channels */
	guint chanlist_channels_found_count;	/* channel total for /LIST operation */
	guint chanlist_channels_shown_count;	/* total number of displayed 
														   channels */

	guint32 chanlist_maxusers;
	guint32 chanlist_minusers;
	guint32 chanlist_minusers_downloaded;	/* used by LIST IRC command */
	int chanlist_search_type;		/* 0=simple 1=pattern/wildcard 2=regexp */
	gboolean chanlist_caption_is_stale;
};

/* this struct is persistant even when delinking/relinking */

typedef struct restore_gui
{
	banlist_info *banlist;

	void *tab;			/* (chan *) */

	/* information stored when this tab isn't front-most */
	GtkListStore *user_model;	/* for filling the GtkTreeView */
	void *buffer;		/* xtext_Buffer */
	char *input_text;	/* input text buffer (while not-front tab) */
	char *topic_text;	/* topic GtkEntry buffer */
	char *key_text;
	char *limit_text;
	gfloat old_ul_value;	/* old userlist value (for adj) */
	gfloat lag_value;	/* lag-o-meter */
	char *lag_text;	/* lag-o-meter text */
	char *lag_tip;		/* lag-o-meter tooltip */
	gfloat queue_value; /* outbound queue meter */
	char *queue_text;		/* outbound queue text */
	char *queue_tip;		/* outbound queue tooltip */
	short flag_wid_state[NUM_FLAG_WIDS];
	unsigned int c_graph:1;	/* connecting graph, is there one? */
} restore_gui;

typedef struct session_gui
{
	GtkWidget
		*xtext,
		*vscrollbar,
		*window,	/* toplevel */
		*topic_entry,
		*note_book,
		*main_table,
		*user_tree,	/* GtkTreeView */
		*user_box,	/* userlist box */
		*button_box_parent,
		*button_box,	/* userlist buttons' box */
		*dialogbutton_box,
		*topicbutton_box,
		*meter_box,	/* all the meters inside this */
		*lagometer,
		*laginfo,
		*throttlemeter,
		*throttleinfo,
		*topic_bar,
		*hpane_left,
		*hpane_right,
		*vpane_left,
		*vpane_right,
		*menu,
		*bar,				/* connecting progress bar */
		*nick_box,		/* contains label to the left of input_box */
		*nick_label,
		*op_xpm,			/* icon to the left of nickname */
		*namelistinfo,	/* label above userlist */
		*input_box,
		*flag_wid[NUM_FLAG_WIDS],		/* channelmode buttons */
		*limit_entry,		  /* +l */
		*key_entry;		  /* +k */

		GtkWidget *shbox, *shentry;	/* search bar hbox */
		gulong search_changed_signal; /* hook for search change event so blanking the box doesn't suck */

#define MENU_ID_NUM 14
	GtkWidget *menu_item[MENU_ID_NUM+1]; /* some items we may change state of */

	void *chanview;	/* chanview.h */

	int bartag;		/*connecting progressbar timeout */

	int pane_left_size;	/*last position of the pane*/
	int pane_right_size;

	guint16 is_tab;	/* is tab or toplevel? */
	guint16 ul_hidden;	/* userlist hidden? */

} session_gui;

extern GdkPixmap *channelwin_pix;
extern GdkPixmap *dialogwin_pix;

#define SPELL_ENTRY_GET_TEXT(e) ((char *)(gtk_entry_get_text (GTK_ENTRY(e))))
#define SPELL_ENTRY_SET_TEXT(e,txt) gtk_entry_set_text(GTK_ENTRY(e),txt)
#define SPELL_ENTRY_SET_EDITABLE(e,v) gtk_editable_set_editable(GTK_EDITABLE(e),v)
#define SPELL_ENTRY_GET_POS(e) gtk_editable_get_position(GTK_EDITABLE(e))
#define SPELL_ENTRY_SET_POS(e,p) gtk_editable_set_position(GTK_EDITABLE(e),p);
#define SPELL_ENTRY_INSERT(e,t,l,p) gtk_editable_insert_text(GTK_EDITABLE(e),t,l,p)

#endif
