void __cdecl tmpl_pending_pop(void)

{
  if (g_diag_message_list.context_notes != (c1_diag_note_cell *)0x0) {
    g_diag_message_list.context_notes = (g_diag_message_list.context_notes)->next;
  }
  return;
}

