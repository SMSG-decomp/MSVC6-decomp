c1_symbol * __cdecl decl_merge_redeclaration(c1_symbol *sym,void *name,c1_symbol *p3)

{
  byte bVar1;
  char cVar2;
  c1_symbol *sym_00;
  c1_type *pcVar3;
  c1_symbol *pcVar4;
  c1_symbol *value;
  uint uVar5;
  short n;
  c1_symbol *pcVar6;
  void *pvVar7;
  int iVar8;
  c1_symbol_attrs local_18;
  
  pcVar4 = sym;
  local_18.storage = sym->storage;
  local_18.flags21 = sym->flags21;
  local_18.flags22 = sym->flags22;
  local_18.flags23 = sym->flags23;
  if ((sym->flags23 & 1) == 0) {
    pcVar6 = (c1_symbol *)0x0;
  }
  else {
    pcVar6 = sym_segment_record(sym);
  }
  sym_attrs_set_segment_record(&local_18,pcVar6);
  if ((pcVar4->flags21 & 0x40) == 0) {
    pvVar7 = (void *)0x0;
  }
  else {
    pvVar7 = sym_extra_record(pcVar4);
  }
  sym_attrs_set_declspec_record(&local_18,pvVar7);
  bVar1 = pcVar4->kind & 0x1f;
  if (((bVar1 == 7) || (bVar1 == 8)) && ((*(byte *)((int)&pcVar4->tail + 10) & 0x80) != 0)) {
    iVar8 = sym_list_1b58_value(pcVar4);
  }
  else {
    iVar8 = 0;
  }
  sym_attrs_set_function_position(&local_18,iVar8);
  bVar1 = pcVar4->kind & 0x1f;
  if ((((bVar1 == 7) || (bVar1 == 8)) || (bVar1 == 6)) &&
     ((*(byte *)((int)&pcVar4->tail + 0xb) & 1) != 0)) {
    cVar2 = '\x01';
  }
  else {
    cVar2 = '\0';
  }
  local_18.flags = cVar2 << 3 | local_18.flags & 0xf7;
  if ((pcVar4->flags23 & 0x80) == 0) {
    local_18.declarator_record = (void *)0x0;
  }
  else {
    local_18.declarator_record = symtab_1b40_lookup(pcVar4);
  }
  pcVar6 = p3;
  sym_00 = sym_static_member_stand_in(p3);
  bVar1 = sym_00->storage & 0xf8 ^ 2;
  sym_00->storage = bVar1;
  sym_00->storage = '\0';
  sym_00->flags21 = '\0';
  sym_00->flags22 = '\0';
  sym_00->flags23 = '\0';
  sym_00->storage = (sym_00->storage ^ bVar1 & 7) & 7 ^ sym_00->storage;
  if (((local_18.storage & 7) == 2) || ((local_18.storage & 7) == 3)) {
    if ((local_18._0_4_ & 0x1000000) != 0) {
      if (local_18.segment == (c1_symbol *)0x0) {
        pcVar4->flags23 = pcVar4->flags23 & 0xfe;
      }
      else {
        sym_set_segment(pcVar4,local_18.segment);
      }
    }
    if ((local_18._0_4_ & 0x400000) != 0) {
      pcVar4->flags22 = pcVar4->flags22 | 0x40;
      pcVar4->storage = pcVar4->storage | 0x40;
      pcVar4->flags21 = pcVar4->flags21 | 0x80;
    }
    pcVar3 = type_skip_arrays(pcVar4->type);
    pvVar7 = g_const_seg_name;
    if ((((byte)pcVar3->flags >> 5 & 1) == 0) &&
       (pvVar7 = g_bss_seg_name, (pcVar4->flags4 & 4) != 0)) {
      pvVar7 = g_data_seg_name;
    }
    sym_set_segment_from(pcVar4,pvVar7);
  }
  if (((byte)g_compile_flags_cc & 1) != 0) {
    sym_00->storage = sym_00->storage | 0x40;
  }
  if ((pcVar6->flags22 & 0xc) != 0) {
    if ((pcVar6->flags22 & 8) == 0) {
      sym_00->flags22 = sym_00->flags22 | 4;
    }
    else {
      diag_error(0x1eb,name,0x178);
    }
  }
  if ((pcVar6->flags22 & 2) != 0) {
    sym_00->flags22 = sym_00->flags22 | 2;
  }
  if ((pcVar6->flags23 & 1) != 0) {
    value = sym_segment_record(pcVar6);
    if (value == (c1_symbol *)0x0) {
      sym_00->flags23 = sym_00->flags23 & 0xfe;
    }
    else {
      sym_set_segment(sym_00,value);
    }
  }
  if ((pcVar4->flags4 & 4) != 0) goto LAB_1044949f;
  pcVar3 = type_skip_arrays_and_functions(pcVar6->type);
  if (((byte)pcVar3->flags >> 5 & 1) == 0) {
    iVar8 = sym_has_reference_type(pcVar6);
    if ((char)iVar8 != '\0') {
      n = 0x212;
      goto LAB_10478ec7;
    }
    if ((((pcVar6->flags5 & 4) != 0) && (bVar1 = (byte)pcVar6->type->base->code, (char)bVar1 < '\0')
        ) && ((bVar1 & 0x8f) == 0x80)) {
      pcVar4 = decl_report_C2530_tail(pcVar6,sym_00,name);
      return pcVar4;
    }
  }
  else {
    uVar5 = type_classify_class_form(pcVar4->type,(int *)&sym);
    pcVar4 = sym;
    if ((uVar5 & 3) != 0) {
      tmpl_instantiate_if_incomplete(sym);
      if (((((pcVar4->detail).cls)->implicit_state41 & 2) != 0) ||
         ((((pcVar4->detail).cls)->implicit_state43 & 2) != 0)) goto LAB_1044954e;
    }
    n = 0x2de;
LAB_10478ec7:
    diag_error(n,name);
  }
LAB_1044954e:
  if ((sym_00->flags22 & 2) != 0) {
    decl_define_variable(sym_00);
  }
LAB_1044949f:
  pcVar3 = pcVar6->type;
  while ((bVar1 = (byte)pcVar3->code, (bVar1 & 0x8f) == 0x83 || ((bVar1 & 0x83) == 0x81))) {
    pcVar3 = pcVar3->base;
  }
  if (((byte)pcVar3->flags >> 5 & 1) != 0) {
    sym_00->flags21 = sym_00->flags21 | 0x10;
  }
  sym_00->flags2 = sym_00->flags2 | 4;
  if ((((byte)g_compile_flags_cc & 1) == 0) &&
     (pcVar4 = sym_class_needing_init(sym_00), pcVar4 != (c1_symbol *)0x0)) {
    if ((pcVar4->flags2 & 4) == 0) {
      tmpl_instantiate_if_needed(pcVar4);
    }
    bVar1 = ((pcVar4->detail).cls)->implicit_state41 & 0x10;
    if (((bVar1 != 0) || ((((pcVar4->detail).cls)->implicit_state43 & 0x10) != 0)) && (bVar1 == 0))
    {
      sym_queue_destructible_object(sym_00);
    }
  }
  g_file_scope_decl_since_body = 1;
  return sym_00;
}

