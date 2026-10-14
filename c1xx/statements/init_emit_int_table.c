void __cdecl init_emit_int_table(c1_symbol *sym,int *values,int count)

{
  c1_symbol *pcVar1;
  c1_node *node;
  
  pcVar1 = arena_alloc(g_arenas + 5,g_symbol_size_table[10] + 3 & 0xfffffffc);
  if (pcVar1 == (c1_symbol *)0x0) {
    pcVar1 = (c1_symbol *)0x0;
  }
  else {
    pcVar1 = sym_init_kind(pcVar1,'\n',(void *)0x0,5);
  }
  sym->flags4 = sym->flags4 | 4;
  sym->storage = sym->storage & 0xf8 ^ 2;
  init_emit_symbol_data(sym,(c1_node *)0x0,&g_il_in);
  if (0 < count) {
    do {
      node = tree_new_int_constant(*values);
      pcVar1->type = node->type;
      init_emit_initializer(pcVar1,node,&g_il_in);
      values = values + 1;
      count = count + -1;
    } while (count != 0);
  }
  il_emit_in_marker();
  return;
}

