c1_node * __cdecl conv_convert_to_type(c1_u8 op,c1_type *type,c1_node *node)

{
  byte bVar1;
  c1_node *pcVar2;
  c1_type *pcVar3;
  c1_type *pcVar4;
  
  if (node == (c1_node *)0x0) {
    return (c1_node *)0x0;
  }
  pcVar4 = node->type;
  bVar1 = (byte)type->code;
  if ((-1 < (char)bVar1) && (-1 < (char)pcVar4->code)) {
    if (type == pcVar4) {
      node->kind = node->kind & 0x7f;
      return node;
    }
    if ((type->code == pcVar4->code) && ((type->extra).sym == (pcVar4->extra).sym)) {
      pcVar3 = type;
      if ((bVar1 & 0x8f) == 0x83) {
        pcVar3 = type_skip_arrays(type->base);
      }
      if ((pcVar4->code & 0x8f) == 0x83) {
        pcVar4 = type_skip_arrays(pcVar4->base);
      }
      if (((pcVar4->flags ^ pcVar3->flags) & 0x3e0) == 0) {
        pcVar2 = conv_convert_to_type_fragment(node,type);
        return pcVar2;
      }
    }
    pcVar2 = conv_convert_basic(op,type,node);
    return pcVar2;
  }
  if (type != pcVar4) {
    pcVar2 = conv_convert_node_to_type(op,type,node);
    return pcVar2;
  }
  return node;
}

