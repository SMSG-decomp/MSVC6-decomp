int __fastcall tuple_chain_reads_reg(c2_tuple *t,void *reg)

{
  byte bVar1;
  c2_operand *pcVar2;
  
  bVar1 = t->flags;
  do {
    if ((bVar1 & 1) == 0) {
      return 0;
    }
    for (pcVar2 = t->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
      if ((pcVar2->kind == '\x01') && (pcVar2->sym == reg)) {
        return 1;
      }
    }
    t = t->prev;
    bVar1 = t->flags;
  } while( true );
}

