uint32_t __fastcall number_exposed_symbol_refs(c2_tuple *t,uint32_t n)

{
  c2_alias_sym_info *pcVar1;
  c2_operand *pcVar2;
  
  if (t != (c2_tuple *)0x0) {
    do {
      if ((t->flags & 1) != 0) {
        for (pcVar2 = t->dst; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
          if ((pcVar2->kind == '\x02') && ((pcVar2->sym->flags5 & 8) != 0)) {
            pcVar1 = (pcVar2->sym->u30).alias_info;
            pcVar2->rank = n;
            bitset_set(pcVar1->ref_nodes,n);
            n = n + 1;
          }
          else {
            pcVar2->rank = 0;
          }
        }
      }
      t = t->next;
    } while (t != (c2_tuple *)0x0);
    return n;
  }
  return n;
}

