int __fastcall block_is_label_only_or_jump(c2_block *block)

{
  c2_tuple *pcVar1;
  c2_tuple *pcVar2;
  
  for (pcVar1 = block->head->next;
      (((pcVar1 != (c2_tuple *)0x0 && (pcVar1->kind == '\x16')) && (pcVar1->op != 0x1b4)) &&
      (pcVar1->op != 0x1b5)); pcVar1 = pcVar1->next) {
  }
  pcVar2 = block->end->prev;
  if (pcVar2 != (c2_tuple *)0x0) {
    while ((pcVar2->kind == '\x16' && (pcVar2->op != 0x1b4))) {
      if ((pcVar2->op == 0x1b5) || (pcVar2 = pcVar2->prev, pcVar2 == (c2_tuple *)0x0)) break;
    }
  }
  if (pcVar1 == pcVar2) {
    if (pcVar1->kind == '\x1a') {
      return 1;
    }
  }
  else if (((pcVar1->kind == '\x1a') && (pcVar2->kind == '\x11')) &&
          (((pcVar2->u20).cond_cells == (c2_cond_cell *)0x0 && (pcVar2->op != 0x18b)))) {
    for (pcVar1 = pcVar1->next;
        (((pcVar1 != (c2_tuple *)0x0 && (pcVar1->kind == '\x16')) && (pcVar1->op != 0x1b4)) &&
        (pcVar1->op != 0x1b5)); pcVar1 = pcVar1->next) {
    }
    if (pcVar1 == pcVar2) {
      return 1;
    }
  }
  return 0;
}

