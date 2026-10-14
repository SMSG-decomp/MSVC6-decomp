char __thiscall mre_note_member_use(c1_mre_tracker *tracker,c1_symbol *cls,void *member_name)

{
  char cVar1;
  int iVar2;
  byte *pbVar3;
  c1_line_map_row *pcVar4;
  
  if (tracker->current->tracked == '\0') {
    cVar1 = '\x02';
  }
  else {
    cVar1 = tracker->busy != '\0';
  }
  if (cVar1 == '\x01') {
    mre_note_queue_push(&tracker->pending,0,cls,member_name);
  }
  else if (cVar1 != '\x02') {
    tracker->busy = '\x01';
    iVar2 = mre_class_ensure_records(cls);
    tracker->busy = '\0';
    if (iVar2 != 1) {
      if (iVar2 != 2) {
        pbVar3 = mre_member_name_text(member_name,(int)cls);
        if (g_line_map_cached_row.position == g_token_position) {
          pcVar4 = &g_line_map_cached_row;
        }
        else {
          pcVar4 = pp_line_map_find_entry(&g_line_map,g_token_position);
        }
        iVar2 = (**(code **)*g_mre_engine)
                          (((cls->detail).cls)->gm_name_index,((cls->detail).cls)->debug_index,
                           pbVar3,0,(pcVar4->line - pcVar4->position) + g_token_position);
        if (iVar2 != 0) {
          if (tracker->pending == (c1_mre_note *)0x0) {
            return '\x01';
          }
          if (tracker->draining != '\0') {
            return '\x01';
          }
          cVar1 = mre_note_queue_drain(tracker);
          return cVar1;
        }
        diag_error(0x1d7,g_pdb_file_name);
      }
      return '\0';
    }
  }
  return '\x01';
}

