c2_operand * __fastcall find_rec_value_for_operand(c2_operand *op,c2_loop *loop)

{
  c2_list_cell *pcVar1;
  c2_tuple *pcVar2;
  int iVar3;
  
  pcVar1 = loop->iv_preheader_inits;
  while( true ) {
    if (pcVar1 == (c2_list_cell *)0x0) {
      return (c2_operand *)0x0;
    }
    pcVar2 = (pcVar1->u04).tuple;
    iVar3 = operand_compare(op,pcVar2->dst);
    if (iVar3 == 0) break;
    pcVar1 = pcVar1->next;
  }
  return pcVar2->src;
}

