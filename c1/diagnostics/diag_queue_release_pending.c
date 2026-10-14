void __fastcall diag_queue_release_pending(fe_diag_context *list)

{
  fe_diag_cell *pfVar1;
  uchar *puVar2;
  fe_message *pfVar3;
  
  pfVar1 = (list->pending).head;
  while (pfVar1 != (fe_diag_cell *)0x0) {
    pfVar1 = (list->pending).head;
    if (pfVar1 == (fe_diag_cell *)0x0) {
      pfVar3 = (fe_message *)0x0;
    }
    else {
      (list->pending).head = pfVar1->next;
      pfVar3 = pfVar1->msg;
    }
    if ((list->pending).head == (fe_diag_cell *)0x0) {
      (list->pending).tail = (fe_diag_cell *)0x0;
    }
    puVar2 = g_arenas[6].cur;
    g_arenas[6].cur = g_arenas[6].cur + 8;
    if (g_arenas[6].end < g_arenas[6].cur) {
      arena_grow(g_arenas + 6);
    }
    *(fe_message **)puVar2 = pfVar3;
    puVar2[4] = '\0';
    puVar2[5] = '\0';
    puVar2[6] = '\0';
    puVar2[7] = '\0';
    pfVar1 = (list->queue).tail;
    if (pfVar1 != (fe_diag_cell *)0x0) {
      pfVar1->next = (fe_diag_cell *)puVar2;
    }
    (list->queue).tail = (fe_diag_cell *)puVar2;
    if ((list->queue).head == (fe_diag_cell *)0x0) {
      (list->queue).head = (fe_diag_cell *)puVar2;
    }
    diag_queue_print(list);
    pfVar1 = (list->pending).head;
  }
  return;
}

