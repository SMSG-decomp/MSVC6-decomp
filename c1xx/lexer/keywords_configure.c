void __cdecl keywords_configure(void)

{
  c1_declspec_attribute *pcVar1;
  char *text;
  int iVar2;
  uchar uVar3;
  c1_keyword_row *next_row;
  c1_keyword_row *row;
  c1_declspec_attribute *pcVar4;
  c1_keyword_row *next_row_2;
  
  if ((g_ms_extensions != '\0') || (g_ms_extensions = '\0', g_opt_ZBe != '\0')) {
    g_ms_extensions = '\x01';
  }
  g_integral_max_bytes = (int)(g_integral_max_bytes + (g_integral_max_bytes >> 0x1f & 7U)) >> 3;
  if (g_integral_max_bytes != 0) {
    if ((g_integral_max_bytes < 4) || (8 < g_integral_max_bytes)) {
      iVar2 = g_integral_max_bytes * 8;
    }
    else {
      if ((g_integral_max_bytes == 4) || (g_integral_max_bytes == 8)) goto LAB_1044681d;
      iVar2 = g_integral_max_bytes << 3;
    }
    diag_warning(1,0x2b8,iVar2,0x20);
  }
  g_integral_max_bytes = 4;
LAB_1044681d:
  text = "auto";
  next_row = g_keyword_token_table;
  do {
    name_intern_keyword((byte *)text);
    g_last_name->flags = g_last_name->flags | 0x10000;
    g_last_name->token_kind = next_row->token;
    text = next_row[1].text;
    next_row = next_row + 1;
  } while ((byte *)text != (byte *)0x0);
  keyword_unreserve((byte *)"__interrupt");
  keyword_unreserve((byte *)"__loadds");
  keyword_unreserve((byte *)"__saveregs");
  keyword_unreserve((byte *)"__segment");
  keyword_unreserve((byte *)"__segname");
  keyword_unreserve((byte *)"__self");
  if (g_ms_extensions == '\0') {
    keyword_unreserve((byte *)"cdecl");
  }
  if ((((((g_opt_Zf == '\0') && (g_ms_extensions == '\0')) &&
        (keyword_unreserve((byte *)"far"), g_opt_Zf == '\0')) &&
       ((g_ms_extensions == '\0' && (keyword_unreserve((byte *)"fortran"), g_opt_Zf == '\0')))) &&
      (g_ms_extensions == '\0')) &&
     (((keyword_unreserve((byte *)"huge"), g_opt_Zf == '\0' && (g_ms_extensions == '\0')) &&
      ((keyword_unreserve((byte *)"near"), g_opt_Zf == '\0' && (g_ms_extensions == '\0')))))) {
    keyword_unreserve((byte *)"pascal");
  }
  keyword_unreserve((byte *)"wchar_t");
  if ((((((g_ms_extensions != '\0') && (keyword_unreserve((byte *)"and"), g_ms_extensions != '\0'))
        && (keyword_unreserve((byte *)"and_eq"), g_ms_extensions != '\0')) &&
       ((keyword_unreserve((byte *)"bitand"), g_ms_extensions != '\0' &&
        (keyword_unreserve((byte *)"or"), g_ms_extensions != '\0')))) &&
      (((keyword_unreserve((byte *)"or_eq"), g_ms_extensions != '\0' &&
        ((keyword_unreserve((byte *)"bitor"), g_ms_extensions != '\0' &&
         (keyword_unreserve((byte *)"xor"), g_ms_extensions != '\0')))) &&
       (keyword_unreserve((byte *)"xor_eq"), g_ms_extensions != '\0')))) &&
     ((keyword_unreserve((byte *)"compl"), g_ms_extensions != '\0' &&
      (keyword_unreserve((byte *)"not"), g_ms_extensions != '\0')))) {
    keyword_unreserve((byte *)"not_eq");
  }
  if ((((g_opt_noBool != '\0') || (g_ms_extensions != '\0')) &&
      (keyword_unreserve((byte *)"bool"), g_opt_noBool != '\0')) &&
     (keyword_unreserve((byte *)"true"), g_opt_noBool != '\0')) {
    keyword_unreserve((byte *)"false");
  }
  keyword_unreserve((byte *)"__CURSOR__");
  keyword_mark_reserved_future_use((byte *)"__resume");
  keyword_mark_reserved_future_use((byte *)"__nounwind");
  keyword_mark_obsolete((byte *)"__syscall");
  keyword_mark_obsolete((byte *)"__near");
  keyword_mark_obsolete((byte *)"__far");
  keyword_mark_obsolete((byte *)"__far16");
  keyword_mark_obsolete((byte *)"__huge");
  keyword_mark_obsolete((byte *)"__fortran");
  keyword_mark_obsolete_export((byte *)"__export");
  if (g_opt_Binl == 0) {
    keyword_mark_reserved_future_use((byte *)"__thiscall");
  }
  keyword_mark_obsolete((byte *)"far");
  keyword_mark_obsolete((byte *)"fortran");
  keyword_mark_obsolete((byte *)"huge");
  keyword_mark_obsolete((byte *)"near");
  keyword_mark_obsolete((byte *)"pascal");
  keyword_mark_obsolete((byte *)"__pascal");
  keyword_mark_not_supported((byte *)"__unaligned");
  keyword_mark_not_supported((byte *)"__builtin_alignof");
  keyword_mark_not_supported((byte *)"__sysapi");
  keyword_mark_not_supported((byte *)"__builtin_isfloat");
  keyword_mark_not_supported((byte *)"__wchar_t");
  keyword_mark_not_supported((byte *)"__ptr64");
  keyword_mark_not_supported((byte *)"__probability");
  keyword_mark_not_supported((byte *)"__nodefault");
  if (((g_integral_max_bytes < 4) &&
      (keyword_mark_not_supported((byte *)"__int8"), g_integral_max_bytes < 4)) &&
     (keyword_mark_not_supported((byte *)"__int16"), g_integral_max_bytes < 4)) {
    keyword_mark_not_supported((byte *)"__int32");
  }
  if (g_integral_max_bytes < 8) {
    keyword_mark_not_supported((byte *)"__int64");
  }
  if (g_integral_max_bytes < 0x10) {
    keyword_mark_not_supported((byte *)"__int128");
  }
  if ((g_ms_extensions != '\0') || (g_pch_option_block != 0)) {
    row = g_keyword_token_table;
    do {
      iVar2 = strncmp(row->text,"__",2);
      if ((iVar2 == 0) &&
         (name_intern_keyword((byte *)row->text), (g_last_name->flags & 0x10000) != 0)) {
        uVar3 = g_last_name->token_kind;
        if (uVar3 == 0xf6) {
          uVar3 = g_last_name->keyword_class;
          if ((uVar3 == '\x01') || (uVar3 == '\x05')) {
            name_intern_keyword((byte *)(row->text + 1));
            g_last_name->flags = g_last_name->flags | 0x10000;
            g_last_name->token_kind = 0xf6;
            g_last_name->keyword_class = uVar3;
          }
        }
        else {
          name_intern_keyword((byte *)(row->text + 1));
          g_last_name->flags = g_last_name->flags | 0x10000;
          g_last_name->token_kind = uVar3;
        }
      }
      next_row_2 = row + 1;
      row = row + 1;
    } while (next_row_2->text != (char *)0x0);
  }
  uVar3 = '\0';
  pcVar4 = g_declspec_attribute_table;
  do {
    name_intern_keyword((byte *)pcVar4->name);
    g_last_name->flags = g_last_name->flags | 0x800000;
    if ((g_last_name->flags & 0x10000) == 0) {
      g_last_name->token_kind = uVar3;
    }
    pcVar1 = pcVar4 + 1;
    pcVar4 = pcVar4 + 1;
    uVar3 = uVar3 + '\x01';
  } while (pcVar1->name != (char *)0x0);
  return;
}

