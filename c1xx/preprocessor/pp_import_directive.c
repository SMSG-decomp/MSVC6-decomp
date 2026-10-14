char __cdecl
pp_import_directive(char *file,c1_vector *attributes,char angle,char **tlh_out,char **tli_out,
                   byte *regenerated)

{
  byte bVar1;
  char *file_00;
  int *piVar2;
  int iVar3;
  uint uVar4;
  c1_u8 *_Path;
  char *pcVar5;
  wchar_t *szFile;
  long lVar6;
  c1_u8 *local_118;
  int iStack_114;
  c1_itypelib *pcStack_110;
  int iStack_10c;
  int iStack_108;
  char acStack_104 [260];
  
  *tlh_out = (char *)0x0;
  *tli_out = (char *)0x0;
  *regenerated = 1;
  if ((g_block_depth != '\0') || (-1 < g_class_depth)) {
    diag_error(0x303);
    return '\0';
  }
  file_00 = import_find_typelib_file(file,angle);
  pp_import_parse_attributes(attributes);
  if ((g_import_no_implementation != 0) && (g_import_implementation_only != 0)) {
    diag_warning(1,0xbb,"no_implementation","implementation_only");
    return '\0';
  }
  if (file_00 == (char *)0x0) {
    piVar2 = _errno();
    *piVar2 = 2;
    diag_fatal_file_errno(0x53,0x166,file);
    return '\0';
  }
  if (g_auto_pch_creating != 0) {
    pp_import_record_dependency(file_00);
  }
  if ((g_minimal_rebuild != '\0') || (g_opt_FD != '\0')) {
    local_118 = (c1_u8 *)0x0;
    iVar3 = (*g_pdb_gi->mre_compiler->vtbl->push_file)(&local_118,file_00,0xffffffff);
    if ((iVar3 == 0) || (iVar3 = (*g_pdb_gi->mre_compiler->vtbl->pop_file)(), iVar3 == 0)) {
      diag_error(0x1d7,g_pdb_file_name);
    }
  }
  import_make_output_names(file_00,&g_import_tlh_path,&g_import_tli_path);
  uVar4 = import_attributes_signature(attributes,file_00,g_import_tlh_path,g_import_tli_path);
  sprintf((char *)((int)&g_import_banner + g_import_banner_signature_offset),"%08lx).",uVar4);
  g_import_file_as_written = file;
  if (g_import_implementation_only == 0) {
    local_118 = (c1_u8 *)g_import_tlh_path;
  }
  else {
    local_118 = (c1_u8 *)g_import_tli_path;
  }
  _Path = (c1_u8 *)(~-(uint)(g_import_implementation_only != 0) & (uint)g_import_tli_path);
  pcVar5 = _fullpath(acStack_104,(char *)local_118,0x104);
  if (pcVar5 != (char *)0x0) {
    local_118 = str_dup_arena(acStack_104,5);
  }
  if ((_Path != (c1_u8 *)0x0) &&
     (pcVar5 = _fullpath(acStack_104,(char *)_Path,0x104), pcVar5 != (char *)0x0)) {
    _Path = str_dup_arena(acStack_104,5);
  }
  iStack_114 = 0;
  if (((g_import_implementation_only != 0) ||
      (bVar1 = import_output_is_current(file_00,g_import_tlh_path,&iStack_114), bVar1 != 0)) &&
     ((g_import_no_implementation != 0 ||
      (bVar1 = import_output_is_current(file_00,g_import_tli_path,&iStack_114), bVar1 != 0)))) {
    import_register_library(file_00);
    *tlh_out = (char *)local_118;
    *tli_out = (char *)_Path;
    *regenerated = 0;
    return '\x01';
  }
  if (g_import_ole_initialized == '\0') {
    import_init_ole(&g_import_ole_initialized);
  }
  szFile = multibyte_to_wide_arena(file_00);
  lVar6 = LoadTypeLib(szFile,&pcStack_110);
  if (lVar6 < 0) {
    diag_fatal_file(lVar6,0x53,0x166,g_import_file_as_written);
  }
  if ((g_import_implementation_only == 0) &&
     (g_import_tlh_file = (FILE *)fopen(g_import_tlh_path,"wt"), g_import_tlh_file == (FILE *)0x0))
  {
    diag_fatal_file_errno(0x53,0x154,g_import_tlh_path);
    return '\0';
  }
  if ((g_import_no_implementation == 0) &&
     (g_import_tli_file = (FILE *)fopen(g_import_tli_path,"wt"), g_import_tli_file == (FILE *)0x0))
  {
    diag_fatal_file_errno(0x53,0x154,g_import_tli_path);
    return '\0';
  }
  bVar1 = import_emit_typelib(pcStack_110);
  iStack_108 = iStack_114;
  iStack_10c = iStack_114;
  if (g_import_implementation_only == 0) {
    futime(g_import_tlh_file->_file,&iStack_10c);
  }
  if (g_import_no_implementation == 0) {
    futime(g_import_tli_file->_file,&iStack_10c);
  }
  if ((g_import_implementation_only == 0) && (iVar3 = fclose((FILE *)g_import_tlh_file), iVar3 != 0)
     ) {
    diag_fatal_file_errno(0x52,0x154,g_import_tlh_path);
  }
  if (g_import_no_implementation == 0) {
    lVar6 = ftell((FILE *)g_import_tli_file);
    iVar3 = fclose((FILE *)g_import_tli_file);
    if (iVar3 != 0) {
      diag_fatal_file_errno(0x52,0x154,g_import_tli_path);
    }
    if (lVar6 == 0) {
      _unlink(g_import_tli_path);
    }
  }
  (*pcStack_110->vtbl->Release)(pcStack_110);
  if (bVar1 == 0) {
    if (g_import_implementation_only == 0) {
      _unlink(g_import_tlh_path);
    }
    if (g_import_no_implementation != 0) {
      return '\0';
    }
    _unlink(g_import_tli_path);
    return '\0';
  }
  *tlh_out = (char *)local_118;
  *tli_out = (char *)_Path;
  return '\x01';
}

