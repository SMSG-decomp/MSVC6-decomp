void __thiscall diag_message_list_add(fe_diag_context *list,int kind,short number,char *args)

{
  fe_diag_cell *pfVar1;
  fe_diag_queue *pfVar2;
  uchar *puVar3;
  fe_message *m;
  
  m = diag_message_alloc();
  diag_message_load(m,(short)kind,number,args);
  puVar3 = g_arenas[6].cur;
  if (list->busy == '\0') {
    g_arenas[6].cur = g_arenas[6].cur + 8;
    if (g_arenas[6].end < g_arenas[6].cur) {
      arena_grow(g_arenas + 6);
    }
    *(fe_message **)puVar3 = m;
    puVar3[4] = '\0';
    puVar3[5] = '\0';
    puVar3[6] = '\0';
    puVar3[7] = '\0';
    pfVar1 = (list->queue).tail;
    if (pfVar1 != (fe_diag_cell *)0x0) {
      pfVar1->next = (fe_diag_cell *)puVar3;
    }
    (list->queue).tail = (fe_diag_cell *)puVar3;
    if ((list->queue).head == (fe_diag_cell *)0x0) {
      (list->queue).head = (fe_diag_cell *)puVar3;
    }
    diag_queue_print(list);
    return;
  }
  if (list->insert_after == (fe_diag_cell *)0x0) {
    g_arenas[6].cur = g_arenas[6].cur + 8;
    pfVar2 = list->insert_list;
    if (g_arenas[6].end < g_arenas[6].cur) {
      arena_grow(g_arenas + 6);
    }
    *(fe_message **)puVar3 = m;
    *(fe_diag_cell **)(puVar3 + 4) = pfVar2->head;
    pfVar2->head = (fe_diag_cell *)puVar3;
    if (*(int *)(puVar3 + 4) == 0) {
      pfVar2->tail = (fe_diag_cell *)puVar3;
    }
    list->insert_after = list->insert_list->head;
    return;
  }
  g_arenas[6].cur = g_arenas[6].cur + 8;
  if (g_arenas[6].end < g_arenas[6].cur) {
    arena_grow(g_arenas + 6);
  }
  *(fe_message **)puVar3 = m;
  *(fe_diag_cell **)(puVar3 + 4) = list->insert_after->next;
  list->insert_after = (fe_diag_cell *)puVar3;
  if (*(int *)(puVar3 + 4) == 0) {
    list->insert_list->tail = (fe_diag_cell *)puVar3;
  }
  return;
}

