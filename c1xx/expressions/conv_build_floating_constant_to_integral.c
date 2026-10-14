c1_node * __thiscall conv_build_floating_constant_to_integral(c1_conversion *conv,c1_node *dest)

{
  char cVar1;
  int iVar2;
  c1_node *pcVar3;
  void *pvStack_8;
  void *pvStack_4;
  
  cVar1 = conv_constant_warnings_enabled(conv);
  if (cVar1 != '\0') {
    diag_warning(2,0xf4,(uint)conv->op,conv->source,conv->target);
  }
  iVar2 = fold_float_to_int64_checked(conv->expr->left,(c1_u32 *)&pvStack_8);
  if (iVar2 != 0) {
    diag_warning(2,0x38);
  }
  conv->expr->op = 'e';
  pcVar3 = conv->expr;
  pcVar3->left = pvStack_8;
  pcVar3->right = pvStack_4;
  conv->expr->type = conv->target;
  conv->expr->kind = conv->expr->kind & 0x7f;
  if (dest != (c1_node *)0x0) {
    pcVar3 = conv_store_converted_value(conv,dest,conv->expr);
    return pcVar3;
  }
  return conv->expr;
}

