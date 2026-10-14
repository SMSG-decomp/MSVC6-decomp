uint16_t __fastcall coff_section_for_symbol(c2_fe_symbol *sym)

{
  c2_fe_symbol *pcVar1;
  uint8_t uVar2;
  ushort uVar3;
  int iVar4;
  c2_fe_symbol *pcVar5;
  uint characteristics;
  char *pcVar6;
  uint16_t comdat_assoc;
  int comdat;
  int local_4;
  
  local_4 = 0;
  if (sym->coff_section == 0) {
    pcVar5 = sym;
    if (sym->combine == '\a') {
      pcVar5 = (sym->u4a).section.comdat_base;
    }
    if (((sym->u44).section_class == '\x01') &&
       ((sym->combine != '\a' || ((sym->u4a).section.comdat_kind != '\x05')))) {
      pcVar6 = pcVar5->name;
      iVar4 = strncmp(pcVar6,".rdata",6);
      if ((iVar4 == 0) ||
         ((iVar4 = strncmp(pcVar6,".xdata",6), iVar4 == 0 ||
          (iVar4 = strncmp(pcVar6,".const",6), iVar4 == 0)))) {
        (sym->u44).section_class = '\x04';
      }
      else {
        iVar4 = strncmp(pcVar6,".text",5);
        if (iVar4 == 0) {
          (sym->u44).section_class = '\0';
        }
        else {
          iVar4 = strncmp(pcVar6,".drectve",8);
          pcVar1 = g_drectve_section;
          if (iVar4 == 0) {
            (sym->u44).section_class = '\n';
            sym->u3e = pcVar1->u3e;
          }
        }
      }
    }
    switch(coff_section_for_symbol_class_table[(char)(sym->u44).section_class]) {
    case 0:
      if ((pcVar5->id == 5) ||
         ((sym->combine == '\a' && ((sym->u4a).section.comdat_kind == '\x05')))) {
        pcVar6 = ".text";
      }
      else {
        pcVar6 = pcVar5->name;
      }
      characteristics = 0x60000020;
      if (g_opt_favor_speed == 0) {
        if (g_opt_cbstring == 0) {
          (sym->u3e).label_flags = 1;
        }
        else {
          (sym->u3e).label_flags = 2;
        }
      }
      else {
        (sym->u3e).label_flags = g_code_section_align;
      }
      break;
    case 1:
      if (pcVar5->id == 2) {
        pcVar6 = ".data";
        characteristics = 0xc0000040;
      }
      else if ((sym->combine == '\a') && ((sym->u4a).section.comdat_kind == '\x05')) {
        pcVar6 = sym->name;
        characteristics = 0xc0000040;
      }
      else {
        pcVar6 = pcVar5->name;
        characteristics = 0xc0000040;
      }
      break;
    case 2:
      if ((pcVar5->id == 4) ||
         ((sym->combine == '\a' && ((sym->u4a).section.comdat_kind == '\x05')))) {
        pcVar6 = ".bss";
        characteristics = 0xc0000080;
      }
      else {
        pcVar6 = pcVar5->name;
        characteristics = 0xc0000080;
      }
      break;
    case 3:
      if ((pcVar5->id == 3) ||
         ((sym->combine == '\a' && ((sym->u4a).section.comdat_kind == '\x05')))) {
        pcVar6 = ".rdata";
        characteristics = 0x40000040;
      }
      else {
        pcVar6 = pcVar5->name;
        characteristics = 0x40000040;
      }
      break;
    case 4:
      pcVar6 = sym->name;
      characteristics = 0x42000048;
      break;
    case 5:
      pcVar6 = sym->name;
      characteristics = 0xa00;
      break;
    case 6:
      if ((pcVar5->id == 9) ||
         ((sym->combine == '\a' && ((sym->u4a).section.comdat_kind == '\x05')))) {
        pcVar6 = ".tls$";
        characteristics = 0xc0000040;
      }
      else {
        pcVar6 = pcVar5->name;
        characteristics = 0xc0000040;
      }
      break;
    case 7:
      pcVar6 = ".xdata$x";
      characteristics = 0x40000040;
      break;
    case 8:
      pcVar6 = ".text$x";
      characteristics = 0x60000020;
      if (g_opt_favor_speed != 0) {
        (sym->u3e).label_flags = g_code_section_align;
      }
      break;
    case 9:
      if ((pcVar5->id == 7) ||
         ((sym->combine == '\a' && ((sym->u4a).section.comdat_kind == '\x05')))) {
        pcVar6 = ".debug$S";
        characteristics = 0x42000048;
      }
      else {
        pcVar6 = pcVar5->name;
        characteristics = 0x42000048;
      }
      break;
    case 10:
      if ((pcVar5->id == 8) ||
         ((sym->combine == '\a' && ((sym->u4a).section.comdat_kind == '\x05')))) {
        pcVar6 = ".debug$P";
        if (g_coff_debug_types_precomp == 0) {
          pcVar6 = ".debug$T";
        }
        characteristics = 0x42000048;
      }
      else {
        pcVar6 = pcVar5->name;
        characteristics = 0x42000048;
      }
      break;
    case 0xb:
      pcVar6 = sym->name;
      characteristics = 0x40000240;
    }
    if (((g_opt_incremental != 0) && (g_cur_func_sym != (c2_fe_symbol *)0x0)) &&
       ((g_cur_func_sym->section_id == sym->id ||
        ((pcVar5 = (sym->u4a).section.comdat_base, pcVar5 != (c2_fe_symbol *)0x0 &&
         (g_cur_func_sym->section_id == pcVar5->id)))))) {
      local_4 = 1;
    }
    if (sym->combine == '\a') {
      uVar2 = (sym->u4a).section.comdat_kind;
      if (uVar2 == '\x05') {
        comdat_assoc = (uint16_t)((sym->u4a).section.comdat_base)->coff_section;
      }
      else {
        comdat_assoc = 0;
      }
      comdat = 1;
      iVar4 = local_4;
      uVar2 = coff_comdat_selection_code(uVar2);
      uVar3 = coff_new_section_ex(pcVar6,characteristics | 0x1000,uVar2,comdat_assoc,comdat,iVar4);
    }
    else {
      uVar3 = coff_new_section(pcVar6,characteristics,1,local_4);
    }
    sym->coff_section = (uint)uVar3;
    if (local_4 != 0) {
      coff_record_function_fixup(sym->coff_section);
    }
    coff_activate_section((uint16_t)sym->coff_section,characteristics);
    coff_symbol_hash_insert(sym);
  }
  return (uint16_t)sym->coff_section;
}

