int __fastcall tuple_reads_memory(c2_tuple *t)

{
  c2_operand *pcVar1;
  
  pcVar1 = t->src;
  while( true ) {
    if (pcVar1 == (c2_operand *)0x0) {
      return 0;
    }
    if ((pcVar1->kind == '\x06') || (pcVar1->kind == '\x02')) break;
    pcVar1 = pcVar1->next;
  }
  return 1;
}

