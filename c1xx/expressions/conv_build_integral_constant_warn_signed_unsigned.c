c1_node * __cdecl
conv_build_integral_constant_warn_signed_unsigned
          (c1_conversion *conv,c1_type *target,c1_type *source,uint value_lo,int value_hi,
          c1_node *dest)

{
  c1_u8 *pcVar1;
  ushort uVar2;
  c1_type *t;
  int target_unsigned;
  uint size;
  c1_node *pcVar3;
  int iVar4;
  ulonglong uVar5;
  
  diag_warning(4,0xf5,(uint)conv->op,source,target);
  t = conv->target;
  if (t->code != conv->source->code) {
    uVar2 = conv->source->code;
    if (((uVar2 & 0x2000) == 0) &&
       ((((uVar2 & 0xfff) != 0x11 || ((uVar2 & 0x1000) != 0)) || (g_opt_J_unsigned_char == '\0'))))
    {
      iVar4 = 0;
    }
    else {
      iVar4 = 1;
    }
    uVar2 = t->code;
    if (((uVar2 & 0x2000) == 0) &&
       ((((uVar2 & 0xfff) != 0x11 || ((uVar2 & 0x1000) != 0)) || (g_opt_J_unsigned_char == '\0'))))
    {
      target_unsigned = 0;
    }
    else {
      target_unsigned = 1;
    }
    size = type_size_scalar(t);
    iVar4 = conv_constant_out_of_range(size,target_unsigned,iVar4,value_lo,value_hi);
    if (iVar4 != 0) {
      pcVar3 = conv_build_integral_constant_warn_truncation(conv,dest);
      return pcVar3;
    }
  }
  uVar5 = conv_cast_constant(conv->op,conv->expr,conv->target);
  pcVar3 = conv->expr;
  pcVar3->left = (void *)(int)uVar5;
  pcVar3->right = (void *)(int)(uVar5 >> 0x20);
  conv->expr->type = conv->target;
  if (((byte)g_compile_flags_c8 & 1) != 0) {
    pcVar1 = &conv->expr->kind;
    *pcVar1 = *pcVar1 & 0x7f;
  }
  if (dest != (c1_node *)0x0) {
    pcVar3 = conv_store_converted_value(conv,dest,conv->expr);
    return pcVar3;
  }
  return conv->expr;
}

