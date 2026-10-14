c1_node * __thiscall conv_build_reference_temporary(c1_conversion *conv,c1_node *dest)

{
  c1_conversion *pcVar1;
  c1_node *pcVar2;
  c1_node *right;
  c1_conversion *pcStack_4;
  
  if ((conv->target_kind == 3) || (conv->target_kind == 6)) {
    pcStack_4 = (c1_conversion *)0x0;
    pcVar2 = conv_new_temporary_variable_address(conv,conv->first->target,(c1_symbol **)&pcStack_4);
    pcStack_4->pad03 = pcStack_4->pad03 | 0x20;
    pcVar1 = conv->first;
    pcVar1->target_symbol = (c1_symbol *)pcStack_4;
    pcVar1->target_kind = 2;
  }
  else {
    pcStack_4 = conv;
    pcVar2 = expr_new_reference_temporary(conv->first->target);
    pcVar1 = conv->first;
    pcVar1->target_symbol = (c1_symbol *)0x0;
    pcVar1->target_kind = 1;
  }
  right = tree_copy_to_arena(pcVar2,g_expr_arena_index);
  pcVar2 = conv_apply_conversion(conv->first,pcVar2);
  pcVar2 = expr_build_builtin_binary('7',pcVar2,right);
  if (dest != (c1_node *)0x0) {
    pcVar2 = tree_new_init_assign(dest,pcVar2);
  }
  if ((conv->flags & 4) != 0) {
    if (conv->op == '}') {
      diag_warning(1,0xac);
    }
    return pcVar2;
  }
  pcVar2 = tree_new_rvalue(pcVar2);
  pcVar2->type = conv->first->target;
  return pcVar2;
}

