c2_fe_symbol * __fastcall
coff_new_comdat_section_symbol(c2_fe_symbol *owner,c2_fe_symbol *base_section)

{
  uint32_t number;
  c2_fe_symbol *pcVar1;
  uint8_t uVar2;
  
  number = fe_symbol_next_id();
  pcVar1 = section_symbol_new((uint32_t)base_section->name,base_section->storage,number);
  uVar2 = owner->combine;
  pcVar1->u3e = base_section->u3e;
  if (uVar2 == '\a') {
    pcVar1->combine = '\a';
    uVar2 = (base_section->u44).section_class;
    (pcVar1->u4a).section.comdat_kind = '\x05';
    if (uVar2 != '\x01') goto switchD_10780a3d_caseD_9;
switchD_10780a3d_caseD_1:
    if (base_section->id != g_il_last_section_id) {
      (pcVar1->u4a).section.comdat_base = owner;
      pcVar1->name = ".data";
      (pcVar1->u44).section_class = uVar2;
      return pcVar1;
    }
  }
  else {
    uVar2 = (base_section->u44).section_class;
    switch(uVar2) {
    case '\x01':
      goto switchD_10780a3d_caseD_1;
    default:
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coff.c",0x905);
    case '\x03':
      (pcVar1->u4a).section.comdat_base = owner;
      pcVar1->name = ".bss";
      (pcVar1->u44).section_class = uVar2;
      return pcVar1;
    case '\x04':
      (pcVar1->u4a).section.comdat_base = owner;
      pcVar1->name = ".rdata";
      (pcVar1->u44).section_class = uVar2;
      return pcVar1;
    case '\t':
      break;
    case '\v':
      pcVar1->name = ".tls$";
      break;
    case '\x11':
      (pcVar1->u4a).section.comdat_base = owner;
      pcVar1->name = ".xdata$x";
      (pcVar1->u44).section_class = uVar2;
      return pcVar1;
    case '\x12':
      (pcVar1->u4a).section.comdat_base = owner;
      pcVar1->name = ".text$x";
      (pcVar1->u44).section_class = uVar2;
      return pcVar1;
    case '\x13':
      (pcVar1->u4a).section.comdat_base = owner;
      pcVar1->name = ".debug$S";
      (pcVar1->u44).section_class = uVar2;
      return pcVar1;
    }
  }
switchD_10780a3d_caseD_9:
  (pcVar1->u4a).section.comdat_base = owner;
  (pcVar1->u44).section_class = uVar2;
  return pcVar1;
}

