c1_node * __cdecl class_build_base_adjustor(c1_symbol *cls,c1_vbase_record *vbase)

{
  c1_symbol *cls_00;
  c1_vbase_record *pcVar1;
  c1_node *pcVar2;
  int iVar3;
  c1_node *right;
  int local_4;
  
  pcVar1 = vbase;
  cls_00 = cls;
  class_virtual_base_info(vbase->base,cls,(int *)&cls,&local_4,(c1_type **)&vbase);
  pcVar2 = expr_this_pointer((c1_symbol *)0x0);
  pcVar2 = expr_virtual_base_offset(pcVar2,(int)cls,local_4,(c1_type *)vbase);
  iVar3 = class_vbase_offset((int)pcVar1->base,(int)cls_00);
  right = tree_new_int_constant(iVar3 - (int)cls);
  pcVar2 = tree_new_binary('F',pcVar2,right);
  return pcVar2;
}

