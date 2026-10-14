longlong __cdecl expr_eval_constant_expression(c1_node *node)

{
  ushort uVar1;
  c1_node *pcVar2;
  longlong lVar3;
  longlong lVar4;
  
  if (node == (c1_node *)0x0) {
    diag_error(0x38);
    return 0;
  }
  pcVar2 = fold_static_const_member(node);
  if ((pcVar2->kind & 7) == 3) {
    if ((pcVar2->type->code & 0x110) != 0) {
      lVar3._0_4_ = pcVar2->left;
      lVar3._4_4_ = pcVar2->right;
      return lVar3;
    }
    if (((g_ms_extensions != '\0') && (uVar1 = pcVar2->type->code, (char)uVar1 < '\0')) &&
       ((uVar1 = uVar1 & 0x8f, uVar1 == 0x86 || (uVar1 == 0x82)))) {
      lVar4._0_4_ = pcVar2->left;
      lVar4._4_4_ = pcVar2->right;
      return lVar4;
    }
    diag_error(0x3a);
  }
  else if (((g_compile_flags_cc & 0x100000) == 0) && ((g_compile_flags_cc & 0x20) == 0)) {
    diag_error(0x39);
    return 0;
  }
  return 0;
}

