int __fastcall select_arm_has_side_effect(c2_tuple *node)

{
  uint32_t uVar1;
  int iVar2;
  c2_operand *pcVar3;
  
  switch(*(undefined1 *)((int)select_arm_has_side_effect_jump_table + (uint)node->kind)) {
  case 0:
    if ((node->op != 0x15b) && (node->op != 0x175)) {
      for (pcVar3 = node->dst; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
        uVar1 = operand_is_unsafe_for_if_convert(pcVar3);
        if (uVar1 != 0) {
          return 1;
        }
      }
      pcVar3 = node->src;
      if (pcVar3 == (c2_operand *)0x0) {
        return 0;
      }
      while (iVar2 = reader_operand_tree_unsafe((c2_node *)pcVar3), iVar2 == 0) {
        pcVar3 = pcVar3->next;
        if (pcVar3 == (c2_operand *)0x0) {
          return 0;
        }
      }
    }
    break;
  case 1:
    return 0;
  }
  return 1;
}

