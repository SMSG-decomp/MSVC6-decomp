c1_keyed_cell * __cdecl lookup_qualifier_chain_splice(c1_keyed_cell *chain,c1_keyed_cell *item)

{
  c1_keyed_cell *pcVar1;
  c1_keyed_cell *pcVar2;
  c1_keyed_cell *pcVar3;
  byte bVar4;
  
  pcVar3 = chain->key;
  pcVar2 = chain;
  while (((pcVar1 = pcVar3, pcVar1 != (c1_keyed_cell *)0x0 &&
          (bVar4 = pcVar1->sym->kind & 0x1f, bVar4 != 4)) && (bVar4 != 0x19))) {
    pcVar3 = pcVar1->key;
    pcVar2 = pcVar1;
  }
  pcVar2->key = item;
  chain->next = item;
  item->next = item;
  return chain;
}

