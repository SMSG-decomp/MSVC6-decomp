char __thiscall mre_note_class_use(c1_mre_tracker *tracker,c1_symbol *cls)

{
  char cVar1;
  int iVar2;
  c1_line_map_row *pcVar3;
  
  if (tracker->current->tracked == '\0') {
    cVar1 = '\x02';
  }
  else {
    cVar1 = tracker->busy != '\0';
  }
  if (cVar1 == '\x01') {
    mre_note_queue_push(&tracker->pending,2,cls,(void *)0x0);
  }
  else if (cVar1 != '\x02') {
    tracker->busy = '\x01';
    iVar2 = mre_class_ensure_records(cls);
    tracker->busy = '\0';
    if (iVar2 != 1) {
      if (iVar2 != 2) {
        if (g_line_map_cached_row.position == g_token_position) {
          pcVar3 = &g_line_map_cached_row;
        }
        else {
          pcVar3 = pp_line_map_find_entry(&g_line_map,g_token_position);
        }
        iVar2 = (**(code **)*g_mre_engine)
                          (((cls->detail).cls)->gm_name_index,((cls->detail).cls)->debug_index,0,1,
                           (pcVar3->line - pcVar3->position) + g_token_position);
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

