/* presets.h
 *
 * Copyright (C) 2008-2025 John Stebbins <stebbins@stebbins>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2,
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

#pragma once

#include "common.h"
#include "handbrake/handbrake.h"
#include "settings.h"
#include "values.h"

G_BEGIN_DECLS

void ghb_presets_bind_tree_model(signal_user_data_t *ud);
void ghb_presets_load(signal_user_data_t *ud);
void ghb_update_from_preset(signal_user_data_t *ud, const gchar *key);
void ghb_settings_init(GhbValue *settings, const char *name);
void ghb_settings_close(void);
void ghb_prefs_load(signal_user_data_t *ud);
void ghb_pref_save(GhbValue *settings, const gchar *key);
void ghb_pref_set(GhbValue *settings, const gchar *key);
void ghb_prefs_store(void);
void ghb_save_queue(GhbValue *queue);
GhbValue* ghb_load_old_queue(int pid);
void ghb_remove_old_queue_file(int pid);
gchar* ghb_get_user_config_dir(const char *subdir);
void ghb_override_user_config_dir(char *dir);
void ghb_settings_to_ui(signal_user_data_t *ud, GhbValue *dict);
void ghb_clear_presets_selection(signal_user_data_t *ud);
void ghb_set_clear_presets_inhibited(gboolean inhibited);
void ghb_select_preset(signal_user_data_t *ud, const char *name, int type);
void ghb_select_default_preset(signal_user_data_t *ud);
void ghb_presets_list_init(signal_user_data_t *ud,
                           const hb_preset_index_t *path);
void ghb_presets_menu_init(signal_user_data_t *ud);
void ghb_presets_list_reinit(signal_user_data_t *ud);
void ghb_presets_menu_reinit(signal_user_data_t *ud);
int ghb_find_pid_file(void);
void ghb_write_pid_file(void);
GhbValue* ghb_get_current_preset(signal_user_data_t *ud);
void ghb_preset_to_settings(GhbValue *settings, GhbValue *preset);
void ghb_prefs_to_settings(GhbValue *settings);
GhbValue* ghb_read_settings_file(const gchar *path);
void ghb_write_settings_file(const gchar *path, GhbValue *dict);
GhbValue* ghb_create_copy_mask(GhbValue *settings);
GhbValue* ghb_settings_to_preset(GhbValue *settings);
void ghb_preset_menu_button_refresh(signal_user_data_t *ud,
                                    const char *name, int type);

void presets_list_selection_changed_cb(
    GtkTreeSelection *selection, signal_user_data_t *ud);

gboolean presets_drag_accept_cb(GtkDropTarget *drop_target, GdkDrop *drop,
                                signal_user_data_t *ud);
GdkDragAction presets_drag_motion_cb(GtkDropTargetAsync *drop_target, GdkDrop *drop,
                                     double x, double y, signal_user_data_t *ud);
gboolean presets_drop_cb(GtkDropTargetAsync *drop_target, GdkDrop *drop,
                         double x, double y, signal_user_data_t *ud);

void preset_edited_cb(
    GtkCellRendererText *cell,
    gchar               *treepath_s,
    gchar               *text,
    signal_user_data_t  *ud);
void presets_row_expanded_cb(
    GtkTreeView        *treeview,
    GtkTreeIter        *iter,
    GtkTreePath        *treepath,
    signal_user_data_t *ud);

G_END_DECLS
