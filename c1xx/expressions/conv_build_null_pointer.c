c1_node * __thiscall conv_build_null_pointer(c1_conversion *conv,c1_node *dest)

{
  byte bVar1;
  ushort uVar2;
  c1_node *pcVar3;
  c1_type *type;
  
  type = conv->target;
  bVar1 = (byte)type->code;
  if ((((char)bVar1 < '\0') && ((bVar1 & 0x8f) == 0x82)) &&
     ((uVar2 = type->flags & 0x18, uVar2 == 0x18 || (uVar2 == 8)))) {
    type = type_strip_based(type);
  }
  conv->expr->type = type;
  conv->expr->kind = conv->expr->kind & 0x7f;
  if (dest != (c1_node *)0x0) {
    pcVar3 = conv_store_converted_value(conv,dest,conv->expr);
    return pcVar3;
  }
  return conv->expr;
}

