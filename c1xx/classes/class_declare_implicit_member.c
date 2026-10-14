c1_symbol * __cdecl class_declare_implicit_member(c1_symbol *cls,int kind,char need,char flag)

{
  c1_symbol *fn;
  c1_declarator *d;
  fe_name *pfVar1;
  c1_decl_record *pcVar2;
  c1_u8 *pcVar3;
  int iVar4;
  byte bVar5;
  c1_u32 *spec_word;
  c1_u32 *spec_word_2;
  c1_symbol *redeclared;
  ushort local_3c [2];
  uint ptr_extra_word1;
  ushort local_34 [2];
  uint ptr_mods_position;
  ushort local_2c [2];
  uint ref_mods_position;
  byte local_24;
  c1_type *local_c;
  c1_symbol *spec_using;
  
  d = arena_alloc(g_arenas + 5,0x58);
  if (d == (c1_declarator *)0x0) {
    d = (c1_declarator *)0x0;
  }
  else {
    pfVar1 = class_special_member_name(kind);
    d->name = pfVar1;
    d->qualifier = (c1_overload_set *)0x0;
    d->op_token = '\x01';
    d->kind = 2;
    pcVar2 = arena_alloc(g_arenas + 5,0x4c);
    if (pcVar2 == (c1_decl_record *)0x0) {
      d->decl = (c1_decl_record *)0x0;
      d->position = g_token_position;
    }
    else {
      pcVar2 = decl_record_init_default(pcVar2,d->name,d->qualifier);
      d->decl = pcVar2;
      d->position = g_token_position;
    }
  }
  d->flags54 = d->flags54 | 0x20;
  d->flags57 = (flag & 1U) << 4 | d->flags57 & 0xef;
  d->flags56 = (need & 1U | 4) << 2 | d->flags56 & 0xfb;
  d->special_kind = (c1_u8)kind;
  pcVar3 = class_special_member_parameters((int)cls,kind,(c1_symbol *)0x0);
  switch(kind) {
  case 1:
    d->name = cls->name;
    d->flags55 = d->flags55 | 0x40;
    d->flags57 = d->flags57 | 2;
    break;
  case 2:
    d->name = cls->name;
    d->flags55 = d->flags55 | 0x40;
    d->flags57 = d->flags57 | 4;
    break;
  case 3:
    d->op_token = '4';
    d->flags57 = d->flags57 | 8;
    break;
  case 4:
    d->name = cls->name;
    d->flags55 = d->flags55 | 0x80;
  }
  pcVar2 = d->decl;
  decl_append_function_layer((int *)pcVar2,pcVar3);
  local_24 = local_24 & 0xf8;
  spec_word_2 = (c1_u32 *)&stack0xffffffdc;
  for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
    *spec_word_2 = 0;
    spec_word_2 = spec_word_2 + 1;
  }
  bVar5 = local_24 & 7 ^ local_24;
  local_24 = bVar5 | 0x20;
  spec_using = (c1_symbol *)0x0;
  if (kind == 3) {
    local_2c[0] = 0;
    ref_mods_position = 0;
    decl_add_reference_modifier(pcVar2,local_2c);
    local_c = g_class_def_stack[g_class_depth].type;
  }
  else if ((kind < 6) || (7 < kind)) {
    local_c = g_type_void;
    local_24 = bVar5 | 0x30;
  }
  else {
    local_3c[0] = 0;
    ptr_extra_word1 = 0;
    local_34[0] = 0;
    ptr_mods_position = 0;
    decl_add_pointer_modifier(pcVar2,local_34,local_3c);
    local_c = g_type_void;
  }
  g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 1;
  decl_check_conversion_return_type(pcVar2,(c1xx_decl_specifiers *)&stack0xffffffdc);
  decl_finish_declarator(pcVar2);
  spec_word = (c1_u32 *)&stack0xffffffdc;
  pcVar3 = d->spec;
  for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(c1_u32 *)pcVar3 = *spec_word;
    spec_word = spec_word + 1;
    pcVar3 = pcVar3 + 4;
  }
  redeclared = (c1_symbol *)0x0;
  class_begin_member_list(d,(c1xx_decl_specifiers *)&stack0xffffffdc,&redeclared);
  fn = d->sym;
  fn->flags21 = fn->flags21 | 1;
  fn->flags2 = fn->flags2 | 7;
  if (((fn->flags22 & 4) != 0) && (need != '\0')) {
    special_member_need_definition(fn);
  }
  return fn;
}

