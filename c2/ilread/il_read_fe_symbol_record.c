c2_fe_symbol * __fastcall il_read_fe_symbol_record(int inline_candidate)

{
  char cVar1;
  FILE *pFVar2;
  uint8_t cls;
  uint16_t uVar3;
  int16_t iVar4;
  int iVar5;
  int iVar6;
  c2_fe_symbol *pcVar7;
  int32_t iVar8;
  uint32_t uVar9;
  c2_fe_symbol *pcVar10;
  char *module_name;
  char *pcVar11;
  uint uVar12;
  uint uVar13;
  int local_arena;
  uint32_t *copy_src;
  uint32_t *copy_dst;
  char *pcVar14;
  int rec_class;
  c2_fe_symbol rec;
  FILE pdb_stream_file;
  
  local_arena = 0;
  iVar5 = il_read_byte();
  cls = (uint8_t)iVar5;
  rec_class = (int)(char)cls;
  switch(rec_class) {
  case 1:
  case 2:
    break;
  case 3:
    iVar5 = il_read_byte();
    uVar13 = (uint)('\0' < (char)(uint8_t)iVar5);
    pcVar7 = fe_symbol_alloc(cls,uVar13);
    pcVar7->cls = '\x03';
    pcVar7->level = (uint8_t)iVar5;
    uVar12 = il_read_id();
    pcVar7->id = uVar12;
    iVar5 = il_read_byte();
    pcVar7->role = (char)iVar5;
    il_read_string(g_il_name_buffer,0x81e);
    il_read_short();
    pcVar7->refcount = 0;
    uVar12 = il_read_byte();
    (pcVar7->u3e).label_flags = (uVar12 & 4) >> 2 | (pcVar7->u3e).label_flags & 0xfffffffe;
    if (g_il_name_buffer[0] == '\0') {
      return pcVar7;
    }
    pcVar11 = decorate_c_name(pcVar7,g_il_name_buffer,uVar13);
    pcVar7->name = pcVar11;
    return pcVar7;
  case 4:
  case 0xe:
  case 0x10:
    uVar12 = il_read_id();
    iVar5 = il_read_byte();
    pcVar7 = fe_symbol_alloc(cls,0);
    pcVar7->cls = '\x04';
    pcVar7->id = uVar12;
    pcVar7->role = (char)iVar5;
    il_read_string(g_il_name_buffer,0x81e);
    il_read_symbol_type(pcVar7);
    uVar12 = il_read_byte();
    uVar12 = uVar12 & 0xf;
    uVar13 = pcVar7->storage & 0xffffff0f;
    pcVar7->storage = uVar12 << 4 | uVar13;
    if (uVar12 == 6) {
      pcVar7->storage = uVar13 | 0x40;
      note_symbol_referenced(pcVar7);
    }
    else {
      if ((uVar12 == 7) || (uVar12 == 9)) {
        uVar9 = uVar12 << 4 & 0xffffff5f | uVar13 | 0x850;
      }
      else {
        if (uVar12 != 10) goto LAB_10742280;
        uVar9 = uVar13 | 0x1040;
      }
      pcVar7->storage = uVar9;
    }
LAB_10742280:
    iVar8 = il_read_long();
    pcVar7->refcount = iVar8;
    if (g_pdb_il_mode == 0) {
      uVar12 = il_read_id();
    }
    else {
      uVar12 = il_read_compact_word_file();
    }
    pcVar7->attrs = uVar12;
    if ((uVar12 & 0x200) == 0) {
      uVar9 = 5;
    }
    else {
      uVar9 = il_read_id();
    }
    pcVar7->section_id = uVar9;
    if (g_il_wide_type_index == 0) {
      iVar4 = il_read_short();
      uVar9 = (uint32_t)iVar4;
    }
    else {
      uVar9 = il_read_long();
    }
    pcVar7->cv_type_index = uVar9;
    if ((uVar12 & 0xc) == 0xc) {
      iVar5 = il_read_byte();
      (pcVar7->u4a).function.cor_type = (uint8_t)iVar5;
      uVar9 = il_read_long();
      pcVar7->coff_section = uVar9;
    }
    if (cls == '\x0e') {
      pcVar7->storage = pcVar7->storage | 0x4000;
      if ((uVar12 & 0xc) == 0xc) {
        uVar9 = il_read_long();
        pcVar7->x77 = uVar9;
      }
      if (g_pdb_il_mode == 0) {
        uVar9 = il_read_long();
        (pcVar7->u4a).function.exp_offset = uVar9;
        uVar9 = il_read_long();
        pcVar7->sym_offset = uVar9;
      }
      uVar3 = il_read_short();
      pcVar7->inline_size = uVar3;
      if (g_pdb_il_mode == 0) {
        uVar9 = il_read_id();
      }
      else {
        uVar9 = il_read_compact_word_file();
      }
      pcVar7->fn_flags = uVar9;
      iVar4 = il_read_short();
      pcVar7->formal_count = iVar4;
      if (g_pdb_il_mode != 0) {
        uVar9 = il_read_long();
        (pcVar7->u4a).function.exp_offset = uVar9;
        il_read_short();
      }
      pcVar7->attrs = -(uint)(g_opt_function_level_linking != 0) & 0x20 | uVar12;
    }
    else if (cls == '\x10') {
      pcVar7->storage = pcVar7->storage | 0x8000;
      uVar12 = il_read_id();
      (pcVar7->u4a).function.exp_offset = uVar12;
    }
    pcVar11 = decorate_c_name(pcVar7,g_il_name_buffer,0);
    pcVar7->name = pcVar11;
    goto LAB_107420db;
  case 5:
    pcVar7 = fe_symbol_alloc(cls,0);
    uVar12 = il_read_id();
    pcVar10 = fe_symbol_lookup_id(uVar12);
    (pcVar7->u3e).alias_base = pcVar10;
    if (pcVar10 == (c2_fe_symbol *)0x0) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\p2symtab.c",0x2f2);
    }
    uVar12 = il_read_id();
    pcVar7->id = uVar12;
    uVar9 = il_read_long();
    pcVar7->size = uVar9;
    iVar5 = il_read_byte();
    pcVar7->role = (char)iVar5;
    if (g_il_wide_type_index == 0) {
      iVar4 = il_read_short();
      pcVar7->cv_type_index = (int)iVar4;
      return pcVar7;
    }
    uVar9 = il_read_long();
    pcVar7->cv_type_index = uVar9;
    return pcVar7;
  case 6:
    return (c2_fe_symbol *)0x0;
  case 7:
    iVar5 = il_read_byte();
    uVar13 = (uint)('\0' < (char)iVar5);
    pcVar7 = fe_symbol_alloc(cls,uVar13);
    uVar12 = il_read_id();
    pcVar7->id = uVar12;
    il_read_string(g_il_name_buffer,0x81e);
    pcVar11 = decorate_c_name(pcVar7,g_il_name_buffer,uVar13);
    pcVar7->name = pcVar11;
    il_read_symbol_type(pcVar7);
    il_read_byte();
    uVar9 = il_read_long();
    pcVar7->size = uVar9;
    uVar12 = il_read_byte();
    uVar12 = (uVar12 & 0xf) << 7 | pcVar7->storage & 0xfffff87f;
    pcVar7->storage = uVar12;
    iVar8 = il_read_long();
    pcVar7->offset = iVar8;
    if (g_il_wide_type_index == 0) {
      iVar4 = il_read_short();
      uVar9 = (uint32_t)iVar4;
    }
    else {
      uVar9 = il_read_long();
    }
    pcVar7->cv_type_index = uVar9;
    uVar13 = il_read_id();
    pcVar7->refcount = uVar13;
    iVar8 = il_read_long();
    *(int32_t *)((int)&pcVar7->u3e + 2) = iVar8;
    if (iVar8 != 0) {
      pcVar7->storage = uVar12 | 0x10000;
    }
    note_symbol_referenced(pcVar7);
    return pcVar7;
  case 8:
    iVar5 = il_read_byte();
    uVar13 = (uint)('\0' < (char)iVar5);
    pcVar7 = fe_symbol_alloc(cls,uVar13);
    uVar12 = il_read_id();
    pcVar7->id = uVar12;
    il_read_string(g_il_name_buffer,0x81e);
    pcVar11 = decorate_c_name(pcVar7,g_il_name_buffer,uVar13);
    pcVar7->name = pcVar11;
    if (g_il_wide_type_index == 0) {
      iVar4 = il_read_short();
      uVar9 = (uint32_t)iVar4;
    }
    else {
      uVar9 = il_read_long();
    }
    pcVar7->cv_type_index = uVar9;
    il_read_symbol_type(pcVar7);
    il_read_byte();
    uVar9 = il_read_long();
    pcVar7->size = uVar9;
    il_read_byte_blob(pcVar7,uVar13);
    note_symbol_referenced(pcVar7);
    return pcVar7;
  case 9:
    pcVar7 = fe_symbol_alloc(cls,0);
    uVar12 = il_read_id();
    pcVar7->id = uVar12;
    il_read_string(g_il_name_buffer,0x81e);
    iVar5 = il_read_byte();
    (pcVar7->u44).section_class = (uint8_t)iVar5;
    pcVar11 = decorate_c_name(pcVar7,g_il_name_buffer,0);
    pcVar7->name = pcVar11;
    il_read_string(g_il_name_buffer,0x81e);
    pcVar11 = arena_strdup(g_il_name_buffer,0);
    pcVar7->storage = (uint32_t)pcVar11;
    pcVar7->level = (pcVar7->u44).section_class != '\x01';
    return pcVar7;
  case 10:
    g_pch_signature = il_read_long();
    il_read_string(g_il_name_buffer,0x81e);
    if ((g_il_name_buffer[0] != '\0') && (g_pdb_il_mode == 0)) {
      g_pch_name = arena_strdup(g_il_name_buffer,0);
      g_pch_exp_il_file = open_il_file(g_pch_name,"","rb","Pch exp il");
      g_pch_sym_il_file = open_il_file(g_pch_name,"","rb","Pch sym il");
    }
    for (iVar5 = il_read_long(); iVar5 != 0; iVar5 = iVar5 + -1) {
      local_arena = il_read_byte();
      il_read_object_comment((int)(char)local_arena);
    }
    return (c2_fe_symbol *)0x0;
  case 0xb:
    iVar5 = il_read_byte();
    uVar13 = (uint)('\0' < (char)iVar5);
    pcVar7 = fe_symbol_alloc(cls,uVar13);
    uVar12 = il_read_id();
    pcVar7->id = uVar12;
    il_read_string(g_il_name_buffer,0x81e);
    pcVar11 = decorate_c_name(pcVar7,g_il_name_buffer,uVar13);
    pcVar7->name = pcVar11;
    il_read_byte();
    if (g_il_wide_type_index == 0) {
      iVar4 = il_read_short();
      pcVar7->cv_type_index = (int)iVar4;
      note_symbol_referenced(pcVar7);
      return pcVar7;
    }
    uVar9 = il_read_long();
    pcVar7->cv_type_index = uVar9;
    note_symbol_referenced(pcVar7);
    return pcVar7;
  default:
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\p2symtab.c",0x3a4);
  case 0xd:
    g_fe_marker_record.cls = '\r';
    iVar5 = il_read_byte();
    g_fe_marker_record.level = (uint8_t)iVar5;
    return &g_fe_marker_record;
  case 0x12:
    g_fe_marker_record.cls = cls;
    g_fe_marker_record.id = il_read_id();
    il_read_string(g_il_name_buffer,0x81e);
    g_fe_marker_record.name = decorate_c_name(&g_fe_marker_record,g_il_name_buffer,0);
    return &g_fe_marker_record;
  case 0x16:
    g_fe_marker_record.cls = '\x16';
    il_read_string(g_il_name_buffer,0x81e);
    uVar12 = 0xffffffff;
    pcVar11 = g_il_name_buffer;
    do {
      if (uVar12 == 0) break;
      uVar12 = uVar12 - 1;
      cVar1 = *pcVar11;
      pcVar11 = pcVar11 + 1;
    } while (cVar1 != '\0');
    module_name = arena_alloc(4,~uVar12);
    uVar12 = 0xffffffff;
    pcVar11 = g_il_name_buffer;
    do {
      pcVar14 = pcVar11;
      if (uVar12 == 0) break;
      uVar12 = uVar12 - 1;
      pcVar14 = pcVar11 + 1;
      cVar1 = *pcVar11;
      pcVar11 = pcVar14;
    } while (cVar1 != '\0');
    uVar12 = ~uVar12;
    pcVar11 = pcVar14 + -uVar12;
    pcVar14 = module_name;
    for (uVar13 = uVar12 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
      *(undefined4 *)pcVar14 = *(undefined4 *)pcVar11;
      pcVar11 = pcVar11 + 4;
      pcVar14 = pcVar14 + 4;
    }
    for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
      *pcVar14 = *pcVar11;
      pcVar11 = pcVar11 + 1;
      pcVar14 = pcVar14 + 1;
    }
    iVar5 = pdb_il_pending_add(module_name);
    if (iVar5 != 0) {
      g_pdb_il_module_index = g_pdb_il_module_index + 1;
      return &g_fe_marker_record;
    }
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\p2symtab.c",0x37a);
  case 0x17:
    il_read_string(g_il_name_buffer,0x81e);
    pcVar11 = pdb_read_stream(g_il_name_buffer,(size_t *)&rec_class);
    pFVar2 = g_il_stream;
    if (pcVar11 != (char *)0x0) {
      pdb_stream_file._cnt = rec_class;
      g_il_stream = &pdb_stream_file;
      pdb_stream_file._flag = 1;
      pdb_stream_file._file = -1;
      pdb_stream_file._ptr = pcVar11;
      read_function_symbols((c2_function *)0x0);
      free(pcVar11);
      g_il_stream = pFVar2;
      g_fe_marker_record.cls = '\x17';
      return &g_fe_marker_record;
    }
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\p2symtab.c",0x389);
  case 0x19:
    il_read_long();
    return (c2_fe_symbol *)rec_class;
  }
  pcVar7 = &rec;
  for (iVar5 = 0x1e; iVar5 != 0; iVar5 = iVar5 + -1) {
    pcVar7->next = (c2_fe_symbol *)0x0;
    pcVar7 = (c2_fe_symbol *)&pcVar7->cls;
  }
  *(undefined2 *)&pcVar7->next = 0;
  *(undefined1 *)((int)&pcVar7->next + 2) = 0;
  iVar5 = il_read_byte();
  rec.cls = '\x01';
  rec.id = il_read_id();
  iVar6 = il_read_byte();
  rec.role = (char)iVar6;
  il_read_string(g_il_name_buffer,0x81e);
  il_read_symbol_type(&rec);
  il_read_byte();
  rec.refcount._2_1_ = (char)iVar5;
  uVar12 = il_read_byte();
  rec.storage = (uVar12 & 7) << 4 | rec.storage & 0xffffff8f;
  uVar12 = il_read_byte();
  rec.storage = (uVar12 & 0xf) << 7 | rec.storage & 0xfffff87f;
  rec.size = il_read_long();
  if (g_pdb_il_mode == 0) {
    rec.attrs = il_read_id();
  }
  else {
    rec.attrs = il_read_compact_word_file();
  }
  if (((rec.storage & 0x70) == 0x30) || ((rec.storage & 0x70) == 0x10)) {
    rec.attrs = rec.attrs & 0xffffdfff;
  }
  uVar12 = rec.storage & 0x780;
  if ((uVar12 == 0x300) || (uVar12 == 0x380)) {
    uVar12 = rec.storage & 0xfffff8ff | 0x80;
LAB_1078324f:
    rec.storage = uVar12 | 0x800;
  }
  else {
    if (uVar12 == 0x480) {
      uVar12 = rec.storage & 0xfffff9ff | 0x180;
      goto LAB_1078324f;
    }
    if (uVar12 == 0x400) {
      rec.storage = rec.storage & 0xfffff97f | 0x1100;
    }
  }
  if ((rec.attrs & 0x200) == 0) {
    rec.section_id = 0;
  }
  else {
    g_il_last_section_id = il_read_id();
    rec.section_id = g_il_last_section_id;
  }
  if (((g_opt_cbstring != 0) && ((rec.attrs & 0x400) != 0)) &&
     (g_cur_func_sym != (c2_fe_symbol *)0x0)) {
    rec.section_id = g_cur_func_sym->section_id;
    if ((g_cur_func_sym->attrs & 0x20) != 0) {
      rec.attrs = rec.attrs | 0x20;
    }
    rec.attrs = rec.attrs | 0x200;
    rec.storage = rec.storage & 0xffffffaf | 0x20;
  }
  if ((rec.attrs & 0x1000) != 0) {
    if (rec.section_id == 0) {
      rec.attrs = rec.attrs | 0x200;
      rec.section_id = 9;
    }
    else {
      pcVar7 = fe_symbol_lookup_id(rec.section_id);
      pcVar11 = pcVar7->name;
      iVar6 = strncmp(pcVar11,".tls$",5);
      if (iVar6 != 0) {
        warning(1,0x31a,g_il_name_buffer,pcVar11,".tls$");
        rec.section_id = 9;
      }
    }
  }
  if (g_il_wide_type_index == 0) {
    iVar4 = il_read_short();
    rec.cv_type_index = (uint32_t)iVar4;
  }
  else {
    rec.cv_type_index = il_read_long();
  }
  if ((cls == '\x02') && (rec._64_4_ = il_read_long(), rec._64_4_ != 0)) {
    rec.storage = rec.storage | 0x10000;
  }
  if (g_il_name_buffer[0] != '\0') {
    rec.name = decorate_c_name(&rec,g_il_name_buffer,0);
  }
  if (((inline_candidate == 0) ||
      ((rec.cls == '\x01' && (((rec.storage & 0x70) == 0x10 || ((rec.storage & 0x70) == 0x30))))))
     && ('\0' < (char)iVar5)) {
    local_arena = 1;
  }
  pcVar7 = fe_symbol_alloc(cls,local_arena);
  uVar12 = fe_symbol_size(rec_class);
  copy_src = (uint32_t *)&rec;
  copy_dst = (uint32_t *)pcVar7;
  for (uVar13 = uVar12 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
    ((c2_fe_symbol *)copy_dst)->next = (c2_fe_symbol *)*copy_src;
    copy_src = copy_src + 1;
    copy_dst = (uint32_t *)&((c2_fe_symbol *)copy_dst)->cls;
  }
  for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
    *(char *)copy_dst = (char)*copy_src;
    copy_src = (uint32_t *)((int)copy_src + 1);
    copy_dst = (uint32_t *)((int)copy_dst + 1);
  }
LAB_107420db:
  if ((pcVar7->storage & 0x1000) == 0) {
    return pcVar7;
  }
  inline_import_global_symbol(pcVar7);
  return pcVar7;
}

