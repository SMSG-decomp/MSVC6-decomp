c1_node * __cdecl expr_build_selected_operator(int *winner,c1_node *left,c1_node *right)

{
  c1_u8 op;
  c1_symbol *sym;
  int *cand;
  c1_node *pcVar1;
  c1_node *pcVar2;
  uint argc;
  bool bVar3;
  
  cand = winner;
  sym = (c1_symbol *)*winner;
  if (sym != (c1_symbol *)0x0) {
    pcVar2 = (c1_node *)0x0;
    bVar3 = (sym->flags1 & 4) == 0;
    if (bVar3) {
      pcVar2 = tree_append_list_item((c1_node *)0x0,left,0);
      left = (c1_node *)0x0;
    }
    else {
      left = expr_build_address_of(left,6);
    }
    argc = (uint)bVar3;
    if (right != (c1_node *)0x0) {
      pcVar2 = tree_append_list_item(pcVar2,right,0);
      argc = argc + 1;
    }
    if ((c1_symbol *)winner[2] != (c1_symbol *)0x0) {
      expr_set_overload_target_and_check_access((c1_symbol *)winner[2],(int)sym);
    }
    pcVar2 = expr_build_call_node(sym,left,(int)pcVar2,winner[9],argc,0);
    return pcVar2;
  }
  op = *(c1_u8 *)winner[0xb];
  winner = (int *)CONCAT31(winner._1_3_,op);
  pcVar2 = ovl_apply_argument_conversion((c1_ovl_candidate *)cand,0);
  if ((((op != '@') && (op != '8')) && (op != 'U')) && (op != 'T')) {
    if (right != (c1_node *)0x0) {
      pcVar1 = ovl_apply_argument_conversion((c1_ovl_candidate *)cand,1);
      if ((op == '2') || (op == 'O')) {
        pcVar1 = expr_full_expression_guarded(pcVar1,3);
      }
      pcVar2 = expr_build_builtin_binary(op,pcVar2,pcVar1);
      return pcVar2;
    }
    pcVar2 = expr_build_builtin_unary((uint)winner,pcVar2);
    return pcVar2;
  }
  pcVar1 = tree_new_int_constant(1);
  pcVar2 = expr_build_builtin_binary(op,pcVar2,pcVar1);
  return pcVar2;
}

