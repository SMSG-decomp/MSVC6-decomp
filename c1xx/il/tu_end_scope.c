void __cdecl tu_end_scope(void)

{
  ushort *puVar1;
  
  if (g_error_count == 0) {
    if (g_minimal_rebuild != '\0') {
      g_minimal_rebuild_tracker->current->tracked = '\0';
    }
    (*g_current_scope->global_scope->vtbl->emit_il)(g_current_scope->global_scope);
    if (g_minimal_rebuild != '\0') {
      g_minimal_rebuild_tracker->current->tracked = '\x01';
    }
    puVar1 = g_debug_record_buffer;
    g_pch_precomp_types = 0;
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

