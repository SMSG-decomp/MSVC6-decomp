void __cdecl
class_init_virtual_base_members_fragment
          (c1_symbol *cls,c1_vbase_record *base_record,c1_vbase_vector *bases,short index,
          char init_adjustor)

{
  int iVar1;
  c1_node *value;
  c1_keyed_cell *member;
  
  if (init_adjustor == '\0') {
    value = tree_new_int_constant(0);
  }
  else {
    value = class_build_base_adjustor(cls,base_record);
  }
  member = class_vtordisp_access_path(cls,base_record);
  class_member_init_by_copy((int *)member,value);
  while ((bases != (c1_vbase_vector *)0x0 && (iVar1 = (int)index, iVar1 < (int)(uint)bases->count)))
  {
    index = index + 1;
    if (bases->data[iVar1]->needs_vtordisp != '\0') {
      class_init_virtual_base_members_fragment(cls,bases->data[iVar1],bases,index,init_adjustor);
      return;
    }
  }
  return;
}

