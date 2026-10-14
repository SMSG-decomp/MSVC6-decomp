int __cdecl conv_classify_cast(c1_type *type,c1_node *node,int mode)

{
  int iVar1;
  c1_type *from;
  byte bVar2;
  
  if (node != (c1_node *)0x0) {
    if (type == (c1_type *)0x0) {
      return 0x400;
    }
    from = node->type;
    if (((from->code & 0x200) == 0) && ((type->code & 0x200) == 0)) {
      bVar2 = (byte)type->code;
      if ((((node->kind & 0x80) != 0) && ((char)bVar2 < '\0')) && ((bVar2 & 0x8f) != 0x80)) {
        return 1;
      }
      if (((bVar2 & 0x8f) == 0x82) && (((byte)from->code & 0x8f) == 0x83)) {
        from = conv_array_to_pointer_type(node);
      }
      iVar1 = conv_classify_types(type,from,mode);
      return iVar1;
    }
  }
  return 0x2000;
}

