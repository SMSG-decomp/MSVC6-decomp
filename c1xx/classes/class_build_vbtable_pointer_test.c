c1_node * __cdecl class_build_vbtable_pointer_test(c1_node *this_ptr)

{
  c1_vbase_vector *pcVar1;
  c1_vtable_vector *pcVar2;
  int iVar3;
  c1_type *pcVar4;
  c1_node *pcVar5;
  c1_node *right;
  short sVar6;
  c1_symbol *sym;
  c1_vtable_record *local_8;
  
  pcVar4 = this_ptr->type->base;
  if ((pcVar4->code & 0x200) == 0) {
    sym = (c1_symbol *)0x0;
  }
  else {
    sym = (pcVar4->extra).cls;
  }
  class_note_vtable_built(sym);
  sVar6 = 0;
  pcVar1 = ((sym->detail).cls)->vbases;
  pcVar2 = ((sym->detail).cls)->vbtables;
  while ((pcVar2 == (c1_vtable_vector *)0x0 || (pcVar2->count == 0))) {
    if ((pcVar1 == (c1_vbase_vector *)0x0) ||
       (iVar3 = (int)sVar6, (int)(uint)pcVar1->count <= iVar3)) goto LAB_104af06b;
    sVar6 = sVar6 + 1;
    pcVar2 = pcVar1->data[iVar3]->vbtables;
  }
  local_8 = *pcVar2->data;
LAB_104af06b:
  pcVar4 = type_with_storage_bits
                     (local_8->vptr_member->type,
                      *(byte *)(((uint)this_ptr->type & -(uint)((this_ptr->type->code & 0x80) != 0))
                               + 2) & 0x18);
  pcVar5 = tree_new_int_constant(local_8->off20);
  pcVar5 = tree_new_node('S',this_ptr,pcVar5,pcVar4);
  pcVar5 = tree_new_rvalue(pcVar5);
  right = tree_new_symbol_ref(local_8->table,'\0');
  pcVar5 = tree_new_node(';',pcVar5,right,g_type_int);
  return pcVar5;
}

