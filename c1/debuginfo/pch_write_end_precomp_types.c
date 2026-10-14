void __cdecl pch_write_end_precomp_types(void)

{
  ushort *puVar1;
  
  if (g_error_count == 0) {
    (*g_current_scope->file_scope->vtbl->emit_il)(g_current_scope->file_scope);
    puVar1 = g_debug_record_buffer;
    g_pch_precomp_types = '\0';
    if (g_debug_types_in_pdb == '\0') {
      g_debug_record_buffer[1] = 0x14;
      *(uint *)(puVar1 + 2) = g_cv_precomp_signature;
      debug_pad_record(6,g_debug_record_buffer);
      g_cv_next_type_index = g_cv_next_type_index + 1;
    }
    return;
  }
  return;
}

