void __fastcall coff_emit_symbol_once(c2_fe_symbol *s)

{
  byte bVar1;
  uint16_t uVar2;
  uint16_t uVar3;
  uint uVar4;
  uint8_t *puVar5;
  c2_fe_symbol *pcVar6;
  uint32_t uVar7;
  int32_t iVar8;
  char cVar9;
  int iVar10;
  uint32_t uVar11;
  uint8_t uVar12;
  char *pcVar13;
  char local_8;
  
  bVar1 = s->flags31;
  if ((bVar1 & 1) != 0) {
    return;
  }
  if ((bVar1 & 4) == 0) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coff.c",0x304);
  }
  uVar12 = s->cls;
  s->flags31 = bVar1 | 1;
  if (uVar12 != '\x01') {
    if (uVar12 == '\x03') {
      iVar8 = s->offset;
      pcVar6 = fe_symbol_lookup_id(s->section_id);
      uVar3 = coff_section_for_symbol(pcVar6);
      uVar7 = s->id;
      iVar10 = coff_is_known_global_id(uVar7);
      uVar4 = -(uint)(iVar10 != 0) & uVar7;
      uVar2 = coff_symbol_type_bits(s);
      cVar9 = '\x06';
      puVar5 = fe_symbol_external_name(s);
      uVar7 = coff_add_symbol((char *)puVar5,uVar3,cVar9,iVar8,uVar2,uVar4);
      s->coff_symbol = uVar7;
      return;
    }
    if (uVar12 != '\x04') {
      return;
    }
    if ((s->storage & 0x800) != 0) {
      iVar10 = 0;
      pcVar13 = (char *)0x0;
      puVar5 = fe_symbol_external_name(s);
      coff_write_directive_record(s__export__107ac5fc,(char *)puVar5,pcVar13,iVar10);
    }
    uVar3 = g_coff_undef_section_id;
    if ((s->storage & 0x8000) != 0) {
      pcVar6 = fe_symbol_lookup_id((s->u4a).function.exp_offset);
      pcVar6->fn_flags = pcVar6->fn_flags | 0x20;
      pcVar6->flags31 = pcVar6->flags31 | 4;
      coff_emit_symbol_once(pcVar6);
      if (pcVar6->coff_symbol == 0) {
        uVar7 = pcVar6->id;
        uVar2 = coff_symbol_type_bits(pcVar6);
        uVar3 = g_coff_undef_section_id;
        iVar10 = 0;
        cVar9 = '\x02';
        puVar5 = fe_symbol_external_name(pcVar6);
        uVar7 = coff_add_symbol((char *)puVar5,uVar3,cVar9,iVar10,uVar2,uVar7);
        pcVar6->coff_symbol = uVar7;
      }
      uVar7 = s->id;
      uVar11 = pcVar6->coff_symbol;
      uVar12 = '\x02';
      uVar2 = coff_symbol_type_bits(s);
      uVar3 = g_coff_undef_section_id;
      iVar8 = s->offset;
      cVar9 = 'i';
      puVar5 = fe_symbol_external_name(s);
      uVar7 = coff_add_weak_external((char *)puVar5,uVar3,cVar9,iVar8,uVar2,uVar11,uVar12,uVar7);
      s->coff_symbol = uVar7;
      return;
    }
    uVar4 = s->storage >> 4 & 0xf;
    if (uVar4 == 3) {
      return;
    }
    if (uVar4 == 4) {
      if (((byte)s->attrs & 0xc) == 0xc) {
        uVar7 = s->coff_section;
        local_8 = '\x03';
      }
      else {
        local_8 = '\x02';
        uVar7 = 0;
      }
      uVar11 = s->id;
      uVar2 = coff_symbol_type_bits(s);
      puVar5 = fe_symbol_external_name(s);
      uVar7 = coff_add_symbol((char *)puVar5,uVar3,local_8,uVar7,uVar2,uVar11);
      s->coff_symbol = uVar7;
      return;
    }
    if (uVar4 == 5) {
      return;
    }
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coff.c",0x3ca);
  }
  uVar4 = s->storage & 0x70;
  if (uVar4 == 0x10) {
    return;
  }
  if (uVar4 == 0x30) {
    return;
  }
  if ((s->storage & 0x800) != 0) {
    iVar10 = 0;
    pcVar13 = s__data_107ac608;
    puVar5 = fe_symbol_external_name(s);
    coff_write_directive_record(s__export__107ac5fc,(char *)puVar5,pcVar13,iVar10);
  }
  switch(s->storage >> 7 & 0xf) {
  case 1:
    local_8 = '\x02';
    uVar7 = 4;
    if ((s->attrs & 0x80000) == 0) {
      uVar7 = s->offset;
    }
    if ((g_coff_incremental_update != 0) && ((s->attrs & 0x20) != 0)) {
      uVar11 = s->id;
      iVar10 = coff_is_known_global_id(uVar11);
      if (iVar10 != 0) {
        coff_reserve_function_slots(uVar11);
      }
    }
    break;
  case 2:
    uVar7 = 0;
    goto LAB_107415a7;
  case 3:
    uVar7 = s->size;
LAB_107415a7:
    local_8 = '\x02';
    uVar3 = g_coff_undef_section_id;
    goto code_r0x10741544;
  case 4:
    uVar7 = s->offset;
    local_8 = '\x03';
  }
  pcVar6 = fe_symbol_lookup_id(s->section_id);
  uVar3 = coff_section_for_symbol(pcVar6);
code_r0x10741544:
  uVar11 = s->id;
  iVar10 = coff_is_known_global_id(uVar11);
  uVar4 = -(uint)(iVar10 != 0) & uVar11;
  uVar2 = coff_symbol_type_bits(s);
  puVar5 = fe_symbol_external_name(s);
  uVar7 = coff_add_symbol((char *)puVar5,uVar3,local_8,uVar7,uVar2,uVar4);
  s->coff_symbol = uVar7;
  return;
}

