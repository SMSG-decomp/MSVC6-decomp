c1_node * __cdecl fold_float_conversion(c1_u8 op,c1_type *t,c1_node *node)

{
  ushort uVar1;
  c1_u32 *pcVar2;
  byte bVar3;
  char *text;
  uint uVar4;
  c1_type *pcVar5;
  int iVar6;
  void *pvVar7;
  ulonglong uVar8;
  c1xx_float_const *out;
  void *local_44;
  c1_type *local_40;
  c1_type_extra local_3c;
  c1_u32 local_38;
  c1xx_float_const value;
  char local_28 [40];
  
  if (((node->type->code & 0x100) != 0) && ((t->code & 0x100) == 0)) {
    node->type = g_type_int;
  }
  pcVar5 = node->type;
  uVar1 = pcVar5->code;
  bVar3 = (byte)uVar1;
  if (((bVar3 >> 4 & 1) == 0) && (-1 < (char)bVar3)) {
    if ((bVar3 >> 5 & 1) != 0) {
      bVar3 = (byte)t->code;
      if ((bVar3 >> 4 & 1) == 0) {
        if ((bVar3 >> 5 & 1) != 0) {
          pcVar2 = node->left;
          value.mantissa_lo = *pcVar2;
          value.mantissa_hi = pcVar2[1];
          value._8_4_ = pcVar2[2];
        }
      }
      else {
        iVar6 = fold_float_to_int64_checked(node->left,(c1_u32 *)&local_44);
        if (iVar6 != 0) {
          diag_warning(2,0x38);
        }
        node->left = local_44;
        node->op = 'e';
        node->right = local_40;
      }
    }
  }
  else {
    bVar3 = (byte)t->code;
    if (((bVar3 >> 4 & 1) == 0) && (-1 < (char)bVar3)) {
      if ((bVar3 >> 5 & 1) != 0) {
        if (((uVar1 & 0x2000) == 0) &&
           ((((uVar1 & 0xfff) != 0x11 || ((uVar1 & 0x1000) != 0)) || (g_opt_J_unsigned_char == '\0')
            ))) {
          iVar6 = 0;
        }
        else {
          iVar6 = 1;
        }
        out = &value;
        text = int64_to_string((int *)&node->left,local_28,10,iVar6);
        uVar4 = float_const_from_string(text,out);
        if ((char)uVar4 != '\0') {
          diag_warning(2,0x38);
        }
      }
    }
    else {
      uVar8 = conv_cast_constant(op,node,t);
      node->left = (void *)(int)uVar8;
      node->right = (void *)(int)(uVar8 >> 0x20);
      uVar1 = t->code;
      if (((uVar1 & 0x2000) != 0) ||
         ((((uVar1 & 0xfff) == 0x11 && ((uVar1 & 0x1000) == 0)) && (g_opt_J_unsigned_char != '\0')))
         ) {
        uVar1 = pcVar5->code;
        if (((uVar1 & 0x2000) == 0) &&
           ((((uVar1 & 0xfff) != 0x11 || ((uVar1 & 0x1000) != 0)) || (g_opt_J_unsigned_char == '\0')
            ))) {
          pcVar5 = node->type;
          uVar1 = pcVar5->code;
          if (((uVar1 & 0x2000) == 0) &&
             ((((uVar1 & 0xfff) != 0x11 || ((uVar1 & 0x1000) != 0)) ||
              (g_opt_J_unsigned_char == '\0')))) {
            uVar4._0_2_ = pcVar5->code;
            uVar4._2_2_ = pcVar5->flags;
            local_40 = pcVar5->base;
            local_3c = pcVar5->extra;
            local_38 = pcVar5->debug_index;
            local_44 = (void *)(uVar4 | 0x2000);
            pcVar5 = type_intern((c1_type *)&local_44);
          }
          node->type = pcVar5;
        }
      }
    }
  }
  if (((byte)t->code >> 5 & 1) != 0) {
    if (g_opt_Op != '\0') {
      iVar6 = type_size_scalar(t);
      fold_float_round_to_width((int)&value,iVar6);
    }
    iVar6 = type_size_scalar(t);
    node->op = 'e';
    value.size = (c1_u16)iVar6;
    pvVar7 = record3_new_from((int *)&value,g_expr_arena_index);
    node->left = pvVar7;
  }
  node->type = t;
  node->kind = node->kind & 0x7f;
  return node;
}

