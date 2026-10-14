longlong __cdecl expr_eval_constant_expression(c1_node *node)

{
  ushort uVar1;
  longlong lVar2;
  longlong lVar3;
  
  if (node == (c1_node *)0x0) {
    diag_error(0x38);
    return 0;
  }
  if ((node->kind & 7) != 3) {
    diag_error(0x39);
    return 0;
  }
  if ((node->type->code & 0x110) != 0) {
    lVar2._0_4_ = node->left;
    lVar2._4_4_ = node->right;
    return lVar2;
  }
  if (((g_ms_extensions != '\0') && (uVar1 = node->type->code, (char)uVar1 < '\0')) &&
     ((uVar1 = uVar1 & 0x8f, uVar1 == 0x86 || (uVar1 == 0x82)))) {
    lVar3._0_4_ = node->left;
    lVar3._4_4_ = node->right;
    return lVar3;
  }
  diag_error(0x3a);
  return 0;
}

