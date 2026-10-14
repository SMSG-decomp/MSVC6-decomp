c1_node * __cdecl
expr_build_call_node(c1_symbol *sym,c1_node *left,int args,int conversions,int argc,int nonvirtual)

{
  c1_u16 cVar1;
  byte bVar2;
  c1_type *pcVar3;
  c1_node *pcVar4;
  c1_node *pcVar5;
  c1_node *pcVar6;
  c1_node *pcVar7;
  c1_symbol *fn;
  c1_arena *pcVar8;
  bool bVar9;
  char cVar10;
  void *visitor;
  int visitor_mask;
  
  bVar9 = nonvirtual != 0;
  cVar10 = '\0';
  if (argc < 0) {
    return (c1_node *)0x0;
  }
  if (sym == (c1_symbol *)0x0) {
    return (c1_node *)0x0;
  }
  if ((sym->flags3 & 4) != 0) {
    diag_error(0x108,sym);
    return (c1_node *)0x0;
  }
  pcVar8 = g_arenas + g_expr_arena_index;
  pcVar7 = (c1_node *)pcVar8->cur;
  pcVar4 = (c1_node *)g_arenas[g_expr_arena_index].end;
  pcVar8->cur = &pcVar7[1].op;
  if (pcVar4 < pcVar7 + 1) {
    arena_grow(pcVar8);
  }
  pcVar7->kind = '\x02';
  pcVar7->op = 'p';
  if ((sym->kind & 0x1f) == 0x1a) {
    sym = *(c1_symbol **)sym->type;
  }
  bVar2 = sym->kind & 0x1f;
  if (((bVar2 == 0x10) || (bVar2 == 0x11)) || (fn = sym, bVar2 == 0x1b)) {
    fn = (c1_symbol *)ovl_first_function_of_set(sym);
  }
  pcVar3 = type_function_return(fn->type);
  pcVar7->type = pcVar3;
  pcVar4 = ovl_convert_call_arguments(fn,fn->type,(c1_node *)args,(c1_conversion *)conversions,argc)
  ;
  pcVar7->right = pcVar4;
  if ((fn->kind & 0x1f) == 6) {
    cVar1 = (fn->detail).halves.lo;
    if (((((cVar1 == 0xd9) && ((g_compile_flags_c4 & 0x2000000) == 0)) && (g_seh_except_depth == 0))
        || ((cVar1 == 0xda && ((g_compile_flags_c4 & 0x2000000) == 0)))) ||
       ((cVar1 == 0xd7 && (g_seh_finally_depth == 0)))) {
      diag_error(0x2c3,sym);
    }
    if (((sym->detail).halves.lo == 0xd8) && ((g_current_function->flags22 & 1) != 0)) {
      diag_error(0x1ea,0x53,sym);
    }
    pcVar7->op = 'w';
    pcVar4 = tree_new_int_constant((uint)(fn->detail).halves.lo);
    pcVar7->left = pcVar4;
  }
  else if ((fn->flags1 & 4) == 0) {
    pcVar4 = tree_new_symbol_ref(sym,'\x01');
    pcVar7->left = pcVar4;
    special_member_need_definition(fn);
  }
  else if ((*(byte *)((int)&fn->tail + 8) & 1) == 0) {
    cVar10 = '\x01';
    pcVar4 = tree_new_symbol_ref(sym,'\x01');
    pcVar7->left = pcVar4;
  }
  else {
    if (left == (c1_node *)0x0) {
      diag_error(0x160,g_scope_vector->entries[(short)fn->scope_index],fn);
      return (c1_node *)0x0;
    }
    pcVar4 = expr_adjust_this_for_member_call(left,fn,(c1_symbol *)nonvirtual,&nonvirtual);
    if ((((*(byte *)((int)&fn->tail + 8) & 0x20) != 0) && (args != 0)) &&
       (pcVar5 = expr_construct_result_in_place(fn,pcVar4,(c1_node *)args), pcVar5 != (c1_node *)0x0
       )) {
      return pcVar5;
    }
    pcVar5 = expr_bound_member_function(fn,pcVar4,(c1_node *)args);
    if (pcVar5 != (c1_node *)0x0) {
      return pcVar5;
    }
    pcVar8 = g_arenas + g_expr_arena_index;
    pcVar5 = (c1_node *)pcVar8->cur;
    pcVar6 = (c1_node *)g_arenas[g_expr_arena_index].end;
    pcVar8->cur = &pcVar5[1].op;
    if (pcVar6 < pcVar5 + 1) {
      arena_grow(pcVar8);
    }
    if (pcVar4->op == 'd') {
      pcVar4 = pcVar4->left;
    }
    pcVar4 = tree_new_unary('=',(c1_type *)
                                **(undefined4 **)
                                  (((uint)fn->type & -(uint)((fn->type->code & 0x80) != 0)) + 8),
                            pcVar4);
    if (((fn->flags21 & 2) == 0) || (bVar9)) {
      special_member_need_definition(fn);
      pcVar5->op = 0x99;
      pcVar6 = tree_new_symbol_ref(sym,'\x01');
      pcVar5->left = pcVar6;
    }
    else {
      pcVar5->op = 0x9a;
      pcVar6 = tree_new_int_constant((fn->detail).value);
      pcVar5->left = pcVar6;
      pcVar4 = tree_new_unary('=',*(c1_type **)(*(int *)(*(int *)(nonvirtual + 0x24) + 0x14) + 0x14)
                              ,pcVar4);
      if (g_minimal_rebuild != '\0') {
        pcVar7 = expr_check_call_context_tail
                           (pcVar4,pcVar5,fn,pcVar7,cVar10,visitor,visitor_mask,left,nonvirtual);
        return pcVar7;
      }
    }
    if ((fn->flags1 & 0x10) == 0x10) {
      pcVar7->type = (c1_type *)
                     **(undefined4 **)(((uint)fn->type & -(uint)((fn->type->code & 0x80) != 0)) + 8)
      ;
    }
    pcVar5->kind = '\x02';
    pcVar5->right = pcVar4;
    pcVar5->type = fn->type;
    pcVar7->left = pcVar5;
  }
  pcVar7 = expr_build_call_with_temporaries
                     (pcVar7,fn,*(ushort *)((uint)fn->type & -(uint)((fn->type->code & 0x80) != 0)))
  ;
  if ((cVar10 != '\0') && (left != (c1_node *)0x0)) {
    visitor_mask = 0xff;
    visitor = &g_side_effect_visitor_vtable;
    cVar10 = tree_has_side_effects((c1_tree_visitor *)&visitor,left);
    if (cVar10 != '\0') {
      pcVar7 = tree_new_binary_typed_right('7',left,pcVar7);
    }
  }
  return pcVar7;
}

