int __fastcall trees_equal_and_pure(c2_node *a,c2_node *b)

{
  int iVar1;
  
  iVar1 = compare_trees(a,b);
  if (iVar1 == 0) {
    iVar1 = tree_has_side_effect_or_mem_read(a);
    if (iVar1 == 0) {
      return 1;
    }
  }
  return 0;
}

