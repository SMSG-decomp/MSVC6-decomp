int __fastcall reader_operand_tree_unsafe(c2_node *n)

{
  uint32_t uVar1;
  int iVar2;
  
  if (n != (c2_node *)0x0) {
    if ((1 << (n->kind & 0x1f) & 0xffeU) == 0) {
      do {
        iVar2 = select_arm_has_side_effect((c2_tuple *)n);
        if (iVar2 != 0) {
          return 1;
        }
        n = (c2_node *)((c2_tuple *)n)->prev;
      } while ((c2_tuple *)n != (c2_tuple *)0x0);
    }
    else {
      uVar1 = operand_is_unsafe_for_if_convert((c2_operand *)n);
      if (uVar1 != 0) {
        return 1;
      }
    }
  }
  return 0;
}

