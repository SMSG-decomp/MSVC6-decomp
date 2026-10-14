uint __cdecl hash_table_bucket(c1_symtab *tab,void *key)

{
  uint uVar1;
  
  uVar1 = (*(code *)(&PTR_symtab_hash_pointer_0_104bc46c)[tab->hash])(key);
  return uVar1 % (uint)tab->nbuckets;
}

