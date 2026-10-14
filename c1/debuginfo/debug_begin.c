void __cdecl debug_begin(char no_header)

{
  ushort *puVar1;
  char cVar2;
  SIG SVar3;
  AGE AVar4;
  uint uVar5;
  uint uVar6;
  
  if (g_debug_begun == 0) {
    g_debug_begun = 1;
    if (((g_batch_continuing == '\0') && (g_debug_types_in_pdb != '\0')) &&
       (cVar2 = pdb_open_type_info(&g_pdb), cVar2 == '\0')) {
      return;
    }
    g_debug_record_buffer = mem_xmalloc(0xff00);
    g_cv_record_body = g_debug_record_buffer + 1;
    if (g_opt_Zi != '\0') {
      if (no_header == '\0') {
        il_emit_debug_record(0xc);
        il_emit_debug_record_10();
        puVar1 = g_debug_record_buffer;
        puVar1[0] = 2;
        puVar1[1] = 0;
        il_emit_debug_record(3,4,g_debug_record_buffer);
      }
      puVar1 = g_cv_record_body;
      if (g_debug_types_in_pdb != '\0') {
        if (g_pdb.pdb != (PDB *)0x0) {
          *g_cv_record_body = 0x16;
          if (g_pdb.pdb == (PDB *)0x0) {
            SVar3 = 0;
          }
          else {
            SVar3 = (*(g_pdb.pdb)->vtbl->QuerySignature)(g_pdb.pdb);
          }
          *(SIG *)(puVar1 + 1) = SVar3;
          if (g_pdb.pdb == (PDB *)0x0) {
            AVar4 = 0;
          }
          else {
            AVar4 = (*(g_pdb.pdb)->vtbl->QueryAge)(g_pdb.pdb);
          }
          *(AGE *)(puVar1 + 3) = AVar4;
          uVar5 = debug_identifier_length((char *)(puVar1 + 5),&g_pdb_file_name);
          uVar6 = (uVar5 & 0xffff) + 10;
          uVar5 = debug_type_pad_to_4((char *)((uVar6 & 0xffff) + 2 + (int)g_debug_record_buffer),
                                      (char)uVar5 + '\f');
          *g_debug_record_buffer = (short)uVar6 + (short)uVar5;
          il_emit_debug_record(0xb,g_debug_record_buffer);
        }
        return;
      }
    }
  }
  return;
}

