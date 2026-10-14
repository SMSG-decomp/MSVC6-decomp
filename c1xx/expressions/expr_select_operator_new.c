c1_symbol * __cdecl expr_select_operator_new(int *name,int arg_types,c1_symbol *cls)

{
  int iVar1;
  c1_symbol *pcVar2;
  c1_lookup_result *result;
  c1_lookup_entry *pcVar3;
  c1_param_clause *clause;
  int *piVar4;
  c1_symbol *pcVar5;
  c1_decl_record decl;
  
  pcVar5 = (c1_symbol *)0x0;
  if (((cls == (c1_symbol *)0x0) ||
      (pcVar5 = class_lookup_member_set(g_current_scope,cls,name,2,0x181),
      pcVar5 == (c1_symbol *)0x0)) ||
     (pcVar2 = *(c1_symbol **)(*(int *)pcVar5->type + 8), pcVar2 == (c1_symbol *)0x0)) {
    result = (*g_current_scope->global_scope->vtbl->lookup)(g_current_scope->global_scope,name,1);
    if ((result == (c1_lookup_result *)0x0) ||
       (pcVar3 = lookup_check_ambiguous_symbol(result,'\x01'), pcVar3 == (c1_lookup_entry *)0x0)) {
      pcVar2 = (c1_symbol *)0x0;
    }
    else {
      pcVar2 = pcVar3->sym;
    }
    if (pcVar2 == (c1_symbol *)0x0) {
      pcVar5 = expr_member_call_candidates_cold_blocks
                         (name,(c1_symbol *)0x0,pcVar5,decl.type,arg_types);
      return pcVar5;
    }
  }
  clause = (c1_param_clause *)g_arenas[5].cur;
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
  decl_record_init(&decl,g_type_void,g_default_decl_specifiers);
  decl_append_function_layer((int *)&decl,clause);
  decl_finish_declarator(&decl);
  pcVar2 = ovl_select_function_for_target_type(pcVar2,decl.type,1,'\x01');
  if (pcVar2 != (c1_symbol *)0x0) {
    expr_set_overload_target_and_check_access(pcVar5,(int)pcVar2);
    pcVar5 = symtab_1700_lookup(pcVar2);
    if (pcVar5 != (c1_symbol *)0x0) {
      return pcVar5;
    }
  }
  return pcVar2;
}

