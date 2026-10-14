uint tree_node_has_side_effect(c1_node *node)

{
  byte bVar1;
  uint3 uVar3;
  c1_type *pcVar2;
  
  pcVar2 = node->type;
  uVar3 = (uint3)((uint)pcVar2 >> 8);
  if ((pcVar2->code == 0x80c) || (pcVar2->code == 0x80e)) {
    return (uint)uVar3 << 8;
  }
  bVar1 = node->op;
  if ((((g_token_class[bVar1] != 'a') && (g_token_class[bVar1] != 's')) && (bVar1 != 0x34)) &&
     ((bVar1 != 0x70 && (bVar1 != 0x77)))) {
    if ((pcVar2->code & 0x8f) == 0x83) {
      pcVar2 = type_skip_arrays(pcVar2->base);
    }
    return CONCAT31((int3)((uint)pcVar2 >> 8),(byte)pcVar2->flags >> 6) & 0xffffff01;
  }
  return CONCAT31(uVar3,1);
}

