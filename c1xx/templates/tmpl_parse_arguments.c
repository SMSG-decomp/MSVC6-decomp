c1_symbol * __cdecl tmpl_parse_arguments(c1_symbol *tmpl,c1_arg_list *args,char dependent)

{
  c1_u8 *pcVar1;
  fe_name **ppfVar2;
  bool bVar3;
  byte bVar4;
  char cVar5;
  c1_sym_list *pcVar6;
  void *pvVar7;
  c1_lookup_entry *pcVar8;
  c1_symbol *key;
  c1_scope_stack *pcVar9;
  c1_keyed_list *pcVar10;
  c1_symbol *cls;
  
  pcVar6 = tmpl_lookup_parameter_list(tmpl);
  if (args == (c1_arg_list *)0x0) {
    if (dependent == '\0') {
      args = parse_reparse_template_arguments((void *)0x0);
    }
    else {
      args = tmpl_arguments_from_parameters(pcVar6);
    }
    if (args != (c1_arg_list *)0x0) goto LAB_10424877;
  }
  else {
LAB_10424877:
    if ((args->flags & 1) != 0) {
      return (c1_symbol *)0x0;
    }
  }
  bVar3 = false;
  if (pcVar6 == (c1_sym_list *)0x0) {
    return (c1_symbol *)0x0;
  }
  if (dependent == '\0') {
    bVar4 = tmpl_check_argument_list(tmpl,pcVar6,&args);
    bVar3 = false;
    if ((bVar4 == 0) && (bVar3 = true, args == (c1_arg_list *)0x0)) {
      return (c1_symbol *)0x0;
    }
    cVar5 = tmpl_arguments_are_concrete((int *)args);
    if (cVar5 == '\0') {
      dependent = '\x01';
    }
  }
  pvVar7 = name_intern_decorated_quiet(tmpl,(int *)args);
  cls = (c1_symbol *)0x0;
  pcVar9 = g_current_scope;
  if (tmpl->scope_index == 0) {
LAB_104248e5:
    pcVar8 = (*pcVar9->global_scope->vtbl->lookup_tag)(pcVar9->global_scope,pvVar7);
    if (pcVar8 == (c1_lookup_entry *)0x0) {
      key = (c1_symbol *)0x0;
    }
    else {
      key = pcVar8->sym;
    }
LAB_104248f5:
    if (key != (c1_symbol *)0x0) goto LAB_104248f9;
  }
  else {
    cls = g_scope_vector->entries[(short)tmpl->scope_index];
    if ((cls->kind & 0x1f) == 0x19) {
      pcVar9 = (c1_scope_stack *)cls->type;
      goto LAB_104248e5;
    }
    pcVar10 = class_lookup_member_name(cls,pvVar7,0x20);
    if (pcVar10 != (c1_keyed_list *)0x0) {
      key = pcVar10->head->sym;
      goto LAB_104248f5;
    }
  }
  key = class_new_tag_record(pvVar7,tmpl->type->code);
  if (dependent != '\0') {
    pcVar1 = &((key->detail).cls)->flags3f;
    *pcVar1 = *pcVar1 | 0x80;
  }
  if ((((tmpl->detail).cls)->layout_flags3c & 0x80) != 0) {
    pcVar1 = &((key->detail).cls)->layout_flags3c;
    *pcVar1 = *pcVar1 | 0x80;
  }
  pcVar9 = g_current_scope;
  if (cls != (c1_symbol *)0x0) {
    if ((cls->kind & 0x1f) != 0x19) {
      key->scope_index = ((cls->detail).cls)->scope_index;
      ppfVar2 = &key->name;
      key->flags2 = (tmpl->flags2 ^ key->flags2) & 3 ^ key->flags2;
      key->name->flags = key->name->flags | 0x40000;
      pcVar6 = (cls->x28).members;
      key->next = (c1_symbol *)0x0;
      if (pcVar6->tail == (c1_sym_link *)0x0) {
        pcVar6->head = (c1_sym_link *)ppfVar2;
      }
      else {
        pcVar6->tail->next = (c1_sym_link *)ppfVar2;
      }
      pcVar6->tail = (c1_sym_link *)ppfVar2;
      if ((((cls->detail).cls)->flags3e & 4) == 0) {
        class_sort_members(cls);
      }
      goto LAB_104248f9;
    }
    key->scope_index = *(c1_u16 *)&cls->type->base;
    pcVar9 = (c1_scope_stack *)cls->type;
  }
  (*pcVar9->global_scope->vtbl->insert)(key);
LAB_104248f9:
  pvVar7 = symtab_15f4_lookup(key);
  if (pvVar7 == (void *)0x0) {
    symtab_1604_insert(key,tmpl);
    symtab_15f4_insert(key,args);
  }
  if (bVar3) {
    key->flags3 = key->flags3 | 4;
  }
  return key;
}

