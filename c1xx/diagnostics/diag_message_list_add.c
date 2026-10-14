void __thiscall diag_message_list_add(c1_diag_context *ctx,int kind,short number,char *args)

{
  c1xx_diag_cell *pcVar1;
  msg *msg;
  c1xx_diag_list *insert_list;
  c1_u8 *cell;
  
  msg = diag_message_alloc();
  diag_message_load(msg,(short)kind,number,args);
  cell = g_arenas[9].cur;
  if (ctx->busy == '\0') {
    g_arenas[9].cur = g_arenas[9].cur + 8;
    if (g_arenas[9].end < g_arenas[9].cur) {
      arena_grow(g_arenas + 9);
    }
    *(msg **)cell = msg;
    cell[4] = '\0';
    cell[5] = '\0';
    cell[6] = '\0';
    cell[7] = '\0';
    pcVar1 = (ctx->queue).tail;
    if (pcVar1 != (c1xx_diag_cell *)0x0) {
      pcVar1->next = (c1xx_diag_cell *)cell;
    }
    (ctx->queue).tail = (c1xx_diag_cell *)cell;
    if ((ctx->queue).head == (c1xx_diag_cell *)0x0) {
      (ctx->queue).head = (c1xx_diag_cell *)cell;
    }
    diag_queue_print(ctx);
    return;
  }
  if (ctx->insert_after == (c1xx_diag_cell *)0x0) {
    g_arenas[9].cur = g_arenas[9].cur + 8;
    insert_list = ctx->insert_list;
    if (g_arenas[9].end < g_arenas[9].cur) {
      arena_grow(g_arenas + 9);
    }
    *(msg **)cell = msg;
    *(c1xx_diag_cell **)(cell + 4) = insert_list->head;
    insert_list->head = (c1xx_diag_cell *)cell;
    if (*(int *)(cell + 4) == 0) {
      insert_list->tail = (c1xx_diag_cell *)cell;
    }
    ctx->insert_after = ctx->insert_list->head;
    return;
  }
  g_arenas[9].cur = g_arenas[9].cur + 8;
  if (g_arenas[9].end < g_arenas[9].cur) {
    arena_grow(g_arenas + 9);
  }
  *(msg **)cell = msg;
  *(c1xx_diag_cell **)(cell + 4) = ctx->insert_after->next;
  ctx->insert_after = (c1xx_diag_cell *)cell;
  if (*(int *)(cell + 4) == 0) {
    ctx->insert_list->tail = (c1xx_diag_cell *)cell;
  }
  return;
}

