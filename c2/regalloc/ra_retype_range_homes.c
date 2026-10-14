void __fastcall ra_retype_range_homes(c2_live_range *lr,uint32_t size)

{
  c2_tuple *pcVar1;
  c2_tuple *pcVar2;
  c2_operand *pcVar3;
  c2_operand *pcVar4;
  c2_symbol *pcVar5;
  ushort type;
  c2_block *pcVar6;
  
  pcVar6 = lr->first_block;
  while( true ) {
    pcVar2 = pcVar6->end;
    for (pcVar1 = pcVar6->head; pcVar1 != pcVar2; pcVar1 = pcVar1->next) {
      if ((pcVar1->op == 0x163) && (pcVar3 = pcVar1->dst, (pcVar3->u18).reg == (c2_symbol *)lr)) {
        pcVar4 = pcVar1->src;
        type = pcVar1->type & 0xf000 | (ushort)size;
        if (pcVar4->kind == '\x02') {
          pcVar5 = symbol_get_part(pcVar4->sym,type,size,0);
          pcVar3->sym = pcVar5;
          pcVar4->sym = pcVar5;
        }
        pcVar3->type = type;
        pcVar4->type = type;
        pcVar1->type = type;
      }
    }
    if (pcVar6 == lr->last_block) break;
    pcVar6 = pcVar6->next;
  }
  return;
}

