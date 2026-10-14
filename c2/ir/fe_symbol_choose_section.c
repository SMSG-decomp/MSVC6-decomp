void __fastcall fe_symbol_choose_section(c2_fe_symbol *s)

{
  uint8_t uVar1;
  uint32_t uVar2;
  uint uVar3;
  int iVar4;
  c2_fe_symbol *pcVar5;
  uint32_t uVar6;
  void *pvVar7;
  c2_fe_symbol *pcVar8;
  int iVar9;
  char *name;
  
  if ((s->cls == '\x01') && (s->section_id == 0)) {
    switch(s->storage >> 4 & 7) {
    case 1:
    case 3:
      s->section_id = 6;
      break;
    case 2:
    case 4:
      uVar3 = s->storage >> 7 & 0xf;
      if (uVar3 == 1) {
LAB_107429b2:
        iVar4 = fe_symbol_storage_is_0x40(s);
        iVar9 = g_opt_incremental;
        if (iVar4 == 0) {
          if ((s->attrs & 0x480) == 0) {
            s->section_id = 4;
            s->storage = s->storage & 0xffffffef | 0x60;
            if (iVar9 == 0) goto LAB_10742a30;
            iVar9 = coff_is_known_global_id(s->id);
            if (iVar9 == 0) {
              pcVar5 = coff_select_data_section(g_cur_func_sym,s);
              uVar2 = pcVar5->id;
              goto LAB_107429a4;
            }
          }
          else {
            s->section_id = 2;
            s->storage = s->storage & 0xffffffaf | 0x20;
          }
        }
        else {
          s->section_id = 3;
        }
      }
      else if (uVar3 != 2) {
        if (uVar3 != 3) goto LAB_107429b2;
        s->section_id = 2;
        s->attrs = s->attrs & 0xffffffdf;
      }
      break;
    default:
      g_error_count = g_error_count + 1;
      fatal_error(1,"E:\\8168\\vc98\\p2\\src\\P2\\x86\\MDmisc.c",0x3b0);
    case 7:
      uVar2 = g_ehdata_section->id;
LAB_107429a4:
      s->section_id = uVar2;
    }
  }
  if ((((g_opt_incremental != 0) && (s->cls == '\x04')) && ((s->storage & 0x4000) != 0)) &&
     ((s->attrs & 0x20) == 0)) {
    uVar2 = s->section_id;
    if ((uVar2 == 0) || (uVar2 == 5)) {
      uVar6 = fe_symbol_next_id();
      name = ".text";
    }
    else {
      uVar6 = fe_symbol_next_id();
      pcVar5 = fe_symbol_lookup_id(uVar2);
      name = pcVar5->name;
    }
    pcVar5 = section_symbol_new((uint32_t)name,0x107a045c,uVar6);
    uVar2 = g_code_section_align;
    s->section_id = pcVar5->id;
    (pcVar5->u44).section_class = '\0';
    (pcVar5->u3e).label_flags = uVar2;
    return;
  }
LAB_10742a30:
  uVar3 = s->attrs;
  if ((uVar3 & 0x20) != 0) {
    uVar2 = s->section_id;
    pcVar5 = fe_symbol_lookup_id(uVar2);
    if (pcVar5->combine != '\a') {
      if (s->cls == '\x04') {
        uVar6 = fe_symbol_next_id();
        pcVar5 = section_symbol_new((uint32_t)s->name,0x107a045c,uVar6);
        uVar6 = g_code_section_align;
        uVar3 = s->fn_flags;
        (pcVar5->u44).section_class = '\0';
        (pcVar5->u3e).label_flags = uVar6;
        (pcVar5->u4a).section.comdat_kind = '\x02' - ((uVar3 & 0x80) != 0);
      }
      else {
        pcVar5 = fe_symbol_lookup_id(uVar2);
        uVar1 = (pcVar5->u44).section_class;
        if (uVar1 == '\x04') {
          uVar6 = fe_symbol_next_id();
          pcVar5 = section_symbol_new((uint32_t)s->name,0x107a012c,uVar6);
          (pcVar5->u44).section_class = '\x04';
        }
        else if (uVar1 == '\x01') {
          uVar6 = fe_symbol_next_id();
          pcVar5 = section_symbol_new((uint32_t)s->name,0x107a0454,uVar6);
          (pcVar5->u44).section_class = '\x01';
        }
        else if (uVar1 == '\v') {
          uVar6 = fe_symbol_next_id();
          pcVar5 = section_symbol_new((uint32_t)s->name,0x107a5720,uVar6);
          (pcVar5->u44).section_class = '\v';
        }
        else {
          if (uVar1 != '\x03') {
            ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\MDmisc.c",0x3d9);
          }
          uVar6 = fe_symbol_next_id();
          pcVar5 = section_symbol_new((uint32_t)s->name,0x107a0450,uVar6);
          (pcVar5->u44).section_class = '\x03';
        }
        if ((uVar3 & 0x20000) == 0) {
          if ((uVar3 & 0x40000) == 0) {
            (pcVar5->u4a).section.comdat_kind = '\x01';
          }
          else {
            (pcVar5->u4a).section.comdat_kind = '\a';
          }
        }
        else {
          (pcVar5->u4a).section.comdat_kind = '\x06';
        }
        (pcVar5->u3e).label_flags = g_default_stack_align;
      }
      pcVar5->combine = '\a';
      pcVar5->level = '\x01';
      *(c2_fe_symbol **)((int)&(pcVar5->u4a).function.x4b + 3) = s;
      *(undefined1 *)&pcVar5->sym_offset = 0;
      pvVar7 = arena_alloc(0,0xc);
      pcVar5->section_id = (uint32_t)pvVar7;
      *(undefined4 *)((int)pvVar7 + 4) = 0;
      pcVar8 = fe_symbol_lookup_id(uVar2);
      (pcVar5->u4a).section.comdat_base = pcVar8;
      s->section_id = pcVar5->id;
    }
  }
  return;
}

