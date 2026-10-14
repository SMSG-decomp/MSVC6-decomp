c1_node * __thiscall conv_apply_standard_conversion(c1_conversion *conv,c1_node *dest)

{
  c1_type *type;
  c1_node *pcVar1;
  byte bVar2;
  
  pcVar1 = conv->expr;
  if ((pcVar1->kind & 7) == 3) {
    pcVar1->type = conv->target;
  }
  else {
    type = conv->target;
    if ((type == conv->source) && (((byte)g_compile_flags_c8 & 1) == 0)) {
      if ((conv->op == '`') && ((type->code & 0xfff) == 0x10)) {
        pcVar1 = conv_apply_standard_conversion_bool_argument(pcVar1,type,conv,dest);
        return pcVar1;
      }
    }
    else {
      pcVar1 = tree_new_unary('d',type,pcVar1);
      bVar2 = (*(byte *)((int)pcVar1->left + 2) ^ pcVar1->flags) & 1 ^ pcVar1->flags;
      pcVar1->flags = bVar2;
      pcVar1->flags = (*(byte *)((int)pcVar1->left + 2) ^ bVar2) & 4 ^ bVar2;
    }
  }
  if (dest != (c1_node *)0x0) {
    pcVar1 = conv_store_converted_value(conv,dest,pcVar1);
  }
  return pcVar1;
}

