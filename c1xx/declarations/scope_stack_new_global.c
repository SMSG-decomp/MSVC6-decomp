c1_scope_stack * __fastcall scope_stack_new_global(c1_scope_stack *stack)

{
  uint n;
  void *name;
  c1_u8 *pcVar1;
  uchar *puVar2;
  c1_symbol *pcVar3;
  c1xx_scope *pcVar4;
  
  stack->depth = '\0';
  stack->saved = (c1_decl_state *)0x0;
  stack->qual_class = (c1_symbol *)0x0;
  stack->using_namespaces = (c1_using_cell **)0x0;
  stack->visited_namespaces = (c1_symbol_vector *)0x0;
  stack->access_op = '\x01';
  stack->reported = '\0';
  stack->keep_aliases = '\0';
  stack->closed_blocks = (c1xx_scope *)0x0;
  stack->segments = (void *)0x0;
  stack->file_records = (fe_file_record *)0x0;
  if (g_scope_pool_left < 0x20) {
    pool_reserve((c1xx_pool *)&g_scope_pool,0x20);
  }
  pcVar4 = (c1xx_scope *)g_scope_pool;
  g_scope_pool_left = g_scope_pool_left - 0x20;
  if (g_scope_pool == (uchar *)0x0) {
    pcVar4 = (c1xx_scope *)0x0;
    g_scope_pool = g_scope_pool + 0x20;
  }
  else {
    puVar2 = g_scope_pool;
    g_scope_pool = g_scope_pool + 0x20;
    puVar2[4] = '\0';
    puVar2[5] = '\0';
    puVar2[6] = '\0';
    puVar2[7] = '\0';
    *(uchar *)((int)pcVar4 + 8) = '\0';
    puVar2[0xc] = '\0';
    puVar2[0xd] = '\0';
    puVar2[0xe] = '\0';
    puVar2[0xf] = '\0';
    puVar2[0x10] = '\0';
    puVar2[0x11] = '\0';
    puVar2[0x12] = '\0';
    puVar2[0x13] = '\0';
    puVar2[0x18] = 0xff;
    puVar2[0x19] = '\x03';
    puVar2[0x1a] = '\0';
    puVar2[0x1b] = '\0';
    puVar2[0x1c] = '\0';
    puVar2[0x1d] = '\0';
    puVar2[0x1e] = '\0';
    puVar2[0x1f] = '\0';
    *(undefined ***)pcVar4 = &PTR_hash_scope_has_entries_104bd894;
  }
  stack->global_scope = pcVar4;
  n = (int)pcVar4[1].vtbl * 4 + 4;
  if (g_scope_pool_left < n) {
    pool_reserve((c1xx_pool *)&g_scope_pool,n);
  }
  g_scope_pool_left = g_scope_pool_left - n;
  puVar2 = g_scope_pool + n;
  (pcVar4->body).symbols = (c1_sym_list *)g_scope_pool;
  g_scope_pool = puVar2;
  stack->current = stack->global_scope;
  stack->contexts[0] = stack->global_scope;
  name = g_name_global_namespace;
  pcVar3 = sym_take_free_record(0x19,g_name_global_namespace,0);
  if (pcVar3 == (c1_symbol *)0x0) {
    pcVar3 = arena_alloc(g_arenas,g_symbol_size_table[0x19] + 3 & 0xfffffffc);
    if (pcVar3 == (c1_symbol *)0x0) {
      pcVar3 = (c1_symbol *)0x0;
    }
    else {
      pcVar3 = sym_init_kind(pcVar3,'\x19',name,0);
    }
  }
  stack->global_ns = pcVar3;
  pcVar1 = g_arenas[0].cur;
  g_arenas[0].cur = g_arenas[0].cur + 8;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  stack->global_ns->type = (c1_type *)pcVar1;
  *(c1xx_scope **)stack->global_ns->type = stack->global_scope;
  stack->global_ns->flags2 = stack->global_ns->flags2 | 4;
  return stack;
}

