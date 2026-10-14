c1_symtab * __cdecl symtab_new(int nbuckets,int arena,int hash,int compare,c1_u8 flag0,c1_u8 flag1)

{
  c1_arena *a;
  c1_symtab *pcVar1;
  c1_symtab *pcVar2;
  c1_symtab_entry **ppcVar3;
  c1_symtab_entry **ppcVar4;
  c1_symtab_entry **ppcVar5;
  
  pcVar1 = (c1_symtab *)g_arenas[arena].cur;
  pcVar2 = (c1_symtab *)g_arenas[arena].end;
  a = g_arenas + arena;
  a->cur = (c1_u8 *)(pcVar1 + 1);
  if (pcVar2 < pcVar1 + 1) {
    arena_grow(a);
  }
  pcVar1->compare = compare;
  pcVar1->hash = hash;
  pcVar1->arena = arena;
  pcVar1->nbuckets = (c1_u16)nbuckets;
  pcVar1->flags = pcVar1->flags & 0xfc ^ flag0 & 1 | (flag1 & 1) << 1;
  ppcVar3 = (c1_symtab_entry **)a->cur;
  ppcVar4 = (c1_symtab_entry **)g_arenas[arena].end;
  ppcVar5 = ppcVar3 + nbuckets;
  a->cur = (c1_u8 *)ppcVar5;
  if (ppcVar4 < ppcVar5) {
    arena_grow(a);
  }
  pcVar1->buckets = ppcVar3;
  pcVar1->count = 0;
  return pcVar1;
}

