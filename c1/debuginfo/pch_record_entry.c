int __cdecl pch_record_entry(int kind,int value,char *text)

{
  c1_u8 *s;
  int iVar1;
  int *piVar2;
  bool bVar3;
  
  if (g_pch_directive_mode == 1) {
    pragma_section_record(kind,value,text);
    return 2;
  }
  if (g_pch_directive_mode != 2) {
    return 0;
  }
  if ((*g_pch_record_cursor == kind) && (g_pch_record_cursor[2] == value)) {
    iVar1 = (int)(short)g_pch_record_cursor[1];
    bVar3 = true;
    piVar2 = g_pch_record_cursor + 3;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar3 = (char)*piVar2 == *text;
      piVar2 = (int *)((int)piVar2 + 1);
      text = text + 1;
    } while (bVar3);
    if (bVar3) {
      g_pch_record_cursor = (int *)((int)g_pch_record_cursor + g_pch_record_cursor[1] + 0xc);
      return 2;
    }
  }
  s = str_dup_arena(g_last_name->text,3);
  iVar1 = pch_auto_match_end();
  if (iVar1 == 3) {
    name_intern((char *)s);
  }
  return iVar1;
}

