uint __cdecl hash_table_bucket(void *table,void *key)

{
  uint uVar1;
  
  uVar1 = (*(code *)(&PTR_hash_fn_pointer_10652258)[*(int *)((int)table + 8)])(key);
  return uVar1 % (uint)*(ushort *)((int)table + 0xc);
}

