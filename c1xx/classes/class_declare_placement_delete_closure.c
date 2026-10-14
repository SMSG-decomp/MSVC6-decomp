void __cdecl class_declare_placement_delete_closure(c1_symbol *op_delete)

{
  c1_declarator *d;
  c1_decl_record *pcVar1;
  c1_u8 *pcVar2;
  c1_symtab *pcVar3;
  c1_symbol *fn;
  int iVar4;
  byte bVar5;
  byte bVar6;
  fe_name *pfVar7;
  c1xx_decl_specifiers *pcVar8;
  c1_symbol *key;
  c1_symbol *value;
  c1_symbol *local_28;
  c1xx_decl_specifiers local_24;
  
  bVar6 = op_delete->flags1 >> 2 & 1;
  pfVar7 = g_name_placement_array_delete_closure;
  if (op_delete->name != g_name_array_delete) {
    pfVar7 = g_name_placement_delete_closure;
  }
  d = arena_alloc(g_arenas + 5,0x58);
  if (d == (c1_declarator *)0x0) {
    d = (c1_declarator *)0x0;
  }
  else {
    d->name = pfVar7;
    d->qualifier = (c1_overload_set *)0x0;
    d->kind = -(uint)(bVar6 != 0) & 2;
    d->op_token = '\x01';
    pcVar1 = arena_alloc(g_arenas + 5,0x4c);
    if (pcVar1 == (c1_decl_record *)0x0) {
      d->decl = (c1_decl_record *)0x0;
      d->position = g_token_position;
    }
    else {
      pcVar1 = decl_record_init_default(pcVar1,d->name,d->qualifier);
      d->decl = pcVar1;
      d->position = g_token_position;
    }
  }
  d->flags54 = d->flags54 | 0x20;
  d->op_token = 0x8d;
  d->flags56 = d->flags56 | 4;
  d->special_kind = '\x11';
  pcVar2 = class_special_member_parameters(0,0x11,op_delete);
  decl_append_function_layer((int *)d->decl,pcVar2);
  local_24.type_sym = (c1_symbol *)0x0;
  local_24.type = g_type_void;
  local_24.spec[0] = local_24.spec[0] ^ (-(bVar6 != 0) & 3U ^ local_24.spec[0]) & 7;
  bVar5 = local_24.spec[0] & 7;
  pcVar8 = &local_24;
  for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
    pcVar8->spec[0] = '\0';
    pcVar8->spec[1] = '\0';
    pcVar8->spec[2] = '\0';
    pcVar8->spec[3] = '\0';
    pcVar8 = (c1xx_decl_specifiers *)(pcVar8->spec + 4);
  }
  local_24.spec[0] = (bVar5 ^ local_24.spec[0]) & 7 ^ local_24.spec[0] | 0x10;
  g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 1;
  decl_check_conversion_return_type(d->decl,&local_24);
  decl_finish_declarator(d->decl);
  pcVar8 = &local_24;
  pcVar2 = d->spec;
  for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined4 *)pcVar2 = *(undefined4 *)pcVar8->spec;
    pcVar8 = (c1xx_decl_specifiers *)(pcVar8->spec + 4);
    pcVar2 = pcVar2 + 4;
  }
  local_28 = (c1_symbol *)0x0;
  if (bVar6 == 0) {
    fn = decl_declare_and_check(d,local_24.spec);
  }
  else {
    g_compile_flags_c4 = g_compile_flags_c4 | 0x4000000;
    class_begin_member_list(d,&local_24,&local_28);
    fn = d->sym;
    fn->flags2 = (op_delete->flags2 ^ fn->flags2) & 3 ^ fn->flags2;
    g_compile_flags_c4 = g_compile_flags_c4 & 0xfbffffff;
  }
  fn->flags21 = fn->flags21 | 1;
  fn->flags2 = fn->flags2 | 4;
  if (((op_delete->flags22 & 0xc) != 0) && (bVar6 = fn->flags22, (bVar6 & 0xc) == 0)) {
    bVar6 = (bVar6 ^ op_delete->flags22) & 4 ^ bVar6;
    fn->flags22 = bVar6;
    bVar6 = (op_delete->flags22 ^ bVar6) & 8 ^ bVar6;
    fn->flags22 = bVar6;
    if ((bVar6 & 4) != 0) {
      special_member_need_definition(fn);
    }
  }
  key = op_delete;
  value = fn;
  pcVar3 = symtab_ensure_1700();
  symtab_insert(pcVar3,key,value);
  pcVar3 = symtab_ensure_1704();
  symtab_insert(pcVar3,fn,op_delete);
  return;
}

