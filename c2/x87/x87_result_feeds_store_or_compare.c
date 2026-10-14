int32_t __fastcall x87_result_feeds_store_or_compare(c2_tuple *t)

{
  c2_symbol *pcVar1;
  c2_tuple *pcVar2;
  c2_operand *pcVar3;
  int32_t iVar4;
  
  pcVar1 = t->dst->sym;
  if ((pcVar1->cls == '\x03') && (pcVar1->def != (c2_tuple *)0x0)) {
    pcVar2 = t->next;
    iVar4 = 1;
    if (((pcVar2->flags & 1) != 0) &&
       (((pcVar3 = pcVar2->src, pcVar3 != (c2_operand *)0x0 && (pcVar3->kind == '\x01')) &&
        (pcVar3->sym == pcVar1)))) {
      switch(pcVar2->op) {
      case 0x5c:
      case 0x5d:
      case 0x5e:
      case 0x62:
      case 99:
        goto switchD_1075ddac_caseD_5c;
      }
    }
  }
  iVar4 = 0;
switchD_1075ddac_caseD_5c:
  return iVar4;
}

