c1_symbol * __cdecl
expr_member_call_candidates_cold_blocks
          (int *name,c1_symbol *fn_set,c1_symbol *member_set,c1_type *fn_type,int arg_types)

{
  int iVar1;
  c1_symbol *key;
  c1_symbol *pcVar2;
  c1_lookup_result *result;
  c1_lookup_entry *pcVar3;
  c1_param_clause *clause;
  int *piVar4;
  
  if (name == g_name_array_delete) {
    result = (*g_current_scope->global_scope->vtbl->lookup)
                       (g_current_scope->global_scope,g_name_delete,1);
    if ((result == (c1_lookup_result *)0x0) ||
       (pcVar3 = lookup_check_ambiguous_symbol(result,'\x01'), pcVar3 == (c1_lookup_entry *)0x0)) {
      fn_set = (c1_symbol *)0x0;
    }
    else {
      fn_set = pcVar3->sym;
    }
  }
  clause = (c1_param_clause *)g_arenas[5].cur;
  if (fn_set != (c1_symbol *)0x0) {
    g_arenas[5].cur = g_arenas[5].cur + 0x1c;
    if (g_arenas[5].end < g_arenas[5].cur) {
      arena_grow(g_arenas + 5);
    }
    if (clause == (c1_param_clause *)0x0) {
      clause = (c1_param_clause *)0x0;
    }
    else {
      *(c1_u8 *)((int)clause + 0x10) = '\x04';
      *(c1_u8 *)((int)clause + 0x11) = '\0';
      *(c1_u8 *)((int)clause + 0x12) = '\0';
      *(c1_u8 *)((int)clause + 0x13) = '\0';
      *(c1_u8 *)((int)clause + 0x14) = '\0';
      *(c1_u8 *)((int)clause + 0) = '\0';
      *(c1_u8 *)((int)clause + 1) = '\0';
      *(c1_u8 *)((int)clause + 2) = '\0';
      *(c1_u8 *)((int)clause + 3) = '\0';
    }
    param_list_add_compiler_formal(clause,(void *)0x0,PTR_104d152c);
    piVar4 = *(int **)(arg_types + 0xc) + 3;
    iVar1 = **(int **)(arg_types + 0xc) + -1;
    if (0 < iVar1) {
      do {
        param_list_add_compiler_formal(clause,(void *)0x0,(c1_type *)*piVar4);
        piVar4 = piVar4 + 1;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
    decl_pop_declarator_state(clause);
    decl_record_init(&stack0x0000000c,g_type_void,g_default_decl_specifiers);
    decl_append_function_layer((int *)&stack0x0000000c,clause);
    decl_finish_declarator((c1_decl_record *)&stack0x0000000c);
    key = ovl_select_function_for_target_type(fn_set,fn_type,1,'\x01');
    if (key != (c1_symbol *)0x0) {
      expr_set_overload_target_and_check_access(member_set,(int)key);
      pcVar2 = symtab_1700_lookup(key);
      if (pcVar2 != (c1_symbol *)0x0) {
        return pcVar2;
      }
    }
    return key;
  }
  return (c1_symbol *)0x0;
}

