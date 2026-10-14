int __cdecl class_vtable_record_reserve_bytes(c1_vtable_record *rec,int size)

{
  int iVar1;
  
  iVar1 = rec->table_size;
  rec->table_size = size + iVar1;
  return iVar1;
}

