c1_node * __cdecl conv_convert_node_to_type(c1_u8 op,c1_type *type,c1_node *node)

{
  c1_type *pcVar1;
  c1_type *pcVar2;
  c1_node *pcVar3;
  byte bVar4;
  ushort uVar5;
  c1_type *pcVar6;
  c1_type local_10;
  
  bVar4 = (byte)type->code;
  if (((char)bVar4 < '\0') && ((node->kind & 0x80) != 0)) {
    if ((type->flags & 0x18) == 0x18) {
      pcVar1 = type->base;
      local_10.debug_index = 0;
      local_10.code = 0x82;
      local_10.flags = decl_apply_default_calling_convention(0x82,0);
      local_10.extra.sym = (c1_symbol *)0x0;
      local_10.base = pcVar1;
      type = type_intern(&local_10);
    }
    node->type = type;
    if (((type->code & 0x8f) != 0x82) || (((byte)type->base->code >> 6 & 1) == 0)) {
      node->kind = node->kind & 0x7f;
    }
    return node;
  }
  pcVar1 = node->type;
  if (-1 < (char)pcVar1->code) {
    pcVar3 = conv_convert_basic('\x01',type,node);
    return pcVar3;
  }
  uVar5 = type->flags & 0x18;
  if ((uVar5 != 0x18) && (uVar5 != 8)) {
    pcVar6 = pcVar1;
    if ((bVar4 >> 6 & 1) == 0) {
      do {
        pcVar6 = pcVar6->base;
        pcVar2 = type;
      } while ((char)pcVar6->code < '\0');
      while ((char)bVar4 < '\0') {
        bVar4 = (byte)pcVar2->base->code;
        pcVar2 = pcVar2->base;
      }
      if ((pcVar6->code != pcVar2->code) || ((pcVar1->extra).sym != (type->extra).sym)) {
        pcVar3 = conv_convert_basic('\x01',type,node);
        return pcVar3;
      }
    }
    pcVar3 = tree_new_cast(type,node);
    return pcVar3;
  }
  pcVar3 = type_based_pointer_from_node(type,node);
  pcVar3 = expr_based_pointer_fixup(pcVar3);
  return pcVar3;
}

