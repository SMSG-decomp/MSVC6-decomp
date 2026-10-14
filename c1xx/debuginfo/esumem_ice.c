void __fastcall esumem_ice(c1_declarator *d)

{
  c1xx_scope *pcVar1;
  uint uVar2;
  c1_u8 cVar3;
  c1_u8 cVar4;
  c1_u8 cVar5;
  byte bVar6;
  char cVar7;
  c1_declarator *d_00;
  fe_name *pfVar8;
  c1_decl_record *pcVar9;
  c1_type *pcVar10;
  c1xx_hash_scope *pcVar11;
  c1_symbol *pcVar12;
  c1_symbol_attrs *pcVar13;
  c1_symbol_attrs *pcVar14;
  c1_u32 *spec_dst;
  c1_symbol *segment;
  void *declspec;
  int iVar15;
  c1_symbol_attrs local_3c;
  c1_symbol_attrs attrs_copy;
  
  if ((g_opt_Zg == '\0') && ((((d->owner->detail).cls)->flags3f & 0x80) == 0)) {
    d_00 = arena_alloc(g_arenas + 5,0x58);
    if (d_00 == (c1_declarator *)0x0) {
      d_00 = (c1_declarator *)0x0;
    }
    else {
      pfVar8 = name_new_S();
      d_00->name = pfVar8;
      d_00->qualifier = (c1_overload_set *)0x0;
      d_00->op_token = '\x01';
      d_00->kind = 0;
      pcVar9 = arena_alloc(g_arenas + 5,0x4c);
      if (pcVar9 == (c1_decl_record *)0x0) {
        d_00->decl = (c1_decl_record *)0x0;
        d_00->position = g_token_position;
      }
      else {
        pcVar9 = decl_record_init_default(pcVar9,d_00->name,d_00->qualifier);
        d_00->decl = pcVar9;
        d_00->position = g_token_position;
      }
    }
    d_00->flags54 = d_00->flags54 & 0xfc;
    pfVar8 = name_intern_symbol_decorated_in(g_class_def_stack[g_class_depth].cls,d->sym);
    d_00->name = pfVar8;
    d_00->flags54 = d_00->flags54 & 0xfe | 2;
    pcVar12 = d->sym;
    local_3c.storage = pcVar12->storage;
    local_3c.flags21 = pcVar12->flags21;
    local_3c.flags22 = pcVar12->flags22;
    local_3c.flags23 = pcVar12->flags23;
    if ((pcVar12->flags23 & 1) == 0) {
      segment = (c1_symbol *)0x0;
    }
    else {
      segment = sym_segment_record(pcVar12);
    }
    sym_attrs_set_segment_record(&local_3c,segment);
    if ((pcVar12->flags21 & 0x40) == 0) {
      declspec = (void *)0x0;
    }
    else {
      declspec = sym_extra_record(pcVar12);
    }
    sym_attrs_set_declspec_record(&local_3c,declspec);
    bVar6 = pcVar12->kind & 0x1f;
    if (((bVar6 == 7) || (bVar6 == 8)) && ((*(byte *)((int)&pcVar12->tail + 10) & 0x80) != 0)) {
      iVar15 = sym_list_1b58_value(pcVar12);
    }
    else {
      iVar15 = 0;
    }
    sym_attrs_set_function_position(&local_3c,iVar15);
    bVar6 = pcVar12->kind & 0x1f;
    if ((((bVar6 == 7) || (bVar6 == 8)) || (bVar6 == 6)) &&
       ((*(byte *)((int)&pcVar12->tail + 0xb) & 1) != 0)) {
      cVar7 = '\x01';
    }
    else {
      cVar7 = '\0';
    }
    local_3c.flags = cVar7 << 3 | local_3c.flags & 0xf7;
    if ((pcVar12->flags23 & 0x80) == 0) {
      local_3c.declarator_record = (void *)0x0;
    }
    else {
      local_3c.declarator_record = symtab_1b40_lookup(pcVar12);
    }
    if (((pcVar12->kind & 0x1f) == 4) && ((((pcVar12->detail).cls)->layout_flags3c & 0x80) != 0)) {
      local_3c.flags = local_3c.flags | 2;
    }
    else {
      local_3c.flags = local_3c.flags & 0xfd;
    }
    pcVar10 = d->type;
    local_3c.flags = local_3c.flags & 0xfb;
    pcVar13 = &local_3c;
    pcVar14 = &attrs_copy;
    for (iVar15 = 6; iVar15 != 0; iVar15 = iVar15 + -1) {
      cVar3 = pcVar13->flags21;
      cVar4 = pcVar13->flags22;
      cVar5 = pcVar13->flags23;
      pcVar14->storage = pcVar13->storage;
      pcVar14->flags21 = cVar3;
      pcVar14->flags22 = cVar4;
      pcVar14->flags23 = cVar5;
      pcVar13 = (c1_symbol_attrs *)&pcVar13->segment;
      pcVar14 = (c1_symbol_attrs *)&pcVar14->segment;
    }
    attrs_copy.storage = local_3c.storage & 0xf9 | 1;
    if (pcVar10 != d->sym->type) {
      diag_fatal(1,".\\esumem.c",0x6b4);
    }
    pcVar10 = type_skip_arrays(d->type);
    if (((byte)pcVar10->flags >> 5 & 1) != 0) {
      attrs_copy.flags21 = attrs_copy.flags21 | 0x10;
    }
    pcVar13 = &attrs_copy;
    spec_dst = (c1_u32 *)d_00->spec;
    for (iVar15 = 6; iVar15 != 0; iVar15 = iVar15 + -1) {
      *spec_dst = *(c1_u32 *)pcVar13;
      pcVar13 = (c1_symbol_attrs *)&pcVar13->segment;
      spec_dst = spec_dst + 1;
    }
    d_00->decl = d->decl;
    pcVar1 = g_current_scope->current;
    pcVar11 = scope_enclosing_namespace(g_current_scope,'\0');
    g_current_scope->current = (c1xx_scope *)pcVar11;
    d_00->flags55 = d_00->flags55 | 0x20;
    iVar15 = g_linkage_stack[g_linkage_depth];
    g_linkage_stack[g_linkage_depth] = 2;
    d_00->flags54 = d_00->flags54 | 0x20;
    pcVar12 = decl_declare_and_check(d_00,&attrs_copy.storage);
    pcVar12->flags3 = pcVar12->flags3 & 0xfe;
    g_linkage_stack[g_linkage_depth] = iVar15;
    pcVar12->flags4 = pcVar12->flags4 & 0xbf;
    d->sym->flags4 = d->sym->flags4 | 0x40;
    g_current_scope->current = pcVar1;
    uVar2 = d->sym->entity;
    d->sym->entity = (pcVar12->entity ^ uVar2) & 0xffffff ^ uVar2;
    esumem_register_copy(d->sym,pcVar12);
  }
  return;
}

