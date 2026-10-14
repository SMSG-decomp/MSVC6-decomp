int __fastcall tree_has_side_effect_or_mem_read(c2_node *n)

{
  int iVar1;
  
  iVar1 = node_has_side_effects(n);
  if (iVar1 == 0) {
    iVar1 = tree_reads_memory_through_temp(n);
    return iVar1;
  }
  return 1;
}

