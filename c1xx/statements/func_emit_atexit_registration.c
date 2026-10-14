void __cdecl func_emit_atexit_registration(c1_symbol *fn)

{
  byte bVar1;
  c1_lookup_result *result;
  c1_lookup_entry *pcVar2;
  c1_node *pcVar3;
  c1_node *left;
  c1_symbol *sym;
  
  if (g_atexit_symbol == (c1_symbol *)0x0) {
    result = (*g_current_scope->global_scope->vtbl->lookup)
                       (g_current_scope->global_scope,g_atexit_name,1);
    if ((result == (c1_lookup_result *)0x0) ||
       (pcVar2 = lookup_check_ambiguous_symbol(result,'\x01'), pcVar2 == (c1_lookup_entry *)0x0)) {
      diag_fatal(1,".\\funcs.c",1000);
    }
    g_atexit_symbol = pcVar2->sym;
    bVar1 = g_atexit_symbol->kind & 0x1f;
    if (((((bVar1 == 0x10) || (bVar1 == 7)) || (bVar1 == 6)) ||
        (((bVar1 == 0x11 || (bVar1 == 8)) || (bVar1 == 0x1b)))) ||
       ((bVar1 == 0x1a &&
        (((bVar1 = **(byte **)g_atexit_symbol->type & 0x1f, bVar1 == 0x10 || (bVar1 == 7)) ||
         ((bVar1 == 6 || (((bVar1 == 0x11 || (bVar1 == 8)) || (bVar1 == 0x1b)))))))))) {
      g_atexit_symbol = sym_first_function_of_overload_set(g_atexit_symbol,'\x01');
    }
  }
  pcVar3 = tree_new_symbol_ref(fn,'\x01');
  pcVar3 = expr_build_builtin_unary(0x31,pcVar3);
  sym = g_init_seg_atexit_function;
  if (g_init_seg_atexit_function == (c1_symbol *)0x0) {
    sym = g_atexit_symbol;
  }
  pcVar3 = tree_append_list_item((c1_node *)0x0,pcVar3,2);
  left = tree_new_symbol_ref(sym,'\x01');
  pcVar3 = tree_new_binary('p',left,pcVar3);
  pcVar3->type = g_type_int;
  stmt_emit_expression(pcVar3);
  return;
}

