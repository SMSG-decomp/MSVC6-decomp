char __cdecl class_base_access(int base,c1_symbol *cls)

{
  char cVar1;
  c1_vbase_record *pcVar2;
  
  if ((cls->flags2 & 4) != 0) {
    pcVar2 = class_find_base_record((c1_symbol *)base,((cls->detail).cls)->vbases);
    return pcVar2->access;
  }
  cVar1 = class_base_access_from_members(base,cls);
  return cVar1;
}

