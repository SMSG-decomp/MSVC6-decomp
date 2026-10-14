c1_vbase_record * __cdecl
class_vbase_record_inherit(c1_vbase_record *src,c1_symbol *base_entry,int arena)

{
  c1_vbase_record *pcVar1;
  int iVar2;
  c1_vtable_vector **ppcVar3;
  
  pcVar1 = class_vbase_record_copy(src,arena);
  ppcVar3 = &pcVar1->vftables;
  iVar2 = 2;
  do {
    class_vtable_vector_link_copies
              (*ppcVar3,*(c1_vtable_vector **)(((int)src - (int)pcVar1) + (int)ppcVar3),base_entry);
    ppcVar3 = ppcVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return pcVar1;
}

