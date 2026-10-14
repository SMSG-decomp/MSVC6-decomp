c2_operand * __fastcall find_dst_symbol_ref(c2_tuple *t,c2_symbol *sym)

{
  c2_operand *pcVar1;
  c2_symbol *pcVar2;
  
  pcVar1 = t->dst;
  do {
    if (pcVar1 == (c2_operand *)0x0) {
      return (c2_operand *)0x0;
    }
    if (((1 << (pcVar1->kind & 0x1f) & 6U) != 0) &&
       (pcVar2 = pcVar1->sym, pcVar2->storage == sym->storage)) {
      if (pcVar2 == sym) {
        return pcVar1;
      }
      if ((pcVar2->offset < sym->size + sym->offset) &&
         (sym->offset < pcVar2->size + pcVar2->offset)) {
        return pcVar1;
      }
    }
    pcVar1 = pcVar1->next;
  } while( true );
}

