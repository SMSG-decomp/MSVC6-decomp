c1_node * __cdecl
pm_build_vi_function_pointer_constant(c1_type *type,c1_node *function,c1_node *offset,void *vbase)

{
  c1_type *type_00;
  c1_symbol *cls;
  c1_node *pcVar1;
  c1_symbol *pcVar2;
  int iVar3;
  c1_node *right3;
  int *vbptr_offset;
  c1_type **vbase_index;
  c1_type **base_type;
  
  type_00 = type;
  if (vbase != (void *)0x0) {
    vbase_index = &type;
    base_type = (c1_type **)0x0;
    pcVar2 = g_scope_vector->entries[*(short *)((int)vbase + 0x18)];
    vbptr_offset = (int *)0x0;
    cls = (c1_symbol *)type_member_pointer_class(type);
    class_virtual_base_info(pcVar2,cls,vbptr_offset,(int *)vbase_index,base_type);
    pcVar1 = tree_new_int_constant((int)type);
    pcVar1 = pm_spill_vi_function_pointer(type_00,function,offset,pcVar1);
    return pcVar1;
  }
  pcVar2 = (c1_symbol *)type_member_pointer_class(type);
  iVar3 = class_vbptr_offset(pcVar2);
  pcVar1 = tree_new_int_constant((int)offset->left - iVar3);
  right3 = tree_new_int_constant(0);
  pcVar1 = pm_spill_vi_function_pointer(type_00,function,pcVar1,right3);
  return pcVar1;
}

