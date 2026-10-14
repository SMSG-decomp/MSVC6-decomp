c1_scope_stack * __fastcall scope_file_init(c1_scope_stack *state)

{
  uint bytes;
  uchar *puVar1;
  uchar *puVar2;
  c1_scope_object *pcVar3;
  
  state->depth = '\0';
  state->unk209 = '\0';
  state->unk20c = 0;
  state->unk210 = 0;
  state->file_records = (fe_file_record *)0x0;
  if (g_scope_pool.left < 0x18) {
    pool_reserve(&g_scope_pool,0x18);
  }
  puVar1 = g_scope_pool.cur;
  g_scope_pool.left = g_scope_pool.left - 0x18;
  pcVar3 = (c1_scope_object *)0x0;
  puVar2 = g_scope_pool.cur + 0x18;
  if (g_scope_pool.cur != (uchar *)0x0) {
    g_scope_pool.cur = g_scope_pool.cur + 0x18;
    puVar1[4] = '\0';
    puVar1[5] = '\0';
    puVar1[6] = '\0';
    puVar1[7] = '\0';
    puVar1[8] = '\0';
    puVar1[0xc] = '\0';
    puVar1[0xd] = '\0';
    puVar1[0xe] = '\0';
    puVar1[0xf] = '\0';
    puVar1[0x14] = 0xff;
    puVar1[0x15] = '\x03';
    puVar1[0x16] = '\0';
    puVar1[0x17] = '\0';
    *(undefined ***)puVar1 = &PTR_scope_has_entries_1065389c;
    pcVar3 = (c1_scope_object *)puVar1;
    puVar2 = g_scope_pool.cur;
  }
  g_scope_pool.cur = puVar2;
  state->file_scope = pcVar3;
  bytes = pcVar3->mask * 4 + 4;
  if (g_scope_pool.left < bytes) {
    pool_reserve(&g_scope_pool,bytes);
  }
  g_scope_pool.left = g_scope_pool.left - bytes;
  puVar1 = g_scope_pool.cur + bytes;
  (pcVar3->entries).buckets = (void **)g_scope_pool.cur;
  g_scope_pool.cur = puVar1;
  state->current = state->file_scope;
  state->objects[0] = state->file_scope;
  return state;
}

