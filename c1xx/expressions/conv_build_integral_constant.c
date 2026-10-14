c1_node * __thiscall conv_build_integral_constant(c1_conversion *conv,c1_node *dest)

{
  c1_u8 *pcVar1;
  ushort uVar2;
  c1_type *t;
  char cVar3;
  int target_unsigned;
  uint size;
  c1_node *pcVar4;
  int iVar5;
  ulonglong uVar6;
  void *lo;
  void *hi;
  
  cVar3 = conv_constant_warnings_enabled(conv);
  if (cVar3 != '\0') {
    lo = conv->expr->left;
    hi = conv->expr->right;
    uVar2 = conv->target->code;
    if (((uVar2 & 0x2000) != 0) ||
       ((((uVar2 & 0xfff) == 0x11 && ((uVar2 & 0x1000) == 0)) && (g_opt_J_unsigned_char != '\0'))))
    {
      uVar2 = conv->source->code;
      if (((uVar2 & 0x2000) == 0) &&
         (((((uVar2 & 0xfff) != 0x11 || ((uVar2 & 0x1000) != 0)) || (g_opt_J_unsigned_char == '\0'))
          && (((int)hi < 1 && ((int)hi < 0)))))) {
        diag_warning(4,0xf5,(uint)conv->op,conv->source,conv->target);
      }
    }
    t = conv->target;
    if (t->code != conv->source->code) {
      uVar2 = conv->source->code;
      if (((uVar2 & 0x2000) == 0) &&
         ((((uVar2 & 0xfff) != 0x11 || ((uVar2 & 0x1000) != 0)) || (g_opt_J_unsigned_char == '\0')))
         ) {
        iVar5 = 0;
      }
      else {
        iVar5 = 1;
      }
      uVar2 = t->code;
      if (((uVar2 & 0x2000) == 0) &&
         ((((uVar2 & 0xfff) != 0x11 || ((uVar2 & 0x1000) != 0)) || (g_opt_J_unsigned_char == '\0')))
         ) {
        target_unsigned = 0;
      }
      else {
        target_unsigned = 1;
      }
      size = type_size_scalar(t);
      iVar5 = conv_constant_out_of_range(size,target_unsigned,iVar5,(uint)lo,(uint)hi);
      if (iVar5 != 0) {
        pcVar4 = conv_build_integral_constant_warn_truncation(conv,dest);
        return pcVar4;
      }
    }
  }
  uVar6 = conv_cast_constant(conv->op,conv->expr,conv->target);
  pcVar4 = conv->expr;
  pcVar4->left = (void *)(int)uVar6;
  pcVar4->right = (void *)(int)(uVar6 >> 0x20);
  conv->expr->type = conv->target;
  if (((byte)g_compile_flags_c8 & 1) != 0) {
    pcVar1 = &conv->expr->kind;
    *pcVar1 = *pcVar1 & 0x7f;
  }
  if (dest == (c1_node *)0x0) {
    return conv->expr;
  }
  pcVar4 = conv_store_converted_value(conv,dest,conv->expr);
  return pcVar4;
}

