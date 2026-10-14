char __cdecl expr_build_constructor_reference(c1_node *callee)

{
  int key;
  c1_symbol *sym;
  byte *pbVar1;
  c1_type *pcVar2;
  c1_symbol *cls;
  c1_symbol *pcVar3;
  
  pcVar3 = callee->left;
  if ((pcVar3->kind & 0x1f) == 0x12) {
    cls = *(c1_symbol **)(*(int *)pcVar3->type + 8);
  }
  else {
    cls = pcVar3;
    pcVar3 = (c1_symbol *)0x0;
  }
  if (((cls->storage & 7) == 7) && (pcVar2 = cls->type, (pcVar2->code & 0x200) != 0)) {
    if ((pcVar2->code & 0x200) == 0) {
      cls = (c1_symbol *)0x0;
    }
    else {
      cls = (pcVar2->extra).cls;
    }
  }
  if ((cls->flags2 & 4) == 0) {
    tmpl_instantiate_if_needed(cls);
  }
  if ((cls->flags1 & 0x10) != 0x10) {
    if ((((cls->detail).cls)->flags3e & 2) != 0) {
      diag_error(0x3bb,cls);
      return '\0';
    }
    diag_error(0x202,cls);
    return '\0';
  }
  if ((((cls->detail).cls)->layout_flags3b & 0x80) != 0) {
    class_check_abstract_instantiation(cls);
    return '\0';
  }
  callee->op = '\x06';
  sym = (c1_symbol *)class_first_constructor((int)cls);
  if (pcVar3 == (c1_symbol *)0x0) {
    pbVar1 = ovl_make_set_of_two(cls,sym);
    callee->left = pbVar1;
    return '\x01';
  }
  key._0_2_ = pcVar3->type->code;
  key._2_2_ = pcVar3->type->flags;
  pcVar2 = (c1_type *)tree_new_list_cell((c1_keyed_list *)0x0,key,sym);
  pcVar3->type = pcVar2;
  return '\x01';
}

