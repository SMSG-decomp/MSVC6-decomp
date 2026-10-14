c1_node * __cdecl
fold_float_constant_conversion_fragment
          (char ms_extensions,uint code,char char_unsigned,c1_type *source_type,c1_node *node,
          c1_type *type,c1_type type_copy,float_const value)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  c1_type *pcVar4;
  int iVar5;
  void *pvVar6;
  
  if ((((((code & 0xfff) == 0x11) && ((code & 0x1000) == 0)) && (char_unsigned != '\0')) &&
      (uVar1 = source_type->code, (uVar1 & 0x2000) == 0)) &&
     (((ms_extensions != '\0' || ((uVar1 & 0xfff) != 0x11)) ||
      (((uVar1 & 0x1000) != 0 || (char_unsigned == '\0')))))) {
    pcVar4 = node->type;
    uVar1 = pcVar4->code;
    if (((uVar1 & 0x2000) == 0) &&
       (((ms_extensions != '\0' || ((uVar1 & 0xfff) != 0x11)) ||
        (((uVar1 & 0x1000) != 0 || (char_unsigned == '\0')))))) {
      uVar2 = pcVar4->code;
      uVar3 = pcVar4->flags;
      type_copy.base = pcVar4->base;
      type_copy.code._0_1_ = (undefined1)uVar2;
      type_copy.code._1_1_ = (byte)((ushort)uVar2 >> 8);
      type_copy.extra = pcVar4->extra;
      type_copy.code._1_1_ = type_copy.code._1_1_ | 0x20;
      type_copy.debug_index = pcVar4->debug_index;
      type_copy.flags = uVar3;
      pcVar4 = type_intern(&type_copy);
    }
    node->type = pcVar4;
  }
  if (((byte)type->code >> 5 & 1) != 0) {
    if (g_opt_Op != '\0') {
      iVar5 = type_size_scalar(type);
      fold_float_round_to_width(&value,iVar5);
    }
    iVar5 = type_size_scalar(type);
    value.size = (ushort)iVar5;
    node->op = 'e';
    pvVar6 = record3_new_from((int *)&value,g_expr_arena_index);
    node->left = pvVar6;
  }
  node->type = type;
  return node;
}

