void __cdecl eh_emit_catchable_type_array(int *item)

{
  c1_symbol *sym;
  c1_node *value;
  int no_dynamic;
  int iStack_8;
  int iStack_4;
  
  sym = (c1_symbol *)decl_begin_initialized_definition((c1_symbol *)*item);
  init_begin(sym,'\0');
  iStack_8 = item[1];
  iStack_4 = iStack_8 >> 0x1f;
  no_dynamic = 0;
  value = tree_new_constant(g_type_int,&iStack_8,g_expr_arena_index);
  init_process_initializer(value,no_dynamic);
  vector_for_each((c1_vector *)item[2],init_emit_address_or_zero);
  init_finish(sym);
  return;
}

