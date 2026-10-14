c1_node * __cdecl conv_build_integral_constant_warn_truncation(c1_conversion *conv,c1_node *dest)

{
  c1_u8 *pcVar1;
  c1_node *pcVar2;
  ulonglong uVar3;
  
  diag_warning(2,0x131,(uint)conv->op,conv->source,conv->target);
  uVar3 = conv_cast_constant(conv->op,conv->expr,conv->target);
  pcVar2 = conv->expr;
  pcVar2->left = (void *)(int)uVar3;
  pcVar2->right = (void *)(int)(uVar3 >> 0x20);
  conv->expr->type = conv->target;
  if (((byte)g_compile_flags_c8 & 1) != 0) {
    pcVar1 = &conv->expr->kind;
    *pcVar1 = *pcVar1 & 0x7f;
  }
  if (dest == (c1_node *)0x0) {
    return conv->expr;
  }
  pcVar2 = conv_store_converted_value(conv,dest,conv->expr);
  return pcVar2;
}

