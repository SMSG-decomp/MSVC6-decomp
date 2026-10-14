void zi_preallocate_eh_records(void)

{
  c2_fe_symbol *pcVar1;
  int iVar2;
  
  g_enc_local_list = (c2_enc_local *)0x0;
  scope_for_each(1,enc_note_static_local);
  g_frame_cursor = 0;
  if (g_frame_eh_record != (c2_fe_symbol *)0x0) {
    iVar2 = frame_alloc_local(g_frame_eh_record->size,0);
    pcVar1 = g_frame_eh_record;
    g_frame_eh_record->offset = iVar2;
    pcVar1->attrs = pcVar1->attrs | 0x800;
  }
  if ((g_opt_eh_enabled == 0) && (g_eh_guard_local != (c2_symbol *)0x0)) {
    pcVar1 = g_eh_guard_local->fe;
    iVar2 = frame_alloc_local(pcVar1->size,0);
    pcVar1->offset = iVar2;
    pcVar1->attrs = pcVar1->attrs | 0x800;
  }
  return;
}

