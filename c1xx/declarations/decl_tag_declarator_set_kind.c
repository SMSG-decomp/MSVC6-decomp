void __thiscall
decl_tag_declarator_set_kind(c1_declarator *d,c1_u16 tag_code,void **insert_fn,char is_definition)

{
  byte bVar1;
  fe_name *pfVar2;
  c1xx_hash_scope *pcVar3;
  c1_symbol *pcVar4;
  
  d->unk50 = tag_code;
  if (((g_compile_flags_c4 & 0x20000) == 0) && (g_pch_precomp_types == 0)) {
    d->flags54 = d->flags54 | 0x10;
  }
  if (g_class_depth < 0) {
    pcVar4 = g_current_function;
    if ((g_current_scope->current->kind != '\0') ||
       (g_current_scope->current == g_current_scope->global_scope)) goto joined_r0x1046aba6;
    pcVar4 = scope_current_namespace(g_current_scope);
  }
  else {
    if (*insert_fn != scope_insert_into_enclosing_namespace) {
      d->owner = g_class_def_stack[g_class_depth].cls;
      goto LAB_1043436d;
    }
    pcVar3 = scope_enclosing_namespace(g_current_scope,'\x01');
    if (pcVar3 == (c1xx_hash_scope *)0x0) goto LAB_1043436d;
    pcVar4 = pcVar3->ns;
joined_r0x1046aba6:
    if (pcVar4 == (c1_symbol *)0x0) goto LAB_1043436d;
  }
  d->owner = pcVar4;
LAB_1043436d:
  d->flags55 = d->flags55 | 4;
  bVar1 = *(byte *)(g_linkage_stack + g_linkage_depth);
  d->unk40 = '\0';
  d->unk41 = '\0';
  d->unk42 = '\0';
  d->unk43 = '\0';
  d->flags54 = (bVar1 ^ d->flags54) & 3 ^ d->flags54;
  if ((g_compile_flags_c8 & 0x2000000) != 0) {
    d->flags56 = d->flags56 | 0x40;
  }
  pfVar2 = d->name;
  if ((((pfVar2 != (fe_name *)0x0) && (pfVar2->flags = pfVar2->flags | 0x20000, 0 < g_paren_depth))
      && (is_definition != '\0')) &&
     (((g_compile_flags_c8 & 0x40000000) == 0 || (*insert_fn != scope_insert_through_object_pointer)
      ))) {
    pcVar4 = sym_new_from_declarator(d,5);
    diag_error(0xcc,pcVar4);
  }
  d->flags57 = (g_block_depth != '\0') << 5 | d->flags57 & 0xdf;
  return;
}

