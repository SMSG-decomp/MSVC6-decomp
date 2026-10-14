c2_tuple * __fastcall iv_increment_tuple(c2_symbol *iv)

{
  c2_tuple *pcVar1;
  c2_tuple *pcVar2;
  int iVar3;
  
  if ((iv->defs->next == (c2_list_cell *)0x0) &&
     (pcVar1 = (iv->defs->u04).tuple, pcVar1->op == 0x15b)) {
    pcVar2 = pcVar1->prev;
    if ((pcVar2->op == 0x16d) || (pcVar2->op == 0x16e)) {
      iVar3 = operand_compare(pcVar2->dst,pcVar1->src);
      if (iVar3 == 0) {
        iVar3 = operand_compare(pcVar1->dst,pcVar2->src);
        if (iVar3 == 0) {
          return pcVar2;
        }
      }
    }
  }
  return (c2_tuple *)0x0;
}

