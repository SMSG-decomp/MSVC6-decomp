int __cdecl class_vbptr_offset(c1_symbol *cls)

{
  c1_vtable_record *rec;
  int iVar1;
  int iVar2;
  
  if ((((cls->detail).cls)->layout_flags3b & 0x10) == 0) {
    return 0;
  }
  rec = *((cls->detail).cls)->vbtables->data;
  iVar1 = class_vtable_vptr_offset(rec);
  iVar2 = class_vbtable_entry_offset((int *)rec->slots,cls,rec);
  return iVar2 + iVar1;
}

