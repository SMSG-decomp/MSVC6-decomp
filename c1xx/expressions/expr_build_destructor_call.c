c1_node * __cdecl
expr_build_destructor_call(c1_symbol *cls,c1_node *obj,int kind,int flag,int do_delete)

{
  byte *pbVar1;
  char cVar2;
  void *name;
  c1_node *pcVar3;
  c1_node *pcVar4;
  uint uVar5;
  int iVar6;
  c1_node *local_c;
  void *visitor;
  int visitor_mask;
  
  uVar5 = g_compile_flags_c8 >> 0x17;
  local_c = (c1_node *)0x0;
  iVar6 = kind;
  if (kind == 1) {
    if ((((cls->detail).cls)->layout_flags3b & 0x20) == 0) {
      iVar6 = 3;
    }
  }
  else if ((kind == 3) && ((((cls->detail).cls)->layout_flags3b & 0x20) != 0)) {
    iVar6 = 2;
  }
  if ((uVar5 & 1) == 0) {
    if ((iVar6 == 4) || (iVar6 == 5)) {
      visitor_mask = 0xff;
      visitor = &g_side_effect_visitor_vtable;
      cVar2 = tree_has_side_effects((c1_tree_visitor *)&visitor,obj);
      if (cVar2 == '\0') {
        local_c = tree_copy_to_arena(obj,0);
      }
      else {
        expr_make_reusable(&local_c,&obj);
      }
    }
    obj = expr_prepare_member_access_object(g_current_scope,'S',obj,'\x01');
  }
  name = dtor_kind_name(iVar6);
  pcVar3 = expr_lookup_name_expression(name);
  if ((char)flag != '\0') {
    pbVar1 = (byte *)((int)pcVar3->left + 1);
    *pbVar1 = *pbVar1 | 8;
  }
  if ((uVar5 & 1) == 0) {
    pcVar4 = tree_new_deleting_dtor_flags_arg(iVar6,(char)do_delete);
    pcVar3 = expr_build_member_access('S',obj,pcVar3);
    pcVar3 = (c1_node *)expr_build_call(pcVar3,pcVar4);
    if ((((iVar6 == 4) || (iVar6 == 5)) && (pcVar3 != (c1_node *)0x0)) && (pcVar3 != obj)) {
      pcVar3 = expr_build_null_guarded(local_c,pcVar3);
    }
    return pcVar3;
  }
  flag = CONCAT31(flag._1_3_,g_current_scope->access_op);
  pcVar4 = tree_new_deleting_dtor_flags_arg(iVar6,'\0');
  pcVar3 = expr_build_member_access((c1_u8)flag,obj,pcVar3);
  pcVar3 = (c1_node *)expr_build_call(pcVar3,pcVar4);
  return pcVar3;
}

