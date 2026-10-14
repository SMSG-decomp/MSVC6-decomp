c2_alias_class_cache * __fastcall
alias_cache_node_new(uint32_t cls,c2_bitset *pointees,void *key,c2_alias_class_cache *next)

{
  c2_alias_class_cache *pcVar1;
  
  pcVar1 = arena_alloc(4,0x14);
  pcVar1->cls = cls;
  pcVar1->pointees = pointees;
  pcVar1->next = next;
  pcVar1->key = key;
  return pcVar1;
}

