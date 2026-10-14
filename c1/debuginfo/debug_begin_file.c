void __cdecl debug_begin_file(char *pch_name)

{
  ushort *puVar1;
  char *pcVar2;
  int iVar3;
  
  if (g_debug_types_in_pdb != '\0') {
    debug_begin('\0');
    return;
  }
  g_cv_type_stream_size = 0;
  debug_begin('\0');
  puVar1 = g_debug_record_buffer;
  g_debug_record_buffer[1] = 0x100e;
  puVar1[2] = 0x1000;
  puVar1[3] = 0;
  iVar3 = g_cv_next_type_index + -0x1001;
  g_cv_next_type_index = g_cv_next_type_index + -1;
  *(int *)(puVar1 + 4) = iVar3;
  *(uint *)(puVar1 + 6) = g_cv_precomp_signature;
  pcVar2 = debug_put_length_prefixed_name((char *)(puVar1 + 8),pch_name);
  debug_pad_record((int)(pcVar2 + (0xe - (int)(puVar1 + 8))),g_debug_record_buffer);
  return;
}

