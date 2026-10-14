c1_node * __cdecl
fold_float_overflow_check
          (byte target_code,uint source_code,c1_node *node,c1_type *type,float_const value)

{
  int iVar1;
  char *text;
  uint uVar2;
  void *pvVar3;
  float_const *out;
  
  if ((target_code >> 5 & 1) != 0) {
    if (((source_code & 0x2000) == 0) &&
       ((((g_ms_extensions != '\0' || ((source_code & 0xfff) != 0x11)) ||
         ((source_code & 0x1000) != 0)) || (g_opt_J_unsigned_char == '\0')))) {
      iVar1 = 0;
    }
    else {
      iVar1 = 1;
    }
    out = &value;
    text = int64_to_string((int *)&node->left,&stack0x0000002c,10,iVar1);
    uVar2 = float_const_from_string(text,out);
    if ((char)uVar2 != '\0') {
      diag_warning(2,0x38);
    }
  }
  if (((byte)type->code >> 5 & 1) != 0) {
    if (g_opt_Op != '\0') {
      iVar1 = type_size_scalar(type);
      fold_float_round_to_width(&value,iVar1);
    }
    iVar1 = type_size_scalar(type);
    value.size = (ushort)iVar1;
    node->op = 'e';
    pvVar3 = record3_new_from((int *)&value,g_expr_arena_index);
    node->left = pvVar3;
  }
  node->type = type;
  return node;
}

