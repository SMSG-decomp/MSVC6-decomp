int __cdecl vtable_slot_subobject_offset(int *path,c1_symbol *cls)

{
  int iVar1;
  
  if ((short)path[1] == 0) {
    return *path;
  }
  iVar1 = class_vbase_offset((int)g_scope_vector->entries[(short)path[1]],(int)cls);
  return *path + iVar1;
}

