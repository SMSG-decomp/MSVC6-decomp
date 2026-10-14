void __thiscall class_check_member_declaration(c1_declaration *decl,c1_decl_specifiers *spec)

{
  byte *pbVar1;
  char cVar2;
  byte bVar3;
  c1_symbol *pcVar4;
  int iVar5;
  void *pvVar6;
  c1_type *pcVar7;
  
  if (g_class_depth < 0) {
    diag_error(0x1c);
    return;
  }
  pcVar7 = spec->type;
  if (decl->name == (void *)0x0) {
    if (((pcVar7->code & 0x200) == 0) || (pcVar4 = (pcVar7->extra).sym, pcVar4 == (c1_symbol *)0x0))
    {
      diag_error(0xd0,pcVar7);
      return;
    }
    diag_extension_warning_or_error(0xc9,0x1d3,pcVar7);
    if ((pcVar4->flags1 & 1) != 0) {
      class_new_member_symbol(pcVar7);
      return;
    }
    if (g_opt_Zg == '\0') {
      diag_error(0x1b,pcVar4);
      return;
    }
  }
  else {
    pcVar4 = decl_declare_declarator(decl,spec);
    decl->sym = pcVar4;
    if ((pcVar4 != (c1_symbol *)0x0) &&
       (iVar5 = class_check_member_redefinition(decl->name), iVar5 == 0)) {
      pcVar7 = decl->type;
      while ((bVar3 = (byte)pcVar7->code, (bVar3 & 0x8f) == 0x83 || ((bVar3 & 0x83) == 0x81))) {
        pcVar7 = pcVar7->base;
      }
      if (((byte)pcVar7->flags >> 5 & 1) != 0) {
        pbVar1 = (byte *)((int)&(g_struct_layouts[g_class_depth].tag)->alignment + 1);
        *pbVar1 = *pbVar1 | 4;
      }
      if (decl->context == 1) {
        pcVar7 = decl->type;
        cVar2 = (char)pcVar7->code;
        while (cVar2 < '\0') {
          pcVar7 = pcVar7->base;
          cVar2 = (char)pcVar7->code;
        }
        class_check_bit_field(decl->sym,pcVar7->code);
        iVar5 = g_class_depth;
      }
      else {
        if (decl->sym->name != g_name_alignment_member) {
          pvVar6 = (void *)class_check_zero_sized_array_member(decl->sym);
          decl->sym->detail = pvVar6;
        }
        class_append_member(decl->sym);
        bVar3 = (g_struct_layouts[g_class_depth].tag)->flags4;
        (g_struct_layouts[g_class_depth].tag)->flags4 = (decl->sym->flags4 ^ bVar3) & 1 ^ bVar3;
        iVar5 = g_class_depth;
        g_struct_layouts[g_class_depth].bitfield_type = 0;
      }
      if ((g_browse_file != (char *)0x0) &&
         (((g_block_depth == '\0' || (g_opt_FR_browse != 0)) &&
          ((g_struct_layouts[iVar5].tag)->name != g_name_unnamed)))) {
        (*g_il_emitter->vtbl->define_symbol)(g_il_emitter,decl->sym);
      }
    }
  }
  return;
}

