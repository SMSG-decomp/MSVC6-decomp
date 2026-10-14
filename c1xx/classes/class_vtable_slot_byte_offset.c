int __cdecl class_vtable_slot_byte_offset(c1_vtable_slot *slot,c1_vtable_record *rec)

{
  c1_vtable_slot *pcVar1;
  int iVar2;
  
  pcVar1 = rec->slots;
  iVar2 = type_int_size();
  return iVar2 * ((int)slot - (int)pcVar1 >> 4);
}

