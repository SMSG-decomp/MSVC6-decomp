c1_node * __cdecl expr_address_of_member(c1_symbol *sym)

{
  byte bVar1;
  int iVar2;
  c1_type *mptype;
  c1_node *pcVar3;
  int *path;
  c1_symbol *sym_00;
  c1_symbol *pcVar4;
  c1_symbol *pcVar5;
  c1_node *pcVar6;
  c1_node *right2;
  c1_type_extra cls;
  void **vbase;
  int *piVar7;
  void *vbase_00;
  int local_18;
  void *local_14;
  c1_type local_10;
  
  local_18 = 0;
  local_14 = (void *)0x0;
  piVar7 = *(int **)sym->type;
  sym_00 = (c1_symbol *)piVar7[2];
  iVar2 = *piVar7;
  if ((sym_00->kind & 0x1f) == 0x11) {
    return (c1_node *)0x0;
  }
  access_check_member(sym);
  cls = (c1_type_extra)((c1_type_extra *)(iVar2 + 8))->cls;
  if (((cls.cls)->kind & 0x1f) != 4) {
    cls = (c1_type_extra)
          ((c1_type_extra *)(g_scope_vector->entries + (short)(cls.cls)->key_ref))->count;
  }
  iVar2 = sym_has_reference_type(sym_00);
  if ((char)iVar2 != '\0') {
    pcVar5 = sym_00;
    pcVar4 = member_path_class(piVar7);
    diag_error(0x27a,pcVar4,pcVar5);
  }
  if ((sym_00->storage & 7) == 3) {
    pcVar3 = expr_reference_named_entity(sym_00,1);
    return pcVar3;
  }
  if ((sym_00->flags21 & 2) != 0) {
    piVar7 = &local_18;
    vbase = &local_14;
    path = (int *)lookup_in_enclosing_scopes('\x01',cls.count,(int)sym_00,(int *)0x0);
    member_path_offset(path,(int *)vbase,piVar7);
  }
  bVar1 = sym_00->kind & 0x1f;
  local_10.extra = cls;
  if ((bVar1 == 7) || (bVar1 == 8)) {
    special_member_need_definition(sym_00);
    local_10.base = sym_00->type;
    local_10.debug_index = 0;
    local_10.code = 0x8e;
    local_10.flags = (byte)(local_10.base)->flags & 0x1f;
    mptype = type_intern(&local_10);
  }
  else {
    local_10.base = sym_00->type;
    local_10.debug_index = 0;
    local_10.code = 0x8a;
    local_10.flags = 0;
    mptype = type_intern(&local_10);
  }
  if ((sym_00->kind & 0x1f) == 3) {
    iVar2 = class_complete_type_of(mptype);
    switch(iVar2) {
    case 1:
    case 2:
      pcVar3 = tree_new_int_constant_raw((sym_00->detail).value);
      pcVar3->type = mptype;
      return pcVar3;
    case 3:
      pcVar5 = (c1_symbol *)type_member_pointer_class(mptype);
      iVar2 = class_vbptr_offset(pcVar5);
      pcVar3 = tree_new_int_constant((int)(sym_00->detail).cls - iVar2);
      pcVar6 = tree_new_int_constant(0);
      pcVar3 = pm_spill_vi_data_pointer(mptype,pcVar3,pcVar6);
      return pcVar3;
    case 4:
      pcVar3 = tree_new_int_constant(0);
      iVar2 = 0;
      pcVar6 = tree_new_int_constant((sym_00->detail).value);
      pcVar3 = pm_spill_general_data_pointer(mptype,pcVar6,iVar2,pcVar3);
      return pcVar3;
    }
  }
  else {
    if ((sym_00->flags21 & 2) != 0) {
      sym_00 = vcall_thunk_lookup_or_new(sym_00);
    }
    pcVar3 = tree_new_symbol_ref(sym_00,'\x01');
    iVar2 = class_complete_type_of(mptype);
    switch(iVar2) {
    case 1:
    case 2:
      pcVar6 = tree_new_int_constant(local_18);
      pcVar3 = expr_member_pointer_cast(mptype,pcVar3,pcVar6);
      return pcVar3;
    case 3:
      vbase_00 = local_14;
      pcVar6 = tree_new_int_constant(local_18);
      pcVar3 = pm_build_vi_function_pointer_constant(mptype,pcVar3,pcVar6,vbase_00);
      return pcVar3;
    case 4:
      pcVar6 = tree_new_int_constant(0);
      iVar2 = 0;
      right2 = tree_new_int_constant(local_18);
      pcVar3 = pm_spill_general_function_pointer(mptype,pcVar3,right2,iVar2,pcVar6);
      return pcVar3;
    }
  }
  return (c1_node *)sym;
}

