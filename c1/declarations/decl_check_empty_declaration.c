void __cdecl decl_check_empty_declaration(c1_u8 *spec)

{
  ushort kind;
  c1_u8 *pcVar1;
  int iVar2;
  char *pcVar3;
  c1_tag_symbol *pcVar4;
  ushort *puVar5;
  
  pcVar1 = spec;
  puVar5 = *(ushort **)(spec + 0xc);
  kind = *puVar5;
  if ((kind & 0x4f0) == 0) {
    if ((((kind & 0x200) != 0) && ((spec[1] & 4) == 0)) && ((g_compile_flags_c4 & 0x200) == 0)) {
      if (*(fe_name **)(*(int *)(puVar5 + 4) + 8) == g_name_unnamed) {
        if (g_ms_extensions != '\0') {
          diag_warning(2,0x5e,puVar5);
          return;
        }
        goto LAB_10634852;
      }
      if (g_tag_found_in_current_scope == 0) {
        spec = (c1_u8 *)scope_insert_through_object;
        pcVar4 = decl_warn_type_definition_in_parentheses
                           (*(fe_name **)(*(int *)(puVar5 + 4) + 8),kind,(int *)&spec,0);
        if (spec != (c1_u8 *)0x0) {
          (*(code *)spec)(pcVar4);
        }
      }
    }
  }
  else if ((g_compile_flags_c8 & 0x400) == 0) {
    if (g_ms_extensions != '\0') {
      iVar2 = format_buffer_acquire();
      format_buffer_free(iVar2);
      iVar2 = format_storage_class(0,*(uint *)pcVar1,*(uint *)(pcVar1 + 4),*(uint *)(pcVar1 + 8));
      pcVar3 = format_buffer_text(iVar2);
      diag_warning(2,0x5b,pcVar3,puVar5);
      format_buffer_leave();
      return;
    }
LAB_10634852:
    diag_error(0x3b,0x4d,0x177);
    return;
  }
  return;
}

