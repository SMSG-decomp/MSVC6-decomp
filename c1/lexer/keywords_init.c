void __cdecl keywords_init(void)

{
  undefined **ppuVar1;
  c1_declspec_attribute *pcVar2;
  char *text;
  int iVar3;
  uchar uVar4;
  undefined **ppuVar5;
  c1_declspec_attribute *pcVar6;
  
  if ((g_ms_extensions != '\0') || (g_ms_extensions = '\0', g_opt_ZBe != '\0')) {
    g_ms_extensions = '\x01';
  }
  g_integral_max_bytes = (int)(g_integral_max_bytes + (g_integral_max_bytes >> 0x1f & 7U)) >> 3;
  if (g_integral_max_bytes != 0) {
    if ((g_integral_max_bytes < 4) || (8 < g_integral_max_bytes)) {
      iVar3 = g_integral_max_bytes * 8;
    }
    else {
      if ((g_integral_max_bytes == 4) || (g_integral_max_bytes == 8)) goto LAB_10614084;
      iVar3 = g_integral_max_bytes << 3;
    }
    diag_warning(1,0x2b8,iVar3,0x20);
  }
  g_integral_max_bytes = 4;
LAB_10614084:
  text = "auto";
  ppuVar5 = &PTR_s_auto_106549c8;
  do {
    name_intern_keyword((byte *)text);
    g_last_name->flags = g_last_name->flags | 0x10000;
    g_last_name->token_kind = *(uchar *)(ppuVar5 + 1);
    text = ppuVar5[2];
    ppuVar5 = ppuVar5 + 2;
  } while ((byte *)text != (byte *)0x0);
  keyword_unreserve((byte *)"asm");
  keyword_unreserve((byte *)"catch");
  keyword_unreserve((byte *)"class");
  keyword_unreserve((byte *)"const_cast");
  keyword_unreserve((byte *)"delete");
  keyword_unreserve((byte *)"dynamic_cast");
  keyword_unreserve((byte *)"explicit");
  keyword_unreserve((byte *)"friend");
  keyword_unreserve((byte *)"inline");
  keyword_unreserve((byte *)"mutable");
  keyword_unreserve((byte *)"namespace");
  keyword_unreserve((byte *)"new");
  keyword_unreserve((byte *)"operator");
  keyword_unreserve((byte *)"private");
  keyword_unreserve((byte *)"protected");
  keyword_unreserve((byte *)"public");
  keyword_unreserve((byte *)"reinterpret_cast");
  keyword_unreserve((byte *)"static_cast");
  keyword_unreserve((byte *)"template");
  keyword_unreserve((byte *)"this");
  keyword_unreserve((byte *)"throw");
  keyword_unreserve((byte *)"try");
  keyword_unreserve((byte *)"typeid");
  keyword_unreserve((byte *)"typename");
  keyword_unreserve((byte *)"using");
  keyword_unreserve((byte *)"virtual");
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
      ((g_ms_extensions == '\0' &&
       ((keyword_unreserve((byte *)"huge"), g_opt_Zf == '\0' && (g_ms_extensions == '\0')))))) &&
     ((keyword_unreserve((byte *)"near"), g_opt_Zf == '\0' && (g_ms_extensions == '\0')))) {
    keyword_unreserve((byte *)"pascal");
  }
  keyword_unreserve((byte *)"wchar_t");
  keyword_unreserve((byte *)"and");
  keyword_unreserve((byte *)"and_eq");
  keyword_unreserve((byte *)"bitand");
  keyword_unreserve((byte *)"or");
  keyword_unreserve((byte *)"or_eq");
  keyword_unreserve((byte *)"bitor");
  keyword_unreserve((byte *)"xor");
  keyword_unreserve((byte *)"xor_eq");
  keyword_unreserve((byte *)"compl");
  keyword_unreserve((byte *)"not");
  keyword_unreserve((byte *)"not_eq");
  keyword_unreserve((byte *)"bool");
  keyword_unreserve((byte *)"true");
  keyword_unreserve((byte *)"false");
  keyword_unreserve((byte *)"__CURSOR__");
  keyword_mark_cpp_only((byte *)"__single_inheritance");
  keyword_mark_cpp_only((byte *)"__multiple_inheritance");
  keyword_mark_cpp_only((byte *)"__virtual_inheritance");
  keyword_mark_cpp_only((byte *)"__novtordisp");
  keyword_mark_cpp_only((byte *)"__uuidof");
  keyword_mark_reserved_future_use((byte *)"__resume");
  keyword_mark_reserved_future_use((byte *)"__nounwind");
  keyword_mark_obsolete((byte *)"__syscall");
  keyword_mark_obsolete((byte *)"__near");
  keyword_mark_obsolete((byte *)"__far");
  keyword_mark_obsolete((byte *)"__far16");
  keyword_mark_obsolete((byte *)"__huge");
  keyword_mark_obsolete((byte *)"__fortran");
  keyword_mark_obsolete_export((byte *)"__export");
  keyword_mark_reserved_future_use((byte *)"__thiscall");
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
  keyword_mark_not_yet_supported((byte *)"bool");
  keyword_mark_not_yet_supported((byte *)"true");
  keyword_mark_not_yet_supported((byte *)"false");
  if ((g_ms_extensions != '\0') || (g_pch_option_block != 0)) {
    ppuVar5 = &PTR_s_auto_106549c8;
    do {
      iVar3 = strncmp(*ppuVar5,"__",2);
      if ((iVar3 == 0) && (name_intern_keyword(*ppuVar5), (g_last_name->flags & 0x10000) != 0)) {
        uVar4 = g_last_name->token_kind;
        if (uVar4 == 0xf6) {
          uVar4 = g_last_name->keyword_class;
          if ((uVar4 == '\x01') || (uVar4 == '\x05')) {
            name_intern_keyword(*ppuVar5 + 1);
            g_last_name->flags = g_last_name->flags | 0x10000;
            g_last_name->token_kind = 0xf6;
            g_last_name->keyword_class = uVar4;
          }
        }
        else {
          name_intern_keyword(*ppuVar5 + 1);
          g_last_name->flags = g_last_name->flags | 0x10000;
          g_last_name->token_kind = uVar4;
        }
      }
      ppuVar1 = ppuVar5 + 2;
      ppuVar5 = ppuVar5 + 2;
    } while (*ppuVar1 != (undefined *)0x0);
  }
  uVar4 = '\0';
  pcVar6 = g_declspec_attributes;
  do {
    name_intern_keyword((byte *)pcVar6->name);
    g_last_name->flags = g_last_name->flags | 0x800000;
    if ((g_last_name->flags & 0x10000) == 0) {
      g_last_name->token_kind = uVar4;
    }
    pcVar2 = pcVar6 + 1;
    pcVar6 = pcVar6 + 1;
    uVar4 = uVar4 + '\x01';
  } while (pcVar2->name != (char *)0x0);
  return;
}

