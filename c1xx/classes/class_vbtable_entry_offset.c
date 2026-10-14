int __cdecl class_vbtable_entry_offset(int *path,c1_symbol *cls,c1_vtable_record *rec)

{
  int iVar1;
  
  if (path[1] == 0) {
    return -*path;
  }
  iVar1 = class_vbase_offset(path[1],(int)cls);
  return (iVar1 - rec->off24) - *path;
}

