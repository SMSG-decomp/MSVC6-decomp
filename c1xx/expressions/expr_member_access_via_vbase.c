c1_node * __cdecl
expr_member_access_via_vbase(uint op,c1_node *object,int *path,c1_type *type,int member_offset)

{
  char cVar1;
  c1_node *pcVar2;
  c1_symbol *cls;
  int local_10;
  int local_c;
  void *visitor_vtable;
  int visitor_mask;
  int *cell;
  
  cls = (c1_symbol *)0x0;
  for (cell = (int *)*path; cell != (int *)0x0; cell = (int *)*cell) {
    cls = (c1_symbol *)cell[2];
  }
  class_virtual_base_info
            (g_scope_vector->entries[*(short *)(path[2] + 0x18)],cls,&local_c,&local_10,
             (c1_type **)&path);
  visitor_mask = 0xff;
  visitor_vtable = &g_side_effect_visitor_vtable;
  cVar1 = tree_has_side_effects((c1_tree_visitor *)&visitor_vtable,object);
  if (cVar1 != '\0') {
    pcVar2 = expr_member_access_via_vbase_spilled
                       (op,object,type,local_c,local_10,member_offset,(c1_type *)path);
    return pcVar2;
  }
  pcVar2 = expr_member_offset_access(op,object,type,local_c,local_10,member_offset,(c1_type *)path);
  return pcVar2;
}

