uint __cdecl expr_refers_to_local_variable(c1_node *node)

{
  byte bVar1;
  c1_node *pcVar2;
  
  pcVar2 = tree_strip_casts_and_segment_bases(node);
  if ((((pcVar2 != (c1_node *)0x0) && ((pcVar2->kind & 7) == 4)) &&
      (bVar1 = *(byte *)((int)pcVar2->left + 0x20) & 7, 3 < bVar1)) && (bVar1 < 7)) {
    return 1;
  }
  return 0;
}

