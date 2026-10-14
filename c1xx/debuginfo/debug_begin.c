void __cdecl debug_begin(char no_header)

{
  ushort *puVar1;
  char cVar2;
  ulong pdb_value;
  ulong pdb_value_2;
  uint name_length;
  uint name_length_2;
  uint uVar3;
  
  if ((g_debug_begun == 0) &&
     (((g_debug_begun = 1, g_batch_continuing != '\0' || (g_debug_types_in_pdb == '\0')) ||
      (cVar2 = pdb_open_type_info(&g_pdb), cVar2 != '\0')))) {
    g_debug_record_buffer = mem_xmalloc(0xff00);
    g_cv_record_body = g_debug_record_buffer + 1;
    if (g_opt_Zi != '\0') {
      if (no_header == '\0') {
        il_emit_debug_record(0xc);
        il_emit_debug_record_10();
        puVar1 = g_debug_record_buffer;
        puVar1[0] = 2;
        puVar1[1] = 0;
        il_emit_debug_record(3);
      }
      puVar1 = g_cv_record_body;
      if (g_debug_types_in_pdb != '\0') {
        if (g_pdb.pdb != (c1xx_pdb *)0x0) {
          *g_cv_record_body = 0x16;
          if (g_pdb.pdb == (c1xx_pdb *)0x0) {
            pdb_value = 0;
          }
          else {
            pdb_value = (*(g_pdb.pdb)->vtbl->query_signature)(g_pdb.pdb);
          }
          *(ulong *)(puVar1 + 1) = pdb_value;
          if (g_pdb.pdb == (c1xx_pdb *)0x0) {
            pdb_value_2 = 0;
          }
          else {
            pdb_value_2 = (*(g_pdb.pdb)->vtbl->query_age)(g_pdb.pdb);
          }
          *(ulong *)(puVar1 + 3) = pdb_value_2;
          name_length = debug_identifier_length((byte *)(puVar1 + 5),g_pdb_file_name);
          uVar3 = (name_length & 0xffff) + 10;
          name_length_2 =
               debug_type_pad_to_4((char *)((uVar3 & 0xffff) + 2 + (int)g_debug_record_buffer),
                                   (char)name_length + '\f');
          *g_debug_record_buffer = (short)uVar3 + (short)name_length_2;
          il_emit_debug_record(0xb);
        }
        return;
      }
    }
  }
  return;
}

