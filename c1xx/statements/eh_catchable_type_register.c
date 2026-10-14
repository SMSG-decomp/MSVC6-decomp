int __cdecl eh_catchable_type_register(c1_catchable_type *ct,char rtti_walk)

{
  c1_catchable_type *pcVar1;
  c1_catchable_type *pcVar2;
  c1_catchable_type *pcVar3;
  
  if (((ct->flags & 0xd) == 0) ||
     (((pcVar1 = symtab_lookup(g_catchable_type_table,ct->cls), rtti_walk != '\0' ||
       (pcVar1 == (c1_catchable_type *)0x0)) &&
      (symtab_insert(g_catchable_type_table,ct->cls,ct), pcVar1 == (c1_catchable_type *)0x0)))) {
    return 0;
  }
  ct->same_type = pcVar1;
  if ((pcVar1->flags & 0x200) == 0) {
    if (((ct->base != (c1_symbol *)0x0) && ((ct->base->key_ref & 0x10000) != 0)) &&
       ((pcVar1->base != (c1_symbol *)0x0 && ((pcVar1->base->key_ref & 0x10000) != 0)))) {
      return 0x4000;
    }
    if (rtti_walk != '\0') {
      pcVar2 = pcVar1->derived;
      pcVar3 = ct->derived;
      if (pcVar2 != pcVar3) {
        do {
          if (pcVar2->cls != pcVar3->cls) break;
          if (((pcVar2->base != (c1_symbol *)0x0) && ((pcVar2->base->key_ref & 0x10000) != 0)) &&
             ((pcVar3->base != (c1_symbol *)0x0 && ((pcVar3->base->key_ref & 0x10000) != 0)))) {
            return 0;
          }
          pcVar2 = pcVar2->derived;
          pcVar3 = pcVar3->derived;
        } while (pcVar2 != pcVar3);
      }
    }
    for (; pcVar1 != (c1_catchable_type *)0x0; pcVar1 = pcVar1->same_type) {
      pcVar1->flags = pcVar1->flags | 0x200;
    }
  }
  return 0x200;
}

