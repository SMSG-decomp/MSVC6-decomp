int __cdecl vtable_slot_this_delta(c1_vtable_slot *slot,c1_symbol *cls,c1_vtable_record *rec)

{
  int iVar1;
  int iVar2;
  
  iVar1 = vtable_slot_subobject_offset(&slot->path_offset,cls);
  iVar2 = class_vtable_vptr_offset(rec);
  return iVar2 - iVar1;
}

