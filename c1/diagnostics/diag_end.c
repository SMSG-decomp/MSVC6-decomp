int __fastcall diag_end(fe_diag_context *list)

{
  int iVar1;
  
  if (list->nesting == 1) {
    if (list->state == 2) {
      list->state = 4;
      diag_queue_release_pending(list);
      diag_run_context_notes(list);
    }
    arena_reset_ptr(g_arenas + 6);
    list->state = 0;
  }
  iVar1 = list->nesting + -1;
  list->nesting = iVar1;
  return iVar1;
}

