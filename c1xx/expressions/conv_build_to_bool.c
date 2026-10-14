c1_node * __thiscall conv_build_to_bool(c1_conversion *conv,c1_node *dest)

{
  c1_u16 *pcVar1;
  int iVar2;
  c1_node *pcVar3;
  c1_type *in_EDX;
  c1_type *extraout_EDX;
  c1_type *extraout_EDX_00;
  c1_type *extraout_EDX_01;
  
  if ((conv->op == 'r') || (conv->op == 'V')) {
    return conv->expr;
  }
  pcVar3 = conv->expr;
  if (pcVar3->op != '\x06') {
    if ((pcVar3->kind & 7) != 3) goto LAB_10498847;
    in_EDX = conv->source;
    pcVar1 = &in_EDX->code;
    if ((*pcVar1 & 0x110) != 0) {
      in_EDX = pcVar3->right;
      if ((pcVar3->left != (void *)0x0 || in_EDX != (c1_type *)0x0) &&
         ((pcVar3->left != (void *)0x1 || (in_EDX != (c1_type *)0x0)))) goto LAB_10498820;
    }
    if ((((byte)*pcVar1 >> 5 & 1) == 0) ||
       ((iVar2 = float_const_compare_mask(6,pcVar3->left,&g_float_zero), in_EDX = extraout_EDX,
        iVar2 == 0 ||
        (iVar2 = float_const_compare_mask(6,conv->expr->left,&g_float_one), in_EDX = extraout_EDX_00
        , iVar2 == 0)))) goto LAB_10498847;
  }
LAB_10498820:
  if ((conv->mode < 4) || (6 < conv->mode)) {
    diag_warning(1,0x131,(uint)conv->op,conv->source,conv->target);
    in_EDX = extraout_EDX_01;
  }
LAB_10498847:
  pcVar3 = conv_warn_forcing_bool
                     (CONCAT31((int3)((uint)in_EDX >> 8),conv->op),conv->expr,conv->target);
  if (dest == (c1_node *)0x0) {
    return pcVar3;
  }
  pcVar3 = conv_store_converted_value(conv,dest,pcVar3);
  return pcVar3;
}

