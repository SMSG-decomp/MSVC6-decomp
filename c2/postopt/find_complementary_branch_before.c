c2_tuple * __fastcall find_complementary_branch_before(c2_tuple *label,c2_tuple *t)

{
  uint8_t uVar1;
  c2_tuple *pcVar2;
  c2_tuple *pcVar3;
  
  pcVar2 = label->prev;
  uVar1 = pcVar2->kind;
  while (uVar1 == '\x1a') {
    pcVar2 = pcVar2->prev;
    uVar1 = pcVar2->kind;
  }
  if (((pcVar2->kind == '\x11') && ((pcVar2->u20).cond_cells != (c2_cond_cell *)0x0)) &&
     ((byte)pcVar2->type == g_cond_inverse[(byte)t->type])) {
    pcVar3 = *(c2_tuple **)(*(int *)((int)&pcVar2->src->sym->u30 + 2) + 0xc);
    uVar1 = pcVar3->kind;
    while (uVar1 == '\x1a') {
      pcVar3 = pcVar3->prev;
      uVar1 = pcVar3->kind;
    }
    return (c2_tuple *)((uint)pcVar2 & (pcVar3 != t) - 1);
  }
  return (c2_tuple *)0x0;
}

