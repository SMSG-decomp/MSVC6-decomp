void coff_open_object_file(void)

{
  c2_comment_record *r;
  uint8_t uVar1;
  char *pcVar2;
  c2_coff_open *desc;
  uint32_t uVar3;
  int iVar4;
  char *message;
  int iVar5;
  bool bVar6;
  
  if ((g_opt_incremental != 0) &&
     (g_object_file = fopen(g_opt_object_path,"rb"), g_object_file != (FILE *)0x0)) {
    fclose(g_object_file);
    iVar5 = pdb_stream_query_cb();
    if (iVar5 != 0) {
      g_incr_info_buffer = arena_alloc(4,iVar5 + 1);
      iVar4 = pdb_stream_read(g_incr_info_buffer,iVar5);
      if (iVar4 != iVar5) {
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coff.c",0xe1);
      }
      uVar1 = prevobj_read_byte();
      if ((uVar1 == '\x05') && (iVar5 = coff_check_incremental_options(), iVar5 != 0)) {
        g_coff_incremental_update = 1;
        pcVar2 = "r+b";
        goto LAB_10758c9f;
      }
    }
  }
  if (g_coff_incremental_update == 0) {
    pcVar2 = "wb";
  }
  else {
    pcVar2 = "r+b";
  }
LAB_10758c9f:
  g_object_file = fopen(g_opt_object_path,pcVar2);
  if (g_object_file == (FILE *)0x0) {
    pcVar2 = g_opt_object_path;
    message = load_message(0x136);
    fatal_error_errno(0x53,message,pcVar2);
  }
  g_object_file_open = 1;
  if (g_il_language == 5) {
    iVar5 = 9;
  }
  else if (g_il_language == 0) {
    iVar5 = 10;
  }
  else {
    iVar5 = (-(uint)(g_il_language != 1) & 0xfffffff5) + 0xb;
  }
  desc = arena_alloc(7,0x24);
  pcVar2 = g_opt_f;
  bVar6 = g_opt_f == (char *)0x0;
  desc->object_file = g_object_file;
  desc->version = 1;
  desc->machine = 0x14c;
  desc->reserved0 = 0xffff;
  desc->reserved1 = 0xffff;
  if (bVar6) {
    pcVar2 = "";
  }
  else {
    pcVar2 = arena_strdup(pcVar2,7);
  }
  desc->source_file = pcVar2;
  desc->error_fn = coff_writer_error;
  desc->alloc_fn = coff_writer_alloc;
  desc->timestamp_fn = coff_writer_timestamp;
  if (iVar5 == 0) {
    desc->comp_id = 0;
  }
  else {
    desc->comp_id = iVar5 << 0x10 | 0x1fe8;
  }
  if ((g_opt_debug_info == 0) && (g_opt_line_numbers == 0)) {
    uVar1 = '\0';
  }
  else {
    uVar1 = '\x01';
  }
  desc->line_info = uVar1;
  uVar3 = coff_writer_open(desc);
  if (uVar3 == 0) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coff.c",0x11c);
  }
  if (g_coff_incremental_update != 0) {
    read_incremental_function_records();
    coff_read_extern_names();
    coff_mark_referenced_globals();
  }
  uVar3 = fe_symbol_next_id();
  g_drectve_section = section_symbol_new(0x107a038c,0x107a5784,uVar3);
  (g_drectve_section->u3e).label_flags = 1;
  g_drectve_section->combine = '\0';
  g_drectve_section->level = '\x01';
  (g_drectve_section->u44).section_class = '\n';
  uVar3 = fe_symbol_next_id();
  g_module_fpo_section = section_symbol_new(0x107a5770,0x107a577c,uVar3);
  (g_module_fpo_section->u3e).label_flags = 1;
  g_module_fpo_section->combine = '\0';
  (g_module_fpo_section->u44).section_class = '\t';
  g_module_fpo_section->level = '\x01';
  for (r = g_coff_comment_records; r != (c2_comment_record *)0x0; r = r->next) {
    (*g_hook_writer_request)(r);
  }
  return;
}

