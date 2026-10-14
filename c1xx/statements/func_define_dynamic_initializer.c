void __cdecl func_define_dynamic_initializer(c1_symbol *sym,int init,c1_node *item)

{
  c1_symbol *sym_00;
  fe_name *pfVar1;
  c1_node *pcVar2;
  c1_node *pcVar3;
  byte bVar4;
  uint mode;
  int bound;
  
  if ((g_compile_flags_c4 & 0x20) != 0) {
    func_definition_end('\x01');
  }
  sym_00 = func_new_dynamic_initializer();
  pfVar1 = name_intern_decorated_in_scope_2(sym,sym_00,'\x01');
  sym_00->name = pfVar1;
  sym_00->flags1 = sym_00->flags1 & 0xfe | 2;
  bVar4 = sym_00->storage & 0xf8 ^ 1;
  sym_00->storage = bVar4;
  sym_00->storage = bVar4 | 0x40;
  sym_00->flags21 = sym_00->flags21 | 1;
  g_current_function = func_body_begin(sym_00);
  func_body_begin_emit();
  func_flow_state_push(g_current_function,(void *)0x0);
  g_compile_flags_c4 = g_compile_flags_c4 | 0x20000;
  func_begin_compound_statement();
  g_current_function->flags2 = g_current_function->flags2 | 4;
  init_static_guard_begin();
  pcVar2 = init_collect_destructible_item((void *)init,item);
  tmpl_prune_instance_list(sym);
  bound = 0;
  mode = 4;
  pcVar3 = expr_reference_named_entity(sym,0);
  pcVar3 = expr_build_address_of(pcVar3,mode);
  pcVar2 = expr_build_new('\0',0,sym,(int)pcVar2,pcVar3,bound);
  pcVar2 = expr_full_expression_guarded(pcVar2,2);
  stmt_emit_expression(pcVar2);
  eh_pop_array_init_state();
  label_emit_definition(g_static_guard_skip_label);
  scope_end_block();
  func_emit_end(g_compile_flags_c8 >> 7 & 1);
  g_compile_flags_c4 = g_compile_flags_c4 & 0xfffdffff;
  vector_push(g_dynamic_initializer_functions,g_current_function);
  g_current_function = (c1_symbol *)0x0;
  return;
}

