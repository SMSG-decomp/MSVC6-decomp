fe_symtab * __cdecl symtab_new(int nbuckets,int arena,int hash,int compare,c1_u8 flag0,c1_u8 flag1)

{
  fe_arena *a;
  fe_symtab *pfVar1;
  fe_symtab *pfVar2;
  fe_symtab_entry **ppfVar3;
  fe_symtab_entry **ppfVar4;
  fe_symtab_entry **ppfVar5;
  
  pfVar1 = (fe_symtab *)g_arenas[arena].cur;
  pfVar2 = (fe_symtab *)g_arenas[arena].end;
  a = g_arenas + arena;
  a->cur = (uchar *)(pfVar1 + 1);
  if (pfVar2 < pfVar1 + 1) {
    arena_grow(a);
  }
  pfVar1->compare = compare;
  pfVar1->hash = hash;
  pfVar1->arena = arena;
  pfVar1->nbuckets = (ushort)nbuckets;
  pfVar1->flags = pfVar1->flags & 0xfc ^ flag0 & 1 | (flag1 & 1) << 1;
  ppfVar3 = (fe_symtab_entry **)a->cur;
  ppfVar4 = (fe_symtab_entry **)g_arenas[arena].end;
  ppfVar5 = ppfVar3 + nbuckets;
  a->cur = (uchar *)ppfVar5;
  if (ppfVar4 < ppfVar5) {
    arena_grow(a);
  }
  pfVar1->buckets = ppfVar3;
  pfVar1->count = 0;
  return pfVar1;
}

