void decl_check_multiple_storage_classes(int ebx,byte *spec)

{
  byte bVar1;
  c1_line_map_row *pcVar2;
  char in_stack_00000014;
  int in_stack_00000018;
  
  diag_error(0x9f);
  switch(in_stack_00000014) {
  case '\x03':
  case '\x0e':
    if ((spec[1] & 1) == 0) {
      spec[1] = spec[1] | 1;
      return;
    }
    bVar1 = 0xe;
    goto LAB_1045b97b;
  case '\x04':
    (*g_idb->vtbl->idb_note_decl_specifier)(g_idb);
    if ((spec[2] & 1) == 0) {
      spec[2] = spec[2] | 1;
      return;
    }
    break;
  case '\x05':
    (*g_idb->vtbl->idb_note_decl_specifier)(g_idb);
    if ((spec[2] & 2) == 0) {
      spec[2] = spec[2] | 2;
      return;
    }
    break;
  case '\x06':
    (*g_idb->vtbl->idb_note_decl_specifier)(g_idb);
    if ((spec[2] & 0xc) == 0) {
      spec[2] = spec[2] | 8;
      return;
    }
    break;
  case '\a':
    (*g_idb->vtbl->idb_note_decl_specifier)(g_idb);
    if ((spec[2] & 0xc) == 0) {
      spec[2] = spec[2] | 4;
      return;
    }
    break;
  case '\b':
    bVar1 = spec[3];
    if ((bVar1 & 1) == 0) {
      if (in_stack_00000018 == ebx) {
        *(int *)(spec + 4) = ebx;
        spec[3] = bVar1 & 0xfe;
        return;
      }
      *(int *)(spec + 4) = in_stack_00000018;
      spec[3] = bVar1 | 1;
      return;
    }
    break;
  case '\t':
    (*g_idb->vtbl->idb_note_decl_specifier)(g_idb);
    if ((spec[3] & 0x10) == 0) {
      spec[3] = spec[3] | 0x10;
      return;
    }
    break;
  case '\n':
    (*g_idb->vtbl->idb_note_decl_specifier)(g_idb);
    if ((spec[2] & 0x40) == 0) {
      spec[2] = spec[2] | 0x40;
      *spec = *spec | 0x40;
      return;
    }
    break;
  default:
    return;
  case '\f':
    bVar1 = spec[1];
    if ((bVar1 & 0x40) == 0) {
      if (in_stack_00000018 != ebx) {
        *(int *)(spec + 0xc) = in_stack_00000018;
        spec[1] = bVar1 | 0x40;
        return;
      }
      *(int *)(spec + 0xc) = ebx;
      spec[1] = bVar1 & 0xbf;
      return;
    }
    break;
  case '\r':
    if (g_line_map_cached_row.position == g_token_position) {
      pcVar2 = &g_line_map_cached_row;
    }
    else {
      pcVar2 = pp_line_map_find_entry(&g_line_map,g_token_position);
    }
    (*g_idb->vtbl->idb_scope_kind3_to_2)
              (g_idb,CONCAT22((short)((uint)g_macro_expansion_depth >> 0x10),
                              (short)pcVar2->line - (short)pcVar2->position) + g_token_position,
               g_macro_expansion_depth);
    if ((spec[1] & 4) == 0) {
      spec[1] = spec[1] | 4;
      return;
    }
    bVar1 = 0xd;
    goto LAB_1045b97b;
  case '\x0f':
    if ((spec[1] & 2) == 0) {
      spec[1] = spec[1] | 2;
      return;
    }
    bVar1 = 0xf;
    goto LAB_1045b97b;
  case '\x11':
    bVar1 = spec[0x14];
    if ((bVar1 & 1) == 0) {
      if (in_stack_00000018 == ebx) {
        *(int *)(spec + 0x10) = ebx;
        spec[0x14] = bVar1 & 0xfe;
        return;
      }
      *(int *)(spec + 0x10) = in_stack_00000018;
      spec[0x14] = bVar1 | 1;
      return;
    }
    break;
  case '\x12':
    if ((spec[0x14] & 2) == 0) {
      spec[0x14] = spec[0x14] | 2;
      return;
    }
    break;
  case '\x13':
    if ((spec[0x14] & 8) == 0) {
      spec[0x14] = spec[0x14] | 8;
      return;
    }
    break;
  case -0x21:
    if ((spec[3] & 4) == 0) {
      spec[3] = spec[3] | 4;
      return;
    }
    bVar1 = 0xdf;
    goto LAB_1045b97b;
  case -0x20:
    if ((spec[3] & 8) == 0) {
      spec[3] = spec[3] | 8;
      return;
    }
    bVar1 = 0xe0;
    goto LAB_1045b97b;
  case -0x14:
    if ((spec[1] & 1) == 0) {
      spec[1] = spec[1] | 9;
      return;
    }
    bVar1 = 0xec;
    goto LAB_1045b97b;
  }
  bVar1 = 6;
LAB_1045b97b:
  if (in_stack_00000014 == '\b') {
    diag_warning(1,0x8d,"allocate");
    return;
  }
  if (in_stack_00000014 == '\f') {
    diag_warning(1,0x8d,"uuid");
    return;
  }
  if (in_stack_00000014 == '\x11') {
    diag_warning(1,0x8d,"implementation_key");
    return;
  }
  if (bVar1 == 6) {
    diag_warning(1,0x8d,g_last_name->text);
    return;
  }
  diag_warning(1,0x8d,g_token_spelling[bVar1]);
  decl_specifiers_merge_return();
  return;
}

