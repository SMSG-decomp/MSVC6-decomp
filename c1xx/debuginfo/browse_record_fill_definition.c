void __cdecl browse_record_fill_definition(c1xx_browse_record *rec,c1_symbol *sym)

{
  c1_u16 *attrs;
  char cVar1;
  char *pcVar2;
  c1_type *pcVar3;
  bool bVar4;
  byte bVar5;
  ushort uVar6;
  uint position;
  uint position_2;
  void *pvVar7;
  byte bVar8;
  uint position_3;
  uint position_4;
  
  if ((((g_browse_excluded_kinds[sym->kind & 0x1f] != 0) || ((sym->flags3 & 1) != 0)) ||
      (((sym->kind & 0x1f) == 4 &&
       (((((sym->detail).cls)->flags3e & 2) != 0 || ((((sym->detail).cls)->flags3f & 0x80) != 0)))))
      ) || ((g_compile_flags_c8 & 0x10000000) != 0)) {
    rec->kind = '\x14';
    return;
  }
  browse_record_assign_entity_id(rec,sym);
  if (((sym->flags1 & 0x10) == 0x10) || ((sym->flags1 & 0x20) == 0x20)) {
    bVar5 = 1;
  }
  else {
    bVar5 = 0;
  }
  rec->flags = rec->flags & 0xfc ^ bVar5;
  bVar5 = sym->kind & 0x1f;
  if ((((bVar5 == 7) || (bVar5 == 8)) || (bVar5 == 6)) &&
     (((sym->flags1 & 2) == 0 && (((sym->name->flags & 0x40000000) == 0 || (sym->scope_index != 0)))
      ))) {
    position = (uint)decorate_name(sym,(c1_symbol *)0x0);
    if ((uint)(1 < g_warnings_as_errors) + g_error_count != 0) {
      il_emitter_begin_unit();
      rec->kind = '\x14';
      return;
    }
    rec->flags = rec->flags | 2;
    position_2 = (uint)mem_xstrdup((char *)position);
    rec->name = (char *)position_2;
    rec->name_record = (fe_name *)0x0;
  }
  bVar5 = sym->kind & 0x1f;
  if (((bVar5 == 0) || (0xe < bVar5)) || ((bVar5 == 5 || ((sym->flags4 & 0x40) == 0)))) {
    position_3 = (uint)sym->name->text;
    if ((*(char *)position_3 == '?') && (*(char *)(position_3 + 1) != '$')) {
      rec->name = (char *)position_3;
      rec->name_record = (fe_name *)0x0;
      sym = symtab_14ac_lookup_by_name(sym);
    }
  }
  else {
    if (bVar5 == 3) {
      pvVar7 = sym_static_member_stand_in(sym);
    }
    else if (bVar5 == 10) {
      pvVar7 = sym_inline_instance_of(sym);
    }
    else {
      pvVar7 = (void *)0x0;
    }
    pcVar2 = *(char **)(*(int *)((int)pvVar7 + 8) + 4);
    rec->name_record = (fe_name *)0x0;
    rec->name = pcVar2;
  }
  bVar5 = sym->kind & 0x1f;
  if (((bVar5 == 0) || (0xe < bVar5)) || (bVar5 == 5)) {
    bVar8 = 0;
  }
  else {
    bVar8 = sym->storage & 7;
    if (bVar8 == 7) {
      rec->attributes = 0;
      rec->type = '\a';
      goto LAB_104072bb;
    }
  }
  if (((bVar5 == 2) || (bVar5 == 3)) || (((bVar5 == 7 || (bVar5 == 8)) && ((sym->flags1 & 4) != 0)))
     ) {
    bVar4 = true;
  }
  else {
    bVar4 = false;
  }
  if (bVar8 == 0) {
LAB_104073c9:
    if ((1 < g_block_depth) &&
       (((bVar5 != 4 || (position_4 = (uint)sym->name->text, *(char *)position_4 != '?')) ||
        (*(char *)(position_4 + 1) != '$')))) {
      *(byte *)&rec->attributes = (byte)rec->attributes | 1;
    }
  }
  else {
    if (bVar8 < 3) {
      if (!bVar4) {
        rec->attributes = 0x40;
      }
    }
    else {
      if (bVar8 != 3) goto LAB_104073c9;
      rec->attributes = 2;
    }
    bVar5 = sym->kind & 0x1f;
    if ((bVar5 == 7) || (bVar5 == 8)) {
      if ((~sym->flags2 & 4) != 0) goto LAB_10407256;
    }
    else if ((bVar8 == 1) && ((sym->flags4 & 4) == 0)) {
LAB_10407256:
      *(byte *)&rec->attributes = (byte)rec->attributes | 0x20;
    }
  }
  if (bVar4) {
    attrs = &rec->attributes;
    *attrs = *attrs | *(ushort *)(g_browse_excluded_kinds + (sym->flags2 & 3) * 4 + 0x1c);
    if ((sym->flags21 & 2) != 0) {
      *attrs = *attrs | 0x200;
    }
    browse_record_set_access(attrs,sym->flags2 & 3);
  }
  bVar5 = sym->kind & 0x1f;
  if (bVar5 == 4) {
    pcVar3 = sym->type;
    cVar1 = (char)pcVar3->code;
    while (cVar1 < '\0') {
      pcVar3 = pcVar3->base;
      cVar1 = (char)pcVar3->code;
    }
    uVar6 = pcVar3->code & 0x20f;
    if (uVar6 == 0x201) {
      rec->type = '\x0f';
    }
    else if (uVar6 == 0x202) {
      rec->type = '\b';
    }
    else if (uVar6 == 0x203) {
      rec->type = '\v';
    }
    else if ((pcVar3->code & 0x100) != 0) {
      rec->type = '\t';
    }
  }
  else if (((bVar5 == 7) || (bVar5 == 8)) && ((sym->flags1 & 4) != 0)) {
    rec->type = '\x10';
  }
  else {
    rec->type = g_browse_symbol_types[sym->kind & 0x1f];
  }
LAB_104072bb:
  if (rec->kind != '\x19') {
    return;
  }
  *(byte *)&rec->attributes = (byte)rec->attributes | 0x20;
  rec->kind = '\x03';
  return;
}

