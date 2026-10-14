c1_node * __thiscall conv_build_integral_constant_to_floating(c1_conversion *conv,c1_node *dest)

{
  char warn;
  c1xx_float_const *pcVar1;
  c1_node *pcVar2;
  c1xx_float_const cStack_c;
  
  warn = conv_constant_warnings_enabled(conv);
  conv_warn_float_truncation_1
            (CONCAT31((int3)((uint)&cStack_c >> 8),conv->op),conv->expr,conv->target,&cStack_c,warn)
  ;
  pcVar1 = conv_float_constant_for_target(conv,&cStack_c);
  conv->expr->left = pcVar1;
  conv->expr->type = conv->target;
  conv->expr->kind = conv->expr->kind & 0x7f;
  if (dest == (c1_node *)0x0) {
    return conv->expr;
  }
  pcVar2 = conv_store_converted_value(conv,dest,conv->expr);
  return pcVar2;
}

